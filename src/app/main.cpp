#include "area_sumator.h"
#include "data_source/binary_data_figures_reader.h"
#include "dom/figures/rectangle.h"
#include "dom/figures/square.h"
#include <iostream>

using namespace dom::figures;
using namespace std;

int main() {
  try {
    const char data[] = {
        1, 0,   0,   20,                                 // square
        2, 10,  10,  20, 30,                             // rectangle
        3, 6,   1,   1,  2,  2, 3, 3, 4, 4, 5, 5, 6, 6,  // polygon
        4, -10, -10, 5                                   // circle
    };
    // create reader for binary data
    data_source::BinaryDataFiguresReader sr;

    // read figures data from array
    sr.read(data, sizeof(data));

    // create standard area calculator implementation
    DefaultFigureAreaCalculator area_calculator;

    // create sumator with default area calculator
    FigureAreaSumator area_sumator(area_calculator);

    // read figure from source and move it to sumator
    while (!sr.isFigureQueueEmpty()) {
      area_sumator.addFigure(sr.popFigure());
    }

    // output data
    cout << "Sum of all figures area:" << area_sumator.calculate() << endl;
  } catch (std::exception) {
    cout << "Exception occured! Exiting. " << endl;
    return 1;
  }

  return 0;
}
