/**
 * File Name: HighCreditAccount.cpp
 *
 * Description:
 * HighCreditAccount ��ü�� �����ϱ� ���� ��� �Լ� ���� ����
 **/
#include <iostream>
#include <iomanip>
#include <string>
#include "HighCreditAccount.h"
#include "Account.h"
#include "DesignSet.h"

using namespace std;

double HighCreditAccount::interestRate[4] = { 0.07, 0.05, 0.03, 0 };

HighCreditAccount::HighCreditAccount() :Account(0, 0, NULL) {
	this->accID = 0;
	this->balance = 0;
	this->cusName = 0;
	this->grade = 0;
	this->addInterestRate = 0;
};

HighCreditAccount::HighCreditAccount(int ID, int money, char* name) :Account(ID, money, name) {
	if (this->balance >= SET_A) { this->grade = 1; this->addInterestRate = interestRate[this->grade - 1]; }
	else if (this->balance >= SET_B) { this->grade = 2; this->addInterestRate = interestRate[this->grade - 1]; }
	else if (this->balance >= SET_C) { this->grade = 3; this->addInterestRate = interestRate[this->grade - 1]; }
	else { this->grade = 4; this->addInterestRate = interestRate[this->grade - 1]; }
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
	if (this->balance >= SET_A) {
		this->grade = GRADE_A;
		this->addInterestRate = interestRate[this->grade - 1];
	}
	else if (this->balance >= SET_B) {
		this->grade = GRADE_B;
		this->addInterestRate = interestRate[this->grade - 1];
	}
	else if (this->balance >= SET_C) {
		this->grade = GRADE_C;
		this->addInterestRate = interestRate[this->grade - 1];
	}
	else {
		this->grade = GRADE_D; this->addInterestRate = interestRate[this->grade - 1];
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
	Account::Deposit(money); //�⺻ ����
	int interest = (int)(money * addInterestRate);
	balance += interest; //��޺� ����
	if (interest) AddDealList(balance, interest, "�������", "-");
	SetGrade();
}


/**
* Function Name: ShowAccInfo
* Description: info ���
* @param: void
* @return: void
*
* Author: -
**/
void HighCreditAccount::ShowAccInfo() const {
	Account::ShowAccInfo();
	cout << "HighCredit" << left << setw(15);
	string gradeString;

	switch (grade)
	{
	case GRADE_A:
		gradeString = "A���"; break;
	case GRADE_B: 
		gradeString = "B���"; break;
	case GRADE_C:
		gradeString = "C���"; break;
	case GRADE_D:
		gradeString = "��޾���"; break;
	default:
		break;
	}

	cout << gradeString << left << setw(15);
	cout << (Account::interestRate + addInterestRate) << left << setw(15);
	if (activation) { changeColor(lightBlue); cout << "���� Ȱ��ȭ" << endl; }
	else { changeColor(lightRed); cout << "���� ����" << endl; }

	changeColor(darkWhite);
}

/**
* Function Name: Transfer
* Description: �۱� �� ��� ����
* @param: void
* @return: int
*
* Author: Jeong MinGyu
**/
int HighCreditAccount::Transfer(int money, Account& accAccount) {
	Account::Transfer(money, accAccount);
	this->SetGrade();
	return money;
}

/**
* Function Name: Withdraw
* Description: ��� �� ��� ����
* @param: int money
* @return: int
*
* Author: Jeong MinGyu
**/
int HighCreditAccount::Withdraw(int money) {
	int result = Account::Withdraw(money);
	SetGrade();
	return result;
}

/**
* Function Name: NointerestRateDeposit
* Description: ���� ���� �Ա� �� ��� ����
* @param: int money
* @return: void
*
* Author: Jeong MinGyu
**/
void HighCreditAccount::NointerestRateDeposit(int money) {
	Account::NointerestRateDeposit(money);
	this->SetGrade();
}