#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "polygon.hpp"

namespace mozhegova
{
  class Diamond : public Shape
  {
  public:
    Diamond(size_t n, point_t * arr);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    ~Diamond();
  private:
    Polygon * poly;
  };
}

#endif
