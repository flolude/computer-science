#include <stdio.h>
#include <math.h>

int is_prime_number(int number)
{
  if (number == 2)
    return 1;
  if (number % 2 == 0 || number % 5 == 0)
    return 0;
  int biggest_possible_divider = floor(sqrt(number));
  for (int i = 2; i <= biggest_possible_divider; i++)
  {
    if (number % i == 0)
      return 0;
  }
  return 1;
}

int smallest_prime_divider(int number)
{
  int i = 2;
  while (i < number)
  {
    if (is_prime_number(i) && number % i == 0)
      return i;
    i++;
  }
  return number;
}

int main(void)
{
  int input;
  printf("Bitte gib eine Zahl ein: ");
  scanf("%d", &input);

  int factors[100];

  int iteration = 0;
  while (input > 1)
  {
    int divider = smallest_prime_divider(input);
    factors[iteration] = divider;
    input /= divider;
    iteration++;
  }

  for (int i = 0; i < iteration; i++)
  {
    if (i == iteration - 1)
      printf("%d\n", factors[i]);
    else
      printf("%d * ", factors[i]);
  }
  return 0;
}