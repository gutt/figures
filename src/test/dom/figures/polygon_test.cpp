#include "gtest/gtest.h"

#include "../../../main/area_calculator.h"
#include "../../../main/dom/figures/polygon.h"
#include <iostream>
#include <memory>

TEST(PolygonTest, Builder) {
  using namespace dom::figures;
  using namespace std;

  shared_ptr<Polygon> polygon =
      dynamic_pointer_cast<Polygon>(Polygon::PolygonBuilder()
                                        .addVerticle(0, 0)
                                        .addVerticle(0, 10)
                                        .addVerticle(10, 10)
                                        .addVerticle(10, 0)
                                        .build());

  EXPECT_EQ(polygon->getVerticles().at(0).getX(), 0);
  EXPECT_EQ(polygon->getVerticles().at(0).getY(), 0);

  EXPECT_EQ(polygon->getVerticles().at(1).getX(), 0);
  EXPECT_EQ(polygon->getVerticles().at(1).getY(), 10);

  EXPECT_EQ(polygon->getVerticles().at(2).getX(), 10);
  EXPECT_EQ(polygon->getVerticles().at(2).getY(), 10);

  EXPECT_EQ(polygon->getVerticles().at(3).getX(), 10);
  EXPECT_EQ(polygon->getVerticles().at(3).getY(), 0);
}

TEST(PolygonTest, Area) {
  using namespace dom::figures;
  using namespace std;

  shared_ptr<Polygon> polygon =
      dynamic_pointer_cast<Polygon>(Polygon::PolygonBuilder()
                                        .addVerticle(0, 0)
                                        .addVerticle(0, 10)
                                        .addVerticle(5, 10)
                                        .addVerticle(10, 0)
                                        .addVerticle(0, 0)
                                        .build());

  auto area = DefaultFigureAreaCalculator::calculate(polygon);

  EXPECT_EQ(area, 75);
}
