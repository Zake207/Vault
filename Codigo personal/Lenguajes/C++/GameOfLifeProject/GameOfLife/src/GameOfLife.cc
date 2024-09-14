#include "../lib/Tools.h"

int main(int argc, char *argv[]) {
  int rows{0}, colums{0}, border_type{0}, open_type{0};
  bool read_file{};
  std::string filename{};
  std::vector<std::string_view> args(argv + 1, argv + argc);
  for (auto i = args.begin(), end = args.end(); i != end; ++i) {
    if (*i == "-size") {
      ++i;
      rows = atoi(i->data());
      ++i;
      colums = atoi(i->data());
    }
    if (*i == "-border") {
      ++i;
      if (*i == "periodic") {
        border_type = 1;
      }
      if (*i == "open") {
        border_type = 2;
        ++i;
        open_type = atoi(i->data());
      }
      if (*i == "mirror" || *i == "reflected") {
        border_type = 3;
      }
      if (*i == "noborder") {
        border_type = 4;
      }
    }
    if (*i == "-init") {
      ++i;
      filename = *i;
      read_file = true;
    }
  }
    if (read_file) {
        Lattice lattice(filename);
        GameOfLife(lattice);
    } else {
        State alive(1);
        Border border(border_type, open_type);
        Lattice lattice(rows, colums, border);
        std::pair<int, int> position{};
        std::cout << "Introduzca la posición de las células vivas. (-1 -1) para terminar la lectura" << std::endl;
        while (std::cin >> position.first >> position.second) {
          if (position.first < 0 && position.second < 0) {
            break;
          }
          lattice.AccesToMatrix()[position.first][position.second].SetState(alive);
        }
        GameOfLife(lattice);
    }
  return 0;
}