#include <iostream>
#include <vector>

#ifndef __CELL_LIFE__
#define __CELL_LIFE__

#include "Cell.h"

class CellLife : public Cell {
public:
  CellLife(Position &kPosition, const State &kState)
      : Cell(kPosition, kState){};
  int GetRow() const { return GetPos()[0]; }
  int GetColum() const { return GetPos()[1]; }
  Position &GetPos() { return cell_position_; }
  Position &GetPos() const { return cell_position_; }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CellLife23_3 : public CellLife {
public:
  CellLife23_3(Position &kPosition, const State &kState)
      : CellLife(kPosition, kState) {}

  std::ostream &display(std::ostream &os) const {
    // os << "( " << cell_position_[0] << ", " << cell_position_[1] << ")";  
    os << GetState().GetChar();
    return os;
  }

  State NextState(Lattice &kLattice) const {
    State dead(0), alive(1);
    int living_cells{0};
    PositionDim<2, int> pos1(2, GetRow() - 1, GetColum() - 1);
    PositionDim<2, int> pos2(2, GetRow() - 1, GetColum());
    PositionDim<2, int> pos3(2, GetRow() - 1, GetColum() + 1);
    PositionDim<2, int> pos4(2, GetRow(), GetColum() - 1);
    PositionDim<2, int> pos5(2, GetRow(), GetColum() + 1);
    PositionDim<2, int> pos6(2, GetRow() + 1, GetColum() - 1);
    PositionDim<2, int> pos7(2, GetRow() + 1, GetColum());
    PositionDim<2, int> pos8(2, GetRow() + 1, GetColum() + 1);
    living_cells += kLattice[pos1].GetState().GetState() +
                    kLattice[pos2].GetState().GetState() +
                    kLattice[pos3].GetState().GetState() +
                    kLattice[pos4].GetState().GetState() +
                    kLattice[pos5].GetState().GetState() +
                    kLattice[pos6].GetState().GetState() +
                    kLattice[pos7].GetState().GetState() +
                    kLattice[pos8].GetState().GetState();
    // std::cout << std::endl;
    // std::cout << std::endl;
    if (GetState().GetState() == 1) {
      if (living_cells == 2 || living_cells == 3) {
        return alive;
      }
    }
    if (GetState().GetState() == 0) {
      if (living_cells == 3) {
        return alive;
      }
    }
    return dead;
  }
};


class CellLife51_346 : public CellLife {
public:
  CellLife51_346(Position &kPosition, const State &kState)
      : CellLife(kPosition, kState) {}

  std::ostream &display(std::ostream &os) const {
    os << GetState().GetState();
    return os;
  }

  State NextState(Lattice &kLattice) const {
    State dead(0), alive(1);
    int living_cells{0};
    PositionDim<2, int> pos1(2, GetRow() - 1, GetColum() - 1);
    PositionDim<2, int> pos2(2, GetRow() - 1, GetColum());
    PositionDim<2, int> pos3(2, GetRow() - 1, GetColum() + 1);
    PositionDim<2, int> pos4(2, GetRow(), GetColum() - 1);
    PositionDim<2, int> pos5(2, GetRow(), GetColum() + 1);
    PositionDim<2, int> pos6(2, GetRow() + 1, GetColum() - 1);
    PositionDim<2, int> pos7(2, GetRow() + 1, GetColum());
    PositionDim<2, int> pos8(2, GetRow() + 1, GetColum() + 1);
    living_cells += kLattice[pos1].GetState().GetState() +
                    kLattice[pos2].GetState().GetState() +
                    kLattice[pos3].GetState().GetState() +
                    kLattice[pos4].GetState().GetState() +
                    kLattice[pos5].GetState().GetState() +
                    kLattice[pos6].GetState().GetState() +
                    kLattice[pos7].GetState().GetState() +
                    kLattice[pos8].GetState().GetState();
    // std::cout << std::endl;
    // std::cout << std::endl;
    if (GetState().GetState() == 1) {
      if (living_cells == 5 || living_cells == 1) {
        return alive;
      }
    }
    if (GetState().GetState() == 0) {
      if (living_cells == 3 || living_cells == 4 || living_cells == 6) {
        return alive;
      }
    }
    return dead;
  }
};

#endif