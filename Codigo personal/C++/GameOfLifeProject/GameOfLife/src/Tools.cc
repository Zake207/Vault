#include "../lib/Tools.h"

/// @brief Prints the title of the program
void PrintTitle() {
  std::cout
      << "###################################################################"
      << std::endl;
  std::cout
      << "                        JUEGO DE LA VIDA                           "
      << std::endl;
  std::cout
      << "###################################################################"
      << std::endl;
}

/// @brief Execute a loop where the lattice recived is updated constantly depending on the instruction recived.
/// @param Lattice The lattice that will be updated.
void GameOfLife(Lattice &Lattice) {
  bool option_c{false};
  system("clear");
  PrintTitle();
  std::cout << Lattice;
  char instruction{};
  while (std::cin >> instruction) {
    if (instruction == 'x') {
      system("clear");
      return;
    }
    if (instruction == 'n') {
      system("clear");
      PrintTitle();
      if (!option_c) {
        Lattice.NextGeneration();
        std::cout << Lattice;
      } else {
        Lattice.NextGeneration();
        std::cout << "Population: " << Lattice.Population() << std::endl;
      }
    }
    if (instruction == 'L') {
      system("clear");
      PrintTitle();
      for (int i = 0; i < 5; ++i) {
        if (!option_c) {
          Lattice.NextGeneration();
          std::cout << Lattice;
        } else {
          Lattice.NextGeneration();
          std::cout << "Population: " << Lattice.Population();
        }
      }
    }
    if (instruction == 'c') {
      option_c = !option_c;
      std::cout << "Population: " << Lattice.Population() << std::endl;
    }
    if (instruction == 's') {
      std::string filename{};
      std::cout << "What's the filename to save the lattice? --> ";
      std::cin >> filename;
      std::ofstream file{filename};
      file << Lattice.GetMatrix().GetRows() << " "
           << Lattice.GetMatrix().GetColums() << " "
           << Lattice.GetBorder().GetBorderType() << " "
           << Lattice.GetBorder().GetOpenType() << '\n';
      for (int i = Lattice.GetMatrix().GetInitialRow();
           i <
           Lattice.GetMatrix().GetRows() + Lattice.GetMatrix().GetInitialRow();
           ++i) {
        for (int j = Lattice.GetMatrix().GetInitialColum();
             j < Lattice.GetMatrix().GetColums() +
                     Lattice.GetMatrix().GetInitialColum();
             ++j) {
              file << Lattice.GetMatrix()[i][j].GetState().GetState();
        }
        file << '\n'; 
      }
    }
  }
}