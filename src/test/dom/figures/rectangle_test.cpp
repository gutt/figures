#include "gtest/gtest.h"

#include "../../../main/area_calculator.h"
#include "../../../main/dom/figures/rectangle.h"
#include <iostream>
#include <memory>

TEST(RectangleTest, Builder) {
  using namespace dom::figures;
  using namespace std;

  shared_ptr<Rectangle> rectangle =
      dynamic_pointer_cast<Rectangle>(Rectangle::RectangleBuilder()
                                          .setPosition(10, 20)
                                          .setWidth(5)
                                          .setHeight(10)
                                          .build());

  EXPECT_EQ(rectangle->getPosition().getX(), 10);
  EXPECT_EQ(rectangle->getPosition().getY(), 20);
  EXPECT_EQ(rectangle->getWidth(), 5);
  EXPECT_EQ(rectangle->getHeight(), 10);
}

TEST(RectangleTest, Area) {
  using namespace dom::figures;
  using namespace std;

  shared_ptr<Rectangle> rectangle =
      dynamic_pointer_cast<Rectangle>(Rectangle::RectangleBuilder()
                                          .setPosition(10, 20)
                                          .setWidth(5)
                                          .setHeight(10)
                                          .build());

  auto area = DefaultFigureAreaCalculator::calculate(rectangle);

  EXPECT_EQ(area, 50);
}
