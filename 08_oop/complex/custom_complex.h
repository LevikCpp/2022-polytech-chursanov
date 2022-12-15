#include <cmath>

template <typename TYPE> class custom_complex {
private:
  TYPE _Re, _Im; // вещественная и мнимая части

public:
  custom_complex() { _Re, _Im = 0; }
  custom_complex(TYPE Re, TYPE Im) {
    _Re = Re;
    _Im = Im;
  }
  ~custom_complex() { _Re, _Im = 0; }

  const custom_complex operator+(const custom_complex cmpl) const {
    return custom_complex(_Re + cmpl._Re, _Im + cmpl._Im);
  }
  const custom_complex operator-(const custom_complex cmpl) const {
    return custom_complex(_Re - cmpl._Re, _Im - cmpl._Im);
  }
  const bool operator==(const custom_complex cmpl) const {
    return _Re == cmpl._Re && _Im == cmpl._Im;
  }
  const double abs() const {
    return sqrt(this->_Re * this->_Re + this->_Im * this->_Im);
  }
};
