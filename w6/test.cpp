#include <string>
#include <iostream>

int main()
{
  // length() is a member fn, non-static fn (stateful depending on the object it is called on)
  std::string s = "Joun";
  std::cout << "length of s: " << s.length() << std::endl;
  s = "Something else";
  std::cout << "length of s: " << s.length() << std::endl;

  // stod() is static fn (stateless, does not depend on the object it is called on)
  // They basically temporarily use some space in the memory and then they give it back
  std::stod("10");
}