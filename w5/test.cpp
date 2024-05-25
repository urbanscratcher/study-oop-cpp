#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> tokenize(std::string csvLine, char separator)
{
  std::vector<std::string> tokens;
  signed int start, end;
  std::string token;

  start = csvLine.find_first_not_of(separator, 0);

  do
  {
    end = csvLine.find_first_of(separator, start);

    if (start == csvLine.length() || start == end)
    {
      break;
    }

    if (end >= 0)
    {
      token = csvLine.substr(start, end - start);
    }
    else
    {
      token = csvLine.substr(start, csvLine.length() - start);
    }

    tokens.push_back(token);
    start = end + 1;

  } while (end != std::string::npos);

  return tokens;
}

int main()
{
  // read a csv file
  std::ifstream csvFile{"20200317.csv"};
  std::string line;
  std::vector<std::string> tokens;

  if (csvFile.is_open())
  {
    std::cout << "File open" << std::endl;

    while (std::getline(csvFile, line))
    {
      std::cout << "Read line " << line << std::endl;
      tokens = tokenize(line, ',');

      // if we don't have 5 tokens, skip the line
      if (tokens.size() != 5)
      {
        std::cout << "Bad line " << std::endl;
        continue;
      }

      // we have 5 tokens
      try
      {
        double price = std::stod(tokens[3]);
        double amount = std::stod(tokens[4]);
        std::cout << price << ":" << amount << std::endl;
      }
      catch (std::exception &e)
      {
        std::cout << "Bad float! " << tokens[3] << std::endl;
        std::cout << "Bad float! " << tokens[4] << std::endl;
        break;
      }
    }

    csvFile.close();
  }
  else
  {
    std::cerr << "File not found" << std::endl;
  }

  return 0;
};