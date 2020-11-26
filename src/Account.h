/**
 * File Name: Account.h
 *
 * Description:
 * 계정 정보를 저장하기 위한 클래스 정의
 **/
#pragma once
#include <queue>
#include "DealList.h"

using namespace std;

#define DEAL_LIST_MAX 50
enum GradeSetMoney { SET_A = 1000000000, SET_B = 100000000, SET_C = 10000000 }; 
//A= 10억, B= 1억, C=1천

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
	queue<DealList*> dealList;// 최근 거래 내역
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