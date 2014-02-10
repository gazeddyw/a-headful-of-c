
/*
 * Internet Knock Knock server
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>


int listener_d;     // This stores the main listener socket for the server


void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}


int open_listener_socket()
{
    int s = socket(PF_INET, SOCK_STREAM, 0);
    if (s == -1)
        error("Unable to open socket");
    
    return s;
}


void bind_to_port(int socket, int port)
{
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(30000);    // "name" has internet port 30000
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    
    int reuse = 1;
    if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR,
                  (char *) &reuse, sizeof(int)) == -1)
        error("Unable to set reuse option on socket");
    
    int c = bind(socket, (struct sockaddr *) &name,
                 sizeof(name));
    if (c == -1)
        error("Unable to bind socket");
}


int say(int socket, char *s)
{
    int result = send(socket, s, strlen(s), 0);
    if (result == -1)                                                               // Good point - Don't call error() if there's
        fprintf(stderr, "%s: %s\n", "Error talking to client", strerror(errno));    // a problem with a CLIENT. The SERVER does
                                                                                    // not need to be stopped!
    return result;
}


int read_in(int socket, char *buf, int len)
{
    char *s = buf;      // Why these assignments??
    int slen = len;     // Just pass buf and len straight into recv()??
    int c = recv(socket, s, slen, 0);
    
    while ((c > 0) && (s[c-1] != '\n')) {
        s += c;
        slen -= c;
        c = recv(socket, s, slen, 0);
    }
    
    if (c < 0)
        return c;
    else if (c == 0)
        buf[0] = '\0';  // Nothing read? Send back an empty string.
    else
        s[c-1] = '\0';
    
    return (len - slen);
}


int catch_signal(int sig, void (*handler)(int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}


void handle_shutdown(int sig)
{
    if (listener_d)
        close(listener_d);
    
    fprintf(stderr, "\n\nBye!\n\n");
    exit(0);
}


int main(int argc, char *argv[])
{
    if (catch_signal(SIGINT, handle_shutdown) == -1)
        error("Can't set the interrupt handler");
    
    listener_d = open_listener_socket();
    bind_to_port(listener_d, 30000);
    
    if (listen(listener_d, 10) == -1)
        error("Unable to listen");
    
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    puts("Awaiting connection...");
    
    char buf[255];  // Buffer for user answers
    
    while (1) {
        
        int connect_d = 
            accept(listener_d, (struct sockaddr *) &client_addr,
            &address_size);
        if (connect_d == -1)
            error("Unable to open secondary socket");
        
	if (!fork()) {                  // fork() the server process when a new client connects
            close(listener_d);          // listener_d can be closed now that we're in the child process
            if (say(connect_d,
                "Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\n\nKnock! Knock!\r\n> ") != -1) {
                read_in(connect_d, buf, sizeof(buf));
                if (strncasecmp("Who's there?", buf, 12))
                    say(connect_d, "You should say \"Who's there?\"\r\n");     // Check the user's answers
                else {
                    if (say(connect_d, "Oscar...\r\n> ") != -1) {
                        read_in(connect_d, buf, sizeof(buf));
                        if (strncasecmp("Oscar who?", buf, 10))
                            say(connect_d, "You should say \"Oscar who?\"\r\n");   // Check the user's answers
                        else
                            say(connect_d, "Oscar silly question, you get a silly answer!\r\n");
                    }
                }
            }
            close(connect_d);
            exit(0);
        }
        close(connect_d);   // Close secondary socket used for the conversation
    }
    return 0;
}
