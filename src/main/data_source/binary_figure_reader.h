#if !defined(BINARY_FIGURE_READER_H)
#define BINARY_FIGURE_READER_H

#include <memory>

#include "../dom/figures/circle.h"
#include "../dom/figures/figure.h"

namespace data_source {

class BinaryFigureReader {
 protected:
  std::shared_ptr<dom::figures::Figure> m_figure = nullptr;

 public:
  BinaryFigureReader() : m_figure(nullptr){};
  virtual ~BinaryFigureReader(){};

  virtual uint32_t read(const char* data, uint32_t length) = 0;

  virtual std::shared_ptr<dom::figures::Figure> getFigure() { return m_figure; }
};
}

#endif
