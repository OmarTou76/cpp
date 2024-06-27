#include "BitcoinExchange.h"
#include <fstream>
#include <iostream>
#include <string>

t_data splitLine(std::string &line) {
  t_data data = {.date = "" , .quantity = "" };
  int pos = 0;
  pos = line.find("|");
  std::string date = line.substr(0, pos);
  std::string quantity = line.substr(pos + 1);
  data.date = date;
  if (pos > -1)
    data.quantity = quantity;
  return data;
}

void readInputContent(const char *filename, BitcoinExchange &btc) {
  std::fstream file(filename);
  std::string line;
  std::getline(file, line);
  while (std::getline(file, line))
    btc.appendValue(splitLine(line));
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
