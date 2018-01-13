#include <iostream>
#include <string>

class Wheel
{
public:
  bool IsFlat() const;
  void Set(bool condition);

private:
  bool _flat{true};
};
bool Wheel::IsFlat() const
{
  return _flat;
}

void Wheel::Set(bool condition)
{
  _flat = condition;
}

class Car
{
public:
  bool InstallWheel(Wheel *, int);

private:
  Wheel *_wheels[4];
};

bool Car::InstallWheel(Wheel *wheel, int i)
{
  if (wheel->IsFlat() == false)
  {
    _wheels[i] = wheel;
    return true;
  }
  else
  {
    return false;
  }
}

class SpareTire
{
public:
  int GetPressure() const;
  void Pump(int pressure);

private:
  int _pressure;
};

int SpareTire::GetPressure() const
{
  return _pressure;
}

void SpareTire::Pump(int pressure)
{
  _pressure = pressure;
}

class Adapter : public Wheel
{
public:
  Adapter() = delete;
  Adapter(SpareTire *);

private:
  SpareTire *_spareTire;
};

Adapter(SpareTire *tire)
{
  _spareTire = tire;
}

int main()
{
}
