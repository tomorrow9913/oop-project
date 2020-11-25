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
	queue<DealList*> dealList; // �ֱ� �ŷ� ����
public:
	Account();
	Account(const Account& ref);
	Account(int ID, int money, char* name);
	int GetAccID() const;
	virtual void Deposit(int money); 
	virtual void NointerestRateDeposit(int money);
	int Withdraw(int money);
	int Transfer(int money, Account& accAccount);
	void ShowAccInfo() const;
	void PrintDealList() const;
	void AddDealList(int balance, int money, string addressID, string message);
	~Account();
};

// ���� ����2 :  �߰� ���� �ִ� �� (high) - A��� (�⺻ ���� + A ����), B��� (�⺻ ���� + B ����), C��� (�⺻ ���� + C����)
class NormalAccount : public Account {
private:
	double addInterestRate;
public:
	NormalAccount();
	NormalAccount(const NormalAccount& ref);
	NormalAccount(int ID, int money, char* name);
	void Deposit(int money);
};


// ���� ����3 : ��޺� ��ü ������ ���� (ex) A - ����, B - 50%........)
class HighCreditAccount : public Account {
private:
	enum Grade { GRADE_A = 1, GRADE_B, GRADE_C, GRADE_D }; //��޹�ȣ  
	int grade;
	double addInterestRate;
	static double interestRate[4];
	void SetGrade();
	
public:
	HighCreditAccount();
	HighCreditAccount(int ID, int money, char* name);
	void Deposit(int money); 
	int GetGrade();
};

#define ERR_LACK -1