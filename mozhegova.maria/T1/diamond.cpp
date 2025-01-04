#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

mozhegova::Diamond::Diamond(size_t n, point_t * arr) :
  poly(nullptr)
{
  poly = new mozhegova::Polygon(n, arr);
}

double mozhegova::Diamond::getArea() const
{
  return poly->getArea();
}

mozhegova::rectangle_t mozhegova::Diamond::getFrameRect() const
{
  return poly->getFrameRect();
}

void mozhegova::Diamond::move(point_t p)
{
  poly->move(p);
}

void mozhegova::Diamond::move(double dx, double dy)
{
  poly->move(dx, dy);
}

void mozhegova::Diamond::scale(double k)
{
  poly->scale(k);
}
