class Car
{
public:
  Car();
  void accelerate();
  static int whichIsFaster(Car carA, Car carB);

private:
  float speed;
}

Car::Car() : speed(0.0f)
{
}

void Car::accelerate()
{
  speed += 0.5f;
}

int Car::whichIsFaster(Car carA, Car carB)
{
  if (carA.speed > carB.speed)
  {
    return 0;
  }
  return 1;
}

int main()
{
  Car car1{};
  car1.accelerate();
  Car car2;
  car2.accelerate();
  car2.accelerate();

  Car::whichIsFaster(car1, car2);
}