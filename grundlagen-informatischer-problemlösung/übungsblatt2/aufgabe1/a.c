#include <stdio.h>

int main(void)
{
  int n;
  printf("Geben Sie eine positive ganze Zahl ein: ");
  scanf("%d", &n);
  printf("Die Fakultät von %d ist: ", n);
  int f = 1;
  while (n > 0)
  {
    f = f * n;
    n = n - 1;
  }
  printf("%d\n", f);
  return 0;
}