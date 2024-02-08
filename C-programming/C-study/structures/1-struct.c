#include <stdio.h>
#include <string.h>
// is like arrays because you can store multiple data, but different data
// int students = [60]; --> can store only one type of datatype

int main()
{
  struct student
  {
    int num;
    char name[60];
    float marks;
  }s1, s2; // --> we can also do this | you can initialize there too
           // }s1 = {1, "ciao", 59.2};
           // for ever istance will be allocated memory separatly

  // now we have just created our own datatype
  // worring:
  // 1- the name have not to be the same
  // 2- we have to put the semicolon
  // 3- it do not take space in memory, is only a template.
  
  struct student s3; // now memory is allocated; the memory space is the
                     // sum of datatype inside the structure; 4 + 60 + 4

  // how to initialize & access of structures

  struct student s = {1, "se tu dall'alto piano guardi il mare", 19.39};
  s3 = s; // it si true
  
  printf("%d\n", s.num); // name of istance + dot (member operator) + name of struct
  
  s1.num = 3;
  strcpy(s1.name, "petru");
  s1.marks = 90.1;
  printf("%s\n", s1.name);

}
