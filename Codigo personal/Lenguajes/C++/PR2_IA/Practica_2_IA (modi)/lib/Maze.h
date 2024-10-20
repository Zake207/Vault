#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

#pragma once

#include "Nodo.h"

using namespace std;

class Maze {
 public:

	/// @brief Constructor de la clase Maze
	/// @param file Fichero que almacena la información del laberinto
	Maze(fstream &file);
	/// @brief Getter de la posicion de arranque
	/// @return Referencia constante de la posicion de arranque
	const pair<int,int> &getStartCoor() const { return start_coor_; }
	/// @brief Getter de la posicion de fin
	/// @return Referencia constante de la posicion de fin
	const pair<int,int> &getEndCoor() const { return end_coor_; }
	/// @brief Getter de la heurística
	/// @return Entero que representa la heurística
	int getHeuristic() const { return heuristic_; }
	/// @brief Setter de la posicion de arranque
	/// @param kCoor_x Entero que representa la coordenada x de la posicion de arranque
	/// @param kCoor_y Entero que representa la coordenada y de la posicion de arranque
	void SetStart(const int kCoor_x, const int kCoor_y);
	/// @brief Setter de la posicion de fin
	/// @param kCoor_x Entero que representa la coordenada x de la posicion de fin
	/// @param kCoor_y Entero que representa la coordenada y de la posicion de fin
	void SetEnd (const int kCoor_x, const int kCoor_y);
	/// @brief Setter de la heurística
	/// @param kHeuristic Entero que representa la heurística
	void SetHeuristic(const int kHeuristic) { heuristic_ = kHeuristic; };
	/// @brief Operador de acceso constante a nodo
	/// @param kCoor_x Entero que representa la coordenada x del nodo
	/// @param kCoor_y Entero que representa la coordenada y del nodo
	/// @return Referencia constante al nodo
	const Nodo &at(const int kCoor_x, const int kCoor_y) const;
	/// @brief Operador de acceso a nodo
	/// @param kCoor_x Entero que representa la coordenada x del nodo
	/// @param kCoor_y Entero que representa la coordenada y del nodo
	/// @return Referencia al nodo
	Nodo &at(const int kCoor_x, const int kCoor_y);
	/// @brief Método que calcula los nodos hijos de un nodo que no son muros o se salen del laberinto
	/// @param kCoor_x Entero que representa la coordenada x del nodo
	/// @param kCoor_y Entero que representa la coordenada y del nodo
	/// @return Vector de punteros a los nodos hijos
	void CalculateChildren(const int kCoor_x, const int kCoor_y, vector<Nodo*>& open, vector<Nodo*>& closed);
	/// @brief Método que actualiza la heurística de los nodos
	void Updateheuristic();
	/// @brief Método que selecciona el nodo con menor valor de f de la lista de abiertos
	/// @param open Referencia al vector de punteros a los nodos abiertos
	/// @return El puntero al nodo con menor valor de f
	Nodo* SelectMinorF(vector<Nodo*> open);
	/// @brief Método que imprime la iteración actual
	/// @param it Número de la iteración
	/// @param open Vector de punteros a los nodos abiertos
	/// @param close Vector de punteros a los nodos cerrados
	/// @param current Puntero al nodo actual
	void PrintIteration(int it, vector<Nodo*> open, vector<Nodo*> close, Nodo* current, ofstream& file_out);
	/// @brief Método que imprime el laberinto con formato más legible
	void Print();
	/// @brief Método que imprime los ids de los nodos
	void PrintIds();
	/// @brief Método que imprime la heurística de los nodos
	void PrintHeuristic();
	/// @brief Método que recorre el laberinto con el algoritmo A*
	void RecorridoAEstrella(string& file_out_name);
 private:
	vector<vector<Nodo>> maze_;
	int colums_{0};
	int rows_{0};
	pair<int,int> start_coor_{};
	pair<int,int> end_coor_{};
	int heuristic_{0};
};