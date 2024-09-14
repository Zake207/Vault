#include <iostream>
#include <vector>

#include "../src/Nif/Nif.h"
#include "../src/Sequence/Sequence.h"
#include "Tools.h"

#ifndef __ORDER_ALGORITHM__
#define __ORDER_ALGORITHM__

template <class Key>
void Algorithm_Selection(StaticSequence<Key> &sequence, bool show = false) {
  int i, j, min;
  Key temp;
  for (i = 0; i < sequence.GetSize() - 1; i++) {
    min = i;
    for (j = i + 1; j < sequence.GetSize(); j++) {
      if (sequence[j] < sequence[min]) {
        min = j;
      }
    }
    temp = sequence[min];
    sequence[min] = sequence[i];
    sequence[i] = temp;
    if (show) {
      sequence.Print();
    }
  }
}

template <class Key>
void Algorithm_HeapSort(StaticSequence<Key> &sequence, int size,
                        bool show = false) {
  if (show) {
    std::cout << "Insertando elementos en el montículo\n";
  }
  for (int i = (size / 2); i >= 0; --i) {
    baja_elemento(i, sequence, size);
    if (show) {
      sequence.Print();
    }
  }
  if (show) {
    std::cout << "Extrayendo elementos del montículo\n";
  }
  for (int i = size - 1; i >= 1; --i) {
    sequence.swap(0, i);
    baja_elemento(0, sequence, i - 1);
    if (show) {
      sequence.Print();
    }
  }
  std::cout << "Secuencia ordenada" << std::endl;
}

template <class Key>
void Algorithm_QuickSort(StaticSequence<Key> &sequence, int ini, int fin,
                         bool show = false) {
  int i = ini;
  int j = fin;
  Key pivot = sequence[(i + j) / 2];
  while (i <= j) {
    while (sequence[i] < pivot) {
      i++;
    }
    while (sequence[j] > pivot) {
      j--;
    }
    if (i <= j) {
      sequence.swap(i, j);
      i++;
      j--;
    }
  }
  if (ini < j) {
    Algorithm_QuickSort(sequence, ini, j, show);
  }
  if (i < fin) {
    Algorithm_QuickSort(sequence, i, fin, show);
  }
  sequence.Print();
}

template <class Key>
void Algorithm_ShellSort(StaticSequence<Key> &sequence, bool show = false) {
  int delta = sequence.GetSize();
  int j;
  Key X;
  while (delta > 1) {
    delta = (5 * delta - 1) / 11;
    for (int i = delta; i < sequence.GetSize(); ++i) {
      X = sequence[i];
      j = i;
      while ((j >= delta) && (X < sequence[j - delta])) {
        sequence[j] = sequence[j - delta];
        j = j - delta;
      }
      sequence[j] = X;
    }
    if (show) {
      sequence.Print();
    }
  }
}

template <class Key>
void Algorithm_RadixSort(StaticSequence<Key> &sequence, bool show = false) {
  int max{sequence[0]}, min{0}, j{0};
  Key temp;

  for (int i = 0; i < sequence.GetSize(); ++i) {
    if (sequence[i] > max) {
      max = sequence[i];
    }
  }

  int cifras{1}, counter{0}, cifra{10};
  while (max / 10 != 0) {
    max = max / 10;
    ++cifras;
  }

  while (counter <= cifras) {
    for (int i = 0; i < sequence.GetSize() - 1; ++i) {
      min = i;
      for (j = i + 1; j < sequence.GetSize(); ++j) {
        if ((sequence[j] % cifra) < (sequence[min] % cifra)) {
          min = j;
        }
      }
      temp = sequence[min];
      sequence[min] = sequence[i];
      sequence[i] = temp;
    }
    cifra = cifra * 10;
    ++counter;
    // if (show) {
    //   sequence.Print();
    // }
  }
}

#endif