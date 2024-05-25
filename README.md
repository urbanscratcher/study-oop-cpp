# Object Oriented Programming with C++
- This is a personal note from my oop course every week
- It includes the concept of oop and usage of c++

## Weekly Summary
### [Week 1. Basics](w1/note.md)
- Execution
  1. Compiler produces object file `g++ -c main.cpp`
  2. Link the object file `g++ main.o -o main` 
  3. Execute `./main`
  - Simply `g++ main.cpp` to produce an executable file (a.out)
  - Or `g++ main.cpp -o main` to produce an executable binary file (main)
  - `g++ --std=c++11 main.cpp` to use enum class etc
- 표준 헤더 파일
  - stdio.h, stdlib.h, string.h, time.h, math.h, memory.h
- 범위 해결 연산자 ::
  - 함수나 변수명 등을 네임스페이스에 따라 구분
- 비트 연산자 <<, >> 오버로딩
  - << : returns ostream type (output). `cout << value`
  - \>> : returns istream type (input). `cin >> value`
- <iostream>
  - ios, istream, ostream, streambuf, cin, cout, cerr, clog

### [Week 2. Refactoring & Function](w2/note.md)
- See all warnings `g++ -Wall main2.cpp`
- /** XYZ */ generates a tooptip of functions

### [Week 3. Data Type](w3/note.md)
- Data type
  - 부호 포함(signed), 양수만(unsigned)
  - 기본형
    - character, integer, floating-point, boolean
  - Float & double
    - `float f = 1.5f`
    - `double d = 1.5`
  - String
  - Enum
    ```cpp
      enum class OrderBookType { bid, ask }
      OrderBookType orderType = OrderBookType::bid
    ```
  - Vector
    ```cpp
      #include<vector>
    ```