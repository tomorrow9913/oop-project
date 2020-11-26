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
void Account::AddDealList(int balance, int money, string addressID, string message) {
	if (dealList.size() == DEAL_LIST_MAX) {
		delete dealList.front();
		dealList.pop();
	}
	
	dealList.push(new DealList(balance, money, addressID, message));
}

Account::~Account()
{
	delete[]cusName;
}

NormalAccount::NormalAccount():Account(0, 0, NULL) {
	this->accID = 0;
	this->balance = 0;
	this->cusName = 0;
	this->addInterestRate = 0.01;
	this->typeCheck = "NormalAccount";
};

NormalAccount::NormalAccount(int ID, int money, char* name) :Account(ID, money, name) {
	this->addInterestRate = 0.01;
	this->typeCheck = "NormalAccount"; //추가
	this->interestRateCheck = addInterestRate; //추가
}

NormalAccount::NormalAccount(const NormalAccount& ref)
	: Account(ref)
{
	this->cusName = new char[strlen(ref.cusName) + 1];
	strcpy_s(this->cusName, (strlen(ref.cusName) + 1), ref.cusName);
}

double HighCreditAccount::interestRate[4] = { 0.07, 0.05, 0.03, 0 };

HighCreditAccount::HighCreditAccount() :Account(0, 0, NULL) {
	this->accID = 0;
	this->balance = 0;
	this->cusName = 0;
	this->grade = 0;
	this->addInterestRate = 0;
	this->typeCheck = "HighCreditAccount";
	this->interestRateCheck = addInterestRate;
};

HighCreditAccount::HighCreditAccount(int ID, int money, char* name) :Account(ID, money, name) {
	if (this->balance >= SET_A)	{ this->grade = 1; this->addInterestRate = interestRate[this->grade - 1]; }
	else if (this->balance >= SET_B) { this->grade = 2; this->addInterestRate = interestRate[this->grade - 1]; }
	else if (this->balance >= SET_C) {this->grade = 3; this->addInterestRate = interestRate[this->grade - 1]; }
	else { this->grade = 4; this->addInterestRate = interestRate[this->grade - 1]; }
	if (this->balance >= SET_A) {
		this->grade = 1;
		this->addInterestRate = interestRate[this->grade - 1];
		this->checkGrade = "A등급";
	}
	else if (this->balance >= SET_B) {
		this->grade = 2;
		this->addInterestRate = interestRate[this->grade - 1];
		this->checkGrade = "B등급";
	}
	else if (this->balance >= SET_C) {
		this->grade = 3;
		this->addInterestRate = interestRate[this->grade - 1];
		this->checkGrade = "C등급";
	}
	else {
		this->grade = 4;
		this->addInterestRate = interestRate[this->grade - 1];

	}
	this->typeCheck = "HighCreditAccount";
	this->interestRateCheck = addInterestRate;
}

/**
* Function Name: SetGrade / GetGrade
* Description: 계좌등급 설정 및 반환
* @param: void / void
* @return: void / int
*
* Author: 
* - get 황진주
* - set Jeong MinGyu
**/
void HighCreditAccount::SetGrade() {
	if (balance >= SET_C && balance < SET_B) {
		grade = GRADE_C;
		addInterestRate = interestRate[grade-1];
	}
	else if (balance >= SET_B && balance < SET_A) {
		grade = GRADE_B;
		addInterestRate = interestRate[grade-1];
	}
	else if (balance >= SET_A) {
		grade = GRADE_A;
		addInterestRate = interestRate[grade-1];
	}
}

int HighCreditAccount::GetGrade() {
	return this->grade;
}

/**
* Function Name: Deposit
* Description: 입금
* @param: int money
* @return: void
*
* Author: 남유정, 박주용, 이승민, 정민규
**/
void NormalAccount::Deposit(int money){
	Account::Deposit(money);
}

/**
* Function Name: Deposit
* Description: 입금
* @param: int money
* @return: void
*
* Author: 남유정, 박주용, 이승민, 정민규
**/
void HighCreditAccount::Deposit(int money){
	//등급 확인
	SetGrade();
	Account::Deposit(money); //기본 이자
	int interest = (int)(money * addInterestRate);
	balance += interest; //등급별 이자
	if(interest) AddDealList(balance, interest, "우대이자", "-");
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
		accAccount.NointerestRateDeposit(money);
		return money;
	}
	else
		return ERR_LACK;
}