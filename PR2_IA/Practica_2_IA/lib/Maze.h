#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#pragma once

#include "Nodo.h"

using namespace std;

class Maze {
 public:
	Maze(fstream &file);
	const pair<int,int> &getStartCoor() const { return start_coor_; }
	const pair<int,int> &getEndCoor() const { return end_coor_; }
	void SetStart(const int kCoor_x, const int kCoor_y);
	void SetEnd (const int kCoor_x, const int kCoor_y);
	const Nodo &at(const int kCoor_x, const int kCoor_y) const;
	Nodo &at(const int kCoor_x, const int kCoor_y);
	vector<Nodo*> CalculateChildren(const int kCoor_x, const int kCoor_y);
	void Updateheuristic();
	void SelectDefChildren(Nodo* current_node, vector<Nodo*>& children, vector<Nodo*>& closed, vector<Nodo*>& open);
	Nodo* SelectMinorF(vector<Nodo*> open);
	void PrintIteration(int it, vector<Nodo*> open, vector<Nodo*> close, Nodo* current);
	void Print();
	void PrintIds();
	void PrintHeuristic();
	Nodo* RecorridoAEstrella();
 private:
	vector<vector<Nodo>> maze_;
	int colums_{0};
	int rows_{0};
	pair<int,int> start_coor_{};
	pair<int,int> end_coor_{};
};