# Week3. Data
## C vs. C++
  - C : strongly typed, weakly checked, programming langugage
  - C++ : stronger type checking
## C++ types
  - Character
    - char
    - char16_t
    - char32_t
    - wchar_t
  - Integer (unsigned/signed)
    - unsigned/signed char
    - unsigned/signed short int
    - unsigned/signed int
    - unsigned/signed long int
    - unsigned/signed long long int
  - Floating-point
    - float
    - double
    - long double
  - Boolean
    - bool
## [Floating point representation](https://www.youtube.com/watch?v=yvdtwKF87Ts)
  - e.g. (5.625)_10
    - -> (101.101)_2 -> [101101,3]
    - -> 0.5625 x 10^1
      - 5626: Mantissa
      - 1: Exponent
    - (101.101)_2 -> 0.101101 x 2^3
      - 101101: Mantissa
      - 3: Exponent
  - Memory efficient
    |S|Exponent|Mantissa|
    |--|--|--|
    |1 bit|4 bits|5 bits|
  - Need of Normalization
    - since many representations exists
    - (101.101)_2 -> 0.101101 x 2^3
    - (101.101)_2 -> 1.01101 x 2^2
    - (101.101)_2 -> 0.0101101 x 2^4
    - (101.101)_2 -> 101101 x 2^-3 ...
### 2 Types of Normalization
1. Explicit Normalization
  - Move the radix point to the LHS of the most significant '1' in the bit sequence
    - (101.101)_2 -> 0.101101 x 2^3
  - Biasing
    - Exponent: Excess 8
    - e.g. (0.0101)_2 -> 0.101 x 2^-1
      - Exponent: -1 + 8 = 7bit
      - |S|Exponent|Mantissa|
        |--|--|--|
        |0|0111|10100|
  - $(-1)^S \times 0.M \times 2^{E-Bias}$
2. Implicit Normalization [v]
  - Move the radix point to the RHS of the most significant '1' in the bit sequence
    - (101.101)_2 -> 1.01101 x 2^2
  - Biasing
    - Exponent: Excess 8
    - e.g. (0.0101)_2 -> 1.0101 x 2^2
      - Exponent: 2 + 8 = 10bit
      - |S|Exponent|Mantissa|
        |--|--|--|
        |0|1010|01101|
  - $(-1)^S \times 1.M \times 2^{E-Bias}$

## Float & Double

```cpp
float f = 1.5f;
double d = 1.5;
```

## String
- String is class
```cpp
#include <string>
// 중괄호 초기화(C++11 style)
std::string timestamp{"2020/03/17 17:01:24.884492"};
std::string timestamp2 = "2020/03/17 17:01:24.884492" 
```

## Enum
```cpp
enum class OrderBookType
{
    bid,
    ask
};

OrderBookType orderType = OrderBookType::bid;
```

## Vector
```cpp
#include <vector>
std::vector<double> prices;
prices.push_back(5002.01)
```

## Class
- class: a specification for something
- instance : the actual version
- define a class
  ```cpp
  class OrderBookEntry
  {
    public:
      double price;
      double amount;
      std::string timestamp;
      std::string product;
      OrderBookType orderType;
  };

  // declare an object(instance)
  OrderBookEntry order1;
  ```
### Constructor
  - 객체가 생성될 때 자동으로 호출되는 특별한 멤버 함수
  ```cpp
  class OrderBookEntry
  {
  public:
    // constructor
    OrderBookEntry(double _price,
                  double _amount,
                  std::string _timestamp,
                  std::string _product,
                  OrderBookType _orderType)
    {
        this->price = _price;
        this->amount = _amount;
        this->timestamp = _timestamp;
        this->product = _product;
        this->orderType = _orderType;
    }

    // members
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
  };

  // make an object by constructor
  OrderBookEntry order1{1000, 0.02, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask};
  ```
  - Constructor initialization list
  - `OrderBook(double price): price(price)`
  - `OrderBook(double price): price{price}`

  ```cpp
  OrderBookEntry(double _price,
                   double _amount,
                   std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType)
        : price(_price), amount(_amount), timestamp(_timestamp), product(_product), orderType(_orderType)
    { }
  ```
### with vector
  ```cpp
  std::vector<OrderBookEntry> orders;
  orders.push_back(OrderBookEntry{1000, 0.02, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask});
  ```
### 3 ways to iterate over a vector
1. call by reference
```cpp
for (OrderBookEntry &order : orders)
    {
        std::cout << "The price is " << order.price << std::endl;
    }

    return 0;
```

2. use index
- index로 벡터에 있는 object에 바로 접근
- `i++` is less efficient than `++i`
  - ++i는 변수 i의 값을 먼저 증가시킨 후, 증가된 값을 사용함. i++는 변수 i의 현재 값을 먼저 사용한 후, 값을 증가시킴
  - i++의 경우, 컴파일러는 임시 변수를 생성하여 현재 값을 저장한 후, i를 증가시키고 임시 변수의 값을 사용함. 이 과정에서 추가적인 메모리 할당과 복사 연산이 발생할 수 있음.
  - ++i의 경우, 컴파일러는 변수 i를 직접 증가시키고 증가된 값을 바로 사용하므로, 임시 변수의 생성과 복사 연산이 필요하지 않음.
```cpp
for (unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "The price is " << orders[i].price << std::endl;
    }
```

3. more object style
```cpp
for (unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "The price is " << orders.at(i).price << std::endl;
    }
```
### classes and data
- problems of global variables & procedural programming
  - difficult debugging, conflict in naming, bad for maintenance, concurrency failure
- Encapsulation needed
  - consideration of public & private