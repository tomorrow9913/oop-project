/** 
 * File Name: Account.cpp
 *
 * Description:
 * Account 객체를 구성하기 위한 멤버 함수 정의 파일
 **/

#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include "Account.h"
#include "DealList.h"

using namespace std;

Account::Account() {
	this->accID = 0;
	this->balance = 0;
	this->cusName = 0;
	this->interestRate = 0.01;
}

Account::Account(int ID, int money, char* name) 
	: accID(ID), balance(money), interestRate(0.01)
{
	AddDealList(money, money, "계좌개설", "-");
	cusName = new char[strlen(name) + 1];
	strcpy_s(cusName, (strlen(name) + 1), name);
}

Account::Account(const Account& ref)
	: accID(ref.accID), balance(ref.balance), interestRate(ref.interestRate)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy_s(cusName, (strlen(ref.cusName) + 1), ref.cusName);
}

/**
* Function Name: GetAccID
* Description: 계좌번호를 반환.
* @param: void
* @return: accID(int)
*
* Author: -
**/
int Account::GetAccID() const { return accID; }

/**
* Function Name: Deposit
* Description: 입금.
* @param: int
* @return: void
*
* Author: -
**/
void Account::Deposit(int money)
{
	int interest = (int)(money * interestRate);	// 기본 이자
	balance += interest;
	if(interest) AddDealList(balance, interest, "예금이자", "-");
	
	string msg;
	cout << "입금 메시지 : ";
	cin >> msg;
	
	balance += money;
	if (money) AddDealList(balance, money, "현금 입금", msg);
}
/**
* Function Name: NointerestRateDeposit
* Description: 이체 시 받는 계좌 잔액 증가.
* @param: int
* @return: void
*
* Author:박주용
**/
void Account::NointerestRateDeposit(int money){
	balance += money;
}

/**
* Function Name: Withdraw
* Description: 출금
*	출금 성공시 잔액 반환
*	실패시 오류 코드(음수) 반환
*	ERR_LACK(-1) : 잔액 부족
* @param: int 출금액
* @return: int 잔액
*
* Author: Jeong MinGyu
**/
int Account::Withdraw(int money)
{
	if (balance < money)
		return ERR_LACK;

	string msg;
	cout << "출금 메시지 : ";
	cin >> msg;

	balance -= money;
	if (money) AddDealList(balance, -money, "현금 출금", msg);
	return balance;
}

/**
* Function Name: ShowAccInfo
* Description: 계좌 정보 출력.
* @param: void
* @return: void
*
* Author: -
**/
void Account::ShowAccInfo() const
{
	cout << "계좌ID: " << accID << endl;
	cout << "이  름: " << cusName << endl;
	cout << "잔  액: " << balance << endl;
	cout << "계좌 정보: " << typeCheck << endl;
	if (typeCheck == "HighCreditAccount") {
		cout << "등급: " << checkGrade << endl;
	}
	cout << "이자:" << interestRateCheck << endl;
}

/**
* Function Name: PrintDealList
* Description: 최근 거래 내역 출력.
* @param: void
* @return: void
*
* Author: Jeong MinGyu
**/
void Account::PrintDealList() const {
	queue<DealList*> copy = dealList;
	
	while (copy.size())
	{
		cout << *(copy.front());
		copy.pop();
	}
	cout << "=============================" << endl;
}

/**
* Function Name: AddDealList
* Description: 최근 거래 내역 추가.
* @param: int balance, int money, int year, int month, int date, string addressID, string message
* @return: void
*ㅏ
* Author: Jeong MinGyu
**/
void Account::AddDealList(int balance, int money, string name, string message) {
	if (dealList.size() == DEAL_LIST_MAX) {
		delete dealList.front();
		dealList.pop();
	}
	
	dealList.push(new DealList(balance, money, name, message));
}

Account::~Account()
{
	delete[]cusName;
}

/**
* Function Name: Transfer
* Description: 이체
* @param: int money, Account accAccount
* @return: int
*
* Author: 남유정, 박주용
**/
int Account::Transfer(int money, Account& accAccount) {//받는 계좌
	if(balance > money){
		balance-=money;
		string msg;
		cout << "메시지를 입력하시오." << endl;
		cin >> msg;
		accAccount.NointerestRateDeposit(money);
		this->AddDealList(this->getBalance(),-money, this->cusName, msg);
        accAccount.AddDealList(accAccount.getBalance(),money,accAccount.cusName, msg);
		return money;
	}
	else
		return ERR_LACK;
}

/**
* Function Name: getbalance
* Description: 잔액 조회
* @param: balance
* @return: int
*
* Author: 남유정, 박주용
**/

int Account::getBalance(){
	return this->balance;
}