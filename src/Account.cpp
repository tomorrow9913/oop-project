/** 
 * File Name: Account.cpp
 *
 * Description:
 * Account ��ü�� �����ϱ� ���� ��� �Լ� ���� ����
 **/

#include <iostream>
#include <cstring>
#include <queue>
#include <string>
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
	AddDealList(money, money, "���°���", "-");
	cusName = new char[strlen(name) + 1];
	strcpy_s(cusName, (strlen(name) + 1), name);
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
	int interest = (int)(money * interestRate);	// �⺻ ����
	balance += interest;
	if(interest) AddDealList(balance, interest, "��������", "-");
	
	string msg;
	cout << "�Ա� �޽��� : ";
	cin >> msg;
	
	balance += money;
	if (money) AddDealList(balance, money, "���� �Ա�", msg);
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

	string msg;
	cout << "��� �޽��� : ";
	cin >> msg;

	balance -= money;
	if (money) AddDealList(balance, -money, "���� ���", msg);
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
	cout << "���� ����: " << typeCheck << endl;
	if (typeCheck == "HighCreditAccount") {
		cout << "���: " << checkGrade << endl;
	}
	cout << "����:" << interestRateCheck << endl;
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
* Description: �ֱ� �ŷ� ���� �߰�.
* @param: int balance, int money, int year, int month, int date, string addressID, string message
* @return: void
*��
* Author: Jeong MinGyu
**/
void Account::AddDealList(int balance, int money, string addressID, string message) {
	if (dealList.size() == DEAL_LIST_MAX) {
		delete dealList.front();
		dealList.pop();
	}
	
	dealList.push(new DealList(balance, money, addressID, message));
}

Account::~Account()
{
	delete[]cusName;
}

NormalAccount::NormalAccount():Account(0, 0, NULL) {
	this->accID = 0;
	this->balance = 0;
	this->cusName = 0;
	this->addInterestRate = 0.01;
	this->typeCheck = "NormalAccount";
};

NormalAccount::NormalAccount(int ID, int money, char* name) :Account(ID, money, name) {
	this->addInterestRate = 0.01;
	this->typeCheck = "NormalAccount"; //�߰�
	this->interestRateCheck = addInterestRate; //�߰�
}

NormalAccount::NormalAccount(const NormalAccount& ref)
	: Account(ref)
{
	this->cusName = new char[strlen(ref.cusName) + 1];
	strcpy_s(this->cusName, (strlen(ref.cusName) + 1), ref.cusName);
}

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
	if (this->balance >= SET_A)	{ this->grade = 1; this->addInterestRate = interestRate[this->grade - 1]; }
	else if (this->balance >= SET_B) { this->grade = 2; this->addInterestRate = interestRate[this->grade - 1]; }
	else if (this->balance >= SET_C) {this->grade = 3; this->addInterestRate = interestRate[this->grade - 1]; }
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
		addInterestRate = interestRate[grade-1];
	}
	else if (balance >= SET_B && balance < SET_A) {
		grade = GRADE_B;
		addInterestRate = interestRate[grade-1];
	}
	else if (balance >= SET_A) {
		grade = GRADE_A;
		addInterestRate = interestRate[grade-1];
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
void NormalAccount::Deposit(int money){
	Account::Deposit(money);
}

/**
* Function Name: Deposit
* Description: �Ա�
* @param: int money
* @return: void
*
* Author: ������, ���ֿ�, �̽¹�, ���α�
**/
void HighCreditAccount::Deposit(int money){
	//��� Ȯ��
	SetGrade();
	Account::Deposit(money); //�⺻ ����
	int interest = (int)(money * addInterestRate);
	balance += interest; //��޺� ����
	if(interest) AddDealList(balance, interest, "�������", "-");
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