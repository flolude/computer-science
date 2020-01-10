#include<stdio.h>

int count_digit(int num, int digit) {
  int counter = 0;
  while(1) {
    int last_digit = num % 10;
    num /= 10;
    if (last_digit == digit) counter++;
    if (num == 0) break;
  }
  return counter;
}

int main(void) {
  int num, digit;
  printf("Zahl eingeben: ");
  scanf("%d", &num);
  printf("Ziffer eingeben: ");
  scanf("%d", &digit);
  int x = count_digit(num, digit);
  printf("Die Ziffer %d kommt %d mal in %d vor\n", digit, x, num);
  return 0;
}