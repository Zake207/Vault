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
    Nodo(int id = -1, const vector<pair<int, double>> &children = vector<pair<int, double>>(), const vector<pair<int, double>> &parents = vector<pair<int, double>>()) {
        id_ = id;
        children_;
        parents_;
    }

    int getId() {
        return id_;
    }

    vector<pair<int, double>> &getChildren() {
        return children_;
    }

    vector<pair<int, double>> &getParents() {
        return parents_;
    }

    void InsertChild(int id, double cost) {
        pair<int, double> child = {id, cost};
        children_.push_back(child);
    }

    void InsertParent(int id, double cost) {
        pair<int, double> parent = {id, cost};
        parents_.push_back(parent);
    }

    // void RemoveChild(int id) {
    //     children_.erase({id, 0});
    // }
    friend ostream &operator<<(ostream &os, const Nodo &nodo) {
        os << "ID: " << nodo.id_ + 1 << endl;
        for (auto &child : nodo.children_) {
            os << " -> " << child.first + 1 << " (" << child.second << ")" << endl;
        }
        for (auto &parent : nodo.parents_) {
            os << " <- " << parent.first + 1<< " (" << parent.second << ")";
        }
        return os;
    }




private:
    int id_;
    vector<pair<int, double>> children_; // IDs de los hijos
    vector<pair<int, double>> parents_; // IDs de los padres
};