#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  int sockfd = 0;

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("ERROR SOCKETFD");
    exit(EXIT_FAILURE);
  }

  if(connect(sockfd,(struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
    perror("CLIENT CONNECTION ERROR");
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  char msg[256];
  recv(sockfd, msg, sizeof(msg), 0);

  printf("the server sends the data --> %s\n", msg);
  close(sockfd);
  return 0;
}
