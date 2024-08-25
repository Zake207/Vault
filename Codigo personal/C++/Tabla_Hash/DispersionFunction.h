#include <iostream>

#include"Nif.h"

#ifndef __DISPERSION__
#define __DISPERSION__

template <class Key> class DispersionFunction {
public:
  DispersionFunction(const int kTable_size) : tablesize_(kTable_size) {}
  virtual int operator()(const Key &key) const = 0;

protected:
  int tablesize_{0};
};

template <class Key>
class DispersionFunctionModule : public DispersionFunction<Key> {
public:
  DispersionFunctionModule(const int kTablesize = 1) : DispersionFunction<Key>(kTablesize) {}
  int operator()(const Key &key) const { return key % DispersionFunction<Key>::tablesize_; }
};

template <class Key>
class DispersionFunctionSum : public DispersionFunction<Key> {
public:
  DispersionFunctionSum(const int kTablesize = 1) : DispersionFunction<Key>(kTablesize) {}
  int operator()(const Key &key) const {
    int first_key = key;
    int second_key{0};
    while (first_key > 0) {
      second_key += first_key % 10;
      first_key /= 10;
    }
    return second_key % DispersionFunction<Key>::tablesize_;
  }
};

template <class Key>
class DispersionFunctionRandom : public DispersionFunction<Key> {
public:
  DispersionFunctionRandom(const int kTablesize = 1) : DispersionFunction<Key>(kTablesize) {}
  int operator()(const Key &key) const {
    srand(key);
    return rand() % DispersionFunction<Key>::tablesize_;
  }
};

#endif