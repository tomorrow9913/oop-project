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
	int wrongCnt;
	bool activation;
	char* cusName;
	double interestRate;
	string pass;
	queue<DealList*> dealList;// �ֱ� �ŷ� ����
public:
	Account();
	Account(const Account& ref);
	Account(int ID, int money, char* name);
	int GetAccID() const;
	virtual void Deposit(int money); 
	virtual void NointerestRateDeposit(int money);
	int getBalance();
	virtual int Withdraw(int money);
	virtual int Transfer(int money, Account& accAccount);
	virtual void ShowAccInfo() const;
	void PrintDealList() const;
	void AddDealList(int balance, int money, string addressID, string message);
	bool GetStatus();
	bool ToggleStatus();
	string GetPW();
	void SetPW(string PW);
	string InputPw();
	int ChageWorngPW(bool mode);
	~Account();
};

#define ERR_LACK -1