#include <stdio.h>

void pointersArray(void);
void arrayInArray(void);

//--------
int main()
{
  pointersArray();
  return 0;
}

//--------
void arrayInArray(void)
{

  int n1[4] = {0, 1, 2, 3};
  int n2[4] = {0, 1, 3, 2};
  int n3[4] = {3, 2, 1, 0};

  int *nn[3] = {n1, n2, n3};
  printf("%d\n", n1[n3[1]]);
}
//--------
void pointersArray(void)
{

  int a = 0, b = 5, c = 2, d = 3;
  int *p1, *p2, *p3, *p4;

  printf("p1:%d, p2:%d\n", p1, p2);

  p1 = &a;
  p2 = &b;
  p3 = &c;
  p4 = &d;


  p2 = &p1 + 1;
  p3 = &p2 + 1;
  p4 = &p3 + 1;

  
  printf("p1:%d, p2:%d, p3:%d, p4:%d\n", p1, p2, p3, p4);
  printf("p1:%d, p2:%d, p3:%d, p4:%d\n", *p1, *(p1+1), (*p1+2), (*p1+3));
}


