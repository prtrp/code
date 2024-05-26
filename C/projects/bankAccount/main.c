#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

void account(void);
void login(void);
void accountFunctions(char*);
void logout(void);
void transferMoney(char*);
void checkBalance(char*);
void home(void);
void showId(char *);

void gotoxy (int y, int x) {
  printf("\033[%d;%dH", y, x);
}

// it is the struct of username data
typedef struct {
  int date;
  int month;
  int year;
  long money;
  
  char phonNum[16];
  char idCard[24];
  char fName[24];
  char lName[24];
  char address[56];
  char passWord[56];
} user;

// it is the struct for see the money
typedef struct {
  char userNameTo[24];
  char userNameFrom[24];
  long int amountMoney;
} transaction;

// main function
int main() {
  home();
  return 0;
}

void home(void) {
  system("clear");
  int choice;

  gotoxy(5, 20);
  printf("WELCOME TO BANK ACCOUNT SYSTEM");

  gotoxy(5, 18);
  printf("**********************************");

  gotoxy(7, 25);
  printf("CREATOR -PETRU RUSU-");

  gotoxy(10, 20);
  printf("1.... CREATE A BANK ACCOUNT");

  gotoxy(12, 20);
  printf("2.... ALREADY A USER? SIGN IN");

  gotoxy(14, 20);
  printf("3.... EXIT");

  printf("ENTER YOUR CHOICE.. ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      system("clear");
      account();
      break;
    case 2:
      login();
      break;
    case 3:
      exit(1);
  }
}

// create the account
void account (void) {
  char ch;
  int i;
  user u1;

  FILE *fp;
  fp = NULL;

  fp = fopen("username.dat", "ab");
  if(fp == NULL) {
    printf("error, pointer NULL\n");
    exit(1);
  }

  system("clear");
  printf("\n\nCreate Account");

  printf("\n\nFirst Name..");
  scanf("%s", &u1.fName);

  printf("\n\nLast Name..");
  scanf("%s", &u1.lName);

  printf("\n\nPhon Number..");
  scanf("%s", &u1.phonNum);

  printf("\n\nId Card..");
  scanf("%s", u1.idCard);
  getchar();
  
  printf("\n\nYour Address..");
  fgets(u1.address, sizeof(u1.address), stdin);

  // the amount of moeny for every account
  u1.money = 5000;

  printf("\n\nDate of Birth..");
  printf("\nDay..");
  scanf("%d", &u1.date);
  printf("\nMonth..");
  scanf("%d", &u1.month);
  printf("\nYear..");
  scanf("%d", &u1.year);
  getchar();

  printf("\n\nPassword..");
  for (i = 0; i < 50; i++) {
    ch = getchar();
    if (ch == '\n' || ch == '\r') {
      break;
    }
    u1.passWord[i] = ch;
  }
  u1.passWord[i] = '\0';

  fwrite(&u1, sizeof(u1), 1, fp);
  fclose(fp);

  printf("\nAccount created successfully!\n");
  home();
}

void login(void) {
  system("clear");
  
  char username[24];
  char password[56];

  char ch;
  int choice;
  int i;

  FILE *fp = NULL;
  fp = fopen("username.dat", "rb");
  if(fp == NULL) {
    printf("Pointer null\n");
    exit(1);
  }
  user u1;

  gotoxy(2, 34);
  printf(" ACCOUNT LOGIN ");
  gotoxy(5, 7);
  printf("*******************************************************************************");

  gotoxy(10, 35);
  printf("==== LOG IN ====");

  gotoxy(12, 35);
  printf("USERNAME.. ");
  scanf("%s", &username);
  getchar();

  gotoxy(14, 35);
  printf("PASSWORD..");
  for (i = 0; i < 50; i++) {
    ch = getchar();
    if (ch == '\n' || ch == '\r') {
      break;
    }
    password[i] = ch;
  }
  password[i] = '\0';
  
  int login_success = 0;  // Variabile per indicare se il login è riuscito
  while (fread(&u1, sizeof(u1), 1, fp)) {
    if (strcmp(username, u1.fName) == 0 && strcmp(password, u1.passWord) == 0) {
      accountFunctions(username);
      login_success = 1;
      break;
    }
  }

  if (!login_success) {
    gotoxy(16, 28);
    printf("===Invalid username or password===");
    gotoxy(18, 35);
    printf("1....TRY AGINE");
    gotoxy(20, 35);
    printf("2....RETRUN TO HOME");
    gotoxy(22, 35); 
    printf("ENTER....");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        login();
        break;
      case 2:
        home();
    }
  }
}

