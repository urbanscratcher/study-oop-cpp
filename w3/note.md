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
### Formula
  1. Explicit Normalization
    `$(-1)^5$`