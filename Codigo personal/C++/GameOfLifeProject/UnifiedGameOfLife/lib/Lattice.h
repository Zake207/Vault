#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#ifndef __LATTICE__
#define __LATTICE__

#include "Cell.h"
class Cell;
class FactoryCell;

class Lattice {
public:
  Lattice(const FactoryCell& kFactory) : factory_{kFactory} {}
  virtual ~Lattice() = 0;
  Lattice(const std::string& kFilename, const FactoryCell& kFactory) : factory_(kFactory) {
    // Inicialización de valores
    std::fstream file(kFilename);
    int size{0};
    std::string line;
    // Capturo la dimensión
    file >> dimension_;
    dimensions_.reserve(dimension_);
    // Al usar eloperador >> este se queda en el final de la linea por lo que lo siguiente que capará será el \n de esta
    getline(file, line);
    // Leo las dimensiones del reticulo.
    int pivot_int;
    for (int i = 0; i < dimension_; ++i) {
      file >> pivot_int;
      dimensions_[i] = pivot_int;
    }
  }
  std::vector<int>& GetDimensions() {return dimensions_;}
  const int GetDimension() { return dimension_;}
  virtual Cell& operator[](const Position&) = 0;
  virtual void nextGeneration() = 0;
  virtual std::size_t Population() const = 0;
  virtual std::ostream& display(std::ostream& os) const = 0;
  friend std::ostream& operator<<(std::ostream& os, const Lattice& kLattice) {
    kLattice.display(os);
    return os;
  }
  virtual void SaveGeneration() = 0;
protected:
  const FactoryCell& factory_;
  int dimension_{1};
  std::vector<int> dimensions_;
  
};

Lattice::~Lattice() {
  std::cout << "Destruyendo Lattice..." << std::endl;
}

#endif

