#include <iostream>
#include <unistd.h> 

#include "DispersionFunction.h"
#include "ExplorationFunction.h"
#include "Sequence.h"
#include "HashTable.h"
#include "Nif.h"

int main(int argc, char *argv[]) {
  int tablesize{1}, block_size{1};
  bool open{false};
  DispersionFunction<Nif>* dispersion;
  DispersionFunction<Nif>* aux_dispersion;
  ExplorationFuntion<Nif>* exploration;
  std::vector<std::string_view> args(argv + 1, argv + argc);
  for (auto i = args.begin(), end = args.end(); i != end; ++i) {
    if (*i == "-ts") {
        ++i;
        tablesize = atoi(i->data());
    }
    if (*i == "-fd") {
        ++i;
        if(*i == "module") {
            dispersion = new DispersionFunctionModule<Nif>(tablesize);
        }
        if(*i == "sum") {
            dispersion = new DispersionFunctionSum<Nif>(tablesize);
        }
        if(*i == "random") {
            dispersion = new DispersionFunctionRandom<Nif>(tablesize);
        }
    }
    if (*i == "-hash") {
        ++i;
        if(*i == "open") {
            open = true;
        }
        if(*i == "closed") {
            open = false;
        }
    }
    if (*i == "-fe") {
        ++i;
        if(*i == "lineal") {
            exploration = new ExplorationFunctionLineal<Nif>;
        }
        if(*i == "cuadratic") {
            exploration = new ExplorationFunctionCuadratic<Nif>;
        }
        if(*i == "double") {
            ++i;
            if(*i == "module") {
                aux_dispersion = new DispersionFunctionModule<Nif>(tablesize);
            }
            if(*i == "sum") {
                aux_dispersion = new DispersionFunctionSum<Nif>(tablesize);
            }
            if(*i == "random") {
                aux_dispersion = new DispersionFunctionRandom<Nif>(tablesize);
            }
            exploration = new ExplorationFunctionDouble<Nif>(*aux_dispersion);
        }
        if(*i == "redispersion") {
            ++i;
            if(*i == "module") {
                aux_dispersion = new DispersionFunctionModule<Nif>(tablesize);
            }
            if(*i == "sum") {
                aux_dispersion = new DispersionFunctionSum<Nif>(tablesize);
            }
            if(*i == "random") {
                aux_dispersion = new DispersionFunctionRandom<Nif>(tablesize);
            }
            exploration = new ExplorationFunctionRedispersion<Nif>(*aux_dispersion);
        }
    }
    if (*i == "-bs") {
        ++i;
        block_size = atoi(i->data());
    }
  }
  if (open) {
    HashTable<Nif, DynamicSequence<Nif>> table(tablesize, *dispersion);
    while(true) {
        std::cout << "####  Menú  ####" << std::endl;
        // std::cout << "0. Auto-insertar" << std::endl; 
        std::cout << "1. Insertar" << std::endl;
        std::cout << "2. Buscar" << std::endl;
        std::cout << "3. Mostrar" << std::endl;
        std::cout << "4. Salir" << std::endl;
        int option;
        std::cin >> option;
        if (option == 0) {
            
        }
        if(option == 1) {
            int dni_int;
            std::cin >> dni_int;
            Nif dni(dni_int);
            table.insert(dni);
        }
        if(option == 2) {
            int dni_int;
            std::cin >> dni_int;
            Nif dni(dni_int);
            table.search(dni);
        }
        if(option == 3) {
            std::cout << table;
        }
        if(option == 4) {
            break;
        }
    }
  } else {
    HashTable<Nif,StaticSequence<Nif>> table(tablesize, *dispersion, *exploration, block_size);
    while (true) {
        std::cout << "####  Menú  ####" << std::endl;
        std::cout << "1. Insertar" << std::endl;
        std::cout << "2. Buscar" << std::endl;
        std::cout << "3. Mostrar" << std::endl;
        std::cout << "4. Salir" << std::endl;
        int option;
        std::cin >> option;
        if(option == 1) {
            int dni_int;
            std::cin >> dni_int;
            Nif dni(dni_int);
            table.insert(dni);
        }
        if(option == 2) {
            int dni_int;
            std::cin >> dni_int;
            Nif dni(dni_int);
            table.search(dni);
        }
        if(option == 3) {
            std::cout << table;
        }
        if(option == 4) {
            break;
        }
    }
  }
  
}