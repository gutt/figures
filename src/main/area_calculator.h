#if !defined(AREA_CALCULATOR_H)
#define AREA_CALCULATOR_H

#include <memory>

#include "dom/figures/circle.h"
#include "dom/figures/figure.h"
#include "dom/figures/polygon.h"
#include "dom/figures/rectangle.h"
#include "dom/figures/square.h"


class FigureAreaCalculatorI {
 public:
  virtual const double calculate(
      const std::shared_ptr<dom::figures::Figure>& figure) = 0;

  virtual ~FigureAreaCalculatorI(){};
};

class DefaultFigureAreaCalculator : public FigureAreaCalculatorI {
 public:
  DefaultFigureAreaCalculator() {}
  virtual ~DefaultFigureAreaCalculator() {}

  const double calculate(
      const std::shared_ptr<dom::figures::Figure>& figure) override;

  static const double calculate(
      const std::shared_ptr<dom::figures::Square>& square);
  static const double calculate(
      const std::shared_ptr<dom::figures::Rectangle>& rectangle);
  static const double calculate(
      const std::shared_ptr<dom::figures::Polygon>& polygon);
  static const double calculate(
      const std::shared_ptr<dom::figures::Circle>& circle);
};

#endif
