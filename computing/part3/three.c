#include <stdio.h>

void bin(unsigned n)
{
  /* step 1 */
  if (n > 1)
    bin(n / 2);

  /* step 2 */
  printf("%d", n % 2);
}

int bis(int x, int m)
{
  /**
   * x  m  result
   * 0  1  1
   * 1  1  1
   * 0  0  0
   * 1  0  1
   * 
   * => OR
   */
  return x | m;
}

int bic(int x, int m)
{
  /**
   * x  m  result
   * 0  1  0
   * 1  1  0
   * 0  0  0
   * 1  0  1
   * 
   * => x AND !m
   */
  return x & ~m;
}

int bool_or(int x, int y)
{
  return bis(x, y);
}

int bool_xor(int x, int y)
{
  /**
   * x  m  result
   * 0  1  1
   * 1  1  0
   * 0  0  0
   * 1  0  1
   * 
   * => XOR
   * 
   * available:
   * - x OR m
   * - x AND !m
   * 
   * XOR = (x AND !y) OR (!x AND y)
   */
  return bis(bic(x, y), bic(y, x));
}

int main(void)
{
  int x = 0b001101;
  int y = 0b101010;

  int bis_result = bis(x, y);
  printf("bis: ");
  bin(bis_result); // 101111
  printf("\n");

  int bic_result = bic(x, y);
  printf("bic: 000");
  bin(bic_result); // 000101
  printf("\n");

  int bool_or_result = bool_or(x, y);
  printf("bor: "); // 101111
  bin(bool_or_result);
  printf("\n");

  int bool_xor_result = bool_xor(x, y);
  printf("xor: "); // 100111
  bin(bool_xor_result);
  printf("\n");
  return 0;
}