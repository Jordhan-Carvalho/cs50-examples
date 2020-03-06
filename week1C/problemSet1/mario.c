#include <cs50.h>
#include <stdio.h>

int get_only_int(void);
void build_pyramid(int height);

int main(void)
{
  int height = get_only_int();
  build_pyramid(height);
}

void build_hashes(int height, int i)
{
  for (int j = 0; j <= height; j++)
  {
    if (i > j)
    {
      printf("#");
    }
  }
}

void build_left_space(int height, int i)
{
  for (int j = 0; j <= height; j++)
  {
    if (i < j)
    {
      printf(" ");
    }
  }
}

void build_pyramid(int height)
{
  for (int i = 1; i <= height; i++)
  {
    //print spaces
    build_left_space(height, i);
    //build left pyramid
    build_hashes(height, i);
    //print gap
    printf("  ");
    //build right pyramid
    build_hashes(height, i);
    // end the row
    printf("\n");
  }
}

int get_only_int(void)
{
  int n;
  do
  {
    n = get_int("Height: ");
  } while (n < 1 || n > 8);
  return n;
}
