#include <iostream>

// Vehicle 클래스 정의
class Vehicle
{
public:
  Vehicle();
  float getSpeed();
  void accelerate();
  void beepHorn();

private:
  float speed;
};

class Train : public Vehicle
{
public:
  Train();
  void beepHorn();
};

Train::Train()
{
}

void Train::beepHorn()
{
  if (getSpeed() < 0.5f)
  {
    std::cout << "toot toot" << std::endl;
  }
  else
  {
    std::cout << "TOOT TOOT" << std::endl;
  }
}

Vehicle::Vehicle() : speed(0.0f)
{
}

float Vehicle::getSpeed()
{
  return speed;
}

void Vehicle::accelerate()
{
  speed += 0.5f;
}

void Vehicle::beepHorn()
{
  std::cout << "Beep beep!" << std::endl;
}

int main()
{
  Vehicle v;
  v.beepHorn();

  Train t;
  t.beepHorn();
  t.accelerate();
  t.beepHorn();
}