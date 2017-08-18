#include "gtest/gtest.h"

#include "../../../main/area_calculator.h"
#include "../../../main/dom/figures/square.h"
#include <iostream>
#include <memory>

TEST(SquareTest, Builder) {
  using namespace dom::figures;

  std::shared_ptr<Square> square = std::dynamic_pointer_cast<Square>(
      Square::SquareBuilder().setPosition(10, 20).setSideLength(5).build());

  EXPECT_EQ(square->getPosition().getX(), 10);
  EXPECT_EQ(square->getPosition().getY(), 20);
  EXPECT_EQ(square->getLength(), 5);
}

TEST(SquareTest, Area) {
  using namespace dom::figures;

  std::shared_ptr<Square> square = std::dynamic_pointer_cast<Square>(
      Square::SquareBuilder().setPosition(10, 20).setSideLength(5).build());

  auto area = DefaultFigureAreaCalculator::calculate(square);
  EXPECT_EQ(area, 25.0);
}
