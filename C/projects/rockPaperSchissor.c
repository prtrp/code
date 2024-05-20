#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char pcSelect()
{
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

int game(char pc, char player)
{
  if(player == pc)
  {
    return 0;
  }
  else if((player == 'r' && pc == 's') || (player == 'p' && pc == 'r') || (player == 's' && pc == 'p'))
  {
    return 1;
  }
  else if((player == 's' && pc == 'r') || (player == 'r' && pc == 'p' || player == 'p' && pc =='s'))
  {
    return -1;
  }

  return -2;

}

void checkGame(int result)
{
  if( result == 0)
  {
    printf("tie\n");
    return;
  }
  else if(result == 1)
  {
    printf("win\n");
    return;
  }
  else if(result == -1)
  {
    printf("lose\n");
    return;
  }
  printf("insert a corect character\n");
  return;
}

int main()
{
  int result;
  char pc, player;
   
  pc = pcSelect();
  printf("select s for scissors, r for rock, p for paper:\n>> ");
  scanf("%c", &player);
  
  result = game(pc, player);
  checkGame(result);
}

