#include "BitcoinExchange.h"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

class ImpossibleToOpenFile : public std::exception {
public:
  const char *what() const throw() { return "Error: could not open file"; }
};

t_data splitLine(std::string &line) {
  t_data data;
  int pos = 0;
  pos = line.find("|");
  std::string date = line.substr(0, pos);
  std::string quantity = line.substr(pos + 1);
  data.date = date;
  data.isValidInput = false;
  data.quantity = static_cast<float>(atof(quantity.c_str()));
  if (pos > -1) {
    data.isValidInput = true;
    data.timestamp = BitcoinExchange::toTimestamp(data.date);
  }
  return data;
}

void readAndSaveInputContent(const char *filename, BitcoinExchange &btc) {
  std::fstream file(filename);
  if (!file.is_open())
    throw ImpossibleToOpenFile();
  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    if (line.length())
      btc.add(splitLine(line));
  }
  file.close();
}

int main(int argc, char **argv) {

  try {
    if (argc != 2)
      throw ImpossibleToOpenFile();
    else {
      BitcoinExchange btc;
      readAndSaveInputContent(argv[1], btc);
      btc.showConversions();
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
