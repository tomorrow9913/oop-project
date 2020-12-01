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
	this->typeCheck = "HighCredit";
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

		checkGrade = new char[strlen("A���") + 1];
		strcpy_s(checkGrade, strlen("A���") + 1,"A���");
	}
	else if (this->balance >= SET_B) {
		this->grade = 2;
		this->addInterestRate = interestRate[this->grade - 1];
		checkGrade = new char[strlen("B���") + 1];
		strcpy_s(checkGrade, strlen("B���") + 1, "B���");
	}
	else if (this->balance >= SET_C) {
		this->grade = 3;
		this->addInterestRate = interestRate[this->grade - 1];
		checkGrade = new char[strlen("C���") + 1];
		strcpy_s(checkGrade, strlen("C���") + 1, "C���");
	}
	else {
		this->grade = 4;
		this->addInterestRate = interestRate[this->grade - 1];
		checkGrade = new char[strlen("��޾���") + 1];
		strcpy_s(checkGrade, strlen("��޾���") + 1, "��޾���");
	}
	this->typeCheck = "HighCredit";
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
	if (this->balance >= SET_A) { this->grade = 1; this->addInterestRate = interestRate[this->grade - 1]; }
	else if (this->balance >= SET_B) { this->grade = 2; this->addInterestRate = interestRate[this->grade - 1]; }
	else if (this->balance >= SET_C) { this->grade = 3; this->addInterestRate = interestRate[this->grade - 1]; }
	else { this->grade = 4; this->addInterestRate = interestRate[this->grade - 1]; }
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