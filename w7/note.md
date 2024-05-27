# Week7. Statistics & Testing
## `std::map`
- 키와 값의 쌍을 저장하고, 키를 기준으로 정렬됨
- 내부적으로 균형 이진 탐색 트리를 사용해 구현됨
  - 이진 탐색 트리(BBST): 이진 탐색 트리(BST)의 특수한 형태로, 트리의 높이를 가능한 한 최소화하여 삽입, 삭제, 탐색 연산이 효율적으로 이루어지도록 함
- 삽입, 삭제, 탐색이 모두 $O(\log n)$ 에 이루어짐
### 선언과 초기화
```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    // std::map 선언
    std::map<int, std::string> myMap;

    // 요소 삽입
    myMap[1] = "one";
    myMap[2] = "two";
    myMap[3] = "three";

    // 초기화 리스트를 사용한 초기화
    std::map<int, std::string> anotherMap = {{4, "four"}, {5, "five"}, {6, "six"}};

    // 요소 접근 및 출력
    std::cout << "myMap[1]: " << myMap[1] << std::endl;
    std::cout << "anotherMap[4]: " << anotherMap[4] << std::endl;

    return 0;
}
```

### 주요 함수와 연산
```cpp
// 1. 삽입
myMap.insert({7, "seven"});
myMap[8] = "eight"; // 위 방법과 동일

// 2. 삭제
myMap.erase(1); // 키가 1인 요소 삭제

// 3. 탐색
auto it = myMap.find(2);
if (it != myMap.end()) {
    std::cout << "Found: " << it->second << std::endl;
} else {
    std::cout << "Not Found" << std::endl;
}

// 4. 순회
// auto 키워드: 변수 타입을 컴파일러가 자동으로 추론하도록 함 (가독성 향상)
// .first: key / .second: value 
for (const auto& pair : myMap) {
    std::cout << pair.first << ": " << pair.second << std::endl;
}

// 5. 크기 및 비어있는지 확인
if (myMap.empty()) {
    std::cout << "Map is empty" << std::endl;
} else {
    std::cout << "Map size: " << myMap.size() << std::endl;
}
```

## 연산자 오버로딩
- 클래스 객체에 대해 표준 연산자(+, -, * 등)의 동작을 정의하는 방법
- 이를 통해 클래스를 사용할 때 기본 데이터 타입처럼 자연스럽게 연산을 수행할 수 있음

### 사용 예시
```cpp
// 부등호 연산자(!=)
bool operator!=(const Vector2D& other) const {
    return !(*this == other);
}

// 단항 연산자(-)
Vector2D operator-() const {
    return Vector2D(-x, -y);
}
```

## 정렬
### `std::sort`
- 퀵소트, 힙소트, 인트로소트를 혼합한 알고리즘 사용

#### 사용 예시
```cpp
#include <algorithm> // std::sort
#include <vector>    // std::vector
#include <iostream>  // std::cout

int main() {
    std::vector<int> vec = {34, 7, 23, 32, 5, 62};

    // 정렬
    std::sort(vec.begin(), vec.end());

    // 정렬된 벡터 출력
    for (int num : vec) {
        std::cout << num << " ";
    }

    return 0;
}
```
### `std::stable_sort`
- `std::sort` 와 비슷하지만, 안정적인 정렬을 보장함
- 동일한 값이 있을 경우 원래 순서를 유지

### 사용 예시
```cpp
#include <algorithm> // std::stable_sort
#include <vector>    // std::vector
#include <iostream>  // std::cout

int main() {
    std::vector<int> vec = {34, 7, 23, 32, 5, 62};

    // 안정적인 정렬
    std::stable_sort(vec.begin(), vec.end());

    // 정렬된 벡터 출력
    for (int num : vec) {
        std::cout << num << " ";
    }

    return 0;
}
```

## `OrderBook` class
- `construct(filename)`
    - CSV로 파일 읽기
- `getKnownProducts()`
    - 상품명 리스팅
    - `map<string, bool>` 사용
    - `map["ETH/BTC"] = true`
- `getOrders(type, product, timestamp)`
- `getEarliestTime()`

## 참조를 담는 벡터를 만들 수 없는 이유
- 참조가 초기화 후 다시 바인딩될 수 없기 때문임
- 벡터는 크기가 변하면서 내부적으로 요소를 복사하거나 이동시키는데, 참조는 이러한 복사나 이동을 지원하지 않음
- 대신, 포인터를 사용하거나 `std::reference_wrapper`를 사용하면 비슷한 기능을 구현할 수 있음
- 예를 들어, 포인터는 복사와 할당이 가능하므로 벡터에 저장하고 관리할 수 있으며, `std::reference_wrapper`는 참조를 감싸서 복사가 가능하도록 만들어 줌

## 네임스페이스
```cpp
using namespace std;

int main(){
    vector<string> strings;
    return 0;
};
```

## 벡터 루프와 메모리
- `const` 항목을 읽기 전용으로 명시함. 쓰기시 컴파일 하면 오류
- `&item` 참조를 사용해 불필요한 복사 방지. 메모리 최적화
```cpp
  // use &s to avoid copying the string
  for (const string &s : strings)
  {
    // cannot compile because s is const
    // s = 'abc';
    cout << s << endl;
  }
```