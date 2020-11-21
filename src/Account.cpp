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
	this->interestRate = 0;
}

Account::Account(int ID, int money, char* name) 
	: accID(ID), balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy_s(cusName, (strlen(name) + 1), name);
}

Account::Account(const Account& ref)
	: accID(ref.accID), balance(ref.balance)
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
};

NormalAccount::NormalAccount(int ID, int money, char* name, int grade, double addInterestRate) {
	this->accID = ID;
	this->balance = money;
	this->cusName = name;
	this->addInterestRate = addInterestRate;
}

NormalAccount::NormalAccount(const NormalAccount& ref)
	: Account(ref)
{

}

HighCreditAccount::HighCreditAccount() {
	this->accID = 0;
	this->balance = 0;
	this->cusName = 0;
	this->grade = 0;
};

HighCreditAccount::HighCreditAccount(int ID, int money, char* name, int grade, double addInterestRate) {
	this->accID = ID;
	this->balance = money;
	this->cusName = name;
	this->grade = grade;
	this->addInterestRate = addInterestRate;
}

/**
* Function Name: SetGrade / GetGrade
* Description: 계좌등급 설정 및 반환
* @param: int / void
* @return: void / int
*
* Author: -황진주
**/
void HighCreditAccount::SetGrade(int grade) {
	this->grade = grade;
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
* Author: 박주용 외 3인
**/
void NormalAccount::Deposit(int money){
	int interest = (int)(money * interestRate);

	balance += interest + money;
}

/**
* Function Name: Deposit
* Description: 입금
*	등급 설정 및 이율 설정 포함
* @param: int money
* @return: void
*
* Author: 박주용 외 3인
**/
void HighCreditAccount::Deposit(int money){
	//TODO 등급 설정 이후 함수 분리
	//돈이 들어올때마다 등급 측정, 이율
	if (balance >= SET_C && balance < SET_B) { SetGrade(GRADE_C); addInterestRate = C_RATE; }
	else if(balance >= SET_B && balance < SET_A){SetGrade(GRADE_B);addInterestRate = B_RATE; }
	else if(balance >= SET_A){SetGrade(GRADE_A);addInterestRate = A_RATE; }
	
	//A,B.C 따라서 다른 이자 
	int interest = (int)(money * interestRate);	// 기본 이자
	interest += (int)(money * addInterestRate); //기본 이자+ 등급별 이자
	
	balance += interest + money;
}
