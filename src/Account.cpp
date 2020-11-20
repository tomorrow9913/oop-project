/** 
 * File Name: Account.cpp
 *
 * Description:
 * Account ��ü�� �����ϱ� ���� ��� �Լ� ���� ����
 **/

#include <iostream>
#include <cstring>
#include "Account.h"

using namespace std;


Account::Account() {

}

Account::Account(int ID, int money, char* name) : accID(ID), balance(money)
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
* Description: ���¹�ȣ�� ��ȯ.
* @param: void
* @return: accID(int)
*
* Author: -
**/
int Account::GetAccID() const { return accID; }

/**
* Function Name: Deposit
* Description: �Ա�.
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
* Description: ���.
* @param: int ��ݾ�
* @return: int ��ݾ�
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
* Description: ���� ���� ���.
* @param: void
* @return: void
*
* Author: -
**/
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

NormalAccount::NormalAccount() {};
NormalAccount::NormalAccount(int ID, int money, char* name, int grade) {
	this->accID = ID;
	this->balance = money;
	this->cusName = name;
	this->grade = grade;
}

void NormalAccount::SetGrade(int grade) {
	this->grade = grade;
}
int NormalAccount::GetGrade() {
	return this->grade;
}

HighCreditAccount::HighCreditAccount() {
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

void HighCreditAccount::SetGrade(int grade) {
	this->grade = grade;
}
int HighCreditAccount::GetGrade() {
	return this->grade;
}
void HighCreditAccount::SetTransferFee(int grade, double transferFee) {
	this->transferFee[grade - 1] = transferFee;
}
int HighCreditAccount::GetTransferFee(int grade) {
	return this->transferFee[grade - 1];
}