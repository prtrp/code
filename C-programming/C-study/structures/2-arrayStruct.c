#include <stdio.h>

struct students 
{
  int indent;
  char name[20];
  float marks;
};

int main()
{
 
  struct students s[3]; // so we can store 3 students
  
  s[0].indent; // --> for call the student data
/*
  s -> |1000|2000|300| -> array that contain the memory of the array tha contain the value
  
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
