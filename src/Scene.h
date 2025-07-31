#pragma once
#include "Figures/Figure.h"
#include <memory>
#include <vector>

class Scene {
public:
  std::vector<std::unique_ptr<Figure>> figures;
  void addFigure(std::unique_ptr<Figure> figure) {
    figures.push_back(std::move(figure));
  }
};