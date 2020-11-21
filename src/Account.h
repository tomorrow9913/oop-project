/**
 * File Name: Account.h
 *
 * Description:
 * ���� ������ �����ϱ� ���� Ŭ���� ����
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

// ���� ����2 :  �߰� ���� �ִ� �� (high) - A��� (�⺻ ���� + A ����), B��� (�⺻ ���� + B ����), C��� (�⺻ ���� + C����)
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

// ���� ����3 : ��޺� ��ü ������ ���� (ex) A - ����, B - 50%........)
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