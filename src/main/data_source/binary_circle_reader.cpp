#include "binary_circle_reader.h"
#include <iostream>

using namespace dom::figures;

namespace data_source {

BinaryCircleReader::BinaryCircleReader() {}

uint32_t BinaryCircleReader::read(const char* data, uint32_t length) {

  if (length < 3) {
    std::cout << "Not enough data to read circle." << std::endl;
    throw std::exception();
  }
  uint32_t bytes_read{0};

  auto x = data[bytes_read++];
  auto y = data[bytes_read++];
  auto radius = data[bytes_read++];

  Circle::CircleBuilder builder;
  builder.setPosition(x, y);
  builder.setRadius(radius);

  m_figure = builder.build();

  return bytes_read;
}
}
