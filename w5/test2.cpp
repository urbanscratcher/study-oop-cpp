#include <string>
#include <iostream>

int main()
{
  double d = 0;
  std::string s = "ssdf";
  try
  {
    d = std::stod(s);
  }
  // const: 예외 객체를 수정할 수 없도록 함
  // 예외 객체를 안전하게 읽기 위해 사용되는 표준 방식
  catch (const std::exception &e)
  {
    throw e;
  }
  std::cout << "d: " << d << std::endl;
}