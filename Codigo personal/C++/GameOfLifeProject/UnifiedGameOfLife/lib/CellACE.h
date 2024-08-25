#include <iostream>
#include <vector>

#ifndef __CELL_ACE__
#define __CELL_ACE__

#include "Cell.h"

class CellACE: public Cell {
 public:
	CellACE(Position& kPosition, const State& kState) : Cell(kPosition, kState) {}
	const int GetPos() const { return cell_position_[0]; }
	Position& GetPos() {return cell_position_; }
 private:
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CellACE110: public CellACE {
 public:
	CellACE110(Position& kPosition, const State& kState) : CellACE(kPosition,kState) {}

	std::ostream& display(std::ostream& os) const {
		os << GetState().GetChar();
		return os;
	}

    State NextState(Lattice& kLattice) const { 
		PositionDim<1,int> pos_L(1, GetPos() - 1);
		PositionDim<1,int> pos_C(1, GetPos());
		PositionDim<1,int> pos_R(1, GetPos() + 1);
		//std::cout << pos_L[0] << pos_C[0] << pos_R[0] << std::endl;
		int L = kLattice[pos_L].GetState().GetState();
		int C = kLattice[pos_C].GetState().GetState();
		int R = kLattice[pos_R].GetState().GetState();
		State next((C + R + C * R + L * C * R) % 2);
		return next;

	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CellACE30: public CellACE {
 public:
	CellACE30(Position& kPosition, const State& kState) : CellACE(kPosition,kState) {}

	std::ostream& display(std::ostream& os) const {
		os << GetState().GetChar();
		return os;
	}

    State NextState(Lattice& kLattice) const { 
		PositionDim<1,int> pos_L(1, GetPos() - 1);
		PositionDim<1,int> pos_C(1, GetPos());
		PositionDim<1,int> pos_R(1, GetPos() + 1);
		int L = kLattice[pos_L].GetState().GetState();
		int C = kLattice[pos_C].GetState().GetState();
		int R = kLattice[pos_R].GetState().GetState();
		State next((C + R + L + C * R) % 2);
		return next;
	}
};

#endif