#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Nodo.h"

using namespace std;

class Maze {
 public:
	Maze(fstream &file) {
		file >> rows_;
		file >> colums_;
		string line;
		getline(file, line);
		for (int i = 0; i < rows_; i++) {
			vector<Nodo> row;
			getline(file, line);
			for (int j = 0; j < colums_ * 2; j++) {
				if (line[j] != ' ') {
					Nodo nodo({i, j/2}, line[j] - '0');
					row.push_back(nodo);
					if (nodo.getVal() == 3) start_coor_ = {i, j/2};
					if (nodo.getVal() == 4) end_coor_ = {i, j/2};
				}
			}
			maze_.push_back(row);
		}
	}
	const pair<int,int> &getStartCoor() const {
		return start_coor_;
	}
	const pair<int,int> &getEndCoor() const {
		return end_coor_;
	}
	void SetStart(const int kCoor_x, const int kCoor_y) {
		if (((kCoor_x >= 0) && (kCoor_y >= 0)) && ((kCoor_x < rows_) && (kCoor_y - colums_))) {
			at(kCoor_x, kCoor_y).SetVal(3);
			at(start_coor_.first, start_coor_.second).SetVal(1);
			start_coor_.first = kCoor_x;
			start_coor_.second = kCoor_y;
		} else {
			cout << "///Error: Las coordenadas introducidas no son correctas. No se cambiará el origen" << endl;
		}
	}
	void SetEnd (const int kCoor_x, const int kCoor_y) {
		if (((kCoor_x >= 0) && (kCoor_y >= 0)) && ((kCoor_x < rows_) && (kCoor_y - colums_))) {
			at(kCoor_x, kCoor_y).SetVal(4);
			at(end_coor_.first, end_coor_.second).SetVal(1);
			end_coor_.first = kCoor_x;
			end_coor_.second = kCoor_y;
		} else {
			cout << "///Error: Las coordenadas introducidas no son correctas. No se cambiará el destino" << endl;
		}
		Updateheuristic();
	}
	const Nodo &at(const int kCoor_x, const int kCoor_y) const {
		return maze_[kCoor_x][kCoor_y];
	}
	Nodo &at(const int kCoor_x, const int kCoor_y) {
		return maze_[kCoor_x][kCoor_y];
	}
	vector<Nodo*> CalculateChildren(const int kCoor_x, const int kCoor_y) {
		vector<Nodo*> actual_children;
		if (kCoor_x - 1 >= 0 && at(kCoor_x - 1, kCoor_y).getVal() != 1) {
			at(kCoor_x - 1, kCoor_y).SetRoadCost(at(kCoor_x,kCoor_y).getRoadCost() + 5);
			actual_children.push_back(&at(kCoor_x - 1, kCoor_y));
		}
		if (kCoor_x + 1 < rows_ && at(kCoor_x + 1, kCoor_y).getVal() != 1) {
			at(kCoor_x + 1, kCoor_y).SetRoadCost(at(kCoor_x,kCoor_y).getRoadCost() + 5);
			actual_children.push_back(&at(kCoor_x + 1, kCoor_y));
		}
		if (kCoor_y - 1 >= 0 && at(kCoor_x, kCoor_y - 1).getVal() != 1) {
			at(kCoor_x, kCoor_y - 1).SetRoadCost(at(kCoor_x,kCoor_y).getRoadCost() + 5);
			actual_children.push_back(&at(kCoor_x, kCoor_y - 1));
			
		}
		if (kCoor_y + 1 < colums_ && at(kCoor_x, kCoor_y + 1).getVal() != 1) {
			at(kCoor_x, kCoor_y + 1).SetRoadCost(at(kCoor_x,kCoor_y).getRoadCost() + 5);
			actual_children.push_back(&at(kCoor_x, kCoor_y + 1));
			
		}
		if (kCoor_x - 1 >= 0 && kCoor_y - 1 >= 0 && at(kCoor_x - 1, kCoor_y - 1).getVal() != 1) {
			at(kCoor_x - 1, kCoor_y - 1).SetRoadCost(at(kCoor_x,kCoor_y).getRoadCost() + 7);
			actual_children.push_back(&at(kCoor_x - 1, kCoor_y - 1));
		}
		if (kCoor_x - 1 >= 0 && kCoor_y + 1 < colums_ && at(kCoor_x - 1, kCoor_y + 1).getVal() != 1) {
			at(kCoor_x - 1, kCoor_y + 1).SetRoadCost(at(kCoor_x,kCoor_y).getRoadCost() + 7);
			actual_children.push_back(&at(kCoor_x - 1, kCoor_y + 1));
		}
		if (kCoor_x + 1 < rows_ && kCoor_y - 1 >= 0 && at(kCoor_x + 1, kCoor_y - 1).getVal() != 1) {
			at(kCoor_x + 1, kCoor_y - 1).SetRoadCost(at(kCoor_x,kCoor_y).getRoadCost() + 7);
			actual_children.push_back(&at(kCoor_x + 1, kCoor_y - 1));
		}
		if (kCoor_x + 1 < rows_ && kCoor_y + 1 < colums_ && at(kCoor_x + 1, kCoor_y + 1).getVal() != 1) {
			at(kCoor_x + 1, kCoor_y + 1).SetRoadCost(at(kCoor_x,kCoor_y).getRoadCost() + 7);
			actual_children.push_back(&at(kCoor_x + 1, kCoor_y + 1));
		}
		// cout << "Hijos de " << kCoor_x << "-" << kCoor_y << ": ";
		// for (int i = 0; i < actual_children.size(); i++) {
		// 	cout << actual_children[i]->getId().first << "-" << actual_children[i]->getId().second << " ";
		// }
		return actual_children;
	}
	void Updateheuristic() {
		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < colums_; j++) {
				if (maze_[i][j].getVal() != 1) 
				maze_[i][j].SetHeuristic((abs(i - end_coor_.first) + abs(j - end_coor_.second)) * 3);
				else 
				maze_[i][j].SetHeuristic(-1);
			}
		}
	}
	Nodo* RecorridoAEstrella() {
		Nodo* current_node = &at(start_coor_.first, start_coor_.second);
		Nodo nodo_final_ = at(end_coor_.first, end_coor_.second);
		vector<Nodo*> open_nodes;
		vector<Nodo*> closed_nodes;
		open_nodes.emplace_back(current_node);
	// Trato el primer nodo que es el de salida
		vector<Nodo*> children = CalculateChildren(current_node->getId().first, current_node->getId().second);
		SelectDefChildren(current_node, children, closed_nodes, open_nodes);
		closed_nodes.emplace_back(open_nodes[0]);
		open_nodes.erase(open_nodes.begin());
		PrintIteration(0, open_nodes, closed_nodes, current_node);
	// Itero hasta que encuentre el destino o no haya solución
		int iter = 1;
		while (true) {
		// Si no hay nodos abiertos posibles a visitar, no hay solución
			if (open_nodes.size() == 0) {
				cout << "No se ha encontrado solución" << endl;
				break;
			}
		// Elijo al de menor coste de los abiertos posibles a visitar, si estuvieran en la lista de cerrados no los considero
			open_nodes.erase(remove_if(open_nodes.begin(), open_nodes.end(), [&](Nodo* n) { return find(closed_nodes.begin(), closed_nodes.end(), n) != closed_nodes.end(); }), open_nodes.end());
			current_node = SelectMinorF(open_nodes);
		// Compruebo si es el destino
			if (current_node->getId() == nodo_final_.getId()) {
				cout << "Camino encontrado al nodo salida (posición: " << current_node->getId().first << current_node->getId().second << ")" << endl;
				return current_node;
				break;
			}
		// Cierro el nodo actual sacandolo de abiertos y metiendolo en cerrados
			open_nodes.erase(find(open_nodes.begin(), open_nodes.end(), current_node));
			closed_nodes.emplace_back(current_node);
		// Genero a los hijos que se pueden visitar y que no hayan sido cerrados, si ya estan en abiertos y el coste es menor lo actualizo
			children = CalculateChildren(current_node->getId().first, current_node->getId().second);
			SelectDefChildren(current_node, children, closed_nodes, open_nodes);
		// Imprimo la iteración
			PrintIteration(iter, open_nodes, closed_nodes, current_node);
			++iter;
		}
	}
	void SelectDefChildren(Nodo* current_node, vector<Nodo*>& children, vector<Nodo*>& closed, vector<Nodo*>& open) {
		for (int i = 0; i < children.size(); i++) {
			// Si no está en cerrados compruebo si está en abiertos
				if (find(closed.begin(), closed.end(), children[i]) == closed.end()) {
				// Si no está en abiertos
					if (find(open.begin(), open.end(), children[i]) == open.end()) {
						children[i]->SetParent(current_node);
						open.emplace_back(children[i]);
				// Si está en abiertos
					} else {
					// Si el coste es menor lo actualizo
						Nodo* node = open[find(open.begin(), open.end(), children[i]) - open.begin()];
						if (node->getRoadCost() > children[i]->getRoadCost()) {
							node->SetRoadCost(children[i]->getRoadCost());
							node->SetParent(children[i]->getParent());
						}
					}
				}
			}
	}
	Nodo* SelectMinorF(vector<Nodo*> open) {
		Nodo* minor = open[0];
		for (int i = 1; i < open.size(); i++) {
			if (open[i]->getRoadCost() + open[i]->getHeuristic() < minor->getRoadCost() + minor->getHeuristic()) {
				minor = open[i];
			}
		}
		return minor;
	}
	void PrintIteration(int it, vector<Nodo*> open, vector<Nodo*> close, Nodo* current) {
		cout << "Iteración " << it << endl;
		cout << "\tActual: " << current->getId().first << "-" << current->getId().second << endl;
		cout << "\tAbiertos: ";
		for (int i = 0; i < open.size(); i++) {
			cout << open[i]->getId().first << "-" << open[i]->getId().second << " ";
		}
		cout << endl;
		cout << "\tCerrados: ";
		for (int i = 0; i < close.size(); i++) {
			cout << close[i]->getId().first << "-" << close[i]->getId().second << " ";
		}
		cout << endl;

	}
	void Print() {
		cout << "Rows: " << rows_ << endl;
		cout << "Colums: " << colums_ << endl;
		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < colums_; j++) {
				if (maze_[i][j].getVal() == 1) cout << "██";
				if (maze_[i][j].getVal() == 0) cout << "  ";
				if (maze_[i][j].getVal() == 3) cout << "S ";
				if (maze_[i][j].getVal() == 4) cout << "E ";
				if (maze_[i][j].getVal() == 5) cout << "* ";
			}
			cout << endl;
		}
	}
	void PrintIds() {
		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < colums_; j++) {
				cout << "("<< maze_[i][j].getId().first + 1 << "-" << maze_[i][j].getId().second + 1 << ") ";
			}
			cout << endl;
		}
	}
	void PrintHeuristic() {
		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < colums_; j++) {
				cout << maze_[i][j].getHeuristic() << " ";
			}
			cout << endl;
		}
	}
 private:
	vector<vector<Nodo>> maze_;
	int colums_{0};
	int rows_{0};
	pair<int,int> start_coor_{};
	pair<int,int> end_coor_{};
};