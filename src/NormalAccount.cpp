/**
 * File Name: NormalAccount.cpp
 *
 * Description:
 * NormalAccount ��ü�� �����ϱ� ���� ��� �Լ� ���� ����
 **/

#include <iostream>
#include <iomanip>
#include "NormalAccount.h"
#include "Account.h"
#include "DesignSet.h"

using namespace std;

NormalAccount::NormalAccount() :Account(0, 0, NULL) {
	this->addInterestRate = 0.01;
};

NormalAccount::NormalAccount(int ID, int money, char* name) :Account(ID, money, name) {
	this->addInterestRate = 0.01;
}

NormalAccount::NormalAccount(const NormalAccount& ref)
	: Account(ref)
{
	this->cusName = new char[strlen(ref.cusName) + 1];
	strcpy_s(this->cusName, (strlen(ref.cusName) + 1), ref.cusName);
}

/**
* Function Name: Deposit
* Description: �Ա�
* @param: int money
* @return: void
*
* Author: ������, ���ֿ�, �̽¹�, ���α�
**/
void NormalAccount::Deposit(int money) {
	Account::Deposit(money);
}

/**
* Function Name: ShowAccInfo
* Description: info ���
* @param: void
* @return: void
*
* Author: -
**/
void NormalAccount::ShowAccInfo() const {
	Account::ShowAccInfo();
	cout << "Normal" << left << setw(15);

	cout << "X" << left << setw(15);
	cout << interestRate + addInterestRate << left << setw(15);
	if (activation) { changeColor(lightBlue); cout << "���� Ȱ��ȭ" << endl; }
	else { changeColor(lightRed); cout << "���� ����" << endl; }

	changeColor(darkWhite);
}
