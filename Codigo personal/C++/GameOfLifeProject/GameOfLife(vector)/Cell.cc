#include <iostream>
#include <vector>

#include "Cell.h"
#include "Lattice.h"
#include "State.h"

/// @brief Default constructor of the class
Cell::Cell() { cell_position_ = 0; }

/// @brief Conatructor of the class
/// @param kPosition Position of the cell
/// @param kState State of the cell
Cell::Cell(const Position kPosition, const State &kState) {
  cell_position_ = kPosition;
  cell_state_.SetNewState(kState.GetState());
}

/// @brief Calculate the next state of the cell based on the lattice provided
/// @param kLattice The lattice where the cell lives
/// @return Return ne next state
State Cell::NextState(const Lattice &kLattice) const {
  State next_state(0);
  if (kLattice.GetBorder().GetBorderType() == 1) {
    // std::cout << "periodic";
    if (GetPosition() == 1) {
      State C(GetState().GetState());
      State R(kLattice.GetCell(GetPosition() + 1).GetState().GetState());
      State L(kLattice.GetCell(kLattice.GetSize()).GetState().GetState());
      next_state.SetNewState((C.GetState() + R.GetState() +
                             C.GetState() * R.GetState() +
                             L.GetState() * C.GetState() * R.GetState())%2);
      // next_state_.SetNewState(next_state.GetState());
    }
    if (GetPosition() == kLattice.GetSize()) {
      State C(GetState().GetState());
      State R(kLattice.GetCell(1).GetState().GetState());
      State L(kLattice.GetCell(GetPosition() - 1).GetState().GetState());
      next_state.SetNewState((C.GetState() + R.GetState() +
                             C.GetState() * R.GetState() +
                             L.GetState() * C.GetState() * R.GetState())%2);
      // next_state_.SetNewState(next_state.GetState());
    }
    if ((GetPosition() > 1) && (GetPosition() < kLattice.GetSize())) {
      State C(GetState().GetState());
      State R(kLattice.GetCell(GetPosition() + 1).GetState().GetState());
      State L(kLattice.GetCell(GetPosition() - 1).GetState().GetState());
      next_state.SetNewState((C.GetState() + R.GetState() +
                             C.GetState() * R.GetState() +
                             L.GetState() * C.GetState() * R.GetState())%2);
      // next_state_.SetNewState(next_state.GetState());
    }
  }
  if (kLattice.GetBorder().GetBorderType() == 2) {
    if (kLattice.GetBorder().GetOpenType() == 1) { // Frio
      if (GetPosition() == 1) {
        State C(GetState().GetState());
        State R(kLattice.GetCell(1).GetState().GetState());
        State L(0);
        next_state.SetNewState((C.GetState() + R.GetState() +
                               C.GetState() * R.GetState() +
                               L.GetState() * C.GetState() * R.GetState())%2);
      }
      if (GetPosition() == kLattice.GetSize()) {
        State C(GetState().GetState());
        State R(0);
        State L(kLattice.GetCell(GetPosition() - 1).GetState().GetState());
        next_state.SetNewState((C.GetState() + R.GetState() +
                               C.GetState() * R.GetState() +
                               L.GetState() * C.GetState() * R.GetState())%2);
      }
      if ((GetPosition() > 1) && (GetPosition() < kLattice.GetSize())) {
        State C(GetState().GetState());
        State R(kLattice.GetCell(GetPosition() + 1).GetState().GetState());
        State L(kLattice.GetCell(GetPosition() - 1).GetState().GetState());
        next_state.SetNewState((C.GetState() + R.GetState() +
                               C.GetState() * R.GetState() +
                               L.GetState() * C.GetState() * R.GetState())%2);
      }
    }
    if (kLattice.GetBorder().GetOpenType() == 2) { // Caliente
      if (GetPosition() == 1) {
        State C(GetState().GetState());
        State R(kLattice.GetCell(1).GetState().GetState());
        State L(1);
        next_state.SetNewState((C.GetState() + R.GetState() +
                               C.GetState() * R.GetState() +
                               L.GetState() * C.GetState() * R.GetState())%2);
      }
      if (GetPosition() == kLattice.GetSize()) {
        State C(GetState().GetState());
        State R(1);
        State L(kLattice.GetCell(GetPosition() - 1).GetState().GetState());
        next_state.SetNewState((C.GetState() + R.GetState() +
                               C.GetState() * R.GetState() +
                               L.GetState() * C.GetState() * R.GetState())%2);
      }
      if ((GetPosition() > 1) && (GetPosition() < kLattice.GetSize())) {
        State C(GetState().GetState());
        State R(kLattice.GetCell(GetPosition() + 1).GetState().GetState());
        State L(kLattice.GetCell(GetPosition() - 1).GetState().GetState());
        next_state.SetNewState((C.GetState() + R.GetState() +
                               C.GetState() * R.GetState() +
                               L.GetState() * C.GetState() * R.GetState())%2);
      }
    }
  }
  if (kLattice.GetBorder().GetBorderType() == 3) {
    if (GetPosition() == 1) {
      State C(GetState().GetState());
      State R(kLattice.GetCell(GetPosition() + 1).GetState().GetState());
      State L(GetState().GetState());
      next_state.SetNewState((C.GetState() + R.GetState() +
                               C.GetState() * R.GetState() +
                               L.GetState() * C.GetState() * R.GetState())%2);
    }
    if (GetPosition() == kLattice.GetSize()) {
      State C(GetState().GetState());
      State R(GetState().GetState());
      State L(kLattice.GetCell(GetPosition() - 1).GetState().GetState());
      next_state.SetNewState((C.GetState() + R.GetState() +
                               C.GetState() * R.GetState() +
                               L.GetState() * C.GetState() * R.GetState())%2);
    }
    if ((GetPosition() > 1) && (GetPosition() < kLattice.GetSize())) {
      State C(GetState().GetState());
      State R(kLattice.GetCell(GetPosition() + 1).GetState().GetState());
      State L(kLattice.GetCell(GetPosition() - 1).GetState().GetState());
      next_state.SetNewState((C.GetState() + R.GetState() +
                               C.GetState() * R.GetState() +
                               L.GetState() * C.GetState() * R.GetState())%2);
    }
  }
  return next_state;
}

/// @brief Update the the state of the cell based on the next state calculated
/// before
void Cell::UpdateState() { cell_state_.SetNewState(next_state_.GetState()); }