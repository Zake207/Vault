#include "../lib/Nodo.h"

    Nodo::Nodo(int id, const vector<pair<int, double>> &children, const vector<pair<int, double>> &parents) {
        id_ = id;
        children_;
        parents_;
    }

    void Nodo::InsertChild(int id, double cost) {
        pair<int, double> child = {id, cost};
        children_.push_back(child);
    }

    void Nodo::InsertParent(int id, double cost) {
        pair<int, double> parent = {id, cost};
        parents_.push_back(parent);
    }
    
    ostream &operator<<(ostream &os, const Nodo &nodo) {
        os << "ID: " << nodo.id_ + 1 << endl;
        for (auto &child : nodo.children_) {
            os << " -> " << child.first + 1 << " (" << child.second << ")" << endl;
        }
        for (auto &parent : nodo.parents_) {
            os << " <- " << parent.first + 1<< " (" << parent.second << ")";
        }
        return os;
    }
