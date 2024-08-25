#include "Lattice.h"
#include "Lattice1D.h"
#include <iostream>
#include <vector>

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

/// @brief Execute a loop where the lattice recived is updated constantly
/// depending on the instruction recived.
/// @param Lattice The lattice that will be updated.
void GameOfLife(Lattice &Lattice) {
  bool option_c{false};
  //system("clear");
  std::cout << Lattice;
  char instruction{'a'};
  while (std::cin.get(instruction)) {
    if (instruction == 'x') {
      system("clear");
      return;
    }
    std::cout << instruction  << "h" << std::endl;
    if (instruction == 'n') {
      //system("clear");
      if (!option_c) {
        Lattice.nextGeneration();
        std::cout << Lattice;
      } else {
        Lattice.nextGeneration();
        std::cout << "Population: " << Lattice.Population() << std::endl;
      }
    }
    if (instruction == 'L') {
      system("clear");
      for (int i = 0; i < 5; ++i) {
        if (!option_c) {
          Lattice.nextGeneration();
          std::cout << Lattice << std::endl;
        } else {
          Lattice.nextGeneration();
          std::cout << "Population: " << Lattice.Population();
        }
      }
    }
    if (instruction == 'c') {
      option_c = !option_c;
      std::cout << "Population: " << Lattice.Population() << std::endl;
    }
    if (instruction == 's') {
      Lattice.SaveGeneration();
    }
  }
}