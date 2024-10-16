#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>

char pcSelect(void);
int game(char, char);
void checkGame(int, char);
void gotoxy(int, int);
void playGame(void);
void home(void);

int main(){
  home();
}

void gotoxy(int x, int y) {
  printf("\033[%d;%dH", x, y);
}

void playGame(void) {
  int result;
  char pc, player;
   
  pc = pcSelect();
  system("clear");
  gotoxy(6, 20);
  printf("select s for scissors, r for rock, p for paper");

  gotoxy(7, 20);
  printf(">> ");
  scanf("%c", &player);
  
  result = game(pc, player);
  checkGame(result, pc);
}


char pcSelect(void){
  srand(time(NULL));
  int randomNum = rand() % 100;
  
  if(randomNum < 33)
  {
    return 's';
  } 
  else if(randomNum >= 33 && randomNum <= 66)
  {
    return 'p';
  }
  else
  {
    return 'r';
  }

}

int game(char pc, char player) {
  if(player == pc) {
    return 0;
  }
  else if((player == 'r' && pc == 's') || (player == 'p' && pc == 'r') || (player == 's' && pc == 'p')) {
    return 1;
  }
  else if((player == 's' && pc == 'r') || (player == 'r' && pc == 'p' || player == 'p' && pc =='s')) {
    return -1;
  }
  return -2;

}

void checkGame(int result, char pc) {
  int choice = 0;

  if(result == 1) {
    gotoxy(9, 20);
    printf("pc select <%c>", pc);

    gotoxy(10, 20);
    printf("you win\n");
  }
  else if(result == 0) {
    gotoxy(9, 20);
    printf("pc select <%c>", pc);

    gotoxy(10, 20);
    printf("you tie\n");
  }
  else if(result == -1) {
    gotoxy(9, 20);
    printf("pc select <%c>", pc);

    gotoxy(10, 20);
    printf("you lose\n");
  }
  else {
    gotoxy(9, 20);
    printf("No valid choice\n");
  }
  gotoxy(14, 20);
  printf("PRESS ENTER");
  getchar();
  scanf("%c", &choice);
  if (choice = '\n') {
    home();
  }
}

void home(void) {
  system("clear");
  int choice = 0;

  gotoxy(10, 30);
  printf("SELECT A CHOICE");

  gotoxy(12, 30);
  printf("1....FOR PLAY AGINE");
  
  gotoxy(13, 30);
  printf("2....FOR EXIT");

  gotoxy(14, 30);
  printf(">>");
  scanf("%d", &choice);
  switch(choice) {
    case 1: 
      getchar();
      playGame();
      break;

    case 2:
      exit(1);
      break;

    default:
      break; 
  }
}

