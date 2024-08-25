#include <iostream>
#include <vector>

#include "Border.h"

#ifndef __LATTICE__
#define __LATTICE__

#include "Cell.h"
class Cell;

class Lattice {
public:
  // Constructors
  Lattice(const int kSize, const Border &kBorder);
  //
	// Getters
  Border GetBorder() const { return border_; }
  const Cell &GetCell(const int &kPosition) const;
  int GetSize() const { return size_; }
	// Acces method
	Cell &AccesToCell(const int &kPosition);
	// Other methods
  void NextGeneration();
  void PrintLattice();
  friend std::ostream &operator<<(std::ostream &os, Lattice &kLattice);

private:
  std::vector<Cell*> lattice_{};
  Border border_{1};
  int size_{0};
};
#endif