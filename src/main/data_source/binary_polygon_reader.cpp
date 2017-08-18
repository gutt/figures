#include "binary_polygon_reader.h"
#include <iostream>

namespace data_source {

BinaryPolygonReader::BinaryPolygonReader() {}

uint32_t BinaryPolygonReader::read(const char* data, uint32_t length) {
  using namespace dom::figures;

  uint32_t bytes_read{0};
  uint32_t verticle_count = data[bytes_read++];
  uint32_t bytes_available = length - bytes_read;

  if (verticle_count > bytes_available * 2)  // wrong size
  {
    std::cout << "Not enough data to read verticles." << std::endl;
    throw std::exception();
  }

  Polygon::PolygonBuilder builder;
  for (size_t i = 0; i < verticle_count; i++) {
    auto x = data[bytes_read++];
    auto y = data[bytes_read++];
    builder.addVerticle(x, y);
  }
  m_figure = builder.build();

  return bytes_read;
}

}  // namespace
