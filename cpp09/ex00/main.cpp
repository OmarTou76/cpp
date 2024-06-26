#include "BitcoinExchange.h"
#include <fstream>
#include <iostream>
#include <string>

void parseLine(std::string &line) {
  // t_data data = {0};
  size_t pos = 0;
  pos = line.find("|");
  std::string date = line.substr(0, pos);
  std::string quantity = line.substr(pos + 1, line.length());

  std::cout << date << ": " << quantity << " elements !" << std::endl;
}

void readInputContent(const char *filename, BitcoinExchange &btc) {
  (void)btc;
  std::fstream file(filename);
  std::string line;
  std::getline(file, line);
  while (std::getline(file, line))
    parseLine(line);
  file.close();
}

int main(int argc, char **argv) {
  if (argc != 2)
    std::cout << "Error: could not open file." << std::endl;
  else {
    BitcoinExchange btc;
    readInputContent(argv[1], btc);
  }
  return 0;
}
