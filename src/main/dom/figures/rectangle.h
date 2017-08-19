#if !defined(RECTANGLE_H)
#define RECTANGLE_H

#include "figure.h"
#include "primitives.h"

namespace dom {
namespace figures {

class RectangleI {
 public:
  virtual Point getPosition() const = 0;
  virtual double getWidth() const = 0;
  virtual double getHeight() const = 0;

  virtual ~RectangleI() {}
};

class Rectangle : public Figure, public RectangleI {
 public:
  class RectangleBuilder;

 private:
  // position
  const Point m_position;
  // side length
  const double m_width;
  const double m_height;

 public:
  explicit Rectangle(const Point& position,
                     const double width,
                     const double height)
      : Figure{FigureType::Rectangle},
        m_position{position},
        m_width(width),
        m_height(height) {}

  explicit Rectangle(const Rectangle& rectangle)
      : Figure{FigureType::Rectangle},
        m_position{rectangle.m_position},
        m_width(rectangle.m_width),
        m_height(rectangle.m_height) {}

  virtual ~Rectangle(){};

  Point getPosition() const override { return m_position; }
  double getWidth() const override { return m_width; }
  double getHeight() const override { return m_height; }
};

class Rectangle::RectangleBuilder : public FigureBuilderI {
 private:
  Point m_position;
  double m_width;
  double m_height;

 public:
  static const constexpr double default_width = 0;
  static const constexpr double default_height = 0;

  RectangleBuilder();
  virtual ~RectangleBuilder(){};

  RectangleBuilder& setPosition(const double x, const double y);
  RectangleBuilder& setWidth(const double width);
  RectangleBuilder& setHeight(const double height);

  std::shared_ptr<Figure> build() override;
};
}
}  // namespaces

#endif
