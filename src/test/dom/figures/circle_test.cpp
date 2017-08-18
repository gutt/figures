#include "gtest/gtest.h"

#include "../../../main/area_calculator.h"
#include "../../../main/dom/figures/circle.h"
#include <iostream>
#include <memory>

TEST(CircleTest, Builder) {
  using namespace dom::figures;

  std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(
      Circle::CircleBuilder().setPosition(10, 20).setRadius(5).build());

  EXPECT_EQ(circle->getPosition().getX(), 10);
  EXPECT_EQ(circle->getPosition().getY(), 20);
  EXPECT_EQ(circle->getRadius(), 5);
}

TEST(CircleTest, Area) {
  using namespace dom::figures;

  std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(
      Circle::CircleBuilder().setPosition(10, 20).setRadius(5).build());

  auto area = DefaultFigureAreaCalculator::calculate(circle);
  EXPECT_NEAR(area, 78.5398, 0.0001);
}
