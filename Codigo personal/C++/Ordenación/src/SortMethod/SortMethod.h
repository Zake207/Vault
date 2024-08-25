#include <iostream>
#include <vector>

#include "../Nif/Nif.h"
#include "../Sequence/Sequence.h"
#include "../../lib/Tools.h"
#include "../../lib/OrderAlgorithm.h"

template <class Key>
class SortMethod {
    public:
        virtual void sort(StaticSequence<Key> &sequence, bool show) = 0;
};

template <class Key>
class SelectionSort: public SortMethod<Key> {
    public:
        void sort(StaticSequence<Key> &sequence, bool show) {
            std::cout << "Using SelectionSort.\n";
            Algorithm_Selection(sequence, show);
        }
};

template <class Key>
class HeapSort: public SortMethod<Key> {
    public:
        void sort(StaticSequence<Key> &sequence, bool show) {
            std::cout << "Using HeapSort.\n";
            Algorithm_HeapSort(sequence, sequence.GetSize(), show);
        }
};

template <class Key>
class QuickSort: public SortMethod<Key> {
    public:
        void sort(StaticSequence<Key> &sequence, bool show) {
            std::cout << "Using QuickSort.\n";
            Algorithm_QuickSort(sequence, 0, sequence.GetSize() - 1, show);
        }
};

template <class Key>
class ShellSort: public SortMethod<Key> {
    public:
        void sort(StaticSequence<Key> &sequence, bool show) {
            std::cout << "Using ShellSort.\n";
            Algorithm_ShellSort(sequence, show);
        }
};

template <class Key>
class RadixSort: public SortMethod<Key> {
    public:
        void sort(StaticSequence<Key> &sequence, bool show) {
            std::cout << "Using RadixSort.\n";
            Algorithm_RadixSort(sequence, show);
        }
};