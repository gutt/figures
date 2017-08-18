#include "area_sumator.h"

void FigureAreaSumator::addFigure(std::shared_ptr<dom::figures::Figure> figure) {
  std::lock_guard<std::mutex> lock(m_vector_mutex);
  m_figures.push_back(figure);
}

double FigureAreaSumator::calculate() {
  std::lock_guard<std::mutex> lock(m_vector_mutex);

  double area_sum = 0.0f;
  for (auto figure : m_figures) {
    area_sum += m_area_calculator.calculate(figure);
  }
  return area_sum;
}

void FigureAreaSumator::clear() {
  std::lock_guard<std::mutex> lock(m_vector_mutex);
  m_figures.clear();
}
