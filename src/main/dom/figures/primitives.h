#if !defined(PRIMITIVES_H)
#define PRIMITIVES_H

namespace dom {
namespace figures {

class Point {
  double m_x;
  double m_y;

 public:
  constexpr Point(const double x, const double y) : m_x{x}, m_y{y} {}
  constexpr Point(const Point& point) : m_x{point.m_x}, m_y{point.m_y} {}

  constexpr double getX() const { return m_x; };
  constexpr double getY() const { return m_y; };

  constexpr void setX(const double x) { m_x = x; };
  constexpr void setY(const double y) { m_y = y; };
};
}
}  // namespaces

#endif
