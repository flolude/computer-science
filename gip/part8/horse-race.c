#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <limits.h>

void horseRace(int n) {
  int *horses = malloc(n * sizeof(int));
  int round = 1, first = 0, second = 0, third = 0;

  while(1) {
    int random = rand() % n;
    horses[random]++;

    if (random != first && random != second && random != third && horses[random] > horses[third]) {
      third = random;
    }
    if (horses[third] > horses[second]) {
      int oldSecond = second;
      second = third;
      third = oldSecond;
    }
    if (horses[second] > horses[first]) {
      int oldFirst = first;
      first = second;
      second = oldFirst;
    }

    printf("\nRunde %d:\n", round);
    printf("Platz 1: Pferd %d (%dm)\n", first + 1, horses[first]);
    printf("Platz 2: Pferd %d (%dm)\n", second + 1, horses[second]);
    printf("Platz 3: Pferd %d (%dm)\n", third + 1, horses[third]);

    if (horses[random] >= 10)
      break;

    round++;
  }
}

int main(void) {
  srand(time(NULL));
  horseRace(100);
  return 0;
}