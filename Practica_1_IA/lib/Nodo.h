#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;

class Nodo {
public:
    /// @brief Constructor de la clase Nodo
    /// @param id identificador del nodo
    /// @param children Los hijos del nodo
    /// @param parents Los padres del nodo
    Nodo(int id = -1, const vector<pair<int, double>> &children = vector<pair<int, double>>(), const vector<pair<int, double>> &parents = vector<pair<int, double>>());
    /// @brief Getter del identificador del nodo
    /// @return El identificador del nodo
    int getId() {return id_;}
    /// @brief Getter de los hijos del nodo
    /// @return Los hijos del nodo
    vector<pair<int, double>> &getChildren() {return children_;}
    /// @brief Getter de los hijos del nodo
    /// @return Los hijos del nodo
    vector<pair<int, double>> &getParents() {return parents_;}
    /// @brief Inserta un hijo al nodo
    /// @param id identificador del hijo
    /// @param cost coste del hijo
    void InsertChild(int id, double cost);
    /// @brief Inserta un padre al nodo
    /// @param id identificador del padre
    /// @param cost coste del padre
    void InsertParent(int id, double cost);
    /// @brief Sobrecarga del operador de inserción
    /// @param os flujo de salida
    /// @param nodo nodo a imprimir
    friend ostream &operator<<(ostream &os, const Nodo &nodo);

private:
    int id_;
    vector<pair<int, double>> children_; // IDs de los hijos
    vector<pair<int, double>> parents_; // IDs de los padres
};