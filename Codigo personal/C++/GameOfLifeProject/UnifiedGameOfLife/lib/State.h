#include <iostream>

#ifndef __STATUS__
#define __STATUS__

class State {
 public:
    State(const int& kState = 0) {
        // std::cout << "# State constructor has been called." << std::endl;
        SetNewState(kState);
    }

    char GetChar() const { return caracter_; }
    int GetState() const { return state_; }

    void SetNewState(const int kState) {
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
    
 private:
    int state_{0};
    char caracter_{'-'};
};


#endif