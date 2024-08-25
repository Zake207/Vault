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

    void SetNewState(const int kState);
    
 private:
    int state_{0};
    char caracter_{'-'};
};


#endif