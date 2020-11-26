/**
 * File Name: HighCreditAccount.cpp
 *
 * Description:
 * HighCreditAccount ��ü�� �����ϱ� ���� ��� �Լ� ���� ����
 **/
#include "HighCreditAccount.h"


double HighCreditAccount::interestRate[4] = { 0.07, 0.05, 0.03, 0 };

HighCreditAccount::HighCreditAccount() :Account(0, 0, NULL) {
	this->accID = 0;
	this->balance = 0;
	this->cusName = 0;
	this->grade = 0;
	this->addInterestRate = 0;
	this->typeCheck = "HighCreditAccount";
	this->interestRateCheck = addInterestRate;
};

HighCreditAccount::HighCreditAccount(int ID, int money, char* name) :Account(ID, money, name) {
	if (this->balance >= SET_A) { this->grade = 1; this->addInterestRate = interestRate[this->grade - 1]; }
	else if (this->balance >= SET_B) { this->grade = 2; this->addInterestRate = interestRate[this->grade - 1]; }
	else if (this->balance >= SET_C) { this->grade = 3; this->addInterestRate = interestRate[this->grade - 1]; }
	else { this->grade = 4; this->addInterestRate = interestRate[this->grade - 1]; }
	if (this->balance >= SET_A) {
		this->grade = 1;
		this->addInterestRate = interestRate[this->grade - 1];
		this->checkGrade = "A���";
	}
	else if (this->balance >= SET_B) {
		this->grade = 2;
		this->addInterestRate = interestRate[this->grade - 1];
		this->checkGrade = "B���";
	}
	else if (this->balance >= SET_C) {
		this->grade = 3;
		this->addInterestRate = interestRate[this->grade - 1];
		this->checkGrade = "C���";
	}
	else {
		this->grade = 4;
		this->addInterestRate = interestRate[this->grade - 1];

	}
	this->typeCheck = "HighCreditAccount";
	this->interestRateCheck = addInterestRate;
}

/**
* Function Name: SetGrade / GetGrade
* Description: ���µ�� ���� �� ��ȯ
* @param: void / void
* @return: void / int
*
* Author:
* - get Ȳ����
* - set Jeong MinGyu
**/
void HighCreditAccount::SetGrade() {
	if (balance >= SET_C && balance < SET_B) {
		grade = GRADE_C;
		addInterestRate = interestRate[grade - 1];
	}
	else if (balance >= SET_B && balance < SET_A) {
		grade = GRADE_B;
		addInterestRate = interestRate[grade - 1];
	}
	else if (balance >= SET_A) {
		grade = GRADE_A;
		addInterestRate = interestRate[grade - 1];
	}
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
* Author: ������, ���ֿ�, �̽¹�, ���α�
**/
void HighCreditAccount::Deposit(int money) {
	//��� Ȯ��
	SetGrade();
	Account::Deposit(money); //�⺻ ����
	int interest = (int)(money * addInterestRate);
	balance += interest; //��޺� ����
	if (interest) AddDealList(balance, interest, "�������", "-");
}