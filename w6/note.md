# Week6. Integrating CSV Parser
## instance method vs. static method
- instance method
  - stateful
  - 특정 객체의 상태에 따라 동작이 달라지는 메서드
  - 객체의 인스턴스 변수에 접근하거나 수정하는 메서드
- static method
  - stateless
  - 인스턴스 상태(인스턴스 변수)와 무관하게 동작하는, 클래스 레벨의 유틸리티 함수
  - 클래스 인스턴스를 생성하지 않고도 호출할 수 있는 메서드
  - They basically temporarily use some space in the memory and then they give it back
- When to use static method
  - 메서드가 인스턴스 변수에 접근할 필요가 없을 때
  - 메서드가 특정 객체의 상태에 무관하게 동작할 수 있을 때
  - 클래스와 관련된 유틸리티 함수
