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
* Description: 출금.
* @param: int 출금액
* @return: int 출금액
*
* Author: -
**/
int Account::Withdraw(int money)
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
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
	this->grade = 0;
};

NormalAccount::NormalAccount(int ID, int money, char* name, int grade) {
	this->accID = ID;
	this->balance = money;
	this->cusName = name;
	this->grade = grade;
}

NormalAccount::NormalAccount(const NormalAccount& ref)
	: Account(ref), grade(ref.grade)
{

}

/**
* Function Name: SetGrade / GetGrade
* Description: 계좌등급 설정 및 반환
* @param: int / void
* @return: void / int
*
* Author: -황진주
**/
void NormalAccount::SetGrade(int grade) {
	this->grade = grade;
}
int NormalAccount::GetGrade() {
	return this->grade;
}

HighCreditAccount::HighCreditAccount() {
	this->accID = 0;
	this->balance = 0;
	this->cusName = 0;
	this->grade = 0;
	transferFee[0] = 1.0;
	transferFee[1] = 1.2;
	transferFee[2] = 1.5;
};
HighCreditAccount::HighCreditAccount(int ID, int money, char* name, int grade) {
	this->accID = ID;
	this->balance = money;
	this->cusName = name;
	this->grade = grade;
	transferFee[0] = 1.0;
	transferFee[1] = 1.2;
	transferFee[2] = 1.5;
}
HighCreditAccount::HighCreditAccount(const HighCreditAccount& ref)
	: Account(ref), grade(ref.grade)
{
	for (int i = 0; i < sizeof(transferFee) / sizeof(double); i++) {
		this->transferFee[i] = ref.transferFee[i];
	}
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
* Function Name: SetTransferFee / GetTransferFee
* Description: 이체 수수료 설정 / 반환
* @param: int, double / int
* @return: void / double
*
* Author: -황진주
**/
void HighCreditAccount::SetTransferFee(int grade, double transferFee) {
	this->transferFee[grade - 1] = transferFee;
}
double HighCreditAccount::GetTransferFee(int grade) {
	return this->transferFee[grade - 1];
}