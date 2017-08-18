#if !defined(AREA_SUMATOR_H)
#define AREA_SUMATOR_H

#include <vector>
#include <mutex>

#include "dom/figures/figure.h"
#include "area_calculator.h"

class FigureAreaSumatorI {
 public:
  virtual void addFigure(std::shared_ptr<dom::figures::Figure> figure)=0;
  virtual void clear()=0;
  virtual double calculate()=0;

  virtual ~FigureAreaSumatorI() {}
};

class FigureAreaSumator : public FigureAreaSumatorI {
  using FigureList = std::vector<std::shared_ptr<dom::figures::Figure>>;

  FigureAreaCalculatorI& m_area_calculator;
  FigureList m_figures;
  std::mutex m_vector_mutex;

 public:
  FigureAreaSumator(FigureAreaCalculatorI& area_calculator)
      : m_area_calculator(area_calculator) {}
  virtual ~FigureAreaSumator(){};

  void addFigure(std::shared_ptr<dom::figures::Figure> figure) override;
  void clear() override;
  double calculate() override;
};

#endif
