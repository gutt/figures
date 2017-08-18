#if !defined(BINARY_SQUARE_READER_H)
#define BINARY_SQUARE_READER_H

#include "../dom/figures/square.h"
#include "binary_figure_reader.h"

namespace data_source {

class BinarySquareReader : public BinaryFigureReader {
 public:
  BinarySquareReader();
  virtual ~BinarySquareReader(){};

  virtual uint32_t read(const char* data, uint32_t length) override;
};

}  // namespace

#endif
