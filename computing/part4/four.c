#include <stdio.h>

unsigned short compare(unsigned short x, unsigned short mask)
{
  return (x & mask) == mask;
}

int rows(unsigned short x)
{
  int top_row = 0b0000000111000000;
  int mid_row = 0b0000000000111000;
  int bottom_row = 0b0000000000000111;

  return (compare(x, top_row) || compare(x, mid_row) || compare(x, bottom_row));
}

int columns(unsigned short x)
{
  int left_col = 0b0000000001001001;
  int mid_col = 0b0000000010010010;
  int righ_col = 0b0000000100100100;

  return (compare(x, left_col) || compare(x, mid_col) || compare(x, righ_col));
}

int diagonals(unsigned short x)
{
  int bottom_left_to_top_right = 0b0000000100010001;
  int bottom_right_to_top_left = 0b0000000100010100;

  return (compare(x, bottom_left_to_top_right) || compare(x, bottom_right_to_top_left));
}

unsigned short winner_result(unsigned short x)
{
  int one_is_winner = (columns(x) || diagonals(x) || rows(x));
  int zero_is_winner = (columns(~x) || diagonals(~x) || rows(~x));
  if (one_is_winner && zero_is_winner)
    return (x & 0b0111111111111111);
  if (one_is_winner || zero_is_winner)
    return (x | 0b1000000000000000);
  return (x & 0b0111111111111111);
}

int main(void)
{
  bin16(~32768);
  int input = 0b0101010101111010;
  printf("input:  ");
  bin16(input);

  int result = winner_result(input);
  printf("\nResult:");
  bin16(result);
}