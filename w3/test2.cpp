#include <vector>
#include <iostream>
#include <string>

class Vec3D
{
public:
  int x;
  int y;
  int z;
};

int main()
{

  Vec3D vec1;
  vec1.x = 10;
  vec1.y = 20;
  vec1.z = 30;

  std::vector<Vec3D> coords;
  coords.push_back(vec1);
  coords[0].x;

  return 0;
}