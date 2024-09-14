#include <iostream>
#include <vector>

#ifndef __POSITION__
#define __POSITION__

typedef int Coor_t;

class Position {
    public:
    virtual Coor_t operator[](int position) const = 0;
};

#endif