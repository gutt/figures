#include "square.h"
#include "primitives.h"

namespace dom {
namespace figures {

Square::SquareBuilder::SquareBuilder()
    : m_position{0.0, 0.0}, m_side_length{default_side_length} {}

Square::SquareBuilder& Square::SquareBuilder::setPosition(const double x,
                                                          const double y) {
  m_position.setX(x);
  m_position.setY(y);
  return *this;
}

Square::SquareBuilder& Square::SquareBuilder::setSideLength(
    const double side_length) {
  m_side_length = side_length;
  return *this;
}

std::shared_ptr<Figure> Square::SquareBuilder::build() {
  auto figure = std::make_shared<Square>(m_position, m_side_length);
  return figure;
}
}
}  // namespaces
