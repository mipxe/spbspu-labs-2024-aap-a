#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "shape.hpp"
#include <cstddef>

namespace mozhegova
{
  class Polygon final: public Shape
  {
  public:
    Polygon(size_t n, const point_t * arr);
    ~Polygon();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    size_t count_;
    point_t * points_;
  };
}

#endif