#include <iostream>
#include <getLine.hpp>
#include "isExpression.hpp"

int main()
{
  char* str = nullptr;
  size_t capacity = 10;
  try
  {
    str = lebedev::getLine(std::cin, capacity, '\n');
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation error!\n";
    return 2;
  }

  std::cout << std::boolalpha;
  std::cout << lebedev::isExpression(str) << '\n';
  delete[] str;
  return 0;
}
