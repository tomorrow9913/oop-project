/** 
 * File Name: Account.cpp
 *
 * Description:
 * Account ��ü�� �����ϱ� ���� ��� �Լ� ���� ����
 **/

#include <iostream>
#include <cstring>
#include <queue>
#include <time.h>
#include "Account.h"
#include "DealList.h"

using namespace std;

Account::Account() {
	this->accID = 0;
	this->balance = 0;
	this->cusName = 0;
	this->interestRate = 0.01;
}

Account::Account(int ID, int money, char* name) 
	: accID(ID), balance(money), interestRate(0.01)
{
	cusName = new char[strlen(name) + 1];
	strcpy_s(cusName, (strlen(name) + 1), name);

	string msg;
	cout << "입금 메시지 입력";
	cin >> msg;
	AddDealList(balance, money, "계좌 개설", msg);
}

Account::Account(const Account& ref)
	: accID(ref.accID), balance(ref.balance), interestRate(ref.interestRate)
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
	int interest = (int)(money * interestRate);	// 기본 이자
	balance += interest;

	AddDealList(balance, interest, "예금 이자", "-");

	string msg;
	cout << "입금 메시지 입력 : ";
	cin >> msg;
	balance += money;
	AddDealList(balance, money, "입금", msg);
}
/**
* Function Name: NointerestRateDeposit
* Description: ��ü �� �޴� ���� �ܾ� ����.
* @param: int
* @return: void
*
* Author:���ֿ�
**/
void Account::NointerestRateDeposit(int money){
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
	string msg;
	cout << "출금 메시지 입력 : ";
	cin >> msg;
	AddDealList(balance, money, "출금", msg);

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

/**
* Function Name: PrintDealList
* Description: �ֱ� �ŷ� ���� ���.
* @param: void
* @return: void
*
* Author: Jeong MinGyu
**/
void Account::PrintDealList() const {
	queue<DealList*> copy = dealList;

	while (copy.size())
	{
		cout << *(copy.front());
		copy.pop();
	}
	cout << "=============================" << endl;
}

/**
* Function Name: AddDealList
* Description: 최근 거래 내역 추가.
* @param: int balance, int money, int year, int month, int date, string addressID, string message
* @return: void
*ㅏ
* Author: Jeong MinGyu
**/
void Account::AddDealList(int balance, int money, string addressID, string message) {
	if (dealList.size() == DEAL_LIST_MAX) {
		delete dealList.front();
		dealList.pop();
	}

	time_t timer = time(NULL);
	struct tm tm_info;
	localtime_s(&tm_info ,&timer);

	dealList.push(new DealList(balance, money, tm_info.tm_year + 1900, tm_info.tm_mon, tm_info.tm_mday, addressID, message));
}

Account::~Account()
{
	delete[]cusName;
}

NormalAccount::NormalAccount() :Account(0, 0, 0) {
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

double HighCreditAccount::interestRate[4] = { 0.07, 0.05, 0.03, 0 };

HighCreditAccount::HighCreditAccount() :Account(0, 0, 0) {
	this->grade = 0;
	this->addInterestRate = 0;
};

HighCreditAccount::HighCreditAccount(int ID, int money, char* name) : Account(ID, money, name) {
	if (this->balance >= SET_A) { this->grade = 1; this->addInterestRate = interestRate[this->grade - 1]; }
	else if (this->balance >= SET_B) { this->grade = 2; this->addInterestRate = interestRate[this->grade - 1]; }
	else if (this->balance >= SET_C) { this->grade = 3; this->addInterestRate = interestRate[this->grade - 1]; }
	else { this->grade = 4; this->addInterestRate = interestRate[this->grade - 1]; }
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
void NormalAccount::Deposit(int money) {
	Account::Deposit(money);
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

	balance += (int)(money * addInterestRate); //등급별 이자
	AddDealList(balance, addInterestRate, "등급 이자", "-");
}

/**
* Function Name: Transfer
* Description: ��ü
* @param: int money, Account accAccount
* @return: int
*
* Author: ������, ���ֿ�
**/
int Account::Transfer(int money, Account& accAccount) {//�޴� ����
	if(balance > money){
		balance-=money;
		accAccount.NointerestRateDeposit(money);
		return money;
	}
	else
		return ERR_LACK;
}