#include <iostream>
#include <vector>
#include <stdarg.h>

#include "Position.h"

#ifndef __POSITION_T__
#define __POSITION_T__

template <int Dim = 2, class Coordinate_t = int>
class PositionDim: public Position {
    public:
        PositionDim (int size, ...) {
            va_list v1;
            va_start(v1, size);
            for (int i = 0; i < Dim; ++i) {
                Coordinates[i] = va_arg(v1, Coor_t);
            }
            va_end(v1);
            dim_ = size;
        }

        int GetDim() {return dim_;}
        void SetDim(int dim) {dim_ = dim;}

        Coor_t operator[] (int position) const {
            if (position >= Dim) {
                throw std::out_of_range("# Posicion inválida");
                return Coordinates[0];
            } else {
              return Coordinates[position];
            }
        }

        friend std::ostream& operator<<(std::ostream& os, PositionDim& pos) {
            for (int i = 0; i < pos.GetDim(); ++ i) {
                os << pos[i];
            }
            return os;
        }
    protected:
        Coor_t Coordinates[Dim];
        int dim_{1};
};

#endif