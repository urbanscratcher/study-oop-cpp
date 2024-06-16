# Week9. Wallet

## std::map
```cpp
  size_type count (const key_type& k) const;
```
- `const` 키워드를 2번 사용하는 이유
  - 1번째 `const`: 매개변수 `k`가 상수 참조임을 나타냄. 함수에 전달된 키 값이 수정되지 않도록 보장
  - 2번째 `const`: `const` (멤버 함수 뒤에 위치): 멤버 함수 자체가 상수 함수임을 나타냄. 해당 멤버 함수가 객체의 상태를 변경하지 않음을 의미. `std::map` 객체의 어떤 멤버 변수도 수정하지 않는다는 것을 보장함.
