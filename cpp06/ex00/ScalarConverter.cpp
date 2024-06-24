#include "ScalarConverter.h"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) { *this = copy; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  (void)rhs;
  return *this;
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &str) {
  int toInt;
  double toDouble;
  float toFloat;
  std::string toChar;
  std::string pseudoLiterals[] = {"+inf",  "-inf",  "nanf",
                                  "+inff", "-inff", "nan"};
  bool isPseudoLiteral = false;

  toDouble = atof(str.c_str());
  toInt = static_cast<int>(toDouble);
  toFloat = static_cast<float>(toDouble);

  if (toInt >= 32 && toInt <= 126) {
    toChar += "'";
    toChar += static_cast<char>(toInt);
    toChar += "'";
  } else
    toChar += "non displayable";

  for (size_t i = 0; i < 6; i++) {
    if (!pseudoLiterals[i].compare(str)) {
      isPseudoLiteral = true;
      break;
    }
  }

  if (!isPseudoLiteral && toInt == 0 && str[0] != 0 && str[1] != 0 &&
      str[0] != '+' && str[0] != '-') {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return;
  }
  if (isPseudoLiteral) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "char: " << toChar << std::endl;
    std::cout << "int: " << toInt << std::endl;
  }

  if (toFloat - static_cast<int>(toFloat) == 0) {
    std::cout << "float: " << toFloat << ".0f" << std::endl;
    std::cout << "double: " << toDouble << ".0" << std::endl;
  } else {
    std::cout << "float: " << toFloat << "f" << std::endl;
    std::cout << "double: " << toDouble << std::endl;
  }
}
