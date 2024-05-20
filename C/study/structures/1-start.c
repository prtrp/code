#include <stdio.h>

int main() {
  struct student{
    int id; // struct member
    char name[20];
    float marks;
  };

  struct student s1 = {2344, "Arianna", 82.3}; // struct variable
  printf("id: %d, name: %s, marks: %.1f\n", s1.id, s1.name, s1.marks);

  // pointer structure
  struct student s2 = {2334, "Petru", 78.4};
  struct student *ptr = &s2;

  printf("id: %d, name: %s, makrs: %.1f\n", ptr->id, ptr->name, ptr->marks);
  return 0;
}
