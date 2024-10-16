#include <stdio.h>

long long factorial(long long n) {
  long long result = 1;
  for(long long i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

long long factorial_division(long long n, long long d) {
  long long i = factorial(n);
  long long j = factorial(d);
  long long result = i/j;
  return result;
}

int main() {
  printf("%lld\n", factorial_division(9741ll, 9737ll)); 
  return 0;
}
