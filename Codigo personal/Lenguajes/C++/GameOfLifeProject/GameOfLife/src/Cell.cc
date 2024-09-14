#include <iostream>
#include <vector>

#include "../lib/Cell.h"
#include "../lib/Lattice.h"
#include "../lib/State.h"

/// @brief Default constructor of the class
Cell::Cell() {
  cell_position_.first = 0;
  cell_position_.second = 0;
}

/// @brief Conatructor of the class
/// @param kPosition Position of the cell
/// @param kState State of the cell
Cell::Cell(const std::pair<int, int> &kPosition, const State &kState) {
  cell_position_ = kPosition;
  cell_state_.SetNewState(kState.GetState());
}

/// @brief Calculate the next state of the cell based on the lattice provided
/// @param kLattice The lattice where the cell lives
/// @return Return the next state
State Cell::NextState(const Lattice &kLattice) const {
  State dead(0), alive(1);
  int living_cells{0};
  int pos_x{GetPositionX()},
      pos_y{GetPositionY()}; // POSICION DE LA CELULA CENTRAL
  if (kLattice.GetBorder().GetBorderType() == 1) { // PERIODICO
    living_cells =
        kLattice.GetMatrix()[pos_x - 1][pos_y - 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x - 1][pos_y].GetState().GetState() +
        kLattice.GetMatrix()[pos_x - 1][pos_y + 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x][pos_y - 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x][pos_y + 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x + 1][pos_y - 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x + 1][pos_y].GetState().GetState() +
        kLattice.GetMatrix()[pos_x + 1][pos_y + 1].GetState().GetState();
  }
  if (kLattice.GetBorder().GetBorderType() == 2) { // Abierto
    if (kLattice.GetBorder().GetOpenType() == 1) { // Frio
      living_cells =
          kLattice.GetMatrix()[pos_x - 1][pos_y - 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x - 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x - 1][pos_y + 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y - 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y + 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y - 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y + 1].GetState().GetState();
    }
    if (kLattice.GetBorder().GetOpenType() == 2) { // Caliente
      living_cells =
          kLattice.GetMatrix()[pos_x - 1][pos_y - 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x - 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x - 1][pos_y + 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y - 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y + 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y - 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y + 1].GetState().GetState();
    }
  }
  if (kLattice.GetBorder().GetBorderType() == 3) {
    // ESQUINA SUPERIOR IZQUIERDA
    if (pos_x == 0 && pos_y == 0) {
      living_cells =
          kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y + 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y + 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y + 1].GetState().GetState();
    }
    // ESQUINA SUPERIOR DERECHA
    if (pos_x == 0 && pos_y == kLattice.GetOriginColum() - 1) {
      living_cells =
      kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
      kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
      kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
      kLattice.GetMatrix()[pos_x][pos_y - 1].GetState().GetState() +
      kLattice.GetMatrix()[pos_x][pos_y - 1].GetState().GetState() +
      kLattice.GetMatrix()[pos_x + 1][pos_y].GetState().GetState() +
      kLattice.GetMatrix()[pos_x + 1][pos_y].GetState().GetState() +
      kLattice.GetMatrix()[pos_x + 1][pos_y - 1].GetState().GetState();
    }
    // ESQUINA INFERIOR IZQUIERDA
    if (pos_x == kLattice.GetOriginRow() - 1 && pos_y == 0) {
      living_cells = 
      kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
      kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
      kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
      kLattice.GetMatrix()[pos_x - 1][pos_y].GetState().GetState() +
      kLattice.GetMatrix()[pos_x - 1][pos_y].GetState().GetState() +
      kLattice.GetMatrix()[pos_x][pos_y + 1].GetState().GetState() +
      kLattice.GetMatrix()[pos_x][pos_y + 1].GetState().GetState() +
      kLattice.GetMatrix()[pos_x - 1][pos_y + 1].GetState().GetState();
    }
    // ESQUINA INFERIOR DERECHA
    if (pos_x == kLattice.GetOriginRow() - 1 && pos_y == kLattice.GetOriginColum() - 1) {
          living_cells = 
          kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x - 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x - 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y - 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y - 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x - 1][pos_y - 1].GetState().GetState();
    }
    // BORDE ARRIBA
    if (pos_x == 0 && (pos_y > 0 && pos_y < kLattice.GetOriginRow())) {
      living_cells = 
      kLattice.GetMatrix()[pos_x][pos_y - 1].GetState().GetState() + 
      kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
      kLattice.GetMatrix()[pos_x][pos_y + 1].GetState().GetState() +
      kLattice.GetMatrix()[pos_x][pos_y - 1].GetState().GetState() +
      kLattice.GetMatrix()[pos_x][pos_y + 1].GetState().GetState() +
      kLattice.GetMatrix()[pos_x + 1][pos_y - 1].GetState().GetState() +
      kLattice.GetMatrix()[pos_x + 1][pos_y].GetState().GetState() +
      kLattice.GetMatrix()[pos_x + 1][pos_y + 1].GetState().GetState();
    }

    // BORDE ABAJO
    if (pos_x == kLattice.GetOriginRow() - 1 && (pos_y > 0 && pos_y < kLattice.GetOriginColum())) {
          living_cells = 
      kLattice.GetMatrix()[pos_x][pos_y - 1].GetState().GetState() + 
      kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
      kLattice.GetMatrix()[pos_x][pos_y + 1].GetState().GetState() +
      kLattice.GetMatrix()[pos_x][pos_y - 1].GetState().GetState() +
      kLattice.GetMatrix()[pos_x][pos_y + 1].GetState().GetState() +
      kLattice.GetMatrix()[pos_x - 1][pos_y - 1].GetState().GetState() +
      kLattice.GetMatrix()[pos_x - 1][pos_y].GetState().GetState() +
      kLattice.GetMatrix()[pos_x - 1][pos_y + 1].GetState().GetState();
    }
    // BORDE IZQUIRDA
    if ((pos_x > 0 && pos_x < kLattice.GetOriginRow()) && pos_y == 0) {
      living_cells =
          kLattice.GetMatrix()[pos_x - 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x - 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x - 1][pos_y + 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y + 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y + 1].GetState().GetState();
    }
    // BORDE DERECHA
    if (pos_x > 0 && pos_x < kLattice.GetOriginRow() && pos_y == kLattice.GetOriginColum() - 1) {
      living_cells =
          kLattice.GetMatrix()[pos_x - 1][pos_y - 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y - 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y - 1].GetState().GetState() +
          kLattice.GetMatrix()[pos_x - 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x - 1][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x][pos_y].GetState().GetState() +
          kLattice.GetMatrix()[pos_x + 1][pos_y].GetState().GetState();
    }
    // NORMAL
    if (pos_x > 0 && pos_x < kLattice.GetOriginRow() && pos_y > 0 && kLattice.GetOriginColum()) {
          living_cells =
        kLattice.GetMatrix()[pos_x - 1][pos_y - 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x - 1][pos_y].GetState().GetState() +
        kLattice.GetMatrix()[pos_x - 1][pos_y + 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x][pos_y - 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x][pos_y + 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x + 1][pos_y - 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x + 1][pos_y].GetState().GetState() +
        kLattice.GetMatrix()[pos_x + 1][pos_y + 1].GetState().GetState();
    }
  }
  if (kLattice.GetBorder().GetBorderType() == 4) {
    living_cells =
        kLattice.GetMatrix()[pos_x - 1][pos_y - 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x - 1][pos_y].GetState().GetState() +
        kLattice.GetMatrix()[pos_x - 1][pos_y + 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x][pos_y - 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x][pos_y + 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x + 1][pos_y - 1].GetState().GetState() +
        kLattice.GetMatrix()[pos_x + 1][pos_y].GetState().GetState() +
        kLattice.GetMatrix()[pos_x + 1][pos_y + 1].GetState().GetState();
  }
  if (GetState().GetState() == 1) {
    if (living_cells == 2 || living_cells == 3) {
      return alive;
    } else {
      return dead;
    }
  } else {
    if (living_cells == 3) {
      return alive;
    } else {
      return dead;
    }
  }
}

/// @brief Update the the state of the cell based on the next state calculated
/// before
void Cell::UpdateState() { cell_state_.SetNewState(next_state_.GetState()); }