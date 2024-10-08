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

    pair<int,int> &getId() {
        return id_;
    }
    int getVal() {
        return valor_;
    }

    Nodo* getParent() {
        return parent_;
    }

    int getRoadCost() {
        return road_cost_;
    }

    int getHeuristic() {
        return heuristic_;
    }

    void SetVal(const int kNewVal) {
        valor_ = kNewVal;
    }

    void SetRoadCost(const int kRoadCost) {
        road_cost_ = kRoadCost;
    }

    void SetHeuristic(const int kHeuristic) {
        heuristic_ = kHeuristic;
    }

    void SetParent(Nodo* parent) {
        parent_ = parent;
    }

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