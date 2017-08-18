#if !defined(BINARY_CIRCLE_READER_H)
#define BINARY_CIRCLE_READER_H

#include "../dom/figures/circle.h"
#include "binary_figure_reader.h"

namespace data_source {

class BinaryCircleReader : public BinaryFigureReader {
 public:
  BinaryCircleReader();
  virtual ~BinaryCircleReader(){};

  uint32_t read(const char* data, uint32_t length) override;
};

}  // namespace

#endif
