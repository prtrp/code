#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>

char* takeWord(int);
int randomWord(void);
void home(void);
void gotoxy(int, int);
void game(void);
void addWord(void);

int main() {
  home();
  return 0;
}

void gotoxy(int x, int y) {
  printf("\033[%d;%dH", y, x);
}

char* takeWord(int numLine) {
  static char buffer[128];
  FILE *fp = fopen("wordsFile.txt", "r");
  if (fp == NULL) {
    printf("ERROR DURING FILE\n");
    exit(10);
  }

  int countLine = 0;
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    if (countLine == numLine) {
      buffer[strcspn(buffer, "\n")] = '\0';
      break;
    }
    countLine++;
  }
  fclose(fp);
  return buffer;
}

int randomWord(void) {
  FILE *fp = NULL;
  fp = fopen("wordsFile.txt", "r");
  if(fp == NULL) {
    printf("error on file\n");
    exit(1);
  }
  
  int random = 0;
  int countWord = 0;
  char buffWord[128];

  while(fgets(buffWord, sizeof(buffWord), fp) != NULL ) {
    countWord++;
  }
  srand(time(NULL));
  random = rand() % (countWord );
  return random;
}

void home(void) {
  int choice;
  system("clear");

  gotoxy(30, 7);
  printf("ENTER A CHOISE");

  gotoxy(30, 9);
  printf("1.... PLAY GAME");

  gotoxy(30, 10);
  printf("2.... ADD A WORD");

  gotoxy(30, 11);
  printf("3.... EXIT");

  gotoxy(30, 13);
  printf("ENTER.... ");

  scanf("%d", &choice);
  switch(choice) {
    case 1: 
     game();
      break;
    case 2:
      addWord();
      break;
    case 3:
      exit(1);
    default:
      home();
      break;
  }
} 

void addWord(void) {
  FILE *fp = NULL;
  fp = fopen("wordsFile.txt", "a");
  char buffer[128];
  int counter = 0, i = 0;

  getchar();
  while((counter = getchar()) != '\n') {
    if (i < sizeof(buffer) - 1) {
      buffer[i] = counter;
      i++;
    }
    buffer[i] = '\0';
  }
  fputs(buffer, fp);
  fputs("\n", fp);
  fclose(fp);
}

void game(void) {
  int numRand = randomWord();
  int game = 0;
  char c;
  char* word;
  char buffWord[128];
  word = takeWord(numRand);
  static char stars[128];
  int i = 0;

  // Popola l'array `stars` con asterischi una sola volta
  while ((c = word[i]) != '\0' && c != '\n') {
    stars[i] = '*';
    i++;
  }
  stars[i] = '\0'; // Aggiungi il terminatore di stringa

  while (game == 0) {
    int error = 0;

    while (strcmp(word, buffWord) != 0) {
      system("clear");
      gotoxy(0,1);
      printf("WORD:\n");

      gotoxy(0,2);
      printf("%s\n", stars);

      gotoxy(0, 3);
      putchar('\n');
      printf("letters inside: %d\n", i);

      gotoxy(0, 5);
      printf("insert the word\n>> ");
      scanf("%s", buffWord);
      fflush(stdin); // Pulisci il buffer dell'input

      error += 1;
      gotoxy(0, 7);
      printf("error %d", error);
    }

    gotoxy(0, 6);
    printf("indovinato\n");
    game = 1; // Imposta game a 1 per uscire dal loop
  }
  gotoxy(0, 8);
}

//        |--|
//        |  |
//        |  O
//        | /|\
//        |  |
//        | / \
//     ___|___
