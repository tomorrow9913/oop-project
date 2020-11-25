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
	queue<DealList*> dealList; // 최근 거래 내역
public:
	Account();
	Account(const Account& ref);
	Account(int ID, int money, char* name);
	int GetAccID() const;
	virtual void Deposit(int money); 
	int Withdraw(int money);
	void ShowAccInfo() const;
	void PrintDealList() const;
	void AddDealList(int balance, int money, int year, int month, int date, string addressID, string message);
	~Account();
};

// 통장 유형2 :  추가 이자 있는 거 (high) - A등급 (기본 이자 + A 이자), B등급 (기본 이자 + B 이자), C등급 (기본 이자 + C이자)
class NormalAccount : public Account {
private:
	double addInterestRate;
public:
	NormalAccount();
	NormalAccount(const NormalAccount& ref);
	NormalAccount(int ID, int money, char* name);
	void Deposit(int money);
};


// 통장 유형3 : 등급별 이체 수수료 차등 (ex) A - 없음, B - 50%........)
class HighCreditAccount : public Account {
private:
	enum Grade { GRADE_A = 1, GRADE_B, GRADE_C, GRADE_D }; //등급번호  
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