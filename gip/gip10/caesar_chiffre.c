#include<stdio.h>
#include <string.h>
#include<stdlib.h>

char* encipher(char string[], int key) {
  int length = strlen(string);
  char *encoded = (char *) malloc(sizeof(char) * length);
  for (int i = 0; i < strlen(string); i++) {
    if (string[i] == ' ') encoded[i] = ' ';
    else encoded[i] = string[i] + key;
  }
  return encoded;
}

char* decipher(char string[], int key) {
  int length = strlen(string);
  char *decoded = (char *) malloc(sizeof(char) * length);
  for (int i = 0; i < strlen(string); i++) {
    if (string[i] == ' ') decoded[i] = ' ';
    else decoded[i] = string[i] - key;
  }
  return decoded;
}

int main(void) {
  char text[] = "YLHOH NDPHQ DOOPDHKOLFK CX GHU XHEHUCHXJXQJ HLQHQ JURVVHQ IHKOHU JHPDFKW CX KDEHQ DOV VLH YRQ GHQ EDHXPHQ KHUXQWHUJHNRPPHQ ZDUHQ XQG HLQLJH VDJWHQ VFKRQ GLH EDHXPH VHLHQ HLQ KROCZHJ JHZHVHQ GLH RCHDQH KDHWWH PDQ QLHPDOV YHUODVVHQ GXHUIHQ";
  char* decoded = decipher(text, 3);
  printf("Klartext: %s\n", decoded);
  printf("Verschluesselt: %s\n", encipher(decoded, 3));
  return 1;
}