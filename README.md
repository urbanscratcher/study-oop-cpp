# Object Oriented Programming with C++
- This is a personal note from my oop course every week
- It includes the concept of oop and usage of c++

## Summary
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

### [Week 5. Tokenizing & File Input & Exception](w5/note.md)
- 토큰화(Tokenizing)
  - 구분자(`,` 등)로 문자열을 개별 요소(토큰)로 분리
- `std::string::npos`
  - 문자열에서 찾기 연산이 실패했을 때 반환되는 특별한 값
- 텍스트 파일 읽기
  - `#include <fstream>` 파일 스트림 클래스 포함
  - `std::ifstream` 파일 읽기 스트림 객체
  - `std::getline()` 줄 단위로 파일 읽기
  - `close()` 파일 닫기로 리소스 누수 방지
- 예외 처리
  - `std::stod()` 유효하지 않은 값 처리
  - `try-catch` 블록을 사용해 예외 처리

### [Week 6. Integrating CSV Parser](w6/note.md)
- 인스턴스 메서드: 특정 객체의 상태에 따라 동작이 달라지며, 인스턴스 변수에 접근하거나 수정함.
- 정적 메서드: 객체 상태와 무관하게 동작하며, 클래스 레벨의 유틸리티 함수로 사용됨. 인스턴스를 생성하지 않고 호출 가능.
- 정적 메서드 사용 시기: 인스턴스 변수에 접근할 필요가 없고, 객체 상태와 무관하게 동작할 때.

### [Week 7. Integrating CSV Parser](w7/note.md)
- std::map 
  - 키와 값을 저장하고 키를 기준으로 정렬된 컨테이너
  - 내부적으로 균형 이진 탐색 트리(BBST)로 구현됨
  - 주요 함수와 연산
    - 삽입: insert 또는 [] 연산자를 사용해 요소를 추가
    - 삭제: erase 함수로 키에 해당하는 요소를 삭제
    - 탐색: find 함수로 키를 기준으로 요소를 검색
    - 순회: for 루프와 auto 키워드를 사용해 map을 순회
    - 크기 및 비어있는지 확인: size와 empty 함수로 확인
  - 연산자 오버로딩
    - 클래스 객체에 대해 표준 연산자(+, -, * 등)의 동작을 정의
    - 이를 통해 클래스를 기본 데이터 타입처럼 자연스럽게 연산 가능
  - 정렬
    - `std::sort` 퀵소트, 힙소트, 인트로소트를 혼합한 알고리즘 사용
    - `std::stable_sort` 안정적인 정렬을 보장, 동일한 값의 원래 순서 유지
  - `OrderBook` 클래스
    - `construct(filename)`: CSV 파일을 읽어와 데이터를 저장
    - `getKnownProducts()`: 상품명을 리스트로 반환, map<string, bool> 사용
    - `getOrders(type, product, timestamp)`: 조건에 맞는 주문 목록 반환
    - `getEarliestTime()`: 가장 이른 시간 반환
  - 참조를 담는 벡터를 만들 수 없는 이유
    - 참조는 초기화 후 다시 바인딩될 수 없기 때문에 벡터에 저장할 수 없음
    - 벡터는 크기 변동 시 요소를 복사하거나 이동시키므로, 참조는 이를 지원하지 않음
- 네임스페이스
  - `using namespace std`
- 벡터 루프와 메모리 최적화
  - `const` 읽기 전용으로 명시, 쓰기 시 컴파일 오류 발생
  - `&item` 참조를 사용해 불필요한 복사 방지, 메모리 최적화


### [Week 8. Matching Algorithm](w8/note.md)
- `getline()`을 사용할 때 `cin()`과 함께 사용 시 문제가 발생할 수 있으며, 이를 해결하기 위해 `cin.ignore()`를 사용해야 함
- 주문서 처리 알고리즘은 매도 주문을 오름차순, 매수 주문을 내림차순으로 정렬하고, 조건에 따라 매칭되며 처리되는 사항은 `sales` 에 기록함.

### [Week 9. Wallet](w9/note.md)

- `std::map`에서 `const` 키워드: 매개변수와 멤버 함수의 상수성을 보장하여, 함수가 전달된 키 값과 객체의 상태를 수정하지 않도록 함.
- 클래스 정적 함수: 클래스 데이터 멤버에 접근할 수 없고, 객체를 인스턴스화하지 않고 호출 가능.
- 클래스 비정적 함수: 클래스 데이터 멤버에 접근 가능하며, 객체를 통해 호출해야 함.

### Week 10
- Midterm

### [Week 11](w11/note.md)
