/****************************************************************
 * File Name: Account.cpp
 *
 * Description:
 * Account ��ü�� �����ϱ� ���� ��� �Լ� ���� ����
 *
 * Extern File
 * Name         Description
 * ============ ================================================
 * iostream     �⺻���� ������� ����
 * cstring      ���ڿ� ó���� ����
 * Account.h    Ŭ���� ���� �ҷ���
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
* Description: ���¹�ȣ ���.
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
* Description: �Ա�.
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
* Description: ���.
* @param: int ��ݾ�
* @return: int ����� �ܾ�
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
* Description: ���� ���� ���.
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
	cout << "����ID: " << accID << endl;
	cout << "��  ��: " << cusName << endl;
	cout << "��  ��: " << balance << endl;
}

Account::~Account()
{
	delete[]cusName;
}