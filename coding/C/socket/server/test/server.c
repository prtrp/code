#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void) {
  int listenfd = 0, connfd = 0;
  struct sockaddr_in server_addr;
  char buff[1024];

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(5000);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if(bind(listenfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    perror("ERROR WITH BIDING\n");
    close(listenfd);
    exit(EXIT_FAILURE);
  }

  if((listen(listenfd, 5)) == -1) {
    perror("ERROR WITH LISTEN\n");
    close(listenfd);
    exit(EXIT_FAILURE);
  }

  while(true) {
    connfd = accept(listenfd, NULL, NULL);
    strcpy(buff, "Message from server");
    write(connfd, buff, strlen(buff));
    close(connfd);
    sleep(1);
  }
  return 0;
}
