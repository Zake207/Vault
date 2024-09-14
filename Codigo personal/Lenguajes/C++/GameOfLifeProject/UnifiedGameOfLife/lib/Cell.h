#include <iostream>
#include <vector>

#ifndef __CELL__
#define __CELL__

#include "State.h"
#include "Position.h"
#include "PositionDim.h"
#include "Lattice.h"

class Lattice;

class Cell {
 public:
	// Constructors
	Cell(Position& kPosition, const State& kState) : cell_position_(kPosition), cell_state_(kState) {}
	// Getters
	State GetState() const { return cell_state_; }
	State GetNextState() const { return next_state_; }
	virtual Position& GetPos() = 0; 
	//Setters
	//void SetPosition(const int kPosition) { cell_position_ = kPosition; }
	void SetState(const State kState) { cell_state_.SetNewState(kState.GetState()); }
	void SetNextState(const State kState) { next_state_.SetNewState(kState.GetState()); }
	
	// Métods
	virtual State NextState(Lattice& kLattice) const = 0;
	virtual void UpdateState() { cell_state_.SetNewState(next_state_.GetState()); }
	//operator overloading
	friend std::ostream& operator<<(std::ostream& os,const Cell& kCell) {
        kCell.display(os);
		return os;
	}
	virtual std::ostream& display(std::ostream&) const = 0;
 protected:
	Position& cell_position_;
	State cell_state_{0};
	State next_state_{0};

};


#endif