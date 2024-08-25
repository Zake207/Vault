#include <iostream>
#include <vector>

#include "../lib/CellMatrix.h"

/// @brief Default constructor of the class
CellMatrix::CellMatrix() {
  colums_ = 1;
  rows_ = 1;
  for (int i = 0; i < colums_; ++i) {
    CellVector vector(colums_, i, 0);
    matrix_.emplace_back(vector);
  }
}

/// @brief Main constructor of the class
/// @param kColums The number of colums that the matrix will have
/// @param kRows The number of rows that the matrix will have
CellMatrix::CellMatrix(const int kColums, const int kRows) {
  colums_ = kColums;
  rows_ = kRows;
  for (int i = 0; i < colums_; ++i) {
    CellVector vector(colums_, i, 0);
    matrix_.emplace_back(vector);
  }
}

/// @brief Adds an additional row on top of the matrix, all the cells will be dead.
void CellMatrix::AddUpperRow() {
  --initial_row_;
  CellVector row(GetColums(), GetInitialRow(), GetInitialColum());
  matrix_.insert(matrix_.begin(), row);
  ++rows_;
}

/// @brief Adds an additional row above the matrix, all the cells will be dead.
void CellMatrix::AddLowerRow() {
  CellVector row(GetColums(), GetRows() + GetInitialRow(), GetInitialColum());
  matrix_.push_back(row);
  ++rows_;
}

/// @brief Adds an additional colum at the left side of the matrix, all the cells will be dead.
void CellMatrix::AddLeftColum() {
  --initial_colum_;
  ++colums_;
  for (int i = 0; i < matrix_.size(); ++i) {
    matrix_[i].Push_front();
  }
}

/// @brief Adds an additional colum at the right side of the matrix, all the cells will be dead.
void CellMatrix::AddRightColum() {
  ++colums_;
  for (int i = 0; i < matrix_.size(); ++i) {
    matrix_[i].Push_back();
  }
}

/// @brief Adds an additional row on top of the matrix, all the cells will be alive.
void CellMatrix::AddUpperRowAlive() {
  --initial_row_;
  State alive(1);
  CellVector row(GetColums(), GetInitialRow(), GetInitialColum());
  for (int i = 0; i < row.GetSize(); ++i) {
    row[i].SetState(alive);
  }
  matrix_.insert(matrix_.begin(), row);
  ++rows_;
}

/// @brief Adds an additional row above the matrix, all the cells will be alive.
void CellMatrix::AddLowerRowAlive() {
  State alive(1);
  CellVector row(GetColums(), GetRows() + GetInitialRow(), GetInitialColum());
  for (int i = 0; i < row.GetSize(); ++i) {
    row[i].SetState(alive);
  }
  matrix_.push_back(row);
  ++rows_;
}

/// @brief Adds an additional colum at the left side of the matrix, all the cells will be alive.
void CellMatrix::AddLeftColumAlive() {
  --initial_colum_;
  ++colums_;
  for (int i = 0; i < matrix_.size(); ++i) {
    matrix_[i].Push_front_alive();
  }
}

/// @brief Adds an additional colum at the right side of the matrix, all the cells will be alive.
void CellMatrix::AddRightColumAlive() {
  ++colums_;
  for (int i = 0; i < matrix_.size(); ++i) {
    matrix_[i].Push_back_alive();
  }
}

/// @brief The acces operator of the class
/// @param kRow The row that want to be accessed
/// @return A const reference to the row, that is a CellVector object
const CellVector &CellMatrix::operator[](const int kRow) const {
  if (kRow >= initial_row_ && kRow <= GetRows() - 1 + GetInitialRow()) {
    return matrix_[kRow - GetInitialRow()];
  } if (kRow < initial_row_) {
    int static_row{rows_ - 1};
    if (GetInitialRow() < 0) { static_row + GetInitialRow();}
    return matrix_[static_row];
  } else {
    return matrix_[0];
  }
}

/// @brief The acces operator of the class
/// @param kRow The row that want to be accessed
/// @return A reference to the row, that is a CellVector object
CellVector &CellMatrix::operator[](const int kRow) {
  if (kRow >= initial_row_ && kRow <= GetRows() - 1 + GetInitialRow()) {
    return matrix_[kRow - GetInitialRow()];
  } if (kRow < initial_row_) {
    int static_row{rows_ - 1};
    if (GetInitialRow() < 0) { static_row + GetInitialRow();}
    return matrix_[static_row];
  } else {
    return matrix_[0];
  }
}

/// @brief The out put operator of the class
/// @param os An ostream object passed by reference
/// @param kMatrix The object that will be printed
/// @return A reference to the ostream object os passed by reference
std::ostream &operator<<(std::ostream &os, const CellMatrix &kMatrix) {
  for (int i = kMatrix.GetInitialRow(), j = kMatrix.GetRows(); j > 0;
       ++i, --j) {
    std::cout << kMatrix[i];
  }
  std::cout << std::endl;
  return os;
}