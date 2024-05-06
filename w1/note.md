
# Week1. Basics
## Converting C++ into a program
### basics
  - `g++ -S main.cpp` produces assembler (main.s)
  - `g++ -c main.cpp` produces object code (main.o)
  - `g++ main.cpp` compile, assemble and link (a.out executable)
### compile
- `g++ main.cpp -o merkel1` merkel1이라는 파일이름의 실행가능한 바이너리 파일 생성
- `./merkel1` 실행

## 표준 헤더 파일 (*.h가 아닌 *)
- C에서는 *.h로 작성했지만, C++는 확장자 제거
  |C 표준 헤더 파일|C++ 표준 헤더 파일|
  |:---:|:---:|
  |stdio.h|cstdio|
  |stdlib.h|cstdlib|
  |string.h|cstring|
  |time.h|ctime|
  |math.h|cmath|
  |memory.h|memory|

## [범위 해결 연산자 ::](https://engkimbs.tistory.com/entry/C-%EB%B2%94%EC%9C%84-%EC%A7%80%EC%A0%95-%EC%97%B0%EC%82%B0%EC%9E%90%EC%99%80-namespace)
- 네임스페이스
  - C++의 예약어
  - 변수, 함수들이 선언된 범위나 묶음
  - std::cout의 std
- 범위 해결 연산자 ::
  - 함수나 변수명 등을 네임스페이스에 따라 구분할 때 사용
  - std::string은 std 영역에서의 데이터 타입 string을 사용하겠다는 의미
  ```cpp
  #include <iostream>
  #include <string>
  using namespace std;

  namespace A {
    void hello(){
      cout << "I am A" << endl;
    }
  }

  namespace B {
    void hello(){
      cout << "I am B" << endl;
    }
  }

  int main(void)
  {
    A::hello();
    B::hello();
  }
  ```

## 비트 연산자 << 오버로딩
- 오버로딩?
  - 함수 중복 정의 - 한 클래스 내에 같은 이름의 메서드를 매개 변수에 따라 여러 개 정의
  - 메서드 이름이 같고, 매개변수의 개수나 형이 달라야 함
  - cf. 오버라이딩: 함수 재정의
- ostream 클래스 안에는 << 연산자 오버로딩이 구현돼 있음
  - ostream 형의 객체가 출력 연산자 <<를 만나면 **우측**에 있는 것을 인수로 하는, ostream 클래스의 멤버 출력 연산자 오버로딩을 호출
- std::cout
  - cout은 ostream 형의 객체
  - <<는 `cout << value`의 리턴 값이 cout이 되는 연산을 함
  - <<는 기본 자료형 리턴
- std::endl
  - <<는 함수 레퍼런스 리턴
- cf. `>>` cin에 사용되는 extraction operator

## <\n
- 줄 마지막 문자인 \n은 OS에 따라 적절한 문자로 변환됨
- 윈도우의 경우 C 텍스트 스트림은 \n을 \r\n으로, \r\n을 \n으로 변환
  - 텍스트 스트림: 0개 이상의 문자와 개행 문자 \n로 구성된 문자열
- 크로스 플랫폼을 지원하지 않으므로 endl 권장

## \<iostream>
### 구성
- `<ios>`
- `<istream>`
- `<ostream>`
- `<streambuf>`
- `cin`
- `cout`
- `cerr` console error
- `clog` console log


### 표준 출력 객체 cout
- Console Output (콘솔 출력)
- C의 printf()

#### 진법 출력
- `oct, dec, hex` 8, 10, 16진수로 출력 설정
- `showbase, uppercase` 16진수 출력 방식 설정
- `setf, unsetf` 출력 방식 설정/해제
  ```cpp
  cout.unsetf(ios::hex | ios::showpos | ios::uppercase);
  ```

#### 유효숫자, 소수 출력 설정
- `precision` 유효 숫자 설정
  ```cpp
  cout.precision(4);
  ```
