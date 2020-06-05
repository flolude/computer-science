#include <stdio.h>

int odd_ones(unsigned x)
{
  for (int i = 16; i >= 1; i /= 2)
  {
    int shifted = x >> i;
    x = x ^ shifted;
  }
  return x << 31 >> 31;
}

/*

Vergleichen der ersten 16 Bits mit letzten 16 Bits (XOR)

i:2
0111 (shifted: 0001)
0001
---- XOR
0110

i:1
0110 (shifted: 0011)
0011
---- XOR
0101

*/

int main(void)
{
  printf("odd_ones(0b0001): %d\n\n", odd_ones(0b0001));
  printf("odd_ones(0b0011): %d\n\n", odd_ones(0b0011));
  printf("odd_ones(0b0111): %d\n\n", odd_ones(0b0111));
  printf("odd_ones(0b1111): %d\n\n", odd_ones(0b1111));
  printf("\nodd_ones(42): %d\n\n", odd_ones(41));

  return 0;
}