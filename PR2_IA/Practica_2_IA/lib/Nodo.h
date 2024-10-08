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
    Nodo(pair<int,int> id, int valor) : id_{pair<int,int>()} {
        id_ = id;
        valor_ = valor;
    }
    /// @brief Getter del atributo id_
    /// @return Retorna el atributo id_
    pair<int,int> &getId() {
        return id_;
    }
    /// @brief Getter del atributo valor_
    /// @return Retorna el atributo valor_
    int getVal() {
        return valor_;
    }
    /// @brief Getter del atributo parent_
    /// @return Retorna el atributo parent_
    Nodo* getParent() {
        return parent_;
    }
    /// @brief Getter del atributo road_cost_
    /// @return Retorna el atributo road_cost_
    int getRoadCost() {
        return road_cost_;
    }
    /// @brief Getter del atributo heuristic_
    /// @return Retorna el atributo heuristic_
    int getHeuristic() {
        return heuristic_;
    }
    /// @brief Setter del atributo valor_
    /// @param kNewVal Nuevo valor para el atributo valor_
    void SetVal(const int kNewVal) {
        valor_ = kNewVal;
    }
    /// @brief Setter del atributo road_cost_
    /// @param kRoadCost Nuevo valor para el atributo road_cost_
    void SetRoadCost(const int kRoadCost) {
        road_cost_ = kRoadCost;
    }
    /// @brief Setter del atributo heuristic_
    /// @param kHeuristic Nuevo valor para el atributo heuristic_
    void SetHeuristic(const int kHeuristic) {
        heuristic_ = kHeuristic;
    }
    /// @brief Setter del atributo parent_
    /// @param parent Nuevo valor para el atributo parent_
    void SetParent(Nodo* parent) {
        parent_ = parent;
    }
    /// @brief Sobrecarga del operador << para imprimir el nodo
    /// @param nodo Nodo con el que se comparará
    /// @return Retorna el nodo con el formato id_.first-id_.second
    friend ostream &operator<<(ostream &os, const Nodo &nodo) {
        os << nodo.id_.first << "-" << nodo.id_.second << " ";
        return os;
    }

private:
    pair<int,int> id_;
    int valor_{0};
    Nodo* parent_; // IDs of the parents
    int road_cost_{0}; // Cost from the start node
    int heuristic_{0}; // Cost to the end node
};