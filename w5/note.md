# Week5. Iteration & Handling Exception & Reading Txt
## Tokenize Algorithm in Pseudocode
- 토큰화(Tokenizing): 지정된 구분자(예; `,`)로 구분된 개별 요소(토큰)를 식별하고 추출하는 작업

### Tokenizing for CSV parser
- 알고리즘은 첫 번째 구분자가 아닌 문자에서 시작해 다음 구분자를 찾아 각 토큰의 끝을 구분함
- 식별된 각 토큰은 추출되어 리스트나 벡터에 저장됨
- 이 과정은 모든 토큰이 추출될 때까지 계속되며, 조건문을 통해 구분자로 끝나지 않는 마지막 토큰도 포함해 처리됨

```cpp
string csvLine = 'thing,thing2,thing3' ## the string we are processing

string vector tokens                   ## stores the tokens

char separator = ','                   ## the character that separates the tokens

int start, end                         ## used to delineate the position of the tokens

start = csvLine.find_first_not_of(separator)

do
  end = next 'separator' after start
  if start == csvLine.length or start == end    ## nothing more to find
    break
  if end >= 0                                   ## we found the separator
    token = csvLine.substr(start, end - start)  ## start, substring length
  else                                          ## data in the end
    token = csvLine.substr(start, csvLine.length - start) ## end is invalid
  
  tokens.push_back(token) ## save the token
  start = end + 1         ## move past this token

  while (end > 0)         ## continue loop condition

  DataRow row{};
    signed int end;
    char sep = ',';

```

#### `std::string::nps`
- `std::string` 클래스에서 정의된 특별한 값. 문자열에서 찾기 연산이 실패했을 때 반환됨
- 보통 `-1` 로 정의
- `npos` "no position"을 의미하며 문자열의 유효한 위치가 아님을 나타냄

```cpp
do{...}
while(std::string::npos)
```

## Reading text file
- `#include <fstream>`
  - 파일 스트림 클래스 `ifstream`, `ostream`, `fstream` 등을 제공 
- `std::ifstream`
  - `ifstream` 객체 생성해서 파일 읽기
- `std::getline()`
  - 입력 스트림(`ifstream`)에서 문자를 읽어 특정 구분자(기본적으로 개행 문자 `\n`)를 만날 때까지 문자열로 저장
    ```cpp
    std::istream& getline(std::istream& is, std::string& str);
    std::istream& getline(std::istream& is, std::string& str, char delim);
    ```
    - `is` 입력 스트림 객체. 일반적으로 std::cin이나 std::ifstream과 같은 스트림 객체
    - `str` 읽은 데이터를 저장할 std::string 객체
    - `delim` (선택) 구분자 문자. 기본값은 개행 문자(`\n`)
- `csvFile.close()`
  - 리소스 누수를 방지하기 위해 파일 닫아주기
- `std::stod()`
  - 문자열 `double` 형으로 변환

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 파일 입력 스트림 객체 생성 및 파일 열기
    std::ifstream csvFile{"example.csv"};

    // 파일 열기 확인
    if (!csvFile.is_open()) {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
        return 1;
    }

    // 파일 내용 읽기
    std::string line;
    while (std::getline(csvFile, line)) {
        std::cout << line << std::endl;
    }

    // 파일 닫기
    csvFile.close();

    return 0;
}
```

## Handling Exceptions
- `std::stod()` 사용시 프로그램이 유효하지 않은 `double` 값이나 부동 소수점 값을 데이터 파일에서 읽을 때 충돌
- 데이터 파일이나 사용자 입력으로부터 데이터를 읽을 때 이러한 문제는 프로그램의 견고성을 저해할 수 있음
- 예외는 프로그램이 예상하지 못한 상황에서 발생하는 이벤트임
- 예외 처리를 통해 프로그램이 이러한 예외 상황을 처리하고 계속 실행될 수 있도록 할 수 있음