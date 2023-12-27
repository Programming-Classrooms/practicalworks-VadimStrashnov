//Пример 12 на фото


#include <iostream>
#include <string>
#include <fstream>


void checkFile(std::ifstream& fin)
{
  if (!fin.good()){
    throw std::exception("File does not exist.\n");
  }
  if (!fin){
    throw std::exception("File is not opened.\n");
  }
  if (fin.peek() == EOF){
    throw std::exception("File is empty.\n");
  }
}


void checkMaxWord(const std::string word, const std::string::size_type begInd, std::string& maxWord, size_t& maxWordPosition, size_t& maxWordLength)
{
  if (word.length() > maxWordLength){
    maxWord = word;
    maxWordLength = word.length();
    maxWordPosition = begInd;
  }
}


void checkMinWord(const std::string word, const std::string::size_type begInd, std::string& minWord, size_t& minWordPosition, size_t& minWordLength)
{
  if (word.length() < minWordLength){
    minWord = word;
    minWordLength = word.length();
    minWordPosition = begInd;
  }
}


std::string transformString(const std::string line)
{
  std::string word;
  std::string maxWord;
  std::string minWord;
  std::string::size_type begInd;
  size_t maxWordPosition = { 0 };
  size_t minWordPosition = { 0 };
  size_t maxWordLength = { 0 };
  size_t minWordLength = INT64_MAX;
  size_t counterWords = { 0 };
  begInd = line.find_first_not_of(" ");
  while (begInd != std::string::npos){
    std::string::size_type endInd;
    endInd = line.find_first_of(" ", begInd); if (endInd == std::string::npos){
      endInd = line.length();
    }
    word = line.substr(begInd, endInd - begInd);
    checkMaxWord(word, begInd, maxWord, maxWordPosition, maxWordLength);
    checkMinWord(word, begInd, minWord, minWordPosition, minWordLength);
    ++counterWords;
    begInd = line.find_first_not_of(" ", endInd);
  }
  if (counterWords < 2){
    return line;
  }
  else{
    if (maxWord == minWord){
      return line;
    }
    else{
      std::string newLine;
      if (minWordPosition > maxWordPosition){
        newLine.append(line.substr(0, maxWordPosition));
        newLine.append(line.substr(minWordPosition, minWordLength));
        newLine.append(line.substr(maxWordPosition + maxWordLength, minWordPosition - (maxWordPosition + maxWordLength)));
        newLine.append(line.substr(maxWordPosition, maxWordLength));
        newLine.append(line.substr(minWordPosition + minWordLength));
        return newLine;
      }
      else{
        newLine.append(line.substr(0, minWordPosition));
        newLine.append(line.substr(maxWordPosition, maxWordLength));
        newLine.append(line.substr(minWordPosition + minWordLength, maxWordPosition - (minWordPosition + minWordLength)));
        newLine.append(line.substr(minWordPosition, minWordLength));
        newLine.append(line.substr(maxWordPosition + maxWordLength));
        return newLine;
      }
    }
  }
}


void changeMinAndMaxWords(std::ifstream& fin, std::string line)
{
  while (getline(fin, line)){
    std::cout << transformString(line) << '\n';
  }
}


int main()
{
  try{
    std::string line;
    std::ifstream fin("input.txt");

    checkFile(fin);
    std::cout << "Formed strings:\n";
    changeMinAndMaxWords(fin, line);
    fin.close();
  }
  catch (const std::exception &e){
    std::cout << e.what() << '\n';
  }
}
