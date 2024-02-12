#include <stdio.h>

// is a pointer taht points to the address of the memory that sotre the structure

int main()
{
  struct student
  {
    int id;
    char name[20];
    float marks;
  };

  struct student s={1, "petru", 90};


  struct student *ptr = &s;

  printf("id = %d, name = %s, marks %s\n", ptr -> id, ptr -> name, ptr -> marks); // --> it means (*ptr).id [which means] s.id // for access better to the values

}
