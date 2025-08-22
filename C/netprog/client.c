#include <arpa/inet.h>  /* inet_addr */
#include <stdio.h>
#include <netinet/in.h> /* sockaddr, sockaddr_in */
#include <sys/socket.h> /* scoket, connect, AF_INET, SOCK_STREAM */
#include <sys/types.h>  /* htonl, htons */
#include <unistd.h>     /* read, write, close */

#define MAX_MSG 256
#define PORT  8080

int main() {
    struct sockaddr_in server_sockaddr_in;

    server_sockaddr_in.sin_family = AF_INET;

    /* indirizzo di loopback */
    server_sockaddr_in.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_sockaddr_in.sin_port = htons(PORT);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    connect (socket_fd, (struct sockaddr*)&server_sockaddr_in, sizeof(server_sockaddr_in));

    while (1) {
        char buffer[MAX_MSG] = {0};
        printf("ENTER message: \n");

        fgets(buffer, MAX_MSG, stdin);

        write(socket_fd, buffer, sizeof(buffer));
    }

    close(socket_fd);
}
