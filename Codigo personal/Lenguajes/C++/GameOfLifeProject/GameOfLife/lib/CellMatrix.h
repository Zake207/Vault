#include <iostream>
#include <vector>

#include "CellVector.h"

#ifndef __CELL_MATRIX__
#define __CELL_MATRIX__

class CellVector;

class CellMatrix {
public:
  // Constructors
  CellMatrix();
  CellMatrix(const int kColums, const int kRows);

  // Getters
  int GetColums() const { return colums_; }
  int GetRows() const { return rows_; }
  int GetInitialRow() const { return initial_row_; }
  int GetInitialColum() const { return initial_colum_; }

  // Matrix Modificators
  void AddUpperRow();
  void AddLowerRow();
  void AddLeftColum();
  void AddRightColum();

  void AddUpperRowAlive();
  void AddLowerRowAlive();
  void AddLeftColumAlive();
  void AddRightColumAlive();

  // Operators
  const CellVector &operator[](const int kRow) const;
  CellVector &operator[](const int kRow);
  friend std::ostream &operator<<(std::ostream &os, const CellMatrix &kMatrix);

private:
  std::vector<CellVector> matrix_;
  int initial_row_{0};
  int initial_colum_{0};
  int colums_{1};
  int rows_{1};
};
#endif