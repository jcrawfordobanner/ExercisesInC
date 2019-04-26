/* Code from Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int open_socket(char *ip, int port)
{
    struct sockaddr_in si;
    int d_sock, c;

    memset(&si, 0, sizeof(si));
    si.sin_family = PF_INET;
    si.sin_addr.s_addr = inet_addr(ip);
    si.sin_port=htons(port);
    if (( d_sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
        error("Can't open socket");

    c = connect(d_sock, (struct sockaddr *) &si, sizeof(si));
    if (c == -1)
        error("Can't connect to the socket");

    return d_sock;
}

int say(int socket, char *s)
{
    int result = send(socket, s, strlen(s), 0);
    if (result == -1)
        error("Can't talk to the server");

    return result;
}

int main(int argc, char *argv[])
{
    int d_sock, bytes_received;
    char buf[255], rec[256];

    /* connect to server */
    d_sock = open_socket("127.0.0.1", 30000);

    /* request the resource */
    recv(d_sock,buf,255,0);
    printf("%s\n", buf);
    close(d_sock);

    return 0;
}
