# Week 12. JUCE
## JUCE란?

### Projucer

- Projucer는 독립 실행형 그래픽 애플리케이션으로, JUCE 프로젝트를 생성하고 관리할 수 있게 해줌
- Projucer를 사용하면 프로젝트를 처음부터 직접 만들 필요 없이, 프로그램을 실행하여 JUCE 프로젝트를 생성할 수 있음
- (첨언) Vite 같은 것으로 이해하면 되는데, JUCE 프로젝트 생성, 플랫폼별 설정, 모듈 관리, 코드 관리를 위해 편리하게 사용할 수 있는 앱

- Projucer를 통해 다양한 종류의 애플리케이션을 만들 수 있음. 예를 들어:
  - **OpenGL 애플리케이션**: 3D 그래픽 인터랙티브 프로그램
  - **오디오 애플리케이션**: DJ 애플리케이션과 같은 오디오 관련 프로그램
  - **플러그인**: 다른 프로그램에 내장되어 기능을 확장하는 작은 프로그램
  - **그래픽 애플리케이션**: 오디오 없이도 복잡한 그래픽 사용자 인터페이스를 가진 프로그램
- Projucer는 다양한 플랫폼에 프로젝트를 내보낼 수 있도록 지원함. 주요 플랫폼으로는:
  - **Xcode**: Mac용 네이티브 애플리케이션
  - **Xcode iOS**: iPhone 및 iPad용 애플리케이션
  - **Visual Studio**: Windows용 네이티브 애플리케이션
  - **Linux MakeFile**: Linux용 애플리케이션
  - **Android**: Android 플랫폼에서 실행되는 애플리케이션

- Projucer는 프로젝트를 관리하고 다양한 플랫폼으로 내보내는 기능을 제공하여, 하나의 코드베이스로 여러 플랫폼에서 애플리케이션을 개발할 수 있게 함

### JUCE API

- 여러 모듈로 구성된 애플리케이션 프로그래밍 인터페이스
- 각 모듈은 다양한 기능을 포함하고 있으며, 이를 통해 복잡한 애플리케이션을 손쉽게 개발할 수 있음
- JUCE API는 객체 지향 프로그래밍에 기반한 수많은 클래스들을 제공하여, 복잡한 기능을 손쉽게 구현할 수 있게 함
- 일관된 패턴으로 설계되어 있어, 한 번 학습하면 다양한 컴포넌트를 쉽게 사용할 수 있음

#### 모듈
- **GUI 모듈**: 다양한 위젯(예: 버튼, 슬라이더, 파형 디스플레이 등)을 제공하여 그래픽 사용자 인터페이스를 쉽게 구축할 수 있음
  - **버튼**: 클릭할 수 있는 일반적인 GUI 컴포넌트로, 클릭 시 애플리케이션에 신호를 보냄
  - **파형 디스플레이**: 오디오 파일의 볼륨을 시간에 따라 시각적으로 표시합니다. 주로 DJ 애플리케이션에서 사용됨
  - **슬라이더**: 값을 조절할 수 있는 컴포넌트로, 클릭하고 드래그하여 값을 변경할 수 있음

- **오디오 모듈**: 오디오 파일 재생, 믹싱, 속도 조절 등의 기능을 제공하여 오디오 관련 애플리케이션을 쉽게 개발할 수 있음
  - **오디오 파일 재생**: 디스크에서 오디오 파일을 읽고 재생할 수 있음
  - **오디오 믹싱**: 여러 오디오 파일을 결합하여 믹싱할 수 있음
  - **속도 조절**: 오디오 파일의 재생 속도를 조절할 수 있음



#### JUCE 모듈 목록

- Analytics
- **Audio**
- Blocks
- Box2D
- Core
- Cryptography
- DSP
- DataStructures
- Events
- **GUI**
- Graphics
- OSC
- OpenGL
- ProductUnlocking
- Video

## JUCE 프로젝트 생성 및 실행 과정

### 주요 단계

1. **프로젝트 생성**:
    - Projucer를 실행하고 새로운 오디오 프로젝트를 만듭니다.
    - 프로젝트 이름을 "OttoDecks"로 지정하고 저장 위치를 설정합니다.
    - 전역 모듈 경로를 사용하고 헤더 및 구현 파일을 생성합니다.
    - Xcode, Visual Studio, Linux Makefile을 타겟으로 하는 Exporter를 설정합니다.

2. **프로젝트 파일 확인**:
    - 생성된 프로젝트를 Projucer에서 확인합니다.
    - 파일 시스템에서 빌드 파일과 소스 폴더를 확인합니다.
    - 프로젝트 파일(OttoDecks.jucer)을 다시 열어 Projucer에서 프로젝트 설정을 변경할 수 있습니다.

3. **IDE에서 프로젝트 열기 및 빌드**:
    - 프로젝트를 IDE에서 엽니다(Xcode, Visual Studio 등).
    - IDE에서 프로젝트를 빌드합니다.
    - 코드에 변경 사항이 있을 경우 다시 빌드합니다.

4. **프로젝트 실행**:
    - 빌드가 완료되면 프로젝트를 실행합니다.
    - 실행된 JUCE 애플리케이션이 나타나지만, 초기에는 빈 화면이 표시됩니다.
 
## 상속

### 기본 클래스 정의

- 먼저, 비디오 게임의 차량을 모델링하는 간단한 클래스를 정의
- `Vehicle` 클래스를 만들어서 다음과 같은 멤버와 메서드를 포함:

  - 멤버 변수: `float speed`
  - 생성자: 속도를 0으로 초기화
  - 메서드: `getSpeed`, `accelerate`, `beepHorn`

### 상속을 통한 새로운 클래스 정의

- 게임에 새로운 종류의 차량을 추가하고자 할 때, 상속을 사용하여 새로운 클래스를 정의함
- 예를 들어, `Train`이라는 클래스를 `Vehicle` 클래스로부터 상속받아 정의
- `Train` 클래스는 `Vehicle` 클래스의 모든 공개(public) 기능을 상속받으며, 일부 기능을 재정의할 수 있음
  - `Train` 클래스는 `Vehicle` 클래스의 생성자를 호출하고, 기본 기능을 상속받음
  - `beepHorn` 메서드를 재정의하여 기차의 특성에 맞는 경적 소리를 구현함

### 상속 코드 예시
```cpp
#include <iostream>

// 기본 클래스(Base Class)
class Vehicle {
public:
    Vehicle() : speed(0) {}

    void accelerate() {
        speed += 10;
        std::cout << "Vehicle speed: " << speed << " km/h" << std::endl;
    }

    void beepHorn() {
        std::cout << "Vehicle horn: Beep beep!" << std::endl;
    }

protected:
    int speed;
};

// 파생 클래스(Derived Class)
class Car : public Vehicle { // Car는 Vehicle을 상속받음
public:
    void beepHorn() {
        std::cout << "Car horn: Honk honk!" << std::endl;
    }
};

int main() {
    Vehicle myVehicle;
    Car myCar;

    myVehicle.accelerate(); // Vehicle speed: 10 km/h
    myVehicle.beepHorn();   // Vehicle horn: Beep beep!

    myCar.accelerate();     // Vehicle speed: 10 km/h (Car also has accelerate method from Vehicle)
    myCar.beepHorn();       // Car horn: Honk honk!

    return 0;
}
```