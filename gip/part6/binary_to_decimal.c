#include <math.h>
#include <stdio.h>

int binaryToDecimal(long int binary)
{
  int decimal = 0, exponent = 0;
  while (binary > 0)
  {
    decimal += binary % 10 == 1 ? pow(2, exponent) : 0;
    binary /= 10;
    exponent++;
  }
  return decimal;
}

long int decimalToBinary(int decimal)
{
  long int binary = 0, i = 0;
  while (decimal > 0)
  {
    int remainder = decimal % 2;
    binary += remainder == 1 ? pow(10, i) : 0;
    decimal /= 2;
    i++;
  }
  return binary;
}

int main()
{
  long int binary = 1000011101010011;
  printf("%ld as decimal is: %d\n", binary, binaryToDecimal(binary));
  int decimal = 34643;
  printf("%d as binary is: %ld\n", decimal, decimalToBinary(decimal));
  return 0;
}
