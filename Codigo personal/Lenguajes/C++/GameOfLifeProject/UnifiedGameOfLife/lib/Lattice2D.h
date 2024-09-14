#include <iostream>
#include <vector>

#include "CellACE.h"
#include "CellLife.h"
#include "FactoryCell.h"
#include "Lattice.h"

#ifndef __LATTICE_2D__
#define __LATTICE_2D__

class Lattice2D : public Lattice {
public:
  Lattice2D(const int kRow, const int kColum, const FactoryCell &kFactory) : Lattice(kFactory) {
    State dead(0), alive(1);
    lattice_.resize(kRow);
    for (int i = 0; i < kRow; ++i) {
      lattice_[i].resize(kColum);
    }
    Position *p;
    for (int i = 0; i < kRow; i++) {
      for (int j = 0; j < kColum; ++j) {
        p = new PositionDim<2, int>(2, i, j);
        lattice_[i][j] = factory_.createCell(*p, dead);
      }
    }
    std::cout << "A continuación introduzca las posiciones que desea que estén vivas." << std::endl; 
    std::cout << "Pulse '-1' para terminar la lectura." << std::endl;
    int pos_x{0}, pos_y{0};
    while (std::cin >> pos_x >> pos_y) {
      if (pos_x == -1 || pos_y == -1 ) {
        break;
      }
      if (pos_x < 0 || pos_x >= kRow || pos_y >= kColum || pos_y < 0) {
        std::cout << "#  Posición inválida: fuera de rango" << std::endl;
      }
      else {
        lattice_[pos_x][pos_y]->SetState(alive);
      }
    }
  }
  Lattice2D(const std::string& kFilename, const FactoryCell& kFactory) : Lattice(kFilename, kFactory) {
    std::string content;
    State dead(0), alive(1);
    Position *p;
    lattice_.resize(dimensions_[0]);
    for (int i = 0; i < lattice_.size(); ++i) {
      lattice_[i].resize(dimensions_[1]);
    }
    for (int i = 0; i < lattice_.size(); ++i) {
      for (int j = 0; j < lattice_[i].size(); ++j) {
        p = new PositionDim<2, int>(2, i, j);
        lattice_[i][j] = factory_.createCell(*p, dead);
      }
    }
    std::fstream file(kFilename);
    getline(file, content);
    getline(file, content);
    for (int i = 0; i < dimensions_[0]; ++i) {
      getline(file, content);
      for (int j = 0; j < lattice_[i].size(); ++j) {
        if (content[j] == '1') {
          lattice_[i][j]->SetState(alive);
        }
      }
    }
  }
  ~Lattice2D() {
    for (int i = 0; i < lattice_.size(); ++i) {
      for (int j = 0; j < lattice_[i].size(); ++j) 
        delete lattice_[i][j];
    }
  }

  int GetRows() const { return lattice_.size(); }
  int GetColums() const { return lattice_[0].size(); }

  std::size_t Population() const {
    int living_cells{0};
    for (int i = 0; i < GetRows(); ++i) {
      for (int j = 0; j < GetColums(); ++j) {
        living_cells += lattice_[i][j]->GetState().GetState();
      }
    }
    return living_cells;
  }

  std::ostream &display(std::ostream &os) const {
    // std::cout << GetRows() << " " << GetColums() << std::endl;
    for (int i = 0; i < lattice_.size(); ++i) {
      for (int j = 0; j < lattice_[i].size(); ++j) {
        os << *lattice_[i][j] << "  ";
      }
      std::cout << std::endl;
    }
    return os;
  }

  void SaveGeneration() {
    std::string filename;
      std::cout << "What's the filename to save the lattice? --> ";
      std::cin >> filename;
      std::ofstream file{filename};
      Position *p;
      file << GetDimension();
      file << "\n";
        file << GetDimensions()[0] << " " << GetDimensions()[1] << "\n";
        for (int i = 0; i < lattice_.size(); ++i) {
          for (int j = 0; j < lattice_[i].size(); ++j) {
            file << lattice_[i][j]->GetState().GetChar();
          }
          file << "\n";
        }
  }

