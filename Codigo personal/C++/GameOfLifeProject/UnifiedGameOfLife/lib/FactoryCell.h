#include <iostream>
#include <vector>

#ifndef __FACTORY_CELL__
#define __FACTORY_CELL__

#include "CellACE.h"
#include "CellLife.h"

class FactoryCell {
public:
  // Método creador de células
  virtual Cell *createCell(Position &, const State &) const = 0;
};

// Replicar para cada tipo de célula
class FactoryCellAce110 : public FactoryCell {
public:
  Cell *createCell(Position &p, const State &s) const {
    return new CellACE110(p, s);
  }
};

class FactoryCellAce30 : public FactoryCell {
public:
  Cell *createCell(Position &p, const State &s) const {
    return new CellACE30(p, s);
  }
};

class FactoryCellLife23_3 : public FactoryCell {
public:
  Cell *createCell(Position &p, const State &s) const {
    return new CellLife23_3(p, s);
  }
};

class FactoryCellLife51_346 : public FactoryCell {
public:
  Cell *createCell(Position &p, const State &s) const {
    return new CellLife51_346(p, s);
  }
};

#endif