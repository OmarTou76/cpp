#include "BitcoinExchange.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

t_data splitLine(std::string &line)
{
  t_data data;
  memset(&data, 0, sizeof(t_data));
  int pos = 0;
  pos = line.find("|");
  std::string date = line.substr(0, pos);
  std::string quantity = line.substr(pos + 1);
  data.date = date;
  data.quantity = static_cast<float>(atof(quantity.c_str()));
  if (pos > -1)
  {
    data.isValidInput = true;
    data.timestamp = BitcoinExchange::toTimestamp(data.date);
  }
  return data;
}

void readAndSaveInputContent(const char *filename, BitcoinExchange &btc)
{
  std::fstream file(filename);
  if (!file.is_open())
    throw std::fstream::failure("Impossible to open file ");
  std::string line;
  std::getline(file, line);
  while (std::getline(file, line))
    btc.add(splitLine(line));
  file.close();
}

int main(int argc, char **argv)
{
  if (argc != 2)
    std::cout << "Error: could not open file." << std::endl;
  else
  {
    BitcoinExchange btc;
    try
    {
      readAndSaveInputContent(argv[1], btc);
      btc.showConversions();
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
  }
  return 0;
}
