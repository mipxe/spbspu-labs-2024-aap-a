#include <strinput.hpp>
#include <cstring>
#include "shape.hpp"
#include "rectangle.hpp"
#include "shapeManipulator.hpp"

int main()
{
  mozhegova::Shape * shapes[1000] = {};
  size_t count = 0;
  bool flag = false;
  double scaleCoef = 0;
  mozhegova::point_t scaleCenter = {0, 0};
  while (!std::cin.eof()) 
  {
    char * str = nullptr;
    try
    {
      str = mozhegova::inputString(std::cin, '\n');
    }
    catch (const std::exception& e)
    {
      std::cerr << "Out of memory\n";
      return 1;
    }
    if (str[0] == '\0')
    {
      delete[] str;
      continue;
    }

    char * tok = std::strtok(str, " ");
    bool isRectangle = std::strcmp(tok, "RECTANGLE") == 0;
    bool isScale = std::strcmp(tok, "SCALE") == 0;

    if (isRectangle)
    {
      double * num = mozhegova::getNum(tok, 4);
      mozhegova::point_t lowLef = {num[0], num[1]};
      mozhegova::point_t uppRig = {num[2], num[3]};
      if (lowLef.x >= uppRig.x || lowLef.y >= uppRig.y)
      {
        flag = false;
      }
      mozhegova::Rectangle * rect = new mozhegova::Rectangle(lowLef, uppRig);
      shapes[count++] = rect;
    }
    else if (isScale)
    {
      double * num = mozhegova::getNum(tok, 3);
      scaleCenter = {num[0], num[1]};
      scaleCoef = num[2];
      if (scaleCoef <= 0)
      {
        delete[] str;
        std::cerr << "Incorrent scale\n";
        return 1;
      }
      break;
    }
    delete[] str;
  }
}
