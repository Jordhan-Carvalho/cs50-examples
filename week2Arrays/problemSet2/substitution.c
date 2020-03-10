#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int checkKey(string key);

int main(int argc, string argv[])
{

  if (argc != 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }
  else
  {
    string key = argv[1];
    int stringLength = strlen(key);

    if (stringLength == 26)
    {
      // CHECK IF THE KEY HAS EXACLTY ONE KEY OF EACH
      if (checkKey(key) == 1)
      {
        return 1;
      }
      string plainText = get_string("plaintext: ");
      int plainTextLength = strlen(plainText);
      // loop
      for (int i = 0; i < plainTextLength; i++)
      {
        // check if plain text if alphanumeric if it is replace
        if (isalpha(plainText[i]))
        {
          // replace (check the letter ASCII code then reduce 65 if uppercase or 97 if lower case, thats the index in the key)
          if (islower(plainText[i]))
          {
            plainText[i] = tolower(key[plainText[i] - 97]);
          }
          else
          {
            plainText[i] = toupper(key[plainText[i] - 65]);
          }
        }
      }

      printf("ciphertext: %s\n", plainText);
      return 0;
    }
    else if (stringLength < 26 || stringLength > 26)
    {
      printf("Key must contain 26 characters.\n");
      return 1;
    }
  }
}

int checkKey(string key)
{
  int result = 0;
  // loop thru each letter and then compare with the array
  for (int i = 0; i < 26; i++)
  {
    //check is valid char
    if (!isalpha(key[i]))
    {
      result = 1;
    }
    int totalRep = 0;
    for (int j = 0; j < 26; j++)
    {
      // check if the letter if repeated
      if (tolower(key[i]) == tolower(key[j]))
      {
        totalRep++;
        if (totalRep >= 2)
        {
          result = 1;
        }
      }
    }
  }
  return result;
}