#if !defined(FIGURE_H)
#define FIGURE_H

#include <cstdint>
#include <iostream>
#include <memory>

namespace dom {
namespace figures {

class Figure {
 public:
  enum class FigureType { Square = 1, Rectangle = 2, Polygon = 3, Circle = 4 };

 protected:
  FigureType m_figure_type;

 public:
  explicit Figure(FigureType figure_type)
      : m_figure_type{figure_type} {/*std::cout << "ctor" << std::endl;*/};

  virtual ~Figure(){};

  const FigureType getType() const { return m_figure_type; };
};

class FigureBuilderI {
 public:
  virtual std::shared_ptr<Figure> build() = 0;

  virtual ~FigureBuilderI() {}
};
}
}  // namespaces

#endif
