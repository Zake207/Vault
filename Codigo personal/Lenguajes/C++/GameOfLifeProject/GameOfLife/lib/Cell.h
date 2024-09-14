#include <iostream>
#include <vector>

#ifndef __CELL__
#define __CELL__

#include "State.h"
#include "Lattice.h"

class Lattice;

class Cell {
 public:
	// Constructors
	Cell();
	Cell(const std::pair<int,int>& kPosition, const State& kState);
	// Getters
	State GetNextState() const { return next_state_; }
	State GetState() const { return cell_state_; }
	int GetPositionX() const { return cell_position_.first; }
	int GetPositionY() const { return cell_position_.second; }	
	//Setters
	//void SetPosition(const int kPosition) { cell_position_ = kPosition; }
	void SetState(const State kState) { cell_state_.SetNewState(kState.GetState()); }
	void SetNextState(const State kState) { next_state_.SetNewState(kState.GetState()); }
	// Métods
	State NextState(const Lattice& kLattice) const;
	void UpdateState();
	//operator overloading
	friend std::ostream& operator<<(std::ostream& os,const Cell& kCell) {
		os << kCell.GetState().GetChar();
		return os;
	}
 private:
	std::pair<int,int> cell_position_{0, 0};
	State cell_state_{0};
	State next_state_{0};

};
#endif