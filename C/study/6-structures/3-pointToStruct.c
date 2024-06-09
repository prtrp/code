#include <stdio.h>

// is a pointer taht points to the address of the memory that sotre the structure


int main()
{
  typedef struct employer{
    char name[20];
    int id;
    float mark;
  } employer;

  employer emp1 = {"petru", 34553, 93.43};
  employer *ptr = &emp1;

  printf("the name is:%s, id is:%d, mark is:%d", ptr->name, ptr->id, ptr->mark);  
  // --> it means (*ptr).id [which means] s.id // for access better to the values
}

