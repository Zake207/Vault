#include <iostream>
#include <vector>

#include "../lib/CellVector.h"

/// @brief Main constructor of the class
/// @param kSize Size of the vector
/// @param kRow The respective row of the vector
/// @param kInitial The first position of the vector, this could be negative or positive
CellVector::CellVector(const int kSize, const int kRow, const int kInitial) {
  size_ = kSize;
  row_ = kRow;
  initial_position_ = kInitial;
  vector_.resize(kSize);
  State dead_state(0);
  for (int i = 0; i < kSize; ++i) {
    std::pair<int, int> position(kRow, i + GetInitial());
    vector_[i] = new Cell(position, dead_state);
  }
}

/// @brief Inserts a dead cell in the left side of the vector, this cell will have (initial position - 1)
///        as its position.
void CellVector::Push_front() {
  State dead(0);
  --initial_position_;
  std::pair<int, int> position(GetRow(), initial_position_);
  vector_.insert(vector_.begin(), new Cell(position, dead));
  ++size_;
}

/// @brief Inserts a dead cell in the right side of the vector.
void CellVector::Push_back() {
  State dead(0);
  std::pair<int, int> position(GetRow(), GetSize() + GetInitial());
  vector_.push_back(new Cell(position, dead));
  ++size_;
}

/// @brief Inserts a living cell in the left side of the vector, this cell will have (initial position - 1)
///        as its position.
void CellVector::Push_front_alive() {
  State dead(1);
  --initial_position_;
  std::pair<int, int> position(GetRow(), initial_position_);
  vector_.insert(vector_.begin(), new Cell(position, dead));
  ++size_;
}

/// @brief Inserts a living cell in the right side of the vector.
void CellVector::Push_back_alive() {
  State dead(1);
  std::pair<int, int> position(GetRow(), GetSize() + GetInitial());
  vector_.push_back(new Cell(position, dead));
  ++size_;
}

/// @brief The access operator of the class
/// @param kPosition The position of the cell that is wanted
/// @return A const reference of the cell, depending if the client want to modify the cell.
const Cell &CellVector::operator[](const int kPosition) const {
  if (kPosition >= initial_position_ && kPosition <= this->size_ - 1 + GetInitial()) {
    return *vector_[kPosition - GetInitial()];
  } if (kPosition < initial_position_) {
      int pos{size_ - 1};
      if( GetInitial() < 0) { pos + GetInitial();}
      return *vector_[pos];
  } else {
    return *vector_[0];
  }
}

/// @brief The access operator of the class
/// @param kPosition The position of the cell that is wanted
/// @return A reference of the cell, depending if the client want to modify the cell.
Cell &CellVector::operator[](const int kPosition) {
  if (kPosition >= initial_position_ && kPosition <= this->size_ - 1 + GetInitial()) {
    return *vector_[kPosition - GetInitial()];
  } if (kPosition < initial_position_) {
      int pos{size_ - 1};
      if( GetInitial() < 0) { pos + GetInitial();}
      return *vector_[pos];
  } else {
    return *vector_[0];
  }
}


/// @brief The output operator
/// @param os The ostream object returned
/// @param kVector The object that will be printed
/// @return Once the Vector is printed, this method returns an ostream reference.
std::ostream &operator<<(std::ostream &os, const CellVector &kVector) {
  for (int i = kVector.GetInitial(), j = kVector.GetSize(); j > 0; ++i, --j) {
    //std::cout << kVector[i].GetPositionX() << "," << kVector[i].GetPositionY() << "  ";
    std::cout << kVector[i] << "  ";
  }
  std::cout << std::endl;
  return os;
}