/** 
 * File Name: Account.cpp
 *
 * Description:
 * Account 객체를 구성하기 위한 멤버 함수 정의 파일
 **/

#include <iostream>
#include <cstring>
#include "Account.h"

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
	balance += interest + money;
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

	balance -= money;
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
	
}

Account::~Account()
{
	delete[]cusName;
}

NormalAccount::NormalAccount() {
	this->accID = 0;
	this->balance = 0;
	this->cusName = 0;
	this->addInterestRate = 0.01;
};

NormalAccount::NormalAccount(int ID, int money, char* name) {
	this->accID = ID;
	this->balance = money;
	this->cusName = new char[strlen(name) + 1];
	strcpy_s(this->cusName, (strlen(name) + 1), name);
	this->addInterestRate = 0.01;
}

NormalAccount::NormalAccount(const NormalAccount& ref)
	: Account(ref)
{
	this->cusName = new char[strlen(ref.cusName) + 1];
	strcpy_s(this->cusName, (strlen(ref.cusName) + 1), ref.cusName);
}

double HighCreditAccount::interestRate[4] = { 0.07, 0.05, 0.03, 0 };

HighCreditAccount::HighCreditAccount() {
	this->accID = 0;
	this->balance = 0;
	this->cusName = 0;
	this->grade = 0;
	this->addInterestRate = 0;
};

HighCreditAccount::HighCreditAccount(int ID, int money, char* name) {
	this->accID = ID;
	this->balance = money;
	this->cusName = new char[strlen(name) + 1];
	strcpy_s(this->cusName, (strlen(name) + 1), name);
	if (this->balance >= SET_A)	{ this->grade = 1; this->addInterestRate = interestRate[this->grade - 1]; }
	else if (this->balance >= SET_B) { this->grade = 2; this->addInterestRate = interestRate[this->grade - 1]; }
	else if (this->balance >= SET_C) {this->grade = 3; this->addInterestRate = interestRate[this->grade - 1]; }
	else { this->grade = 4; this->addInterestRate = interestRate[this->grade - 1]; }
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
	balance += (int)(money * addInterestRate); //등급별 이자
}