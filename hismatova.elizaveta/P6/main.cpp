#include <iostream>
#include <cstring>
#include <get_string.h>
#include "suitable_string.h"

int main()
{
  size_t length = 0;
  char* str = hismatova::get_line(std::cin, length);
  if (str == nullptr || length == 0)
  {
    std::cerr << "no string\n";
    free(str);
    return 1;
  }
  size_t position = 0;
  if (hismatova::isValidString(str, position) && position == length)
  {
    std::cout << "true\n";
  }
  else
  {
    std::cout << "false\n";
  }
  free(str);
  return 0;
}
