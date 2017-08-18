#if !defined(BINARY_DATA_FIGURES_READER_H)
#define BINARY_DATA_FIGURES_READER_H

#include <map>
#include <mutex>
#include <queue>

#include "../dom/figures/figure.h"

#include "binary_circle_reader.h"
#include "binary_figure_reader.h"
#include "binary_polygon_reader.h"
#include "binary_rectangle_reader.h"
#include "binary_square_reader.h"

namespace data_source {

class FigureQueueI {
 public:
  virtual bool isFigureQueueEmpty() = 0;
  virtual std::shared_ptr<dom::figures::Figure> popFigure() = 0;

  virtual ~FigureQueueI() {}
};

class BinaryFiguresReaderI {
 public:
  virtual uint32_t read(const char* data, const int data_size) = 0;

  virtual ~BinaryFiguresReaderI() {}
};

class BinaryDataFiguresReader : public BinaryFiguresReaderI,
                                public FigureQueueI {
 private:
  using FigureQueue = std::queue<std::shared_ptr<dom::figures::Figure>>;

  enum class Type { square, rectangle, polygon, circle };

  std::map<int, Type> m_id_to_type_ref = {{1, Type::square},
                                          {2, Type::rectangle},
                                          {3, Type::polygon},
                                          {4, Type::circle}};

  BinarySquareReader m_square_reader;
  BinaryRectangleReader m_rectangle_reader;
  BinaryCircleReader m_circle_reader;
  BinaryPolygonReader m_polygon_reader;

  std::mutex m_queue_mutex;

  FigureQueue m_figure_queue;

 public:
  BinaryDataFiguresReader(){};
  virtual ~BinaryDataFiguresReader(){};

  // inherited from FigureQueueI
  virtual std::shared_ptr<dom::figures::Figure> popFigure() override;
  virtual bool isFigureQueueEmpty() override;

  // inherited from BinaryFiguresReaderI
  uint32_t read(const char* data, const int data_size) override;
};
}

#endif
