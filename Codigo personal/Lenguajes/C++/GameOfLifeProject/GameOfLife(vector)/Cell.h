#include <iostream>
#include <vector>

#include "State.h"

#ifndef __CELL__
#define __CELL__

#include "Lattice.h"
class Lattice;

typedef int Position;

class Cell {
 public:
	// Constructors
	Cell();
	Cell(const Position kPosition, const State& kState);
	// Getters
	State GetNextState() const { return next_state_; }
	State GetState() const { return cell_state_; }
	Position GetPosition() const { return cell_position_; }
	//Setters
	//void SetPosition(const int kPosition) { cell_position_ = kPosition; }
	void SetState(const State kState) { cell_state_.SetNewState(kState.GetState()); }
	void SetNextState(const State kState) { next_state_.SetNewState(kState.GetState()); }
	// Métods
	State NextState(const Lattice& kLattice) const;
	void UpdateState();
	//operator overloading
	friend std::ostream& operator<<(std::ostream& os, Cell& kCell) {
		os << kCell.GetState().GetChar();
		return os;
	}
 private:
	Position cell_position_{0};
	State cell_state_{0};
	State next_state_{0};

};
#endif