#if !defined(CIRCLE_H)
#define CIRCLE_H

#include "figure.h"
#include "primitives.h"
#include <iostream>
#include <memory>

namespace dom {
namespace figures {

class CircleI {
 public:
  virtual Point getPosition() const = 0;
  virtual double getRadius() const = 0;

  virtual ~CircleI(){};
};

class Circle : public Figure, public CircleI {
 public:
  class CircleBuilder;

 private:
  const Point m_position;
  const double m_radius;

 public:
  explicit Circle(Point& position, double radius)
      : Figure{FigureType::Circle}, m_position{position}, m_radius(radius) {}

  explicit Circle(const Circle& circle)
      : Figure{FigureType::Circle},
        m_position{circle.m_position},
        m_radius(circle.m_radius) {}

  virtual ~Circle(){};

  Point getPosition() const override { return m_position; }
  double getRadius() const override { return m_radius; }
};

class Circle::CircleBuilder : public FigureBuilderI {
 private:
  Point m_position;
  double m_radius;

 public:
  static const constexpr double default_radius{0.0};

  CircleBuilder();
  virtual ~CircleBuilder(){};

  CircleBuilder& setPosition(const double x, const double y);
  CircleBuilder& setRadius(const double radius);

  std::shared_ptr<Figure> build() override;
};
}
}  // namespaces

#endif
