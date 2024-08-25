#include <fstream>
#include <iostream>
#include <vector>

#include "../lib/Lattice.h"

/// @brief The principal constructor of the lattice.
/// @param kRows The number of rows that the lattice will have
/// @param kColums The number of the colums that the lattice will have
/// @param kBorder The type of border condition.
Lattice::Lattice(const int kRows, const int kColums, const Border &kBorder) {
  border_ = kBorder;
  for (int i = 1; i < kRows; ++i) {
    AccesToMatrix().AddLowerRow();
  }
  for (int i = 1; i < kColums; ++i) {
    AccesToMatrix().AddRightColum();
  }
  original_colum_ = kColums;
  original_row_ = kRows;
  if (border_.GetBorderType() == 2) {
    if (border_.GetOpenType() == 1) {
      AccesToMatrix().AddLeftColum();
      AccesToMatrix().AddLowerRow();
      AccesToMatrix().AddRightColum();
      AccesToMatrix().AddUpperRow();
    }
    if (border_.GetOpenType() == 2) {
      AccesToMatrix().AddLeftColumAlive();
      AccesToMatrix().AddLowerRowAlive();
      AccesToMatrix().AddRightColumAlive();
      AccesToMatrix().AddUpperRowAlive();
    }
  }
  // if (border_.GetBorderType() == 3) {
  //   State alive(1);
  //   AccesToMatrix().AddLowerRow();
  //   AccesToMatrix().AddUpperRow();
  //   for (int i = GetMatrix().GetInitialColum(); i < GetMatrix().GetColums() - 1 + GetMatrix().GetInitialColum(); ++i) {
  //     if (GetMatrix()[0][i].GetState().GetState() == 1) {
  //       AccesToMatrix()[-1][i].SetState(alive);
  //     }
  //     // if (GetMatrix()[GetOriginRow() - 1][i].GetState().GetState() == 1) {
  //     //   AccesToMatrix()[GetOriginRow()]
  //     // }
  //   }
  //   AccesToMatrix().AddLeftColum();
  //   AccesToMatrix().AddRightColum();
  // }
}

/// @brief Modification of the main constructor of the lattice.
/// @param kRows The number of rows that the lattice will have
/// @param kColums The number of the colums that the lattice will have
Lattice::Lattice(const int kRows, const int kColums) {
  Border periodic(1);
  border_ = periodic;
  for (int i = 1; i < kRows; ++i) {
    AccesToMatrix().AddLowerRow();
  }
  for (int i = 1; i < kColums; ++i) {
    AccesToMatrix().AddRightColum();
  }
  original_colum_ = kColums;
  original_row_ = kRows;
  if (border_.GetBorderType() == 2) {
    if (border_.GetOpenType() == 1) {
      AccesToMatrix().AddLeftColum();
      AccesToMatrix().AddLowerRow();
      AccesToMatrix().AddRightColum();
      AccesToMatrix().AddUpperRow();
    }
    if (border_.GetOpenType() == 2) {
      AccesToMatrix().AddLeftColumAlive();
      AccesToMatrix().AddLowerRowAlive();
      AccesToMatrix().AddRightColumAlive();
      AccesToMatrix().AddUpperRowAlive();
    }
  }
}

