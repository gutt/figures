#include "rectangle.h"

namespace dom {
namespace figures {

Rectangle::RectangleBuilder::RectangleBuilder()
    : m_position{0.0, 0.0}, m_width{default_width}, m_height{default_height} {}

Rectangle::RectangleBuilder& Rectangle::RectangleBuilder::setPosition(
    const double x,
    const double y) {
  m_position.setX(x);
  m_position.setY(y);
  return *this;
}

Rectangle::RectangleBuilder& Rectangle::RectangleBuilder::setWidth(
    const double width) {
  m_width = width;
  return *this;
}

Rectangle::RectangleBuilder& Rectangle::RectangleBuilder::setHeight(
    const double height) {
  m_height = height;
  return *this;
}

std::shared_ptr<Figure> Rectangle::RectangleBuilder::build() {
  auto figure = std::make_shared<Rectangle>(m_position, m_width, m_height);
  return figure;
}
}
}
