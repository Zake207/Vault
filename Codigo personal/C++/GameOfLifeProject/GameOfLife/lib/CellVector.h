#include <iostream>
#include <vector>

#ifndef __CELL_VECTOR__
#define __CELL_VECTOR__

#include "Cell.h"
class Cell;

class CellVector {
public:
  //Constructores
  CellVector(const int kSize, const int kRow, const int kInitial);
  // Getters
  int GetSize() const { return size_; }
  int GetInitial() const { return initial_position_; }
  int GetRow() const { return row_; }
  const Cell &GetCell(const int kPosition = 0) { return this->operator[](kPosition - initial_position_); }
  // Inline Modifiers
  void DecrementInitial() { --initial_position_; }
  Cell &AccesToCell(const int kPosition = 0) { return this->operator[](kPosition - initial_position_); }
  // Size Pushers
  void Push_front();
  void Push_back();
  void Push_front_alive();
  void Push_back_alive();
  // Operators
  const Cell &operator[](const int kPosition) const;
  Cell &operator[](const int kPosition);
  friend std::ostream &operator<<(std::ostream &os, const CellVector &kVector);

private:
  int initial_position_{0};
  std::vector<Cell *> vector_{};
  int size_{1};
  int row_{0};
};

#endif