void accountFunctions(char* usrNam){
  system("clear");

  int choice;

  gotoxy(5, 20);
  printf(" HOME ");

  gotoxy(7, 20);
  printf("******");

  gotoxy(9, 20);
  printf(" 1....CHECK BALANCE");

  gotoxy(11, 20);
  printf(" 2....TRANSFER MONEY");

  gotoxy(13, 20);
  printf(" 3....LOG OUT");

  gotoxy(15, 20);
  printf(" 4....SHOW USER ID");

  gotoxy(17, 20);
  printf(" 5....EXIT");

  gotoxy(19, 20);
  printf(" ENTER YOUR CHOICES..");
  scanf("%d", &choice);
  
  switch(choice) {
    case 1:
      checkBalance(usrNam);
      break;
    case 2:
      transferMoney(usrNam);
      break;
    case 3:
      logout();
      home();
      break;
    case 4:
      showId(usrNam);
      break;
    case 5:
      exit(0);
      break;
  }
}

void showId(char *usrNam) {
  system("clear");
  char ch;
  FILE *fp = NULL;
  fp = fopen("username.dat", "rb");
  if(fp == NULL) {
    printf("error in the pointer\n");
    exit(1);
  }
  user u1;

  while(fread(&u1, sizeof(u1), 1, fp)) {
    if(strcmp(usrNam, u1.fName) == 0) {
      gotoxy(5, 20);
      printf("==== YOUR ACCOUNT INFO ====");
      gotoxy(7, 20);
      printf("***************************");
      gotoxy(9, 20);
      printf("NAME.........%s\n", u1.fName);
      gotoxy(10, 20);
      printf("LASR NAME....%s\n\n\n", u1.lName);

      gotoxy(12, 20);
      printf("birthday.....%d-%d-%d\n", u1.date, u1.month, u1.year);

      gotoxy(14, 20);
      printf("idCard.......%s", u1.idCard);
      gotoxy(15, 20);
      printf("Phon Number..%s", u1.phonNum);
      gotoxy(16, 20);
      printf("address......%s", u1.address);
    }
  } 
  fclose(fp);

  gotoxy(18, 20);
  printf("INSERT ENTER FOR CONTINUE");
  getchar();
  while ((ch = getchar()) != EOF) {
    if (ch == '\n') {
      break;
    }
  }
  accountFunctions(usrNam);
}

void logout(void) {
  printf("please wait, logging out");
  fflush(stdout); // Assicurati che il messaggio venga stampato immediatamente

  for (int i = 0; i < 10; i++) {
    usleep(50000); // Pausa
    printf(".");
    fflush(stdout); // Assicurati che ogni punto venga stampato immediatamente
  }

  system("clear"); // Pulisce lo schermo alla fine
}

