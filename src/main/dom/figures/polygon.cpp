#include "polygon.h"

namespace dom {
namespace figures {

PolygonI::PolygonBuilderI& Polygon::PolygonBuilder::addVerticle(const double x,
                                                              const double y) {
  m_verticles.push_back(Point(x, y));
  return *this;
}

std::shared_ptr<Figure> Polygon::PolygonBuilder::build() {
  auto figure = std::make_shared<Polygon>(m_verticles);
  return figure;
}
}
}
