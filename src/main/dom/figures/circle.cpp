#include "circle.h"
#include "primitives.h"

namespace dom {
namespace figures {

Circle::CircleBuilder::CircleBuilder()
    : m_position{0.0, 0.0}, m_radius{default_radius} {}

Circle::CircleBuilder& Circle::CircleBuilder::setPosition(const double x,
                                                          const double y) {
  m_position.setX(x);
  m_position.setY(y);
  return *this;
}

Circle::CircleBuilder& Circle::CircleBuilder::setRadius(const double radius) {
  m_radius = radius;
  return *this;
}

std::shared_ptr<Figure> Circle::CircleBuilder::build() {
  auto figure = std::make_shared<Circle>(m_position, m_radius);
  return figure;
}
}
}  // namespaces
