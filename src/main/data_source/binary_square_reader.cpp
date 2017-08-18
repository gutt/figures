#include "binary_square_reader.h"
#include <iostream>

namespace data_source {

using namespace dom::figures;

BinarySquareReader::BinarySquareReader() {}

uint32_t BinarySquareReader::read(const char* data, uint32_t length) {

  if (length < 3) {
    std::cout << "not enough data to read square: " << length << std::endl;
    throw std::exception();  // not enough data!
  }
  uint32_t bytes_read{0};

  auto x = data[bytes_read++];
  auto y = data[bytes_read++];
  auto side_length = data[bytes_read++];

  Square::SquareBuilder builder;
  builder.setPosition(x, y);
  builder.setSideLength(side_length);

  m_figure = builder.build();

  return bytes_read;
}
}
