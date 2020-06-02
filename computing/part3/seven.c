#include <stdio.h>

unsigned rotate_left(unsigned x, int n)
{
  return (x << (4 * n)) | (x >> (sizeof(unsigned) - (4 * n)));
}

unsigned rotate_right(unsigned x, int n)
{
  return (x >> (4 * n)) | (x << (sizeof(unsigned) - (4 * n)));
}

int main(void)
{
  int x = 0x87654321;
  int n = 2;
  printf("input: 0x%x (shift %d)\n", x, n);
  printf("rotate_left: 0x%d\n", rotate_left(x, n));
  printf("rotate_right: 0x%d\n", rotate_right(x, n));
  return 0;
}