- `showpoint` 유효 숫자 설정한만큼 나머지 소숫점도 보이도록 설정
- `fixed` 고정 소숫점 방식 설정
- `scientific` 부동 소숫점 방식 설정

#### 칸/공백 출력 설정
- `width` 칸 설정
- `fill` 공백 채울 값 설정
- `left` 채울 값부터 출력
- `right` 문자열 출력 후 채울 값 출력
- `internal` 부호와 숫자 따로 출력

#### bool 출력 설정
- bool은 true를 1, false를 0으로 인식하는데 cout의 boolalpha를 이용하면 문자열(true, false)로 출력 가능
- `boolalpha` bool 출력 방식 설정
  ```cpp
  cout << boolalpha << true << endline
  ```

### [cout vs. printf](https://blog.naver.com/view7186/222083168651)
#### cout
- \<iostream>
- C++의 스트림 유형 객체
- 출력값의 자료형을 컴파일러가 검사할 수 있음
- 출력값의 유형에 따라 적절한 함수를 호출함

#### printf
- \<cstdio>
- 주로 C 문자열을 표시하는 함수
- 출력값의 자료형을 컴파일러가 검사할 수 없음 (버그 발생 확률 높음)
- 처리 속도가 더 빠름
  - 일반적으로 cin/cout/endl이 scanf/printf/\n보다 속도가 느림

#### 속도차 발생 이유
- C++에서 C의 stdio buffer를 동기화하는 과정에서 지연이 발생하기 때문
- [std::endl은 출력 버퍼를 비우고(저장된 내용을 즉시 출력 =flush), \n은 모아뒀다가 출력](https://yechoi.tistory.com/48)

#### 속도차 해결법
- cout을 사용시 개행할 때는 flush가 불필요하게 호출되지 않게 endl보다 \n 사용
- (편법) cout.tie(NULL); or sync_with_stdio(false); 사용
- 속도가 중요한 경우 printf 사용

### 표준 입력 객체 cin
- Console Input (콘솔 입력)
- C의 scanf()
- 입력 버퍼에서 해당되는 자료형 값만 읽음

#### 입력 버퍼에서 값 읽기 (개행 처리)
- `get` 하나는 반환 값으로 처리, 다른 하나는 인자로 처리
  - 입력 버퍼를 비울 수 있음 - \n이 나오기 전까지 계속 읽으면 됨
- `getline` \n이 나오기 전까지 입력을 받음 

#### 입력 성공 여부에 따른 처리
- `good, eof, fail, bad` 입출력 스트림 오류 판단
  - `goodbit` 입출력 스트림의 오류가 없다는 표시(0x0)
  - `eofbit` EOF(파일의 끝)를 발견했다는 표시(0x1)
  - `failbit` 입출력이 실패했다는 표시(0x2)
  - `badbit` 입출력 스트림이 손상됐다는 표시(0x4)
- `rdstate` cin의 현재 비트 마스크 값 출력
- `setstate` 비트 마스크 설정, 나머지는 유지
- `clear` 비트 마스크 설정, 나머지는 초기화. 기본 인자는 ios::goodbit

#### 입력값 읽기
- `ignore` 지정한 길이 안에서 지정한 문자가 나오기 전까지의 모든 값 무시
  ```cpp
  // 620+7702 입력시 7702 출력
  cin.ignore(5, '+');
  ```
- `peek` 현재 버퍼에 남아있는 값 읽기

### 유니코드 입출력
- `wcout, wcin`

## \<iomanip>
- Input Output Manipulator (입출력 조정자)
- 출력 조정(진법 설정 등)의 또다른 방법

### 구성
  - `setw()` 칸 설정
  - `setprecision()` 부동 소수점 유효숫자 설정
  - `setfill()` 공백을 채울 값 지정
  - `setbase()` 진법 설정




## 참고자료
- [C++ 언어 정리하기](https://m.blog.naver.com/PostView.naver?blogId=ruvendix&logNo=220953194013&targetKeyword=&targetRecommendationCode=1)