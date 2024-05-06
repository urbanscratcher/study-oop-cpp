#include <iostream>

// Error case 1 - if the name is not 'main', it throws an error
// it fails to link the object files

// Error case 2 - if a declared function is followed by main() but main calls it, it throws an error

// void printHello()
// {
//   std::cout << "Hi" << std::endl;
// }

// /** compute the average of x and y */
// float average(float a, float b)
// {
//   return (a + b) / 2;
// }

// Error case 3 - If two separate files are compiled, it works
// But if one file is compiled, it throws an error

// Function prototypes
void printHello();
float average(float a, float b);

int main()
{
  printHello();
  float z = average(2, 3);
  std::cout << z << std::endl;
  return 0;
}
