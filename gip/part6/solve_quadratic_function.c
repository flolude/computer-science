#include <stdio.h>
#include <math.h>

int solve(int a, int b, int c, double *x1, double *x2)
{
  double inside_root = b * b - 4 * a * c;
  *x1 = (-b + sqrt(inside_root)) / (2 * a);
  *x2 = (-b - sqrt(inside_root)) / (2 * a);
  if (inside_root > 0)
    return 2;
  if (inside_root == 0)
    return 1;
  /*
   * if (inside_root < 0)
   * ist in dem Fall redundant
   */
  return 0;
}

int main()
{
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);
  double x1, x2;
  int anzahl = solve(a, b, c, &x1, &x2);
  if (!anzahl)
    printf("keine Lösung");
  else if (anzahl == 1)
    printf("eine Lösung x: %lf", x1);
  else if (anzahl > 1)
    printf("zwei Lösungen x1: %lf x2: %lf", x1, x2);
}