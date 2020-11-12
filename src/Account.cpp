/****************************************************************
 * File Name: Account.cpp
 *
 * Description:
 * Account 객체를 구성하기 위한 멤버 함수 정의 파일
 *
 * Extern File
 * Name         Description
 * ============ ================================================
 * iostream     기본적인 입출력을 위함
 * cstring      문자열 처리를 위함
 * Account.h    클래스 정의 불러옴
 * 
 * Extern Variables
 * Name         Type        Description
 * ============ =========== ====================================
 *
 * Global Variables
 * Name         Type        Description
 * ============ =========== ====================================
 * None
 ****************************************************************/

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
* Description: 계좌번호 출력.
* @param: void
* @return: accID
* etc: const function
*
* Author: -
* Creat Date: -
* Last Edit: -
*
* Algorithm:
***************************************************************/
int Account::GetAccID() const { return accID; }

/****************************************************************
* Function Name: Deposit
* Description: 입금.
* @param: int
* @return: void
* etc: None
*
* Author: -
* Creat Date: -
* Last Edit: -
*
* Algorithm:
***************************************************************/
void Account::Deposit(int money)
{
	balance += money;
}

/****************************************************************
* Function Name: Withdraw
* Description: 출금.
* @param: int 출금액
* @return: int 출금후 잔액
* etc: None
*
* Author: -
* Creat Date: -
* Last Edit: -
*
* Algorithm:
***************************************************************/
int Account::Withdraw(int money)
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}

/****************************************************************
* Function Name: ShowAccInfo
* Description: 계좌 정보 출력.
* @param: void
* @return: void
* etc: const Function
*
* Author: -
* Creat Date: -
* Last Edit: -
*
* Algorithm:
***************************************************************/
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