void transferMoney(char *usrNam) {
  system("clear");
  int foundFrom = 0, foundTo = 0;
  long posFrom = -1, posTo = -1;
  char nobody[8] = "nobody";
  char ch;
  int i, j;
  user u1;
  transaction tr1;

  FILE *ftrack = NULL, *fp = NULL; 
  fp = fopen("username.dat", "rb+");
  ftrack = fopen("moneyTrack.txt", "a+");
  if(fp == NULL && ftrack == NULL) {
    printf("error in fp or ftrack pointer\n");
    exit(0);
  }
  char userTo[24];

  gotoxy(4, 33);
  printf("---- TRANSFER MONEY ----");
  gotoxy(5, 33);
  printf("========================");

  gotoxy(13, 15);
  printf(" TO (username of person, if you want to exit enter nobody)....");
  scanf("%s", &userTo);

  if(strcmp(userTo, nobody) == 0) {
    accountFunctions(usrNam);
  }

  gotoxy(16, 33);
  printf("ENTER THE AMOUNT OF MOENY TO TRANSFER....");
  scanf("%d", &tr1.amountMoney);
  getchar();
 
  strncpy(tr1.userNameTo, userTo, sizeof(tr1.userNameTo) - 1);
  tr1.userNameTo[sizeof(tr1.userNameTo) - 1] = '\0';
  strncpy(tr1.userNameFrom, usrNam, sizeof(tr1.userNameFrom) - 1);
  tr1.userNameFrom[sizeof(tr1.userNameFrom) - 1] = '\0';

  gotoxy(18, 33);
  printf("%s inviated %d moeny to %s", tr1.userNameFrom, tr1.amountMoney, tr1.userNameTo);
  fprintf(ftrack, "   User  -%s\n   sent  -%d\nTo user  -%s\n\n", tr1.userNameFrom, tr1.amountMoney, tr1.userNameTo);
//--------------------------------------------->>
  while (fread(&u1, sizeof(user), 1, fp)) {
    if (strcmp(u1.fName, tr1.userNameFrom) == 0) {
      u1.money -= tr1.amountMoney;
      foundFrom = 1;
      posFrom = ftell(fp) - sizeof(user); // Memorizza la posizione del mittente
    }
    if (strcmp(u1.fName, tr1.userNameTo) == 0) {
      u1.money += tr1.amountMoney;
      foundTo = 1;
      posTo = ftell(fp) - sizeof(user); // Memorizza la posizione del destinatario
    }
    if (foundFrom && foundTo) {
      break;
    }
  }

  // Aggiorna il mittente nel file
  if (foundFrom) {
    fseek(fp, posFrom, SEEK_SET);
    fread(&u1, sizeof(user), 1, fp); // Leggi di nuovo per assicurarti di non sovrascrivere nulla per errore
    u1.money -= tr1.amountMoney;
    fseek(fp, posFrom, SEEK_SET);
    fwrite(&u1, sizeof(user), 1, fp);
    fflush(fp);
  } else {
    printf("Sender user %s not found\n", tr1.userNameFrom);
  }

  // Aggiorna il destinatario nel file
  if (foundTo) {
    fseek(fp, posTo, SEEK_SET);
    fread(&u1, sizeof(user), 1, fp); // Leggi di nuovo per assicurarti di non sovrascrivere nulla per errore
    u1.money += tr1.amountMoney;
    fseek(fp, posTo, SEEK_SET);
    fwrite(&u1, sizeof(user), 1, fp);
    fflush(fp);
  } else {
    printf("Recipient user %s not found\n", tr1.userNameTo);
  }

  fclose(fp);
  fclose(ftrack);


  gotoxy(20, 33);
  printf("AMOUNT SUCCESSFULLY TRANSFERRED....");
  gotoxy(22, 33);
  printf("INSERT ENTER FOR CONTINUE");
  while((ch = getchar()) != EOF) {
    if (ch == '\n') {
      break;
    }
  }

  accountFunctions(usrNam);
}

void checkBalance(char *usrNam) {
  char ch;
  FILE *fp = fopen("username.dat", "rb");
  if (fp == NULL) {
    printf("error in the pointer");
    exit(1);
  }
  user u1;
  int found = 0;

  system("clear");
  gotoxy(30, 33);
  while (fread(&u1, sizeof(u1), 1, fp)) {
    if (strcmp(u1.fName, usrNam) == 0) {
      getchar();
      printf("=====THE USER %s HAS %d$=====", usrNam, u1.money);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("User %s not found\n", usrNam);
  }

  gotoxy(32, 33);
  printf("     INSERT ENTER FOR CONTINUE");
  while ((ch = getchar()) != EOF) {
    if (ch == '\n') {
      break;
    }
  }
  fclose(fp);

  if (found) {
    accountFunctions(usrNam);
  }
}
