#include "shapeManipulator.hpp"
#include <cstring>

double * mozhegova::getNum(char * tok, size_t length)
{
  double * num = new double [length];
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
double mozhegova::sumArea(Shape ** shapes, size_t n)
{
  double sum = 0;
  for (size_t i = 0; i < n; i++)
  {
    sum += shapes[i]->getArea();
  }
  return sum;
}
void mozhegova::printCoorRect(Shape ** shapes, size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    rectangle_t rect = shapes[i]->getFrameRect();
    double lx = rect.pos.x - rect.width / 2;
    double ly = rect.pos.y - rect.height / 2;
    double rx = rect.pos.x + rect.width / 2;
    double ry = rect.pos.y + rect.height / 2;
    std::cout.precision(1);
    std::cout << " " << lx << " " << ly << " " << rx << " " << ry << "\n";
  }
}
void mozhegova::scaleShapes(Shape ** shapes, size_t n, point_t p, double k)
{
  for (size_t i = 0; i < n; i++)
  {
    point_t ptr = shapes[i]->getFrameRect().pos;
    shapes[i]->move(p);
    point_t newptr = shapes[i]->getFrameRect().pos;
    point_t vectorMove = {(newptr.x - ptr.x) * k, (newptr.y - ptr.y) * k};
    shapes[i]->scale(k);
    shapes[i]->move(-vectorMove.x, -vectorMove.y);
  }
}
void mozhegova::destroy(Shape ** shapes, size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    delete shapes[i];
  }
}
