/**
 * File Name: Account.h
 *
 * Description:
 * 계정 정보를 저장하기 위한 클래스 정의
 **/
#pragma once

#define C_RATE 0.03
#define B_RATE 0.05
#define A_RATE 0.07

enum Grade { GRADE_A = 1, GRADE_B, GRADE_C, GRADE_D };
enum GradeSetMoney { SET_A = 1000000000, SET_B = 100000000, SET_C = 10000000 };

class Account
{
protected:
	int accID;
	int balance;
	char* cusName;
	double interestRate;
public:
	Account();
	Account(const Account& ref);
	Account(int ID, int money, char* name);
	int GetAccID() const;
	virtual void Deposit(int money); 
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

// 통장 유형2 :  추가 이자 있는 거 (high) - A등급 (기본 이자 + A 이자), B등급 (기본 이자 + B 이자), C등급 (기본 이자 + C이자)
class NormalAccount : Account {
private:
	double addInterestRate;
public:
	NormalAccount();
	NormalAccount(const NormalAccount& ref);
	NormalAccount(int ID, int money, char* name, int grade, double addInterestRate);
	void Deposit(int money);
	void SetGrade(int grade);
	int GetGrade();
};

// 통장 유형3 : 등급별 이체 수수료 차등 (ex) A - 없음, B - 50%........)
class HighCreditAccount : Account {
private:
	int grade;
	double addInterestRate;
public:
	HighCreditAccount();
	HighCreditAccount(const HighCreditAccount& ref);
	HighCreditAccount(int ID, int money, char* name, int grade, double addInterestRate);
	void Deposit(int money);
	void SetGrade(int grade);
	int GetGrade();
};

#define ERR_LACK -1