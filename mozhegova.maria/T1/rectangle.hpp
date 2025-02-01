#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "polygon.hpp"

namespace mozhegova
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(size_t n, point_t * arr);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    ~Rectangle();
  private:
    Polygon * poly;
  };
}

#endif
