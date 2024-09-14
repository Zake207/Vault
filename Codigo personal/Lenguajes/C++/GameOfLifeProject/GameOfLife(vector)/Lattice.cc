#include <iostream>
#include <vector>

#include "Border.h"
#include "Lattice.h"
// #include "Cell.h"

/// @brief Constructor of the class.
/// @param kSize The size that the vector will have.
/// @param kBorder The border condition that the lattice will have.
Lattice::Lattice(const int kSize, const Border &kBorder) {
  lattice_.resize(kSize);
  size_ = kSize;
  border_ = kBorder;
  State alive_state(1), dead_state(0);
  for (int i = 0; i < size_; ++i) {
    lattice_[i] = new Cell(i + 1, dead_state);
  }
  lattice_[lattice_.size() / 2]->SetState(alive_state);
}

/// @brief Calculate the next state of the cells int the lattice
void Lattice::NextGeneration() {
  // First cicle: Each cell in the lattice look its neighborhood
  // to calculate the next state
  for (int i = 0; i < GetSize(); ++i) {
    // std::cout << i << std::endl;
    AccesToCell(i + 1).SetNextState(GetCell(i + 1).NextState(*this));
  }
  // Second cicle: Each cell updates its state
  for (int i = 0; i < GetSize(); ++i) {
    AccesToCell(i + 1).UpdateState();
  }
}

const Cell &Lattice::GetCell(const int &kPosition) const {
  return *lattice_[kPosition - 1];
}
Cell &Lattice::AccesToCell(const int &kPosition) {
  return *lattice_[kPosition - 1];
}

/// @brief Method used to print the lattice
void Lattice::PrintLattice() {
  for (int i = 0; i < lattice_.size(); ++i) {
    std::cout << *lattice_[i];
  }
}

 std::ostream &operator<<(std::ostream &os, Lattice &kLattice) {
    kLattice.PrintLattice();
    return os;
  }