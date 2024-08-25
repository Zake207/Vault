#include <iostream>

#include "src/Sequence/Sequence.h"
#include "src/Nif/Nif.h"
#include "src/SortMethod/SortMethod.h"
#include "lib/OrderAlgorithm.h"

int main() {
    // StaticSequence<Nif> sequence(8);
    // sequence.Print();
    // HeapSort<Nif> heap_sort;
    // heap_sort.sort(sequence, true);
    // sequence.Print();
    StaticSequence<Nif> sequence(8, true);
    sequence.Print();
    RadixSort<Nif> sort;
    sort.sort(sequence, false);
    sequence.Print();
    return 0;
}