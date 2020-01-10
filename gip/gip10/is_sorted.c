#include<stdio.h>

int is_sorted(int num) {
  int last_digit;
  int penultimate_digit;
  while(1) {
    last_digit = num % 10;
    num /= 10;
    penultimate_digit = num % 10;
    if (num == 0) break;
    if (last_digit > penultimate_digit) return 0;
  }
  return 1;
}

int main(void) {
  int num;
  printf("Zahl eingeben: ");
  scanf("%d", &num);
  int sorted = is_sorted(num);
  if (sorted)
    printf("%d ist von links nach rechts absteigend sortiert\n", num);
  else
    printf("%d ist nicht von links nach rechts absteigend sortiert\n", num);
  return 0;
}