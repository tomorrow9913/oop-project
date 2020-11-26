/** 
 * File Name: Account.cpp
 *
 * Description:
 * Account ��ü�� �����ϱ� ���� ��� �Լ� ���� ����
 **/

#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include "Account.h"
#include "DealList.h"

using namespace std;

Account::Account() {
	this->accID = 0;
	this->balance = 0;
	this->cusName = 0;
	this->interestRate = 0.01;
	this->activation = true;
}

Account::Account(int ID, int money, char* name) 
	: accID(ID), balance(money), interestRate(0.01)
{
	this->activation = true;
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
	cout << "Ȱ��ȭ ����:" << activation << endl;
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
	cout << "=============================" << endl;
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
		cout << "�޽����� �Է��Ͻÿ�." << endl;
		cin >> msg;

		balance -= money;
		this->AddDealList(this->getBalance(), -money, this->cusName, msg);
		balance -= fee;
		this->AddDealList(this->getBalance(), -fee, "�۱ݼ�����", "-");
		
		accAccount.NointerestRateDeposit(money);
		accAccount.AddDealList(accAccount.getBalance(), money, accAccount.cusName, msg);

		return money;
	}
	else {
		cout << "�ܾ��� �����մϴ�." << endl;
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