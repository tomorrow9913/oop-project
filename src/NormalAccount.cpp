/**
 * File Name: NormalAccount.cpp
 *
 * Description:
 * NormalAccount ��ü�� �����ϱ� ���� ��� �Լ� ���� ����
 **/
#include "NormalAccount.h"

NormalAccount::NormalAccount() :Account(0, 0, NULL) {
	this->addInterestRate = 0.01;
	this->typeCheck = "Normal";
};

NormalAccount::NormalAccount(int ID, int money, char* name) :Account(ID, money, name) {
	this->addInterestRate = 0.01;
	this->typeCheck = "Normal";
	this->interestRateCheck = addInterestRate; 
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