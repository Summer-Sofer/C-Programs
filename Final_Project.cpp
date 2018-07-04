#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// count words in a file
int countWords(const char * pfile);

// number of characters in a text file
int countChar(const char * pfile);

int main()
{
  const char str[] = "Here is a sentence I wrote.";
  int numWords = countWords(str);
  return 0;
}

int countWords(const char * pfile)
{
  int wordCount = 0;
  int length = 0;

  if (pfile == NULL)
    return 1;

  while (*pfile)
  {
    if (*pfile == ' ')
      length = 0;
    else if (++length == 1)
      wordCount++;

    pfile++;
  }
  cout << "The amount of words in your string is: " << wordCount;
  return wordCount;
}

int countChar(const char * pfile)
{
  char ch;
}

// all 3 in one
int triplePower(const char * pfile)
{
  ifstream indata;
  char ch;
  int lines = 0, words = 0, chr = 0;

  indata.open("filename.txt");

  while(indata)
  {
    if( ch == '\n')
      lines++;
    else if (ch == ' ')
      words++;
    else
      chr++;
  }
}
