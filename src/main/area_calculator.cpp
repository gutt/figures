#include "area_calculator.h"

#include <cmath>

#include "dom/figures/circle.h"
#include "dom/figures/polygon.h"
#include "dom/figures/rectangle.h"
#include "dom/figures/square.h"

using namespace dom::figures;

const double DefaultFigureAreaCalculator::calculate(
    const std::shared_ptr<Figure>& figure) {
  Figure::FigureType type = figure->getType();

  switch (type) {
    case Figure::FigureType::Square:
      return calculate(std::dynamic_pointer_cast<Square>(figure));

    case Figure::FigureType::Rectangle:
      return calculate(std::dynamic_pointer_cast<Rectangle>(figure));

    case Figure::FigureType::Circle:
      return calculate(std::dynamic_pointer_cast<Circle>(figure));

    case Figure::FigureType::Polygon:
      return calculate(std::dynamic_pointer_cast<Polygon>(figure));

    default:
      // unknown figure!
      std::cout << "area calculator: unknown figure! " << int(type)
                << std::endl;
      throw std::exception();
  }
  return -1;
}

const double DefaultFigureAreaCalculator::calculate(
    const std::shared_ptr<dom::figures::Square>& square) {
  auto length = square->getLength();
  return length * length;
}

const double DefaultFigureAreaCalculator::calculate(
    const std::shared_ptr<dom::figures::Rectangle>& rectangle) {
  auto width = rectangle->getWidth();
  auto height = rectangle->getHeight();
  return width * height;
}

const double DefaultFigureAreaCalculator::calculate(
    const std::shared_ptr<dom::figures::Polygon>& polygon) {
  double area = 0;

  auto verticles = polygon->getVerticles();
  int verticle_count = verticles.size();

  for (int i = 1; i < verticle_count; i++) {
    int j = (i + 1) % verticle_count;
    area += verticles.at(i).getX() * verticles.at(j).getY();
    area -= verticles.at(i).getY() * verticles.at(j).getX();
  }
  area /= 2;
  return (area < 0 ? -area : area);
}

const double DefaultFigureAreaCalculator::calculate(
    const std::shared_ptr<dom::figures::Circle>& circle) {
  constexpr double pi = std::atan(1) * 4;
  return (pi * std::pow(circle->getRadius(), 2));
}
