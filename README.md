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

### [Week 4. Class Encapsulation](w4/note.md)
- 헤더 및 구현 파일
  - `OrderBookEntry.h`에 클래스 선언
  - `OrderBookEntry.cpp`에 구현
- 컴파일 및 링크
  - 링크할 때 구현 파일도 함께 포함해야 함
  - `g++ --std=c++11 main.cpp OrderBookEntry.cpp -o main`
- 객체 초기화 (C++11)
  - `CustomClass objectName{}`
- 생성자와 초기화 함수 분리
  - 책임 분리, 유연성, 오류 처리, 테스트 용이성을 위해 분리
- 클래스 내 멤버에 대한 접근 제한
  - `public` 키워드로 멤버 노출
  - `private` 키워드로 데이터 은닉과 캡슐화
- 헤더 파일 중복 포함 방지
  - `.h` 파일 상단부에 `#pragma once` 사용