/// @brief Constructor of the object based on file reading
/// @param kFilename A string that represent the name of the file
Lattice::Lattice(const std::string &kFilename) {
  int rows{0}, colums{0}, border_type{0}, open_type{0};
  State dead(0), alive(1);
  std::fstream file(kFilename);
  std::string content{};

  file >> rows;
  original_row_ = rows;
  file >> colums;
  original_colum_ = colums;
  file >> border_type;
  file >> open_type;

  Border border(border_type, open_type);
  border_ = border;
  for (int i = 1; i < rows; ++i) {
    AccesToMatrix().AddLowerRow();
  }
  for (int i = 1; i < colums; ++i) {
    AccesToMatrix().AddRightColum();
  }
  if (border_.GetBorderType() == 2) {
    if (border_.GetOpenType() == 1) {
      AccesToMatrix().AddLeftColum();
      AccesToMatrix().AddLowerRow();
      AccesToMatrix().AddRightColum();
      AccesToMatrix().AddUpperRow();
    }
    if (border_.GetOpenType() == 2) {
      AccesToMatrix().AddLeftColumAlive();
      AccesToMatrix().AddLowerRowAlive();
      AccesToMatrix().AddRightColumAlive();
      AccesToMatrix().AddUpperRowAlive();
    }
  }
  std::vector<std::string> pattern{};
  getline(file, content);
  for (int i = 0; i <= rows; ++i) {
    getline(file, content);
    pattern.push_back(content);
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < colums; ++j) {
      file >> content;
      if (pattern[i][j] == '0') {
        AccesToMatrix()[i][j].SetState(dead);
      }
      if (pattern[i][j] == '1') {
        AccesToMatrix()[i][j].SetState(alive);
      }
    }
  }
  if (border_.GetBorderType() == 3) {
    State alive(1);
    AccesToMatrix().AddLowerRow();
    AccesToMatrix().AddUpperRow();
    for (int i = GetMatrix().GetInitialColum(); i < GetMatrix().GetColums() + GetMatrix().GetInitialColum(); ++i) {
      if (GetMatrix()[0][i].GetState().GetState() == 1) {
        AccesToMatrix()[-1][i].SetState(alive);
      }
      if (GetMatrix()[GetOriginRow() - 1][i].GetState().GetState() == 1) {
        AccesToMatrix()[GetOriginRow()][i].SetState(alive);
      }
    }
    AccesToMatrix().AddLeftColum();
    AccesToMatrix().AddRightColum();
    for (int i = GetMatrix().GetInitialRow(); i < GetMatrix().GetRows() + GetMatrix().GetInitialRow(); ++i) {
      if (GetMatrix()[i][0].GetState().GetState() == 1) {
        AccesToMatrix()[i][-1].SetState(alive);
      }
      if (GetMatrix()[i][GetOriginColum() - 1].GetState().GetState() == 1) {
        AccesToMatrix()[i][GetOriginColum()].SetState(alive);
      }
    }
  }
}

void Lattice::MirrorBorders() {
  State alive(1), dead(0);
    for (int i = GetMatrix().GetInitialColum(); i < GetMatrix().GetColums() + GetMatrix().GetInitialColum(); ++i) {
      if (GetMatrix()[0][i].GetState().GetState() == 1) {
        AccesToMatrix()[-1][i].SetState(alive);
      } else {
        AccesToMatrix()[-1][i].SetState(dead);
      }
      if (GetMatrix()[GetOriginRow() - 1][i].GetState().GetState() == 1) {
        AccesToMatrix()[GetOriginRow()][i].SetState(alive);
      } else {
        AccesToMatrix()[GetOriginRow()][i].SetState(dead);
      }
    }
    for (int i = GetMatrix().GetInitialRow(); i < GetMatrix().GetRows() + GetMatrix().GetInitialRow(); ++i) {
      if (GetMatrix()[i][0].GetState().GetState() == 1) {
        AccesToMatrix()[i][-1].SetState(alive);
      } else {
        AccesToMatrix()[i][-1].SetState(dead);
      }
      if (GetMatrix()[i][GetOriginColum() - 1].GetState().GetState() == 1) {
        AccesToMatrix()[i][GetOriginColum()].SetState(alive);
      } else {
        AccesToMatrix()[i][GetOriginColum()].SetState(dead);
      }
    }
}


/// @brief Calculate the next generation of the cells in the lattice
void Lattice::NextGeneration() {
  if (GetBorder().GetBorderType() == 4) {
    CheckBorders();
    for (int i = GetMatrix().GetInitialRow(); i < GetMatrix().GetRows() + GetMatrix().GetInitialRow(); ++i) {
      for (int j = GetMatrix().GetInitialColum(); j < GetMatrix().GetColums() + GetMatrix().GetInitialColum(); ++j) {
        AccesToMatrix()[i][j].SetNextState(GetMatrix()[i][j].NextState(*this));
      }
    }
    for (int i = GetMatrix().GetInitialRow();
         i < GetMatrix().GetRows() + GetMatrix().GetInitialRow(); ++i) {
      for (int j = GetMatrix().GetInitialColum();
           j < GetMatrix().GetColums() + GetMatrix().GetInitialColum(); ++j) {
        AccesToMatrix()[i][j].UpdateState();
      }
    }
  } else {
    for (int i = 0; i < GetOriginRow(); ++i) {
      for (int j = 0; j < GetOriginColum(); ++j) {
        AccesToMatrix()[i][j].SetNextState(GetMatrix()[i][j].NextState(*this));
      }
    }
    for (int i = 0; i < GetOriginRow(); ++i) {
      for (int j = 0; j < GetOriginColum(); ++j) {
        AccesToMatrix()[i][j].UpdateState();
      }
    }
    if (border_.GetBorderType() == 3) {
      MirrorBorders();
    }
  }
}

