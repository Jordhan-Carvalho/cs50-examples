// Prints string char by char, one per line, using strlen, remembering string's length

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  string s = get_string("Input: ");
  printf("Output: ");
  // this could be used to have the same effect o n =strlen(s) inline, because it would not be calling the function every lopp
  // int n = strlen(s);
  for (int i = 0, n = strlen(s); i < n; i++)
  {
    printf("%c", s[i]);
  }
  printf("\n");
}