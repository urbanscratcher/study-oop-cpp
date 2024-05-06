#include <iostream>
#include <string>

// make a categorical namespace
enum class Colors
{
  blue,
  green,
  red
};

int main()
{

  std::string s = "hello";

  float f = 1.5f;
  double d = 1.5;

  // Compile warning: out of range 0~65535
  // i go back to 0
  unsigned short i = 65535;
  unsigned long l = 65537;

  std::cout << "sizeof unsigned short " << sizeof(unsigned short) << std::endl;
  std::cout << "sizeof unsigned long " << sizeof(unsigned long) << std::endl;
  std::cout << "i contains " << i << std::endl;

  return 0;
}