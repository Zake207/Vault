#include <iostream>

#include "DispersionFunction.h"
#include "Nif.h"

#ifndef __EXPLORATION__
#define __EXPLORATION__

template <class Key> class ExplorationFuntion {
    public:
        virtual int operator() (const Key& key, int n) const = 0;
};

template<class Key>class ExplorationFunctionLineal : public ExplorationFuntion<Key> {
    public:
        int operator() (const Key& key, int n) const {
            return n;
        }
};

template<class Key>class ExplorationFunctionCuadratic : public ExplorationFuntion<Key> {
    public:
        int operator() (const Key& key, int n) const {
            return n * n;    
        }
};

template<class Key>class ExplorationFunctionDouble : public ExplorationFuntion<Key> {
    public:
        ExplorationFunctionDouble(const DispersionFunction<Key>& kFunc) : function_(kFunc) {}
        int operator() (const Key& key, int n) const {
            return function_(key) * n;
        }
    protected:
        const DispersionFunction<Key>& function_;
};

template<class Key>class ExplorationFunctionRedispersion : public ExplorationFuntion<Key> {
    public:
    ExplorationFunctionRedispersion(const DispersionFunction<Key>& kFunc) : function_(kFunc) {}
        int operator() (const Key& key, int n) const {
            srand(int(key));
            Key aux;
            while (n > 0) {
                int(aux) = rand();
                --n;
            }
            return function_(aux);
        }
    protected:
        const DispersionFunction<Key>& function_;
};

#endif
