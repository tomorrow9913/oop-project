/**
 * File Name: Account.h
 *
 * Description:
 * ���� ������ �����ϱ� ���� Ŭ���� ����
 **/
#pragma once
#include <queue>
#include "DealList.h"

using namespace std;

#define DEAL_LIST_MAX 50
enum GradeSetMoney { SET_A = 1000000000, SET_B = 100000000, SET_C = 10000000 }; 
//A= 10��, B= 1��, C=1õ

class Account
{
protected:
	int accID;
	int balance;
	char* cusName;
	double interestRate; 
	double interestRateCheck;
	const char* typeCheck;	
	const char* checkGrade;	
	queue<DealList*> dealList;// �ֱ� �ŷ� ����
public:
	Account();
	Account(const Account& ref);
	Account(int ID, int money, char* name);
	int GetAccID() const;
	virtual void Deposit(int money); 
	virtual void NointerestRateDeposit(int money);
	int getBalance();
	int Withdraw(int money);
	int Transfer(int money, Account& accAccount);
	void ShowAccInfo() const;
	void PrintDealList() const;
	void AddDealList(int balance, int money, string addressID, string message);
	~Account();
};

#define ERR_LACK -1