
/*
 * A server program to generate random advice 
 * for any client who connects to it
 * 
 * Version 2:
 * Now comes complete with error checking
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>     // Required for sockets
#include <arpa/inet.h>      // Required to create internet addresses


void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}


int main(int argc, char *argv[])
{
    char *advice[] = {
        "Take smaller bites.\r\n",
        "Go for the tight jeans. No, they do NOT make you look fat.\r\n",
        "One word: Inappropriate.\r\n",
        "Just for today, be honest. Tell your boss what you *really* think.\r\n",
        "You might want to rethink that haircut.\r\n"
    };
    
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);
    if (listener_d == -1)
        error("Socket connection failed");
    
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(30000);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    
    int reuse = 1;                                              // YES, REUSE THE PORT. If the server is
    if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR,        // shut down then re-started again, the 
                    (char *) &reuse, sizeof(int)) == -1)        // port will still be bound from the 
        error("Unable to set reuse option on the socket");      // previous process, so it must be reused.
    
    if (bind(listener_d, (struct sockaddr *) &name,
                        sizeof(name)) == -1)
        error("Unable to bind port");
    
    listen(listener_d, 1);
    puts("Waiting for connection...");
    
    while (1) {
        struct sockaddr_storage client_addr;
        unsigned int address_size = sizeof(client_addr);
        
        int connect_d = 
            accept(listener_d, (struct sockaddr *) &client_addr,
            &address_size);
            
        char *msg = advice[rand() % 5];
    
        send(connect_d, msg, strlen(msg), 0);
        close(connect_d);
    }
    
    return 0;
}