/// @brief Method that calculate the amount of living cells in the lattice
/// @return The number of living cells in the lattice
int Lattice::Population() const {
  int living_cells{0};
  if (GetBorder().GetBorderType() == 4) {
    for (int i = GetMatrix().GetInitialRow();
         i < GetMatrix().GetRows() + GetMatrix().GetInitialRow(); ++i) {
      for (int j = GetMatrix().GetInitialColum();
           j < GetMatrix().GetColums() + GetMatrix().GetInitialColum(); ++j) {
        if (GetMatrix()[i][j].GetState().GetState() == 1) {
          ++living_cells;
        }
      }
    }
  } else {
    for (int i = 0; i < GetOriginRow(); ++i) {
      for (int j = 0; j < GetOriginColum(); ++j) {
        if (GetMatrix()[i][j].GetState().GetState() == 1) {
          ++living_cells;
        }
      }
    }
  }
  return living_cells;
}

/// @brief Checks the borders of the lattice looking for living cells, if exists
/// expands
///        the lattice adding the necesaries rows and colums.
void Lattice::CheckBorders() {
  for (int i = GetMatrix().GetInitialColum();
       i < GetMatrix().GetColums() + GetMatrix().GetInitialColum(); ++i) {
    if (CheckCell(GetMatrix().GetInitialRow(), i) == 1) {
      AccesToMatrix().AddUpperRow();
      break;
    }
  }
  for (int i = GetMatrix().GetInitialColum();
       i < GetMatrix().GetColums() + GetMatrix().GetInitialColum(); ++i) {
    if (CheckCell(GetMatrix().GetRows() - 1 + GetMatrix().GetInitialRow(), i) ==
        1) {
      AccesToMatrix().AddLowerRow();
      break;
    }
  }
  for (int i = GetMatrix().GetInitialRow();
       i < GetMatrix().GetRows() + GetMatrix().GetInitialRow(); ++i) {
    if (CheckCell(i, GetMatrix().GetInitialColum()) == 1) {
      AccesToMatrix().AddLeftColum();
      break;
    }
  }
  for (int i = GetMatrix().GetInitialRow();
       i < GetMatrix().GetRows() + GetMatrix().GetInitialRow(); ++i) {
    if (CheckCell(i, GetMatrix().GetColums() - 1 +
                         GetMatrix().GetInitialColum()) == 1) {
      AccesToMatrix().AddRightColum();
      break;
    }
  }
}

/// @brief Checks the state of a specific cell in the lattice
/// @param kPos_x Position in the X-axis
/// @param kPos_y Positionin the Y-axis
/// @return Returns the state of the cell.
int Lattice::CheckCell(const int kPos_x, const int kPos_y) const {
  return GetMatrix()[kPos_x][kPos_y].GetState().GetState();
}

/// @brief The acces operator that allows to access an specific cell in the
/// lattice
/// @param kPosition A std::pair variable that represents the position of the
/// cell
/// @return A reference to the cell in the position
Cell &Lattice::operator[](const std::pair<int, int> &kPosition) {
  return AccesToMatrix()[kPosition.first][kPosition.second];
}

/// @brief The output operator of the class
/// @param os An ostream object passed by reference
/// @param kLattice The Lattice that will be printed
/// @return once printed, the ostream object is returned
std::ostream &operator<<(std::ostream &os, Lattice &kLattice) {
  std::cout << kLattice.GetMatrix();
  return os;
}
