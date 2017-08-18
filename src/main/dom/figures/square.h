#if !defined(SQUARE_H)
#define SQUARE_H

#include "figure.h"
#include "primitives.h"
#include <iostream>
#include <memory>

namespace dom {
namespace figures {

class SquareI {
 public:
  virtual Point getPosition() const = 0;
  virtual double getLength() const = 0;

  virtual ~SquareI() {}
};

class Square : public Figure, public SquareI {
 public:
  class SquareBuilder;

 private:
  const Point m_position;
  const double m_side_length;

 public:
  explicit Square(Point& position, double side_length)
      : Figure{FigureType::Square},
        m_position{position},
        m_side_length(side_length) {}

  explicit Square(const Square& square)
      : Figure{FigureType::Square},
        m_position{square.m_position},
        m_side_length(square.m_side_length) {}

  virtual ~Square(){};

  Point getPosition() const override { return m_position; }
  double getLength() const override { return m_side_length; }
};

class Square::SquareBuilder : public FigureBuilderI {
 private:
  Point m_position;
  double m_side_length;

 public:
  static const constexpr double default_side_length{0.0};

  SquareBuilder();
  virtual ~SquareBuilder(){};

  SquareBuilder& setPosition(const double x, const double y);
  SquareBuilder& setSideLength(const double side_length);

  std::shared_ptr<Figure> build() override;
};
}
}  // namespaces

#endif
