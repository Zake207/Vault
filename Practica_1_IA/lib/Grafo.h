#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stack>

#pragma once

#include "Nodo.h"

class Grafo {
public:
    /// @brief Constructor de la clase Grafo
    Grafo(vector<Nodo>& node_list);
    /// @brief Imprime los nodos del grafo
    void Print();
    /// @brief Realiza un recorrido en amplitud (BFS) del grafo
    /// @param output_file archivo de salida
    void RecorridoAmplitud(std::ofstream &output_file);
    /// @brief Realiza un recorrido en profundidad (DFS) del grafo
    /// @param output_file archivo de salida
    void RecorridoProfundidad(std::ofstream &output_file);
private:
    vector<Nodo> node_list_;
};