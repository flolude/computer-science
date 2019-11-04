#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x1, y1, z1,
      x2, y2, z2;

  printf("Koordinaten musst du wiefolgt formatieren: x y z\n");
  printf("Gebe die Koordinaten für den ersten Punkt ein: ");
  scanf("%d %d %d", &x1, &y1, &z1);
  printf("Gebe die Koordinaten für den zweiten Punkt ein: ");
  scanf("%d %d %d", &x2, &y2, &z2);

  float xLength = abs(x1 - x2),
        yLength = abs(y1 - y2),
        zLength = abs(z1 - z2),
        volume = xLength * yLength * zLength,
        surfaceArea = 2 * (yLength * zLength + yLength * xLength + xLength * zLength),
        edgeLength = 4 * (xLength + yLength + zLength);

  printf("\nVolumen: %.2f\n", volume);
  printf("Oberflächeninhalt: %.2f\n", surfaceArea);
  printf("Kantenlängen: %.2f\n", edgeLength);

  return 0;
}