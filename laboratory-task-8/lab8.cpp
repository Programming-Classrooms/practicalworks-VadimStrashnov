/*  Словом, входящим в состав строки, назовём непрерывную
    последовательность символов, ограниченную символами–разделителями, началом и концом строки. 
    Символы, относящиеся к разделителям, определяет пользователь, если иное не сказано в условии задачи.
    Если решить задачу невозможно, программа должна выдать соответствующее сообщение.

    Словом в строке считается последовательность букв латинского
    алфавита, остальные символы рассматриваются как разделители между словами.
    Слова в каждой из двух исходных строк упорядочены по алфавиту.
    Необходимо сформировать новую строку из всех слов исходных строк. 
    Слова в новой строке должны быть также упорядочены по алфавиту. 
    Прописные и строчные буквы в словах не различать. 
    Слова в новой строке должны разделяться ровно одним пробелом.
*/


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>


void inputString(std::string& string)
{
  getline(std::cin,string);
}


void checkIsEmptyString(const std::string string)
{
  if (string.length() == 0) {
    throw std::exception(" Nothing in string!\n");
  }
}


void turnDelimetersIntoSpace(std::string string)
{
  for (size_t i = 0; i < string.length(); ++i) {
    if (isalpha(string[i]) == false) {
      string[i] =  ' ';
    }
  }
}


void checkForWords(const std::string string)
{
  size_t counter = 0;

  for (size_t i = 0; i < string.length(); ++i) {
    if (isalpha(string[i]))
    {
      ++counter;
    }
  }

  if (counter < 1)
  {
    throw std::exception(" No words in string!\n");
  }
}


bool caseInsensitiveCompare(const std::string firstString, const std::string secondString)
{
  size_t length = std::min(firstString.length(), secondString.length());

  for (size_t i = 0; i < length; ++i) {
    char symbol1 = std::tolower(firstString[i]);
    char symbol2 = std::tolower(secondString[i]);
    if (symbol1 != symbol2) {
      return symbol1 < symbol2;
    }
  }

  return firstString.length() < secondString.length();
}


void sortWords(std::vector<std::string>& manyOfWords)
{
  for (size_t i = 0; i < manyOfWords.size(); ++i) {
    for (size_t j = i + 1; j < manyOfWords.size(); ++j) {
      if (caseInsensitiveCompare(manyOfWords[j], manyOfWords[i])) {
        std::swap(manyOfWords[i], manyOfWords[j]);
      }
    }
  }
}


void sortStringAlphabetically(const std::string firstString, const  std::string secondString, std::vector<std::string>& manyOfWords)
{
  size_t prev = 0;
  size_t pos = 0;

  while ((pos = firstString.find_first_of(" ", prev)) != std::string::npos)
  {
    if (pos > prev)
      manyOfWords.push_back(firstString.substr(prev, pos - prev));
    prev = pos + 1;
  }

  if (prev < firstString.length()) {
    manyOfWords.push_back(firstString.substr(prev, std::string::npos));
  }

  prev = 0;
  pos = 0;

  while ((pos = secondString.find_first_of(" ", prev)) != std::string::npos){
    if (pos > prev)
      manyOfWords.push_back(secondString.substr(prev, pos - prev));
    prev = pos + 1;
  }

  if (prev < secondString.length()) {
    manyOfWords.push_back(secondString.substr(prev, std::string::npos));
  }
  sortWords(manyOfWords);
}


void outputFinalString(std::vector<std::string>& manyOfWords)
{
  for (size_t i = 0; i < manyOfWords.size(); ++i) {
    std::cout << manyOfWords[i] << " ";
  }
}


int main()
{
  try{
    std::string firstString;
    std::string secondString;

    std::cout << " Write first string:\n";
    inputString(firstString);
    checkIsEmptyString(firstString);
    checkForWords(firstString);
    turnDelimetersIntoSpace(firstString);

    std::cout << " Write second string:\n";
    inputString(secondString);
    checkIsEmptyString(secondString);
    checkForWords(secondString);
    turnDelimetersIntoSpace(secondString);

    std::vector<std::string> manyOfWords;
    sortStringAlphabetically(firstString, secondString, manyOfWords);

    std::cout << " Your result:\n";
    outputFinalString(manyOfWords);
  }
  catch (const std::exception e){
    std::cout << e.what();
  }

  return 0;
}
