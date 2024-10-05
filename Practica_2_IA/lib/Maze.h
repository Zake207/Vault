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
			at(kCoor_x, kCoor_y - 1).SetRoadCost(5);
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
		return actual_children;
	}
	void Updateheuristic() {
		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < colums_; j++) {
				maze_[i][j].SetHeuristic((abs(i - end_coor_.first) + abs(j - end_coor_.second)) * 3);
			}
		}
	}
	Nodo* RecorridoAEstrella() {
		Nodo* current_node = &at(start_coor_.first, start_coor_.second);
		Nodo nodo_final_ = at(end_coor_.first, end_coor_.second);
		vector<Nodo*> open_nodes;
		vector<Nodo*> closed_nodes;
		open_nodes.push_back(current_node);
		// Trato el primer nodo que es el de salida
		vector<Nodo*> children = CalculateChildren(current_node->getId().first, current_node->getId().second);
		for (int i = 0; i < children.size(); i++) {
			children[i]->SetParent(current_node);
			open_nodes.emplace_back(children[i]);
		}
		closed_nodes.emplace_back(open_nodes[0]);
		open_nodes.erase(open_nodes.begin());
		cout << "Iteración 0" << endl;
		cout << "\t Abiertos: ";
		for (int i = 0; i < open_nodes.size(); i++) {
			cout << open_nodes[i]->getId().first << "-" << open_nodes[i]->getId().second << " ";
		}
		cout << endl;
		cout << "\t Cerrados: ";
		for (int i = 0; i < closed_nodes.size(); i++) {
			cout << closed_nodes[i]->getId().first << "-" << closed_nodes[i]->getId().second << " ";
		}
		cout << endl;
		// Itero hasta que encuentre el destino o no haya solución
		int iter = 1;
		while (true) {
			// Si no hay nodos abiertos posibles a visitar, no hay solución
			if (open_nodes.size() == 0) {
				cout << "No se ha encontrado solución" << endl;
				break;
			}
			// Elijo al de menor coste de los abiertos posibles a visitar, si estuvieran en la lista de cerrados no los considero
			vector<Nodo*> def_open_nodes;
			set_difference(open_nodes.begin(), open_nodes.end(), closed_nodes.begin(), closed_nodes.end(), back_inserter(def_open_nodes));
			open_nodes = def_open_nodes;
			current_node = open_nodes[0];
			for (int i = 1; i < open_nodes.size(); i++) {
				if (current_node->getRoadCost() + current_node->getHeuristic() > open_nodes[i]->getRoadCost() + open_nodes[i]->getHeuristic()) {
					current_node = open_nodes[i];
				}
			}
			// Compruebo si es el destino
			if (current_node->getVal() == 4) {
				return current_node;
				break;
			}
			// Cierro el nodo actual sacandolo de abiertos y metiendolo en cerrados
			open_nodes.erase(find(open_nodes.begin(), open_nodes.end(), current_node));
			closed_nodes.emplace_back(current_node);
			// Genero a los hijos que se pueden visitar y que no hayan sido cerrados, si ya estan en abiertos y el coste es menor lo actualizo
			children = CalculateChildren(current_node->getId().first, current_node->getId().second);
			for (int i = 0; i < children.size(); i++) {
				if (find(closed_nodes.begin(), closed_nodes.end(), children[i]) == closed_nodes.end()) {
					if (find(open_nodes.begin(), open_nodes.end(), children[i]) == open_nodes.end()) {
						children[i]->SetParent(current_node);
						open_nodes.emplace_back(children[i]);
					} else {
						Nodo* node = open_nodes[find(open_nodes.begin(), open_nodes.end(), children[i]) - open_nodes.begin()];
						if (node->getRoadCost() > children[i]->getRoadCost()) {
							node->SetRoadCost(children[i]->getRoadCost());
						}
					}
				}
			}
			// Imprimo la iteración
			cout << "Iteración " << iter << endl;
			cout << "\t Actual: " << current_node->getId().first << "-" << current_node->getId().second << endl;
			cout << "\t Abiertos: ";
			for (int i = 0; i < open_nodes.size(); i++) {
				cout << open_nodes[i]->getId().first << "-" << open_nodes[i]->getId().second << " ";
			}
			cout << endl;
			cout << "\t Cerrados: ";
			for (int i = 0; i < closed_nodes.size(); i++) {
				cout << closed_nodes[i]->getId().first << "-" << closed_nodes[i]->getId().second << " ";
			}
			cout << endl;
			++iter;
		}
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