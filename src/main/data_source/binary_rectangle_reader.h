#if !defined(BINARY_RECTANGLE_READER_H)
#define BINARY_RECTANGLE_READER_H

#include "../dom/figures/rectangle.h"
#include "binary_figure_reader.h"

namespace data_source {

class BinaryRectangleReader : public BinaryFigureReader {
 public:
  BinaryRectangleReader();
  virtual ~BinaryRectangleReader(){};

  virtual uint32_t read(const char* data, uint32_t length) override;
};

}  // namespace

#endif
