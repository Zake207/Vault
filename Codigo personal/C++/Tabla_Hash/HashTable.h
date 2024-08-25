#include <iostream>
#include <vector>

#include "DispersionFunction.h"
#include "ExplorationFunction.h"
#include "Sequence.h"

#ifndef __HASHTABLE__
#define __HASHTABLE__

template <class Key, class Container = StaticSequence<Key>>
class HashTable {
public:
  HashTable(unsigned size, DispersionFunction<Key> &DFunction,
            ExplorationFuntion<Key> &EFunction, unsigned block_size)
      : tablesize_(size), fd_(DFunction), fe_(EFunction),
        block_size_(block_size) {
    std::cout << "# Creando tabla..." << std::endl;
  }

private:
  int tablesize_{0};
  DispersionFunction<Key> &fd_;
  ExplorationFuntion<Key> &fe_;
  std::vector<Container *> table_;
  int block_size_{1};
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class Key> class HashTable<Key, DynamicSequence<Key>> {
public:
  HashTable(unsigned size, DispersionFunction<Key> &DFunction)
      : tablesize_(size), fd_(DFunction) {
    std::cout << "# Creando tabla dinámica..." << std::endl;
    Sequence<Key> *p;
    table_.resize(tablesize_);
    for (int i = 0; i < tablesize_; ++i) {
      p = new DynamicSequence<Key>;
      table_[i] = p;
    }
    std::cout << "# Tabla de dispersión dinámica creada." << std::endl;
  }

  bool search(const Key &key) const {
    int iterator{fd_(key)};
    if (table_[iterator]->search(key)) {
      std::cout << "# Elemento encontrado en la posición " << iterator
                << std::endl;
      return true;
    }
    std::cout << "# Elemento no encontrado " << std::endl;
    return false;
  }
  bool insert(const Key &key) {
    int iterator{fd_(key)};
    table_[iterator]->insert(key);
    return true;
  }

  friend std::ostream &operator<<(std::ostream &os, HashTable<Key, DynamicSequence<Key>> hash) {
    for (int i = 0; i < hash.tablesize_; ++i) {
      hash.table_[i]->Print();
    }
    return os;
  }

private:
  int tablesize_{0};
  DispersionFunction<Key> &fd_;
  std::vector<Sequence<Key> *> table_;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Key> class HashTable<Key, StaticSequence<Key>> {
public:
  HashTable(int size, DispersionFunction<Key> &DFunction, ExplorationFuntion<Key> &EFunction, unsigned block_size)
      : tablesize_(size), fd_(DFunction), fe_(EFunction), block_size_(block_size) {
    std::cout << "# Creando tabla estática..." << std::endl;
    StaticSequence<Key> *p;
    table_.resize(tablesize_);
    for (int i = 0; i < tablesize_; ++i) {
      p = new StaticSequence<Key>(block_size_);
      table_[i] = p;
    }
    std::cout << "# Tabla de dispersión estática creada." << std::endl;
  }


  bool search(const Key &key) const {
    int iteration{0}, direction{fd_(key)}, origin{direction};
    while (table_[direction]->IsFull()) {
      if(table_[direction]->search(key)) {                  // SI LO ENCUENTRA EN LA DIRECCIÓN CALCULADA DEVUELVE TRUE.
        std::cout << "# Elemento encontrado con " << iteration << " iteraciones." << std::endl;
        return true;
      }                                                     // SI NO AUMENTA EL INTERATOR Y CALCULA LA NUEVA DIRECCIÓN
      ++iteration;
      direction = (fd_(key) + fe_(key,iteration)) % tablesize_;
      if (direction == origin) {                            // SI SE REGRESÓ AL ORIGEN DETERMINA QUE NO SE ENCONTRARÁ EL ELEMENTO.
        std::cout << "# Sin coincidencias (" << iteration << " iteraciones)." << std::endl;
        return false;
      }
    }
    if(table_[direction]->search(key)) {                    // SI EN ALGÚN MOMENTO ENCUENTRA UNA CELDA INCOMPLETA SE DETIENE A REVISARLA
      std::cout << "# Elemento encontrado con " << iteration << " iteraciones." << std::endl;
      return true;
    }
    std::cout << "# Sin coincidencias (" << iteration << " iteraciones)." << std::endl;
    return false;
  }
  

  bool insert(const Key &key) {
    int iteration{0}, direction{fd_(key)}, origin{direction};
    while (table_[direction]->IsFull()) {
      ++iteration;
      direction = (fd_(key) + fe_(key,iteration)) % tablesize_;
      if (direction == origin) {
        std::cout << "# El elemento no se puede insertar." << std::endl;
        return false;
      }
    }
    table_[direction]->insert(key);
    return true;
  }

  friend std::ostream &operator<<(std::ostream &os, HashTable<Key, StaticSequence<Key>> hash) {
    for (int i = 0; i < hash.tablesize_; ++i) {
      hash.table_[i]->Print();
    }
    return os;
  }
private:
int tablesize_{0};
DispersionFunction<Key> &fd_;
ExplorationFuntion<Key> &fe_;
std::vector<StaticSequence<Key> *> table_;
int block_size_{1};
};

#endif