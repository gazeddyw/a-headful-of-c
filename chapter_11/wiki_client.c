
/*
 * Internet Wiki Client
 * 
 * This program prints the source code for a
 * Wikipedia page of the user's choice
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>              // netdb.h is required for the getaddrinfo() function below


void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int open_socket(char *host, char *port)
{
    struct addrinfo *res;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    // getaddrinfo() finds ADDRESSES by DOMAIN
    if (getaddrinfo(host, port, &hints, &res) == -1)
        error("Unable to resolve address");
    
    int d_sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    // server equivalent is socket(PF_INET, SOCK_STREAM, 0);
    if (d_sock == -1)
        error("Unable to open socket");
        
    // res->ai_addr is the address of the remote host and port
    int c = connect(d_sock, res->ai_addr, res->ai_addrlen);     // Connect to the remote socket
    freeaddrinfo(res);  // Once connected, address data can be deleted
    if (c == -1)
        error("Unable to connect to socket");
    
    return d_sock;
}

int say(int socket, char *s)
{
    int result = send(socket, s, strlen(s), 0);
    if (result == -1)
        fprintf(stderr, "%s: %s\n", "Error communicating with server",
                strerror(errno));
    
    return result;
}

int main(int argc, char *argv[])
{
    int d_sock = open_socket("en.wikipedia.org", "80");
    
    char buf[255];
    sprintf(buf, "GET /wiki/%s HTTP/1.1\r\n", argv[1]);
    say(d_sock, buf);
    
    say(d_sock, "Host: en.wikipedia.org\r\n\r\n");
    
    char rec[256];
    int bytes_rcvd = recv(d_sock, rec, 255, 0);
    while (bytes_rcvd) {
        if (bytes_rcvd == -1)
            error("Unable to read from server");
        
        rec[bytes_rcvd] = '\0';
        printf("%s", rec);
        bytes_rcvd = recv(d_sock, rec, 255, 0);
    }
    close(d_sock);
    return 0;
}
