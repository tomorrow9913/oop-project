# Account

Last Edit: 2020.11.13.

======================================

# 개요

객체의 정의는 `Account.h` 에 정의 되어 있으며 멤버 함수의 구현은 `Account.cpp`에 구현이 되어있습니다.

Account 클래스는 계정 정보를 저장하는 클래스입니다.

객체의 생성은 아래와 같이 사용합니다.

```cpp
// 일반적인 클래스 생성
Account acc = Account(ID, money, name);

// 포인터로 클래스 생성
Account *acc = new Account(ID, money, name);
```

# 멤버 변수
## Private
|변수명|자료형|설명|
|------|---|---|
|accID|int|계좌 번호|
|balance|int|잔액|
|cusName|char*|계좌 주인|

# 멤버 함수
## Public
|Method|반환형|설명|
|------|---|---|
|Account(ID, money, name)||주어진 id로 money원을 가진 name소유의 계정을 생성합니다|
|Account(ref)||복사 생성자|
|~Account()||객체가 파괴될 때 클래스를 정리합니다.|
|GetAccID()|int|객체의 계좌 번호를 반환합니다|
|Deposit(money)|void|현재 객체의 금액에 money만큼 추가합니다.|
|Withdraw(money)|int|현재 객체의 잔액보다 money가 적다면 잔액을 money만큼 줄입니다.|
|ShowAccInfo()|void|현재 계좌 정보를 출력합니다|

# 자세한 문서

## Account(ID, money, name)

생성자로서 주어진 id로 money원을 가진 name소유의 계정을 생성합니다.

int ID, int money, char* name

### 매개변수

|이름|자료형|설명|
|------|---|---|
|ID|int|계좌 번호|
|money|int|초기 금액|
|name|char *|계좌 주인 이름|

### 반환값

없음

## Account(ref)

복사 생성자로 복사가 이루어질 때 자동으로 호출 됩니다.

### 매개변수

|이름|자료형|설명|
|------|---|---|
|ref|const Account&|Account 클래스|

### 반환값

없음

## ~Account()

객체가 파괴될 때 자동으로 호출 됩니다.

### 매개변수

없음

### 반환값

없음

## GetAccID()

객체의 계좌 번호를 반환합니다

### 매개변수

없음

### 반환값

`int` - 계좌 번호를 반환합니다.

## Deposit(money)

현재 객체의 금액에 money만큼 추가합니다.

### 매개변수

|이름|자료형|설명|
|------|---|---|
|money|int|입금할 금액|

### 반환값

void

## Withdraw(money)

현재 객체의 잔액보다 money가 적다면 잔액을 money만큼 줄입니다.

### 매개변수

|이름|자료형|설명|
|------|---|---|
|money|int|출금할 금액|

### 반환값

`int` - 출금 금액이 잔액보다 많다면 0을 리턴, 출금이 가능하면 출금액 money를 반환

## ShowAccInfo()

### 매개변수

void

### 반환형

void