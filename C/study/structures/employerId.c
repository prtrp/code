#include <stdio.h>

typedef struct employer{
  int id;
  char name[20];
  float salary;
} employer;

int main(void) {
  employer person[3];
  for(int i = 0; i < 3; i++) {
    printf("insert the variable of penrson[%d]\n", i);
    scanf("%d%s%f", &person[i].id, &person[i].name, &person[i].salary);
  }

  for(int i = 0; i < 3; i++) {
    printf("person[%d]: id = %d, name = %s, salary = %f\n", i,  person[i].id, person[i].name, person[i].salary);
  }
}

