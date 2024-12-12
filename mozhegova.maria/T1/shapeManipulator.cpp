#include "shapeManipulator.hpp"
#include <cstring>

double * mozhegova::getNum(char * tok, size_t length)
{
  double num[length] = {};
  for (size_t i = 0; tok != NULL; i++)
  {
    tok = std::strtok(NULL, " ");
    if (tok != NULL)
    {
      num[i] = std::atof(tok);
    }
  }
  return num;
}
