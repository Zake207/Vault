
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>

#include "Lattice.h"
#include "Cell.h"
//#include "State.h"

int main(int argc, char* argv[]) {
  int size{0};
  int border_type{0}, open_type{0};
  bool read_file{false};
  std::string filename{};
  std::vector<std::string_view> args(argv + 1, argv + argc);
  // This part of the program reads the parameters passed by command line
  for (auto i = args.begin(), end = args.end(); i != end; ++i) {
    if ( *i == "-size") {
        ++i;
        size = atoi(i->data());
    }
    if ( *i == "-border") {
      ++i;
      if (*i == "periodic") {
          border_type = 1;
      }
      if (*i == "open") {
        border_type = 2;
        ++i;
        open_type = atoi(i->data());
      }
      if (*i == "mirror") {
        border_type = 3;
      }
    }
    if ( *i == "-init") {
      ++i;
      filename = *i;
      read_file = true;
    }
  }
  // Creation of the lattice
  Border border(border_type, open_type);
  Lattice Lattice(size, border);
  // Reading of the initial state of the lattice
  if (read_file) {
    State dead(0), alive(1);
    std::fstream file(filename);
    std::string content{};
    getline(file, content);
    assert(content.size() == Lattice.GetSize());
    file.close();
    for (int i = 0; i < content.size(); ++i) {
      if(content[i] == '-') {
        Lattice.AccesToCell(i + 1).SetState(dead);
      }
      if(content[i] == 'X') {
        Lattice.AccesToCell(i + 1).SetState(alive);
      }
    }
  }

  std::cout << Lattice;
  char enterKey{};
  while (true) {
    enterKey = std::cin.get(); // Waits until the Enter button is pressed
    if (enterKey == '\n') {
    // std::cout << std::endl;
    Lattice.NextGeneration();
    std::cout << Lattice;
    } else if (enterKey == 'q') {
      break; // Return if 'q' is pressed
    }
  }
    return 0;
}