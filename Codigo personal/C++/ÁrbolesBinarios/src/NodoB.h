#include <iostream>

#ifndef __NODO__
#define __NODO__

template<class Key>
class NodoB {
 public:
    NodoB(const Key& clave, NodoB<Key>* izdo = NULL, NodoB<Key>* dcho = NULL) : dato_(clave), izdo_(izdo), dcho_(dcho)  {}
    
    Key GetDato() const {
        return dato_;
    }

    NodoB<Key>* GetIzquierda() const {
        return izdo_;
    }

    NodoB<Key>* GetDerecha() const {
        return dcho_;
    }

    NodoB<Key>*& AccessIzquierda() {
        return izdo_;
    }

    NodoB<Key>*&      AccessDerecha() {
        return dcho_;
    }

private:
  Key dato_;
  NodoB<Key>* izdo_ = NULL;
  NodoB<Key>* dcho_ = NULL;
};

#endif