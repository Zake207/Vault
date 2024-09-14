#include <iostream>
#include <unistd.h> 

#ifndef __NIF__
#define __NIF__

class Nif {
public:
  Nif() {
    nif_ = 10000000 + (rand() % 89999999);
  }

  Nif(const int kNumber) {
    nif_ = kNumber;
  }
  int GetValue() const { return nif_; }
  bool operator<(int number) const { return GetValue() < number; }
  bool operator<(const Nif& nif) const { return GetValue() < nif.GetValue(); }

  bool operator<=(int number) const { return GetValue() <= number; }
  bool operator<=(const Nif& nif) const { return GetValue() <= nif.GetValue(); }

  bool operator>(int number) const { return GetValue() > number; }
  bool operator>(const Nif& nif) const { return GetValue() > nif.GetValue(); }

  bool operator>=(int number) const { return GetValue() >= number; }
  bool operator>=(const Nif& nif) const { return GetValue() >= nif.GetValue(); }

  bool operator==(int number) const { return GetValue() == number; }
  bool operator==(const Nif& nif) const { return GetValue() == nif.GetValue(); }

  int operator%(int number) const { return GetValue() % number; }
  int operator%(const Nif& nif) const { return GetValue() % nif.GetValue(); }

  operator int() const {
    return GetValue();
  }

  operator unsigned() const {
    return GetValue();
  }
  
  operator long() const {
    return GetValue();
  }

  friend std::ostream& operator<<(std::ostream& os, const Nif& nif) {
    os << nif.GetValue();
    return os;
  }

  friend std::istream& operator>>(std::istream& is, Nif& nif) {
    is >> nif.nif_;
    return is;
  }

private:
  int nif_{0};
};

#endif