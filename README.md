# Object Oriented Programming with C++
- This is a personal note from my oop course every week
- It includes the concept of oop and usage of c++

## Weekly Summary
- [Week 1](w1/note.md)
  - Execution
    1. Compiler produces object file `g++ -c main.cpp`
    2. Link the object file `g++ main.o -o main` 
    3. Execute `./main`
    - Simply `g++ main.cpp` to produce an executable file (a.out)
    - Or `g++ main.cpp -o main` to produce an executable binary file (main)
  - 표준 헤더 파일
    - stdio.h, stdlib.h, string.h, time.h, math.h, memory.h
  - 범위 해결 연산자 ::
    - 함수나 변수명 등을 네임스페이스에 따라 구분
  - 비트 연산자 <<, >> 오버로딩
    - << : returns ostream type (output). `cout << value`
    - \>> : returns istream type (input). `cin >> value`
  - <iostream>
    - ios, **istream**, **ostream**, streambuf, **cin**, **cout**, cerr, clog
- [Week 2](w2/note.md)
