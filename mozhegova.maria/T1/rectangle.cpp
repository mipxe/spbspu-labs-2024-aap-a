#include "rectangle.hpp"

mozhegova::Rectangle::Rectangle(size_t n, point_t * arr) :
  poly(nullptr)
{
  poly = new mozhegova::Polygon(n, arr);
}

double mozhegova::Rectangle::getArea() const
{
  return poly->getArea();
}

mozhegova::rectangle_t mozhegova::Rectangle::getFrameRect() const
{
  return poly->getFrameRect();
}

void mozhegova::Rectangle::move(point_t p)
{
  poly->move(p);
}

void mozhegova::Rectangle::move(double dx, double dy)
{
  poly->move(dx, dy);
}

void mozhegova::Rectangle::scale(double k)
{
  poly->scale(k);
}
