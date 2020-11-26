/**
 * File Name: HighCreditAccount.cpp
 *
 * Description:
 * HighCreditAccount 객체를 구성하기 위한 멤버 함수 정의 파일
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
		this->checkGrade = "A등급";
	}
	else if (this->balance >= SET_B) {
		this->grade = 2;
		this->addInterestRate = interestRate[this->grade - 1];
		this->checkGrade = "B등급";
	}
	else if (this->balance >= SET_C) {
		this->grade = 3;
		this->addInterestRate = interestRate[this->grade - 1];
		this->checkGrade = "C등급";
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
* Description: 계좌등급 설정 및 반환
* @param: void / void
* @return: void / int
*
* Author:
* - get 황진주
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
* Description: 입금
* @param: int money
* @return: void
*
* Author: 남유정, 박주용, 이승민, 정민규
**/
void HighCreditAccount::Deposit(int money) {
	//등급 확인
	SetGrade();
	Account::Deposit(money); //기본 이자
	int interest = (int)(money * addInterestRate);
	balance += interest; //등급별 이자
	if (interest) AddDealList(balance, interest, "우대이자", "-");
}