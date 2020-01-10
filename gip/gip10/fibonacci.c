#include<stdio.h>

int fibonacci(int n ) {
  int fibonacci_number = 1;
  int penultimate = 0;
  int previous = 1;
  for (int i = 1; i <= n; i++) {
    fibonacci_number = penultimate + previous;
    penultimate = previous;
    previous = fibonacci_number;
  }
  return fibonacci_number;
}

int main(void) {
  int n;
  printf("Zahl eingeben: ");
  scanf("%d", &n);
  printf("\nFibonacci number of %d is %d\n", n, fibonacci(n));
  return 0;
}