#include <iostream>
#include <vector>

#include "../src/Nif/Nif.h"
#include "../src/Sequence/Sequence.h"

#ifndef __TOOLS__
#define __TOOLS__

template <class Key>
void baja_elemento(int i, StaticSequence<Key> &sequence, int n) {
  int h, h1, h2;
  while (2 * i + 1 <= n) {
    h1 = 2 * i + 1;
    h2 = h1 + 1;
    if (h1 == n) {
      h = h1;
    }
    else if (sequence[h1] > sequence[h2]) {
        h = h1;
    }
    else {
        h = h2;
    }
    if (sequence[h] <= sequence[i]) {
      break;
    }
    else {
      sequence.swap(i, h);
      i = h;
    }
  }
}

#endif
