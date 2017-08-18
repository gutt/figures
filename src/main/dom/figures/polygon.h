#if !defined(POLYGON_H)
#define POLYGON_H

#include <iostream>
#include <vector>

#include "figure.h"
#include "primitives.h"

namespace dom {
namespace figures {

class PolygonI {
 protected:
  using Verticles = std::vector<Point>;

  virtual Verticles getVerticles() const = 0;

  virtual ~PolygonI() {}
};

class Polygon : public Figure, public PolygonI {
 public:
  class PolygonBuilder;

 private:
  const Verticles m_verticles;

 public:
  explicit Polygon(const Verticles& verticles)
      : Figure{FigureType::Polygon}, m_verticles{verticles} {}

  explicit Polygon(const Polygon& polygon)
      : Figure{FigureType::Polygon}, m_verticles{polygon.m_verticles} {}

  virtual ~Polygon() {}

  Verticles getVerticles() const override { return m_verticles; }
};

class Polygon::PolygonBuilder : public FigureBuilderI {
 private:
  Verticles m_verticles;

 public:
  PolygonBuilder() {}
  virtual ~PolygonBuilder() {}

  PolygonBuilder& addVerticle(const double x, const double y);

  std::shared_ptr<Figure> build() override;
};
}
}  // namespaces

#endif
