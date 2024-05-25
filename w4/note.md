# Week4. Data
## 커스텀 헤더 (specification)
- `OrderBookEntry.h` 에 클래스 선언하기
```cpp
class OrderBookEntry
{
public:
  OrderBookEntry(double _price,
                 double _amount,
                 std::string _timestamp,
                 std::string _product,
                 OrderBookType _orderType);

  double price;
  double amount;
  std::string timestamp;
  std::string product;
  OrderBookType orderType;
};
```

## 커스텀 헤더 구현 (implementation)
- `OrderBookEntry.cpp` 에서 클래스 내부 구현
- 클래스 내부로 접근하기 위해 네임스페이스가 필요함
```cpp
// constructor implementation
// needs namespace to be specified
OrderBookEntry::OrderBookEntry(double _price,
                               double _amount,
                               std::string _timestamp,
                               std::string _product,
                               OrderBookType _orderType) : price(_price), amount(_amount), timestamp(_timestamp), product(_product), orderType(_orderType)
{
  
}
```

## 컴파일 과정과 역할 분담
- `g++ --std=c++11 main.cpp OrderBookEntry.cpp` `./a.out`
- `g++ --std=c++11 main.cpp OrderBookEntry.cpp -o main` `./main`
- 위의 명령어에서 `OrderBookEntry.cpp`를 포함하는 이유는 `OrderBookEntry` 클래스의 실제 구현을 컴파일하고, `main.cpp`에서 이 클래스의 인스턴스를 사용할 때 링크하여 전체 프로그램이 완성되도록 하기 위함
- 즉, `main.cpp` 파일은 구현 대신 선언만 보면 되고, 구현이 사용 가능하도록 하는 것은 링크 단계에서 이루어짐

### 1. 컴파일 단계
- 각 `.cpp` 파일이 개별적으로 컴파일돼 `.o` 객체 파일이 생성됨
- 예를 들어, `OrderBookEntry.cpp`를 컴파일하면 `OrderBookEntry.o` 객체 파일이 생성
### 2. 링크 단계
- 컴파일된 객체 파일들이 결합돼 실행 파일 생성
- `main.cpp`에서 `OrderBookEntry` 클래스를 사용할 때, 이 클래스의 실제 구현이 필요하므로 `OrderBookEntry.o` 파일이 링크되어야 함

## 객체 초기화 (C++11)
- 리스트 초기화: 중괄호 `{}` 를 통한 객체 초기화

### 1. 기본 초기화
- 기본 생성자를 호출해 객체 초기화
```cpp
class Example {
public:
    Example() {
        // 기본 생성자
    }
    Example(int x) {
        // 매개변수가 있는 생성자
    }
};

int main() {
    Example obj{};  // 기본 생성자 호출, Example obj();와 동일
}
```

### 2. 값 초기화
- 기본값을 사용하여 객체를 초기화. POD (Plain Old Data) 타입에서 유용
```cpp
struct PodType {
    int x;
    double y;
};

int main() {
    PodType pod{};  // x는 0으로, y는 0.0으로 초기화됨
}
```

### 3. 집합 초기화
- 구조체나 배열 같은 집합 타입을 초기화
```cpp
struct Data {
    int a;
    double b;
};

int main() {
    Data d{1, 2.3};  // a는 1, b는 2.3으로 초기화됨

    int arr[3]{1, 2, 3};  // 배열 초기화
}
```

### 4. 범위 기반 for 루프와 함께 사용
- 리스트 초기화와 범위 기반 for 루프를 함께 사용해 컨테이너 초기화 및 반복
```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};

    for (int n : vec) {
        std::cout << n << ' ';
    }
    // 출력: 1 2 3 4 5
}
```
## 생성자와 초기화 함수 분리 이유
1. 책임 분리 (Separation of Concerns)
  - 생성자: 객체가 유효한 상태로 존재하도록 하는 데 필요한 최소한의 작업
  - 초기화 함수(init): 객체 생성 후 호출돼 추가적인 초기화 작업. 특정 작업을 수행하기 전 필요한 설정이나 초기화 과정을 처리할 수 있음
2. 유연성 증가
  - 단계적 초기화, 재초기화 작업 가능
3. 오류 처리
  - 초기화 과정에서 발생할 수 있는 오류를 `init()` 에서 처리 가능
4. 테스트 용이성

## 클래스 내부 접근 제한
- `private` 키워드를 사용해 클래스의 내부 멤버에 대한 접근을 제한함으로써 데이터 은닉과 캡슐화 구현

```cpp
class MerkelMain
{
public:
  ...

private:
  ...
};
```

## 헤더 파일 중복 포함 방지
- `#pragma once` C++에서 헤더 파일이 여러 번 포함되는 것을 방지하기 위해 사용하는 전처리기 지시자임
- 중복 정의로 인한 컴파일 오류를 예방함
- 모든 `.h` 상단에 포함하기를 권장