  std::vector<std::vector<Cell*>>& GetMatrix() {return lattice_;}

protected:
  std::vector<std::vector<Cell *>> lattice_;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Lattice2DPeriodic : public Lattice2D {
public:
  Lattice2DPeriodic(const int kRow, const int kColum, const FactoryCell &kFactory) : Lattice2D(kRow, kColum, kFactory) {}
  Lattice2DPeriodic(const std::string& kFilename, const FactoryCell& kFactory) : Lattice2D(kFilename, kFactory) {}

  void nextGeneration() {
    for (int i = 0; i < GetRows(); ++i) {
      for (int j = 0; j < GetColums(); ++j) {
        lattice_[i][j]->SetNextState(lattice_[i][j]->NextState(*this));
      }
    }
    for (int i = 0; i < GetRows(); ++i) {
      for (int j = 0; j < GetColums(); ++j) {
        lattice_[i][j]->UpdateState();
      }
    }
  }

  Cell &operator[](const Position &kPosition) {
    int positionX = kPosition[0];
    if (positionX < 0) {
      positionX = GetRows() - 1;
    }
    if (positionX >= GetRows()) {
      positionX = 0;
    }
    int positionY = kPosition[1];
    if (positionY < 0) {
      positionY = GetColums() - 1;
    }
    if (positionY >= GetColums()) {
      positionY = 0;
    }
    return *lattice_[positionX][positionY];  
  }
};

class Lattice2DOpen : public Lattice2D {
public:
  Lattice2DOpen(const int kRow, const int kColum, const FactoryCell &kFactory, const bool kOpen_type) : Lattice2D(kRow, kColum, kFactory) {
    State state(kOpen_type);
    PositionDim<2,int> p(2,-1,-1);
    std::vector<Cell*> v;
    v.reserve(lattice_[0].size());
    v.resize(lattice_[0].size());
    for (int i = 0; i < kColum; ++i) {
        v[i] = factory_.createCell(p,state);
    }
    lattice_.insert(lattice_.begin(), v);
    lattice_.emplace_back(v);
    for (int i = 0; i < lattice_.size(); ++i) {
        lattice_[i].insert(lattice_[i].begin(), factory_.createCell(p,state));
        lattice_[i].emplace_back(factory_.createCell(p,state));
    }
  }
  Lattice2DOpen(const std::string& kFilename, const FactoryCell& kFactory, const bool kOpen_type) : Lattice2D(kFilename, kFactory) {
    State state(kOpen_type);
    PositionDim<2,int> p(2,-1,-1);
    std::vector<Cell*> v;
    v.reserve(lattice_[0].size());
    v.resize(lattice_[0].size());
    for (int i = 0; i < dimensions_[1]; ++i) {
        v[i] = factory_.createCell(p,state);
    }
    lattice_.insert(lattice_.begin(), v);
    lattice_.emplace_back(v);
    for (int i = 0; i < lattice_.size(); ++i) {
        lattice_[i].insert(lattice_[i].begin(), factory_.createCell(p,state));
        lattice_[i].emplace_back(factory_.createCell(p,state));
    }
  }

  void nextGeneration() {
    for (int i = 1; i < lattice_.size() - 1; ++i) {
      for (int j = 1; j < lattice_[i].size() - 1; ++j) {
        lattice_[i][j]->SetNextState(lattice_[i][j]->NextState(*this));
      }
    }
    for (int i = 1; i < lattice_.size() - 1; ++i) {
      for (int j = 1; j < lattice_[i].size() - 1; ++j) {
        lattice_[i][j]->UpdateState();
      }
    }
  }

  Cell &operator[](const Position &kPosition) {
    int positionX = kPosition[0];
    int positionY = kPosition[1];
    return *lattice_[positionX + 1][positionY + 1];  
  }
};

class Lattice2DReflected : public Lattice2D {
public:
  Lattice2DReflected(const int kRow, const int kColum, const FactoryCell &kFactory) : Lattice2D(kRow, kColum, kFactory) {}
  Lattice2DReflected(const std::string& kFilename, const FactoryCell& kFactory) : Lattice2D(kFilename, kFactory) {}
  void nextGeneration() {
    for (int i = 0; i < lattice_.size(); ++i) {
      for (int j = 0; j < lattice_[i].size(); ++j) {
        lattice_[i][j]->SetNextState(lattice_[i][j]->NextState(*this));
      }
    }
    for (int i = 0; i < lattice_.size(); ++i) {
      for (int j = 0; j < lattice_[i].size(); ++j) {
        lattice_[i][j]->UpdateState();
      }
    }
  }

