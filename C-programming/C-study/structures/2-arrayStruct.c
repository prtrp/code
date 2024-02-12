#include <stdio.h>
int first_look(void)
{

  struct students 
  {
    int indent;
    char name[20];
    float marks;
  };

 
  struct students s[3]; // so we can store 3 students
  
  s[0].indent; // --> for call the student data
/*
  1 -
  s -> |1000|2000|300| -> array that contain the memory of the array tha contain the value
  s is a internal pointer
  
  2-
  they are pointers too
  1000 --> |indent value|char value| float value| -> name[0] array of pointers
  1000 --> |indent value|char value| float value| -> name[1] array of pointers
  3000 --> |indent value|char value| float value| -> name[2] array of pointers
*/

  for(int i = 0; i < 3; i++)
  {
    printf("\ninster the data of the students [%d]: \n", i + 1);
    scanf("%d%s%f", &s[i].indent, s[i].name, &s[i].marks);
  }

  for(int i = 0; i < 3; i++)
    printf("\nStudent %d: indent = %d, name = %s, marks = %.2f\n",i + 1, s[i].indent, s[i].name, s[i].marks);

    return 0;
}

int exe()
{
  struct garage
  {
    int model;
    char identifier[9];
    float marks;
  };

  struct garage car[3];
  
  for(int i = 0; i < 3; i++)
  {
    printf("insert the data of the car n[%d]:\n", i + 1);
    scanf("%d%s%f", &car[i].model, car[i].identifier, &car[i].marks);
  }

  for(int i = 0; i < 3; i++)
    printf("\ncar %d: model = %d, identifier = %s, marks = %.2f\n",i + 1, car[i].model, car[i].identifier, car[i].marks);

}    

int main()
{
  exe();
}
