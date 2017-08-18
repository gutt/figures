#include "binary_data_figures_reader.h"

namespace data_source {

using namespace dom::figures;

bool BinaryDataFiguresReader::isFigureQueueEmpty() {
  std::lock_guard<std::mutex> lock(m_queue_mutex);

  return m_figure_queue.empty();
}

std::shared_ptr<Figure> BinaryDataFiguresReader::popFigure() {
  std::lock_guard<std::mutex> lock(m_queue_mutex);

  std::shared_ptr<Figure> figure = m_figure_queue.front();
  m_figure_queue.pop();

  return figure;
}

uint32_t BinaryDataFiguresReader::read(const char* data, const int data_size) {
  uint32_t cursor = 0;

  int32_t data_available = data_size - cursor;

  while (data_available > 0) {
    int figure_id = data[cursor];
    BinaryFigureReader* binaryreader = nullptr;

    cursor++;
    data_available = data_size - cursor;

    Type type = m_id_to_type_ref[figure_id];
    switch (type) {
      case Type::square:
        binaryreader = &m_square_reader;
        break;

      case Type::rectangle:
        binaryreader = &m_rectangle_reader;
        break;

      case Type::circle:
        binaryreader = &m_circle_reader;
        break;

      case Type::polygon:
        binaryreader = &m_polygon_reader;
        break;

      default:
        // TODO: handle unknown figure!
        break;
    }

    if (binaryreader != nullptr) {
      std::shared_ptr<dom::figures::Figure> figure;
      cursor += binaryreader->read(&data[cursor], data_available);
      {
        std::lock_guard<std::mutex> lock(m_queue_mutex);
        m_figure_queue.push(binaryreader->getFigure());
      }
    }

    data_available = data_size - cursor;
  }
  return cursor;
}

}  // namespace
