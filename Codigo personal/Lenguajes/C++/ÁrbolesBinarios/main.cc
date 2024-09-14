#include <iostream>
#include <fstream>

#include "src/ArbolB.h"
#include "src/NodoB.h"
#include "src/Nif.h"

int main(int argc, char* argv[]) {
system("clear");
  srand((unsigned)time(NULL));
  int ab{0}, init{0}, random_elements{1};
  std::string filename{};
  std::vector<std::string_view> args(argv + 1, argv + argc);
  // This part of the program reads the parameters passed by command line
  for (auto i = args.begin(), end = args.end(); i != end; ++i) {
    if ( *i == "-ab") {
        ++i;
        if (*i == "abe") ab = 0;
        if (*i == "abb") ab = 1;
    }
    if ( *i == "-init") {
        ++i;
        if (*i == "manual") init = 0;
        if (*i == "file") {
            init = 1;
            ++i;
            filename = i->data();
        }
        if (*i == "random") {
            ++i;
            random_elements = atoi(i->data());
            init = 2;
        }
    }
  }
  ArbolB<Nif>* arbol;
  switch (ab) {
  case 0:
    std::cout << "# Creando Árbol Binario Equilibrado..." << std::endl;
    arbol = new ArbolBE<Nif> ();
    break;
  case 1:
    std::cout << "# Creando Árbol Binario Balanceado..." << std::endl;
    arbol = new ArbolBB<Nif> ();
    break;
  default:
    std::cout << "# Tipo de arbol inválido, cerrando programa." << std::endl;
    return -1;
    break;
  }
  switch (init) {
  case 1: {
    std::cout << "# Leyendo árbol del fichero " << filename << std::endl;
    std::ifstream file(filename);
    int number;
    while (file >> number) {
      Nif nodo(number);
      arbol->Insertar(nodo);
    }
  }
    break;
  case 2:
    if (random_elements < 0) {
        std::cout << "# Número de valores inválido, cerrando programa..." << std::endl;
        return -1;
    }
      std::cout << "# Insertando " << random_elements << " elementos aleatorios." << std::endl;
      for (int i = 0; i < random_elements; ++i) {
        Nif nif;
        arbol->Insertar(nif);
      }
    break;
  default:
    break;
  }
  std::cout << *arbol << std::endl;
  int option;
      system("clear");
  while (true) {
    std::cout << *arbol << "\n\n";
    std::cout << "[0] Salir" << std::endl;
    std::cout << "[1] Insertar" << std::endl;
    std::cout << "[2] Buscar" << std::endl;
    std::cout << "[3] Mostrar en inorden" << std::endl;
    std::cin >> option;
    switch (option) {
    case 0:
        return 0;
        break;
    case 1: {
        int number;
        std::cout << "Introdizca el valor a insertar:";
        std::cin >> number; 
        Nif n(number);
        std::cout << "\nInsertando...\n";
        arbol->Insertar(n);
      }
      break;
    case 2: {
        int number1;
        std::cout << "Introdizca el valor a buscar:";
        std::cin >> number1; 
        Nif n1(number1);
        std::cout << "\nBuscando...\n";
        if (arbol->Buscar(n1)) std::cout << "# Encontrado" << std::endl;
      }
      break;
    case 3:
        arbol->Inorden(arbol->GetRaiz());
      break;
    
    default:
        break;
    }
  }
}