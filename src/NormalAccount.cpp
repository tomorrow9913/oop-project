/**
 * File Name: NormalAccount.cpp
 *
 * Description:
 * NormalAccount 객체를 구성하기 위한 멤버 함수 정의 파일
 **/
#include "NormalAccount.h"

NormalAccount::NormalAccount() :Account(0, 0, NULL) {
	this->accID = 0;
	this->balance = 0;
	this->cusName = 0;
	this->addInterestRate = 0.01;
	this->typeCheck = "NormalAccount";
};

NormalAccount::NormalAccount(int ID, int money, char* name) :Account(ID, money, name) {
	this->addInterestRate = 0.01;
	this->typeCheck = "NormalAccount"; //추가
	this->interestRateCheck = addInterestRate; //추가
}

NormalAccount::NormalAccount(const NormalAccount& ref)
	: Account(ref)
{
	this->cusName = new char[strlen(ref.cusName) + 1];
	strcpy_s(this->cusName, (strlen(ref.cusName) + 1), ref.cusName);
}

/**
* Function Name: Deposit
* Description: 입금
* @param: int money
* @return: void
*
* Author: 남유정, 박주용, 이승민, 정민규
**/
void NormalAccount::Deposit(int money) {
	Account::Deposit(money);
}