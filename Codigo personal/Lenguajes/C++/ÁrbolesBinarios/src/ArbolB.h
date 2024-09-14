#include <iostream>
#include <queue>
#include <vector>
#include <sys/time.h>

#include "NodoB.h"

#ifndef __ARBOL__
#define __ARBOL__

template <class Key> class ArbolB {
public:
  ArbolB(NodoB<Key> *raiz = NULL) : raiz_(raiz) {}
  ~ArbolB() { Podar(raiz_); }

  void Podar(NodoB<Key> *nodo) {
    if (nodo == NULL)
      return;
    Podar(nodo->GetIzquierda());
    Podar(nodo->GetDerecha());
    delete nodo;
    nodo = NULL;
  }
  NodoB<Key> *GetRaiz() const { return raiz_; }

  bool Hoja(NodoB<Key> *nodo) {
    return !nodo->GetDerecha() && !nodo->GetIzquierda();
  }

  const int Tam() { return TamRama(raiz_); }

  const int TamRama(NodoB<Key> *nodo) {
    if (nodo == NULL)
      return 0;
    return (1 + TamRama(nodo->GetIzquierda()) + TamRama(nodo->GetDerecha()));
  }

  virtual bool Insertar(const Key &key) = 0;
  virtual bool Buscar(const Key &key) const = 0;

  void Inorden(NodoB<Key> *nodo) const {
    if (nodo == NULL)
      return;
    Inorden(nodo->GetIzquierda());
    std::cout << nodo->GetDato() << " ";
    Inorden(nodo->GetDerecha());
  }

  friend std::ostream &operator<<(std::ostream &os, const ArbolB &arbol) {
    std::queue<std::pair<NodoB<Key> *, int>> Q;
    std::pair<NodoB<Key> *, int> dupla;
    NodoB<Key> *nodo;
    int nivel, nivel_actual = 0;
    dupla.first = arbol.GetRaiz();
    dupla.second = 0;
    Q.push(dupla);
    os << "\n[Nivel " << nivel_actual << "]";
    while (!Q.empty()) {
      dupla = Q.front();
      nodo = dupla.first;
      nivel = dupla.second;
      if (nivel > nivel_actual) {
        nivel_actual = nivel;
        os << "\n[Nivel " << nivel_actual << "]";
      }
      if (nodo != NULL) {
        os << "[" << nodo->GetDato() << "]";
        dupla.first = nodo->GetIzquierda();
        dupla.second = nivel + 1;
        Q.push(dupla);
        dupla.first = nodo->GetDerecha();
        dupla.second = nivel + 1;
        Q.push(dupla);
      } else {
        os << "[.]";
      }
      Q.pop();
    }
    return os;
  }

protected:
  NodoB<Key> *raiz_;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Key> class ArbolBE : public ArbolB<Key> {
public:
  ArbolBE(NodoB<Key> *raiz = NULL) : ArbolB<Key>(raiz) {
    std::cout << "# Arbol Binario Equilibrado creado." << std::endl;
  }
  ~ArbolBE() { Podar(this->raiz_); }

  bool Insertar(const Key &key) {
    if (this->raiz_ == NULL) {
      this->raiz_ = new NodoB(key);
      return true;
    } else {
      if (Buscar(key))
        return false;
      return InsertarNodo(this->raiz_, key);
    }
  }

  bool Buscar(const Key &key) const {
    timeval start;
    timeval end;
    gettimeofday(&start, NULL);
    bool encontrado{false};
    Busqueda(this->raiz_, key, encontrado);
    gettimeofday(&end, NULL);
    std::cout << "Tiempo de búsqueda: " << (end.tv_sec - start.tv_sec)*1000 + (end.tv_usec - start.tv_usec)/1000.0 << " milisegundos" << std::endl;
    return encontrado;
  }

protected:
  bool InsertarNodo(NodoB<Key> *nodo, const Key &clave) {
    if (this->TamRama(nodo->GetIzquierda()) <=
        this->TamRama(nodo->GetDerecha())) {
      if (nodo->GetIzquierda() != NULL) {
        InsertarNodo(nodo->GetIzquierda(), clave);
      } else {
        nodo->AccessIzquierda() = new NodoB(clave);
        return true;
      }
    } else {
      if (nodo->GetDerecha() != NULL) {
        InsertarNodo(nodo->GetDerecha(), clave);
      } else {
        nodo->AccessDerecha() = new NodoB(clave);
        return true;
      }
    }
    return false;
  }

  void Busqueda(NodoB<Key> *nodo, const Key &key, bool &encontrado) const {
    if (nodo->GetDato() == key) {
      encontrado = true;
      return;
    }
    if (nodo->GetIzquierda() != NULL) {
      Busqueda(nodo->GetIzquierda(), key, encontrado);
    }
    if (nodo->GetDerecha() != NULL) {
      Busqueda(nodo->GetDerecha(), key, encontrado);
    }
  }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Key> class ArbolBB : public ArbolB<Key> {
public:
  ArbolBB(NodoB<Key> *raiz = NULL) : ArbolB<Key>(raiz) {
    std::cout << "# Arbol Binario de Busqueda creado." << std::endl;
  }
  ~ArbolBB() { Podar(this->raiz_); }

  // Insercion
  bool Insertar(const Key &key) {
    bool insertado{false};
    if (this->raiz_ == NULL) {
      this->raiz_ = new NodoB<Key>(key, NULL, NULL);
      return true;
    } else {
      if (Buscar(key)) {
        std::cout << "# Elemento ya existe" << std::endl;
        return false;
      }
      InsertarNodo(this->raiz_, key, insertado);
      return insertado;
    }
  }
  // Busqueda
  bool Buscar(const Key &key) const {
    timeval start; 
    timeval end;
    gettimeofday(&start, NULL);
    bool encontrado{false};
    Busqueda(this->raiz_, key, encontrado);
    gettimeofday(&end, NULL);
    std::cout << "Tiempo de búsqueda: " << (end.tv_sec - start.tv_sec)*1000 + (end.tv_usec - start.tv_usec)/1000.0 << " milisegundos" << std::endl;
    return encontrado;
  }

protected:
  void InsertarNodo(NodoB<Key> *nodo, const Key &clave, bool &insertado) {
    if (clave < nodo->GetDato()) {
      if (nodo->GetIzquierda() == NULL) {
        insertado = true;
        nodo->AccessIzquierda() = new NodoB<Key>(clave, NULL, NULL);
      } else {
        InsertarNodo(nodo->GetIzquierda(), clave, insertado);
      }
    }
    if (clave > nodo->GetDato()) {
      if (nodo->GetDerecha() == NULL) {
        insertado = true;
        nodo->AccessDerecha() = new NodoB<Key>(clave, NULL, NULL);
      } else {
        InsertarNodo(nodo->GetDerecha(), clave, insertado);
      }
    }
  }

  void Busqueda(NodoB<Key> *nodo, const Key &key, bool &encontrado) const {
    if (nodo->GetDato() == key) {
      encontrado = true;
      return;
    }
    if (key < nodo->GetDato() && nodo->GetIzquierda() != NULL) {
      Busqueda(nodo->GetIzquierda(), key, encontrado);
    }
    if (key > nodo->GetDato() && nodo->GetDerecha() != NULL) {
      Busqueda(nodo->GetDerecha(), key, encontrado);
    }
    return;
  }
};

#endif