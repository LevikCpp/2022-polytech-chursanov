#include <cmath>
class complex
{
private:
  int _Re, _Im; // вещественная и мнимая части

public:
  complex();
  complex(int Re, int Im);
  ~complex();

  const complex operator+(const complex cmpl) const;
  const complex operator-(const complex cmpl) const;
  //void operator=(const complex cmpl);
  const bool operator==(const complex cmpl) const;
  const double abs() const;
};

complex::complex()
{
  _Re, _Im = 0;
}

complex::complex(int Re, int Im)
{
  _Re = Re;
  _Im = Im;
}
complex::~complex()
{
  _Re, _Im = 0;
}
// void operator=(const complex cmpl)
// {
//   this._Re = cmpl._Re
//   this._Im = cmpl._Im
// }
const complex complex::operator+(const complex cmpl) const
{
  return complex(_Re + cmpl._Re, _Im + cmpl._Im);
}
const complex complex::operator-(const complex cmpl) const
{
  return complex(_Re - cmpl._Re, _Im - cmpl._Im);
}
const bool complex::operator==(const complex cmpl) const
{
  return _Re == cmpl._Re && _Im == cmpl._Im;
}
const double complex::abs() const
{
  return sqrt(_Re * _Re + _Im * _Im);
}