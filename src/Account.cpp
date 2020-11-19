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

/****************************************************************
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