#include <stdio.h>

int count_bits(unsigned int x)
{
  unsigned int i = 0;
  while (x)
  {
    i = i + (x & 1);
    x = x >> 1;
  }
  return i;
}

int main(void)
{
  unsigned int x, y;
  printf("Enter x: ");
  scanf("%d", &x);
  printf("Enter y: ");
  scanf("%d", &y);

  // XOR = (x AND !y) OR (!x AND y)
  unsigned int result = (unsigned int)(x & ~y) | (~x & y);
  printf("Result: %d\n", result);
  printf("Number of bits: %d\n", count_bits(result));
  return result;
}