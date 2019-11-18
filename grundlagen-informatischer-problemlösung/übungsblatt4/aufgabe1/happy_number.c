#include <stdio.h>

int is_unhappy_sum(int number)
{
  int unhappy_sums[8] = {20, 4, 16, 37, 58, 89, 145, 42};
  for (int i = 0; i < 8; i++)
  {
    if (unhappy_sums[i] == number)
    {
      return 1;
    }
  }
  return 0;
}

int is_happy_number(int number)
{
  int sum = 0;
  while (number > 0)
  {
    int digit = number % 10;
    sum += (digit * digit);
    if (is_unhappy_sum(sum))
    {
      return 0;
    }
    number /= 10;
  }
  return 1;
}

int main(void)
{
  for (int i = 1; i <= 500; i++)
  {
    if (is_happy_number(i))
    {
      printf("Happy: %d\n", i);
    }
  }
}