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

    double * num = nullptr;
    char * tok = std::strtok(str, " ");
    bool isRectangle = std::strcmp(tok, "RECTANGLE") == 0;
    bool isScale = std::strcmp(tok, "SCALE") == 0;

    if (isRectangle)
    {
      try
      {
        mozhegova::getNum(tok, 4, num);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Out of memory\n";
        delete[] str;
        mozhegova::destroy(shapes, count);
        return 1;
      }
      mozhegova::point_t lowLef = {num[0], num[1]};
      mozhegova::point_t uppRig = {num[2], num[3]};
      if (lowLef.x >= uppRig.x || lowLef.y >= uppRig.y)
      {
        flag = true;
      }
      mozhegova::Rectangle * rect = new mozhegova::Rectangle(lowLef, uppRig);
      shapes[count++] = rect;
    }
    else if (isScale)
    {
      try
      {
        mozhegova::getNum(tok, 3, num);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Out of memory\n";
        delete[] str;
        mozhegova::destroy(shapes, count);
        return 1;
      }
      scaleCenter = {num[0], num[1]};
      scaleCoef = num[2];
      delete[] str;
      break;
    }
    delete[] str;
  }
  if (scaleCoef <= 0)
  {
    std::cerr << "Incorrect scale\n";
    mozhegova::destroy(shapes, count);
    return 1;
  }
  std::cout.precision(1);
  std::cout << mozhegova::sumArea(shapes, count);
  mozhegova::printCoorRect(shapes, count);
  mozhegova::scaleShapes(shapes, count, scaleCenter, scaleCoef);
  std::cout << mozhegova::sumArea(shapes, count);
  mozhegova::printCoorRect(shapes, count);
  mozhegova::destroy(shapes, count);
  if (flag)
  {
    std::cerr << "There is an incorrect shape\n";
  }
}
