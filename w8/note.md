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

## Pseudocode of Matching Algorithm
- 주문서(매수 및 매도 주문)를 처리하여 거래를 완료하는 알고리즘
- 가격이 가장 높은 매도 주문부터 처리됨
- 매수 주문은 bids, 매도 주문은 asks로 정의
- 순서
  1. 주문서(asks 및 bids)에서 매도 주문(asks)을 오름차순으로, 매수 주문(bids)을 내림차순으로 정렬
  2. 매수 주문(bids)와 매도 주문(asks) 간의 매칭을 확인
  3. 각 매도 주문(asks)에 대해 각 매수 주문(bids)을 확인하면서 매치가 발생하는지 확인
  4. 매치가 발생한 경우:
    - 매수 주문(bid)의 가격 >= 매도 주문(ask)이면 매치
    - 매치된 거래 정보를 기록하고, 조건에 따라 해당 거래에 사용된 주문의 양을 조정
  5. 모든 주문을 처리할 때까지 위 단계를 반복

- 수도코드
  ```
  asks = orderbook.asks
  bids = orderbook.bids

  sales = []
  sort asks lowest first
  sort bids highest first

  for ask in asks:
    for bid in bids:
      if bid.price >= ask.price # we have a match
        sale = new order()
        sale.price = ask.price

        # now work out how much was sold and
        # create new bids and asks covering
        # anything that was not sold
        if bid.amount == ask.amount: # bid completely clears ask
          sale.amount = ask.amount
          sales.append(sale)
          bid.amount = 0 # make sure the bid is not processed again
          # can do no more with this ask
          # go onto the next ask
          break

        if bid.amount > ask.amount: # ask is completely gone slice the bid
          sale.amount = ask.amount
          sales.append(sale)
          # we adjust the bid in place
          # so it can be used to process the next ask
          bid.amount = bid.amount - ask.amount
          # ask is completely gone, so go to next ask break

        if bid.amount < ask.amount # bid is completely gone, slice the ask
          sale.amount = bid.amount
          sales.append(sale)
          # update the ask
          # and allow further bids to process the ramining amount
          ask.amount = ask.amount - bid.amount
          bid.amount = 0 # make sure the bid is not processed again
          # some ask remains so go to the next bid
          continue
  ```

## `break` vs. `continue`
  - for 루프 내부에서 break와 continue는 루프의 동작을 제어하는 키워드
  - `break` 루프를 즉시 종료하고, 루프를 빠져나와 루프 이후의 코드로 이동함. 따라서 break가 실행되면 루프 내부의 나머지 코드는 실행되지 않고, 바깥쪽 코드 블록으로 제어가 넘어감.
  - `continue` 현재 루프의 이번 반복을 중지하고 다음 반복으로 넘어감. 따라서 continue가 실행되면 루프 내부의 나머지 코드는 실행되지 않고, 현재 반복은 종료되고 다음 반복이 시작됨.