  Cell &operator[](const Position &kPosition) {
    int positionX = kPosition[0];
    if (positionX < 0) {
      positionX = 0;
    }
    if (positionX >= GetRows()) {
      positionX = GetRows() - 1;
    }

    int positionY = kPosition[1];
    if (positionY < 0) {
      positionY = 0;
    }
    if (positionY >= GetColums()) {
      positionY = GetColums() - 1;
    }
    // std::cout << positionX << "|" << positionY << " ";
    return *lattice_[positionX][positionY];  
  }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Lattice2DNoBorder : public Lattice2D {
public:
  Lattice2DNoBorder(const int kRow, const int kColum, const FactoryCell &kFactory) : Lattice2D(kRow, kColum, kFactory) {
    initial_row_ = 0;
    initial_colum_ = 0;
  }
  Lattice2DNoBorder(const std::string& kFilename, const FactoryCell& kFactory) : Lattice2D(kFilename, kFactory) {
    initial_row_ = 0;
    initial_colum_ = 0;
  }

  void nextGeneration() {
    CheckBorders();
    for (int i = 0; i < lattice_.size(); ++i) {
      for (int j = 0; j < lattice_[i].size(); ++j) {
        lattice_[i][j]->SetNextState(lattice_[i][j]->NextState(*this));
      }
    }
    for (int i = 0; i < lattice_.size(); ++i) {
      for (int j = 0; j < lattice_[i].size(); ++j) {
        lattice_[i][j]->UpdateState();
      }
    }
  }
  void AddUpperRow() {
    State dead(0);
    --initial_row_;
    Position* p;
    std::vector<Cell*> v;
    v.resize(GetColums());
    for (int i = 0; i < lattice_[0].size(); ++i) {
        p = new PositionDim<2,int>(2, initial_row_, i + initial_colum_);
        v[i] = factory_.createCell(*p, dead);
    }
    lattice_.insert(lattice_.begin(), v);
  }
  void AddLowerRow() {
    State dead(0);
    Position* p;
    std::vector<Cell*> v;
    v.resize(lattice_[0].size());
    for (int i = 0; i < lattice_[i].size(); ++i) {
        p = new PositionDim<2,int>(2, lattice_.size() + initial_row_, i + initial_colum_);
        v[i] = factory_.createCell(*p, dead);
    }
    lattice_.emplace_back(v);
  }
  void AddLeftColum() {
    --initial_colum_;
    State dead(0);
    Position* p;
    for (int i = 0; i < GetRows(); ++i) {
      p = new PositionDim<2,int> (2, i + initial_row_, initial_colum_);
      lattice_[i].insert(lattice_[i].begin(), factory_.createCell(*p, dead));
    }
  }
  void AddRightColum() {
    State dead(0);
    Position* p;
    for (int i = 0; i < lattice_.size(); ++i) {
      p = new PositionDim<2,int> (2, i + initial_row_, lattice_[i].size() + initial_colum_);
      lattice_[i].emplace_back(factory_.createCell(*p, dead));
    }
  }

  void CheckBorders() {
    for (int i = 0; i < GetColums(); ++i) {
        if(lattice_[0][i]->GetState().GetState() == 1) {
            AddUpperRow();
            break;
        }
    }
    for (int i = 0; i < GetColums(); ++i) {
        if(lattice_[lattice_.size() - 1][i]->GetState().GetState() == 1) {
            AddLowerRow();
            break;
        }
    }
    for (int i = 0; i < lattice_.size(); ++i) {
        if(lattice_[i][0]->GetState().GetState() == 1) {
            AddLeftColum();
            break;
        }
    }
    for (int i = 0; i < lattice_.size(); ++i) {
        if(lattice_[i][lattice_[i].size() + initial_colum_]->GetState().GetState() == 1) {
            AddRightColum();
            break;
        }
    }
  }

  Cell &operator[](const Position &kPosition) {
    int positionX = kPosition[0];
    if (positionX >= initial_row_ && positionX <= GetRows() - 1 + initial_row_) {
      positionX = positionX - initial_row_;
    }
    if (positionX < initial_row_) {
      int pos{GetRows() - 1};
      if (initial_row_ < 0) {
        pos + initial_row_;
      }
      positionX = pos;
     } 
     if (positionX > GetRows() + initial_row_) {
      positionX = 0;
     }
    ////////////////////////////////////////////////////////////////////////////////
    int positionY = kPosition[1];
    if (positionY >= initial_colum_ && positionY <= GetColums() - 1 + initial_colum_) {
      positionY = positionY - initial_colum_;
    }
    if (positionY < initial_colum_) {
      int pos2{GetColums() - 1};
      if (initial_colum_ < 0) {
        pos2 + initial_colum_;
      }
      positionY = pos2;
    } 
    if (positionY > GetColums() + initial_colum_) {
      positionY = 0;
    }
    //std::cout << positionX << "|" << positionY << " ";
    return *lattice_[positionX][positionY];  
  }
  protected: 
    int initial_row_{0};
    int initial_colum_{0};

};

#endif