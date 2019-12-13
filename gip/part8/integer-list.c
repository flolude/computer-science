#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void readIntArray(int a[], int l) {
  for (int i = 0; i < l; i++) {
    scanf("%d", &a[i]);
  }
}

void printIntArray(int a[], int l) {
  printf("(");
  for (int i = 0; i < l; i++) {
    printf(" %d ", a[i]);
  }
  printf(")");
}

int main(void) {
  int number_of_integers = 0;
  printf("Wie viele ganze Zahlen willst du eingeben?\n");
  scanf("%d", &number_of_integers);
  int *a = malloc(number_of_integers * sizeof(int));
  printf("Gebe nun die Zahlen ein\n");
  readIntArray(a, number_of_integers);
  printf("Du hast folgende Zahlen eingeben:\n");
  printIntArray(a, number_of_integers);

  int max = INT_MIN, min = INT_MAX;
  double average = 0;
  for (int i = 0; i < number_of_integers; i++) {
    if (a[i] > max)
      max = a[i];
    if (a[i] < min)
      min = a[i];
    average += (double)a[i] / number_of_integers;
  }

  printf("\nMaximum: %d\n", max);
  printf("Maximum: %d\n", min);
  printf("Mittelwert: %f\n", average);

  return 0;
}