#include <iostream>
#include <vector>

#ifndef __LATTICE__
#define __LATTICE__

#include "Border.h"
#include "Cell.h"
#include "CellMatrix.h"
class Cell;


class Lattice {
public:
  // Constructors
  Lattice(const int kRows, const int kColums, const Border &kBorder);
  Lattice(const int kRows, const int kColums);
  Lattice(const std::string& kFilename);
	// Getters
  const int GetOriginRow() const { return original_row_; }
  const int GetOriginColum() const { return original_colum_; }
  const Border &GetBorder() const { return border_; }
  const CellMatrix &GetMatrix() const { return lattice_; } 
	// Acces method
	CellMatrix &AccesToMatrix() { return lattice_; };
	// Other methods
  void NextGeneration();
  int CheckCell(const int kPos_x, const int kPos_y) const;
  int Population() const;
  void CheckBorders();
  void MirrorBorders();
  //Operators
  Cell &operator[](const std::pair<int,int>& kPosition);
  friend std::ostream &operator<<(std::ostream &os, Lattice &kLattice);

private:
  CellMatrix lattice_;
  Border border_;
  int original_row_{1};
  int original_colum_{1};
};
#endif