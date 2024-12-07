#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace mozhegova
{
  class Rectangle : Shape
  {
  public:
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t lowerLeft;
    point_t upperRight;
    double width = upperRight.x - lowerLeft.x;
    double height = upperRight.y - lowerLeft.y;
  };
}

#endif
