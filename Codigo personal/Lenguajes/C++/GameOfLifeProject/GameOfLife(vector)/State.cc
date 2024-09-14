#include <iostream>

#include "State.h"

/// @brief Set a new state to the object
/// @param kState The new state that the object will have
void State::SetNewState(const int kState) {
  switch (kState) {
  case 0:
    state_ = 0;
    caracter_ = '-';
    break;
  case 1:
    state_ = 1;
    caracter_ = 'X';
    break;
  default:
    break;
  }
}