/** 
 * File Name: Account.cpp
 *
 * Description:
 * Account ��ü�� �����ϱ� ���� ��� �Լ� ���� ����
 **/

#include <iostream>
#include <conio.h>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include "Account.h"
#include "HighCreditAccount.h"
#include "DealList.h"
#include "DesignSet.h"

using namespace std;

Account::Account() {
	this->accID = 0;
	this->wrongCnt = 0;
	this->balance = 0;
	this->cusName = 0;
	this->interestRate = 0.01;
	this->activation = true;
	this->pass = "1111";
}

Account::Account(int ID, int money, char* name) 
	: accID(ID), balance(money), interestRate(0.01)
{
	this->activation = true;
	this->wrongCnt = 0;
	this->pass = InputPw();
	AddDealList(money, money, "���°���", "-");
	cusName = new char[strlen(name) + 1];

	strcpy_s(cusName, (strlen(name) + 1), name);

	system("cls");
	changeColor(lightGreen); cout << "�˸�"; changeColor(darkWhite);
	cout << " : ���� ���� �Ϸ�";
}

Account::Account(const Account& ref)
	: accID(ref.accID), balance(ref.balance), interestRate(ref.interestRate)
{
	pass = ref.pass;
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
	cout << "\t\t\t\t\t�Ա� �޽��� : "; changeColor(lightGreen);
	cin >> msg; changeColor(darkWhite);

	system("cls");
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
	cout << "\t\t\t\t\t��� �޽��� : ";
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
	cout << " " << left << setw(15)
		<< accID << left << setw(15)
		<< cusName << left << setw(15) 
		<< balance << left << setw(15);
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
	stack<DealList*> sortRecent;
	
	while (copy.size())
	{
		sortRecent.push(copy.front());
		copy.pop();
	}

	while(sortRecent.size()){
		cout << *(sortRecent.top());
		sortRecent.pop();
	}
}

/**
* Function Name: AddDealList
* Description: �ֱ� �ŷ� ���� �߰�.
* @param: int balance, int money, int year, int month, int date, string addressID, string message
* @return: void
*
* Author: Jeong MinGyu
**/
void Account::AddDealList(int balance, int money, string name, string message) {
	if (dealList.size() == DEAL_LIST_MAX) {
		delete dealList.front();
		dealList.pop();
	}
	
	dealList.push(new DealList(balance, money, name, message));
}

Account::~Account()
{
	delete[]cusName;
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
	int fee;
	string msg;

	if (this->balance >= SET_A) fee = 100;
	else if (this->balance < SET_A && this->balance >= SET_B) fee = 300;
	else if (this->balance < SET_B && this->balance > SET_C) fee = 500;
	else fee = 700;

	if (this->balance >= fee + money) {
		cout << "\t\t\t\t\t�۱� �޽��� : "; changeColor(lightGreen);
		cin >> msg; changeColor(darkWhite);

		balance -= money;
		this->AddDealList(this->getBalance(), -money, this->cusName, msg);
		balance -= fee;
		this->AddDealList(this->getBalance(), -fee, "�۱ݼ�����", "-");
		
		accAccount.NointerestRateDeposit(money);
		accAccount.AddDealList(accAccount.getBalance(), money, accAccount.cusName, msg);
		return money;
	}
	else {
		system("cls");
		changeColor(lightRed); cout << "���"; changeColor(darkWhite);
		cout << " : �ܾ��� �����մϴ�.";
		return ERR_LACK;
	}	
}

/**
* Function Name: getbalance
* Description: �ܾ� ��ȸ
* @param: balance
* @return: int
*
* Author: ������, ���ֿ�
**/
int Account::getBalance(){
	return this->balance;
}

/**
* Function Name: GetStatus
* Description: ���� Ȱ��ȭ ���� Ȯ��
* @param: void
* @return: bool
*
* Author: ������, ���α�
**/
bool Account::GetStatus() {
	return this->activation;
}

/**
* Function Name: ToggleStatus
* Description: ���� Ȱ��ȭ
* @param: void
* @return: bool
*
* Author: ������, ���α�
**/
bool Account::ToggleStatus() {
	return this->activation = this->activation ? false : true;
}

/**
* Function Name: GetPW
* Description: ��й�ȣ ��ȸ
* @param: void
* @return: string
*
* Author: Jeong MinGyu
**/
string Account::GetPW() {
	return this->pass;
}

/**
* Function Name: SetPW
* Description: ��й�ȣ ����
* @param: string;
* @return: void
*
* Author: Jeong MinGyu
**/
void Account::SetPW(string PW) {
	this->pass = PW;
}

/**
* Function Name: InputPw
* Description: ��й�ȣ �Է�
* @param: void
* @return: string
*
* Author: Jeong MinGyu
**/
string Account::InputPw() {
	fflush(stdin);
	string pass;

	cout << "\t\t\t\t\t��й�ȣ �Է�: ____\b\b\b\b";
	for (int i = 0; i < 4; i++)
	{
		changeColor(lightGreen);
		pass += _getch();
		cout << "*";
		changeColor(darkWhite);
	}
	fflush(stdin);
	cout << endl;
	return pass;
}

/**
* Function Name: addWorngPW
* Description: ��й�ȣ Ʋ�� Ƚ�� ���� && Ƚ�� �ʰ��� ���� ����
* @param: bool(false - �ʱ�ȭ, true - ����)
* @return: int(��й�ȣ Ʋ�� Ƚ��)
*
* Author: Jeong MinGyu
**/
int Account::ChageWorngPW(bool mode) {
	if (mode) {
		++(this->wrongCnt);
		//TODO �Ʒ� 3ȸ Ƚ�� �����صа� ��ȣ ����� ���ּ���.
		if (this->wrongCnt >= 3 && this->GetStatus()) {
			this->ToggleStatus();
		}
		return this->wrongCnt;
	}
	return this->wrongCnt = 0;
}