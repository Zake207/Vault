#include <iostream>

#include "src/Sequence/Sequence.h"
#include "src/Nif/Nif.h"
#include "src/SortMethod/SortMethod.h"
#include "lib/OrderAlgorithm.h"

int main(int argc, char *argv[]) {
  system("clear");
  srand((unsigned)time(NULL));
  int size{0}, order{1}, sequence_type{1};
  bool trace{false};
  std::string filename{};
  StaticSequence<Nif> sequence(1,true);
  SortMethod<Nif>* order_method;
  std::vector<std::string_view> args(argv + 1, argv + argc);
  // This part of the program reads the parameters passed by command line
  for (auto i = args.begin(), end = args.end(); i != end; ++i) {
    if ( *i == "-size") {
        ++i;
        size = atoi(i->data());
    }
    if ( *i == "-ord") {
        ++i;
        if ( *i == "Selection") {
            order = 1;
        }
        if ( *i == "Heap") {
            order = 2;
        }
        if ( *i == "Quick") {
            order = 3;
        }
        if ( *i == "Shell") {
            order = 4;
        }
        if ( *i == "Radix") {
            order = 5;
        }
    }
    if ( *i == "-init") {
        ++i;
        if ( *i == "manual") {
            sequence_type = 1;
        }
        if ( *i == "random") {
            sequence_type = 2;
        }
        if ( *i == "file") {
            ++i;
            filename = i->data();
            sequence_type = 3;
        }
    }
    if ( *i == "-trace") {
        trace = true;
    }
  }
  switch (sequence_type) {
  case 1:
    sequence = StaticSequence<Nif>(size);
    break;
  case 2:
    sequence = StaticSequence<Nif>(size, true);
    break;
  case 3:
    sequence = StaticSequence<Nif>(size, filename);
    break;
  default:
    std::cout << "Unknown type of initialization for the sequence, random selected\n";
    sequence = StaticSequence<Nif>(size, true);
    break;
  }
  sequence.Print();
  switch (order) {
  case 1:
    order_method = new SelectionSort<Nif>;
    break;
  case 2:
    order_method = new HeapSort<Nif>;
    break;
  case 3:
    order_method = new QuickSort<Nif>;
    break;
  case 4:
    order_method = new ShellSort<Nif>;
    break;
  case 5:
    order_method = new RadixSort<Nif>;
    break;
  default:
    std::cout << "Unknown type of ordenation method, finishing...\n";
    break;
  }
  order_method->sort(sequence, trace);
  sequence.Print();
  return 0;
}