#include <iostream>
#include <vector>

#include "FactoryCell.h"

#ifndef __LATTICE_1D__
#define __LATTICE_1D__

#include "Lattice.h"

class Lattice1D : public Lattice {
public:
  Lattice1D(const int kSize, const FactoryCell &kFactory) : Lattice(kFactory) {
    State dead(0), alive(1);
    lattice_.resize(kSize);
    Position *p;
    for (int i = 0; i < kSize; i++) {
      p = new PositionDim<1, int>(1, i);
      lattice_[i] = factory_.createCell(*p, dead);
    }
    auto pos{0};
    std::cout << "A continuación introduzca las posiciones que desea que estén vivas." << std::endl; 
    std::cout << "Pulse 'q' para terminar la lectura." << std::endl;
    while (std::cin >> pos) {
      if (pos == 'q') {
        break;
      }
      if (pos < 0 || pos >= kSize) {
        std::cout << "#  Posición inválida: fuera de rango" << std::endl;
      }
      else {
        lattice_[pos]->SetState(alive);
      }
    }
  }
  ~Lattice1D() {
    for (int i = 0; i < lattice_.size(); ++i) {
      delete lattice_[i];
    }
  }
  Lattice1D(const std::string& kFilename, const FactoryCell& kFactory) : Lattice(kFilename, kFactory) {
    std::string content;
    State dead(0), alive(1);
    lattice_.resize(dimensions_[0]);
    Position *p;
    for (int i = 0; i < lattice_.size(); i++) {
      p = new PositionDim<1, int>(1, i);
      lattice_[i] = factory_.createCell(*p, dead);
    }
    std::fstream file(kFilename);
    getline(file, content);
    getline(file, content);
    getline(file, content);
    for (int i = 0; i < dimensions_[0]; ++i) {
      if (content[i] == '1') {
        lattice_[i]->SetState(alive);
      }
    }
  }
  
  void SaveGeneration() {
      std::string filename;
      std::cout << "What's the filename to save the lattice? --> ";
      std::cin >> filename;
      std::ofstream file{filename};
      Position *p;
      file << GetDimension();
      file << "\n";
        file << GetDimensions()[0] << "\n";
        for (int i = 0; i < lattice_.size(); ++i) {
          file << lattice_[i]->GetState().GetChar();
        }
  }

  int GetSize() const { return lattice_.size(); }

  std::size_t Population() const {
    int living_cells{0};
    for (int i = 0; i < GetSize(); ++i) {
      living_cells += lattice_[i]->GetState().GetState();
    }
    return living_cells;
  }

  std::ostream &display(std::ostream &os) const {
    for (int i = 0; i < GetSize(); ++i) {
      os << *lattice_[i] << "  ";
    }
    os << "\n";
    return os;
  }

protected:
  std::vector<Cell *> lattice_;
};

class Lattice1DPeriodic : public Lattice1D {
public:
  Lattice1DPeriodic(const int kSize, const FactoryCell &kFactory) : Lattice1D(kSize, kFactory) {}
  Lattice1DPeriodic(const std::string& kFilename, const FactoryCell& kFactory) : Lattice1D(kFilename, kFactory) {}

  void nextGeneration() {
    for (int i = 0; i < GetSize(); ++i) {
      lattice_[i]->SetNextState(lattice_[i]->NextState(*this));
    }
    for (int i = 0; i < GetSize(); ++i) {
      lattice_[i]->UpdateState();
    }
  }

  Cell &operator[](const Position &kPosition) {
    int position = kPosition[0];
    if (position < 0)
      position = GetSize() - 1;
    if (position >= GetSize())
      position = 0;
    return *lattice_[position];
  }
};

