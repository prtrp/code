#include <stdio.h>
#include <netinet/in.h>     /* sockaddr_int, INADDR_ANY */
#include <sys/socket.h>     /* socket, bind, listen, accept, AF_INET, SOCK_STREAM */
#include <sys/types.h>      /* htonl, htons, socklen_t */
#include <unistd.h>         /* read, write, close */

#define MAX_MSG 256
#define PORT 8080

int main(void) {

    /* initialize the detail of the server socket */
    struct sockaddr_in server_sockaddr_in;


    /* AF_INET = IPv4 */
    server_sockaddr_in.sin_family = AF_INET;

    /* */
    server_sockaddr_in.sin_addr.s_addr = htonl(INADDR_ANY);

    server_sockaddr_in.sin_port = htons(PORT);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    bind(socket_fd, (struct sockaddr*)&server_sockaddr_in, sizeof(server_sockaddr_in));

    listen(socket_fd, 5);

    struct sockaddr_in client_sockaddr_in;
    socklen_t len = sizeof(client_sockaddr_in);

    int connection_fd = accept(socket_fd, (struct sockaddr*)&client_sockaddr_in, &len);

    char buffer[MAX_MSG] = {0};

    read(connection_fd, buffer, sizeof(buffer));
    printf("%s", buffer);

    char status = 0;

    write(connection_fd, &status , 1);
    close (socket_fd);

    return 0;
} 

