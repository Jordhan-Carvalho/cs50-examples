#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int countLetters(int length, string text);
int countWords(int length, string text);
int countSentences(int length, string text);
float findAvg100Word(int value, int numberWords);

int main(void)
{
  string text = get_string("Text: ");
  int textLength = strlen(text);
  printf("%s\n", text);

  int totalLetters = countLetters(textLength, text);
  int totalWords = countWords(textLength, text);
  int totalSentences = countSentences(textLength, text);

  // Find the average of lettters and setences per 100 words
  float L = findAvg100Word(totalLetters, totalWords);
  float S = findAvg100Word(totalSentences, totalWords);

  // Calculate Coleman-Liau index
  float index = 0.0588 * L - 0.296 * S - 15.8;

  //round to the nearest number
  if (index < 1)
  {
    printf("Before Grade 1\n");
  }
  else if (index > 16)
  {
    printf("Grade 16+\n");
  }
  else
  {
    printf("Grade %i\n", (int)round(index));
  }
}

int countLetters(int length, string text)
{
  int totalLetters = 0;
  for (int i = 0; i < length; i++)
  {
    if (isalpha(text[i]))
    {
      totalLetters++;
    }
  }
  return totalLetters;
}

int countWords(int length, string text)
{
  int totalWords = 0;
  for (int i = 0; i < length; i++)
  {
    if (isspace(text[i]))
    {
      totalWords++;
    }
  }
  return totalWords + 1;
}

int countSentences(int length, string text)
{
  int totalSentences = 0;
  for (int i = 0; i < length; i++)
  {
    if (text[i] == '.' || text[i] == '!' || text[i] == '?')
    {
      totalSentences++;
    }
  }
  return totalSentences;
}

float findAvg100Word(int value, int numberWords)
{
  return value * 100 / (float)numberWords;
}