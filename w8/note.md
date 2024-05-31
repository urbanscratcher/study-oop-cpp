# Week8. User Input & Matching

- to enable the user of our simulation to interactively enter bids and asks to the order book.

## `getline()` vs. `cin()`
- `std::cin >> `
  - 공백, 탭, 개행 문자를 구분자로 사용해 단어 단위로 입력을 읽음
  - 그러나 공백을 포함한 문자열을 제대로 처리하지 못함
  - 예를 들어, "Hello World"를 입력하면 `Hello` 만 읽고 `World` 는 버퍼에 남게 됨
- `std::getline(std::cin, userOption)`
  - 개행 문자(`\n`)를 만나기 전까지의 모든 입력을 1줄로 읽음
  - 공백을 포함한 전체 줄을 입력받을 수 있음
  - 예를 들어, "Hello World"를 입력하면 `Hello World` 전체를 읽어들임
  - 기본적으로 문자열 입력에 사용되며, 숫자 입력 시 추가 변환이 필요할 수 있음

## `cin()`과 함께 사용시 `getline()` 입력 문제
- `std::getline()`을 호출하기 전에 입력 버퍼를 정리해 예상치 못한 문제를 방지해야 함
- 문제
  - `std::cin`을 사용해 값을 입력받은 후, `std::getline()`을 호출하면 예상치 못한 동작이 발생할 수 있음
  - `std::cin`은 공백(스페이스, 탭)이나 개행 문자(`\n`)를 구분자로 사용해 입력을 읽음
  - 사용자가 입력한 값 이후에 남아 있는 개행 문자(`\n`)가 입력 버퍼에 남음
  - 이 경우 `std::getline()`은 새로운 입력을 기다리지 않고 즉시 리턴하게 됨
- 해결 방법
  - 입력 버퍼에 남아 있는 개행 문자 제거하기
  ```cpp
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  ```

## 오버로딩 (Overloading)
