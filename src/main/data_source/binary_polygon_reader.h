#if !defined(BINARY_POLYGON_READER_H)
#define BINARY_POLYGON_READER_H

#include "../dom/figures/polygon.h"
#include "binary_figure_reader.h"

namespace data_source {

class BinaryPolygonReader : public BinaryFigureReader {
 public:
  BinaryPolygonReader();
  virtual ~BinaryPolygonReader() {}

  virtual uint32_t read(const char* data, uint32_t length) override;
};

}  // namespace

#endif
