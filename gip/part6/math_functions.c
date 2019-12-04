#include <math.h>
#include <stdio.h>

double f1(double x, double y)
{
  if (x == y)
    printf("Teilen durch 0 ist nicht erlaubt!\n");
  return (x + y) / (x - y);
}

double f2(double x, double y)
{
  return sqrt((x * x) + (y * y));
}

int main()
{
  double x = 22, y = 42;
  printf("f1(%lf, %lf) = %lf\n", x, y, f1(x, y));
  printf("f2(%lf, %lf) = %lf\n", x, y, f2(x, y));
  return 0;
}