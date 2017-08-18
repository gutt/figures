#include "gtest/gtest.h"

#include <iostream>

#include "../../main/data_source/binary_circle_reader.h"
#include "../../main/data_source/binary_data_figures_reader.h"
#include "../../main/data_source/binary_polygon_reader.h"
#include "../../main/data_source/binary_rectangle_reader.h"
#include "../../main/data_source/binary_square_reader.h"
#include "../../main/dom/figures/rectangle.h"
#include "../../main/dom/figures/square.h"
#include <memory>

TEST(SquareBinaryReader, Builder) {
  using namespace dom::figures;
  using namespace std;

  char data[] = {5, 5, 10};

  data_source::BinarySquareReader sr;

  auto bytes_read = sr.read(data, sizeof(data));
  std::shared_ptr<Square> square =
      std::dynamic_pointer_cast<Square>(sr.getFigure());

  EXPECT_EQ(bytes_read, sizeof(data));

  EXPECT_EQ(square->getPosition().getX(), 5);
  EXPECT_EQ(square->getPosition().getY(), 5);
  EXPECT_EQ(square->getLength(), 10);
}

TEST(RectangleBinaryReader, Builder) {
  using namespace dom::figures;
  using namespace std;

  char data[] = {5, 5, 10, 10};

  data_source::BinaryRectangleReader sr;

  auto bytes_read = sr.read(data, sizeof(data));
  std::shared_ptr<Rectangle> rectangle =
      std::dynamic_pointer_cast<Rectangle>(sr.getFigure());

  EXPECT_EQ(bytes_read, sizeof(data));

  EXPECT_EQ(rectangle->getPosition().getX(), 5);
  EXPECT_EQ(rectangle->getPosition().getY(), 5);
  EXPECT_EQ(rectangle->getWidth(), 10);
  EXPECT_EQ(rectangle->getHeight(), 10);
}

TEST(PolygonBinaryReader, Builder) {
  using namespace dom::figures;
  using namespace std;

  char data[] = {5, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0};

  data_source::BinaryFigureReader* sr = new data_source::BinaryPolygonReader();

  auto bytes_read = sr->read(data, sizeof(data));
  std::shared_ptr<Polygon> polygon =
      std::dynamic_pointer_cast<Polygon>(sr->getFigure());
  delete sr;

  EXPECT_EQ(bytes_read, sizeof(data));

  EXPECT_EQ(polygon->getVerticles().at(1).getX(), 0);
  EXPECT_EQ(polygon->getVerticles().at(1).getY(), 10);
  EXPECT_EQ(polygon->getVerticles().at(2).getX(), 10);
  EXPECT_EQ(polygon->getVerticles().at(2).getY(), 10);
  EXPECT_EQ(polygon->getVerticles().at(4).getX(), 0);
  EXPECT_EQ(polygon->getVerticles().at(4).getY(), 0);
}

TEST(CircleBinaryReader, Builder) {
  using namespace dom::figures;
  using namespace std;

  char data[] = {10, 10, 15};

  data_source::BinaryFigureReader* sr = new data_source::BinaryCircleReader();

  auto bytes_read = sr->read(data, sizeof(data));
  std::shared_ptr<Circle> circle =
      std::dynamic_pointer_cast<Circle>(sr->getFigure());
  delete sr;

  EXPECT_EQ(bytes_read, sizeof(data));
  EXPECT_EQ(circle->getPosition().getX(), 10);
  EXPECT_EQ(circle->getPosition().getY(), 10);
  EXPECT_EQ(circle->getRadius(), 15);
}

TEST(BinaryDataFiguresReader, Builder) {
  using namespace dom::figures;
  using namespace std;

  char data[] = {1, 5,  5,  10, 2,  5, 5, 10, 10, 3,  5,  0, 0,
                 0, 10, 10, 10, 10, 0, 0, 0,  4,  10, 10, 15};

  data_source::BinaryDataFiguresReader* sr =
      new data_source::BinaryDataFiguresReader();

  auto bytes_read = sr->read(data, sizeof(data));

  while (!sr->isFigureQueueEmpty()) {
    shared_ptr<Figure> figure = sr->popFigure();

    auto type = figure->getType();

    switch (type) {
      case Figure::FigureType::Square: {
        std::shared_ptr<Square> square =
            std::dynamic_pointer_cast<Square>(figure);

        EXPECT_EQ(square->getPosition().getX(), 5);
        EXPECT_EQ(square->getPosition().getY(), 5);
        EXPECT_EQ(square->getLength(), 10);
      } break;

      case Figure::FigureType::Rectangle: {
        std::shared_ptr<Rectangle> rectangle =
            std::dynamic_pointer_cast<Rectangle>(figure);

        EXPECT_EQ(rectangle->getPosition().getX(), 5);
        EXPECT_EQ(rectangle->getPosition().getY(), 5);
        EXPECT_EQ(rectangle->getWidth(), 10);
        EXPECT_EQ(rectangle->getHeight(), 10);
      } break;

      case Figure::FigureType::Circle: {
        std::shared_ptr<Circle> circle =
            std::dynamic_pointer_cast<Circle>(figure);

        EXPECT_EQ(circle->getPosition().getX(), 10);
        EXPECT_EQ(circle->getPosition().getY(), 10);
        EXPECT_EQ(circle->getRadius(), 15);
      } break;
      case Figure::FigureType::Polygon: {
        std::shared_ptr<Polygon> polygon =
            std::dynamic_pointer_cast<Polygon>(figure);

        EXPECT_EQ(polygon->getVerticles().at(1).getX(), 0);
        EXPECT_EQ(polygon->getVerticles().at(1).getY(), 10);
        EXPECT_EQ(polygon->getVerticles().at(2).getX(), 10);
        EXPECT_EQ(polygon->getVerticles().at(2).getY(), 10);
        EXPECT_EQ(polygon->getVerticles().at(4).getX(), 0);
        EXPECT_EQ(polygon->getVerticles().at(4).getY(), 0);
      } break;
      default:
        break;
    }
  }
  EXPECT_EQ(bytes_read, sizeof(data));

  delete sr;
}
