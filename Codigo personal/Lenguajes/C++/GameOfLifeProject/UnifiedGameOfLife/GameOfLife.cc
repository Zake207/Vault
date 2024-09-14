#include <iostream>
#include <stdarg.h>
#include <vector>

#include "lib/Cell.h"
#include "lib/CellACE.h"
#include "lib/CellLife.h"
#include "lib/FactoryCell.h"
#include "lib/Lattice.h"
#include "lib/Lattice1D.h"
#include "lib/Lattice2D.h"
#include "lib/PositionDim.h"
#include "lib/Tools.h"

int main(int argc, char *argv[]) {
  int border_type{0}, open_type{0}, dim{0};
  std::vector<int> dimensions;
  bool read_file{};
  FactoryCell *factory;
  Lattice *Lattice;
  std::string filename, cell;
  std::vector<std::string_view> args(argv + 1, argv + argc);
  for (auto i = args.begin(), end = args.end(); i != end; ++i) {
    // Lectura de la dimension del retículo.
    if (*i == "-dim") {
      ++i;
      dim = atoi(i->data());
    }
    // lectura de las dimensiones del retículo
    if (*i == "-size") {
      for (int j = 0; j < dim; ++j) {
        ++i;
        dimensions.push_back(atoi(i->data()));
      }
    }
    // Lectura de la condicion de frontera
    if (*i == "-border") {
      ++i;
      if (*i == "periodic") {
        border_type = 1;
      }
      if (*i == "open") {
        border_type = 2;
        ++i;
        open_type = atoi(i->data());
      }
      if (*i == "mirror" || *i == "reflected") {
        border_type = 3;
      }
      if (*i == "noborder") {
        border_type = 4;
      }
    }
    // Lectura del fichero de inicialización
    if (*i == "-init") {
      ++i;
      filename = *i;
      read_file = true;
    }
    // Lectura del tipo de célula.
    if (*i == "-cell") {
      ++i;
      cell = *i;
      if (*i == "Ace110") {
        factory = new FactoryCellAce110;
      }
      if (*i == "Ace30") {
        factory = new FactoryCellAce30;
      }
      if (*i == "Life23_3") {
        factory = new FactoryCellLife23_3;
      }
      if (*i == "Life51_346") {
        factory = new FactoryCellLife51_346;
      }
    }
  }
  if (read_file) {
    if (dim == 1) {
      switch (border_type) {
      case 1:
        Lattice = new Lattice1DPeriodic(filename, *factory);
        break;
      case 2:
        Lattice = new Lattice1DOpen(filename, *factory, open_type);
        break;
      case 3:
        Lattice = new Lattice1DReflective(filename, *factory);
        break;
      case 4:
        Lattice = new Lattice1DNoBorder(filename, *factory);
        break;
      default:
        std::cout << "# tipo de frontera no reconocida" << std::endl;
        break;
      }
    }
    if (dim == 2) {
      switch (border_type) {
      case 1:
        Lattice = new Lattice2DPeriodic(filename, *factory);
        break;
      case 2:
        Lattice = new Lattice2DOpen(filename, *factory, open_type);
        break;
      case 3:
        Lattice = new Lattice2DReflected(filename, *factory);
        break;
      case 4:
        Lattice = new Lattice2DNoBorder(filename, *factory);
        break;
      default:
        std::cout << "# tipo de frontera no reconocida" << std::endl;
        break;
      }
    }
  } else {
    if (dim == 1) {
      switch (border_type) {
      case 1:
        Lattice = new Lattice1DPeriodic(dimensions[0], *factory);
        break;
      case 2:
        Lattice = new Lattice1DOpen(dimensions[0], *factory, open_type);
        break;
      case 3:
        Lattice = new Lattice1DReflective(dimensions[0], *factory);
        break;
      case 4:
        Lattice = new Lattice1DNoBorder(dimensions[0], *factory);
        break;
      default:
        std::cout << "# tipo de frontera no reconocida" << std::endl;
        break;
      }
    }
    if (dim == 2) {
      switch (border_type) {
      case 1:
        Lattice = new Lattice2DPeriodic(dimensions[0], dimensions[1], *factory);
        break;
      case 2:
        Lattice = new Lattice2DOpen(dimensions[0], dimensions[1], *factory, open_type);
        break;
      case 3:
        Lattice = new Lattice2DReflected(dimensions[0], dimensions[1], *factory);
        break;
      case 4:
        Lattice = new Lattice2DNoBorder(dimensions[0], dimensions[1], *factory);
        break;
      default:
        std::cout << "# tipo de frontera no reconocida" << std::endl;
        break;
      }
    }
  }
  GameOfLife(*Lattice);
}
