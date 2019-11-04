#include <stdio.h>

int main()
{
  int fahrenheit, celsius;

  printf("Geben Sie eine ganze, positive Zahl ein: ");
  scanf("%d", &fahrenheit);

  celsius = (fahrenheit - 32) * 5 / 9;
  printf("%d Grad Fahrenheit sind %d Grad Celsius", fahrenheit, celsius);
  return 0;
}