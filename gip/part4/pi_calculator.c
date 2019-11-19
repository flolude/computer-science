#include <stdio.h>
#include <math.h>

int main()
{
  double accuracy;
  printf("Genauigkeit eingeben: ");
  scanf("%lf", &accuracy);

  double pi = 0;
  int n = 0;
  double sum = 0;

  while (1)
  {
    double numerator = n % 2 == 0 ? 1 : -1;
    double denominator = 2 * n + 1;
    double summand = numerator / denominator;

    double new_sum = sum + summand;

    if (fabs((sum * 4) - (new_sum * 4)) < accuracy)
      break;

    sum = new_sum;
    n++;
  }
  pi = sum * 4;

  printf("Pi nach %d Iterationen: %f\n", n, pi);
  printf("Abweichung: %f\n", fabs(pi - M_PI));

  return 0;
}