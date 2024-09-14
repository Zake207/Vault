#include <iostream>
#include <unistd.h> 

#include "DispersionFunction.h"
#include "ExplorationFunction.h"
#include "Sequence.h"
#include "HashTable.h"
#include "Nif.h"

int main() {
    DispersionFunction<Nif>* df = new DispersionFunctionModule<Nif>(7);

    DispersionFunction<Nif>* f = new DispersionFunctionSum<Nif>(7);

    ExplorationFuntion<Nif>* ef = new ExplorationFunctionLineal<Nif>;

    // HashTable<int, DynamicSequence<int>> table (7, *df);
    // table.insert(23);
    // table.insert(0);
    // table.insert(1);
    // table.insert(3);
    // table.insert(4);
    // table.insert(5);
    // table.insert(6);
    // table.insert(7);
    // table.insert(8);
    // std::cout << table;
    // table.search(23);
    // table.search(76);

    HashTable<Nif, StaticSequence<Nif>> table(7, *df, *ef, 3);
    std::cout << table;
    Nif dni(0), dni1(7), dni2(14), dni3(21), dni4(28), dni5(35), dni6(3), dni7(17);
    table.insert(dni);
    table.insert(dni1);
    table.insert(dni2);
    std::cout << table;
    table.insert(dni3);
    table.insert(dni4);
    table.insert(dni5);
    table.insert(dni6);
    table.insert(dni7);
    std::cout << table;

    std::cout << dni6 % 7 << std::endl;

}