class Lattice1DOpen : public Lattice1D {
public:
  Lattice1DOpen(const int kSize, const FactoryCell &kFactory, const bool kOpen_type) : Lattice1D(kSize, kFactory), border_type_(kOpen_type) {
    PositionDim<1, int> p(1, -1);
    State s(kOpen_type);
    lattice_.insert(lattice_.begin(), factory_.createCell(p, s));
    lattice_.push_back(factory_.createCell(p, s));
  }
  Lattice1DOpen(const std::string& kFilename, const FactoryCell& kFactory, const bool kOpen_type) : Lattice1D(kFilename, kFactory) {
    PositionDim<1, int> p(1, -1);
    State s(kOpen_type);
    lattice_.insert(lattice_.begin(), factory_.createCell(p, s));
    lattice_.push_back(factory_.createCell(p, s));
  }

  void nextGeneration() {
    for (int i = 1; i < GetSize() - 1; ++i) {
      lattice_[i]->SetNextState(lattice_[i]->NextState(*this));
    }
    for (int i = 1; i < GetSize() - 1; ++i) {
      lattice_[i]->UpdateState();
    }
  }

  Cell &operator[](const Position &kPosition) {
    int position = kPosition[0];
    return *lattice_[position + 1]; // REVISAR ESTE +1 DE AHI
  }

protected:
  int border_type_{0};
};

class Lattice1DReflective : public Lattice1D {
public:
  Lattice1DReflective(const int kSize, const FactoryCell &kFactory) : Lattice1D(kSize, kFactory) {}
  Lattice1DReflective(const std::string& kFilename, const FactoryCell& kFactory) : Lattice1D(kFilename, kFactory) {}

  void nextGeneration() {
    for (int i = 0; i < GetSize(); ++i) {
      lattice_[i]->SetNextState(lattice_[i]->NextState(*this));
    }
    for (int i = 0; i < GetSize(); ++i) {
      lattice_[i]->UpdateState();
    }
  }

  Cell &operator[](const Position &kPosition) {
    int position = kPosition[0];
    if (position < 0)
      position = 0;
    if (position >= GetSize())
      position = GetSize() - 1;
    return *lattice_[position];
  }
};

class Lattice1DNoBorder : public Lattice1D {
public:
  Lattice1DNoBorder(const int kSize, const FactoryCell &kFactory) : Lattice1D(kSize, kFactory) {}
  Lattice1DNoBorder(const std::string& kFilename, const FactoryCell& kFactory) : Lattice1D(kFilename, kFactory) {}

  void CheckBorders() {
    if (lattice_[0]->GetState().GetState() == 1) {
      --initial_;
      Position *p = new PositionDim<1, int>(1, initial_);
      State s(0);
      lattice_.insert(lattice_.begin(), factory_.createCell(*p, s));
    }
    if (lattice_[GetSize() - 1]->GetState().GetState() == 1) {
      int pos{GetSize() + initial_ - 1};
      if (initial_ == 0)
        pos = GetSize();
      Position *p = new PositionDim<1, int>(1, pos);
      State s(0);
      lattice_.emplace_back(factory_.createCell(*p, s));
    }
  }
  void nextGeneration() {
    CheckBorders();
    for (int i = 0; i < GetSize(); ++i) {
      lattice_[i]->SetNextState(lattice_[i]->NextState(*this));
    }
    for (int i = 0; i < GetSize(); ++i) {
      lattice_[i]->UpdateState();
    }
  }

  Cell &operator[](const Position &kPosition) {
    int position = kPosition[0];
    if (position >= initial_ && position <= GetSize() - 1 + initial_) {
      return *lattice_[position - initial_];
    }
    if (position < initial_) {
      int pos{GetSize() - 1};
      if (initial_ < 0) {
        pos + initial_;
      }
      return *lattice_[pos];
    } else {
      return *lattice_[0];
    }

    // if (position < initial_) position = GetSize() - 1;
    // if (position >= GetSize()) position = 0;
    // return *lattice_[position + initial_];
  }

private:
  int initial_{0};
};

#endif

// DEBERIA HACER QUE CADA CELULA SE REPRESENTE DE MANERA DIFERENTE? El display
// de cada célula se encarga EL DESTRUCTOR SE IMPLEMENTARIA EN LA CLASE BASE
// PERO CADA CLASE LATTICE nD DEBE ESPECIFICAR COMO LIBERA EL ESPACIO