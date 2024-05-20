#include <stdio.h>

void employersCount(void);
void pointerStruct(void);

struct student
{
  char name[40];
  int id;
  float marks;
} s = {"giorgio", 18, 342.23};

int main()
{  
  pointerStruct();

}
//-------
void employersCount(void)
{
  struct student employers[3];
  printf("isert name, id, marks\n");

  for(int i = 0; i < 3; i ++)
    scanf("%s%d%f", employers[i].name, &employers[i].id, &employers[i].marks);

  for(int i = 0; i < 3; i++)
    printf("the name is: %s, the id is:%d, the mark is; %f\n", employers[i].name, employers[i].id, employers[i].marks);
}

//-------
 void pointerStruct(void)
{
  struct student *ptr = &s;
  printf("the name is %s\n", ptr -> name);
}

//-------
void typedf(void)
{
  typedef struct painters
  {
    char name[20];
    int price;
    char id[7];
  } painers;

  painers p1 = {"the moon on baloon", 45000, "ee4re4"};
}


