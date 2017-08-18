#include "binary_rectangle_reader.h"
#include <iostream>

namespace data_source {

using namespace dom::figures;

BinaryRectangleReader::BinaryRectangleReader() {}

uint32_t BinaryRectangleReader::read(const char* data, uint32_t length) {

  if (length < 4) {
    std::cout << "Not enough data to read rectangle." << std::endl;
    throw std::exception();  // not enough data!
  }
  uint32_t bytes_read{0};

  auto x = data[bytes_read++];
  auto y = data[bytes_read++];
  auto width = data[bytes_read++];
  auto height = data[bytes_read++];

  Rectangle::RectangleBuilder builder;
  builder.setPosition(x, y);
  builder.setWidth(width);
  builder.setHeight(height);

  m_figure = builder.build();

  return bytes_read;
}

}  // namespace
