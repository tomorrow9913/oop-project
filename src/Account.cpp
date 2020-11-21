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
* Description: ���
*	��� ������ �ܾ� ��ȯ
*	���н� ���� �ڵ�(����) ��ȯ
*	ERR_LACK(-1) : �ܾ� ����
* @param: int ��ݾ�
* @return: int �ܾ�
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
* Description: ���µ�� ���� �� ��ȯ
* @param: int / void
* @return: void / int
*
* Author: -Ȳ����
**/
void HighCreditAccount::SetGrade(int grade) {
	this->grade = grade;
}
int HighCreditAccount::GetGrade() {
	return this->grade;
}

/**
* Function Name: Deposit
* Description: �Ա�
* @param: int money
* @return: void
*
* Author: ���ֿ� �� 3��
**/
void NormalAccount::Deposit(int money){
	int interest = (int)(money * interestRate);

	balance += interest + money;
}

/**
* Function Name: Deposit
* Description: �Ա�
*	��� ���� �� ���� ���� ����
* @param: int money
* @return: void
*
* Author: ���ֿ� �� 3��
**/
void HighCreditAccount::Deposit(int money){
	//TODO ��� ���� ���� �Լ� �и�
	//���� ���ö����� ��� ����, ����
	if (balance >= SET_C && balance < SET_B) { SetGrade(GRADE_C); addInterestRate = C_RATE; }
	else if(balance >= SET_B && balance < SET_A){SetGrade(GRADE_B);addInterestRate = B_RATE; }
	else if(balance >= SET_A){SetGrade(GRADE_A);addInterestRate = A_RATE; }
	
	//A,B.C ���� �ٸ� ���� 
	int interest = (int)(money * interestRate);	// �⺻ ����
	interest += (int)(money * addInterestRate); //�⺻ ����+ ��޺� ����
	
	balance += interest + money;
}
