// 12 Пример на фото


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>


void inputString(char*& str)
{
  std::cin.getline(str, 300);
}


void sortString(char*& str)
{
  for (size_t i = 0; i < strlen(str); ++i) {
    if (isalnum(str[i]) == false) {
      str[i] = ' ';
    }
  }
}


void createBigString(char* str1, char* str2, char*& finalstr, char* delims)
{
  char* saveptr1;
  char* saveptr2;
  char* pch1 = strtok_s(str1, delims, &str1);
  char* pch2 = strtok_s(str2, delims, &str2);
  finalstr = strcpy(finalstr, pch1);
  finalstr = strcat(finalstr, " ");
  pch1 = strtok_s(NULL, delims, &str1);
  while (pch1 != NULL || pch2 != NULL) {

    if (pch2 != NULL) {
      finalstr = strcat(finalstr, pch2);
      finalstr = strcat(finalstr, " ");
      pch2 = strtok_s(NULL, delims, &str2);
    }
    if (pch1 != NULL) {
      finalstr = strcat(finalstr, pch1);
      finalstr = strcat(finalstr, " ");
      pch1 = strtok_s(NULL, delims, &str1);
    }
  }
}


int main()
{
  try {
    char* str1 = new char[300];
    char* str2 = new char[300];
    char* finalstr = new char[600];
    char* delims = new char[300];

    std::cout << " Write the first string:\n";
    inputString(str1);
    std::cout << " Write the second string:\n";
    inputString(str2);
    std::cout << " Write delimeters:\n";
    inputString(delims);
    sortString(str1);
    sortString(str2);
    createBigString(str1, str2, finalstr, delims);
    std::cout << " Your final string: " << finalstr;
  }
  catch (const char* msg) {
    std::cout << msg;
  }
  return 0;
}
