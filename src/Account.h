/**
 * File Name: Account.h
 *
 * Description:
 * ���� ������ �����ϱ� ���� Ŭ���� ����
 **/
#pragma once

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
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

// ���� ����2 :  �߰� ���� �ִ� �� (high) - A��� (�⺻ ���� + A ����), B��� (�⺻ ���� + B ����), C��� (�⺻ ���� + C����)
class NormalAccount : Account {
private:
	int grade;
public:
	NormalAccount();
	NormalAccount(const NormalAccount& ref);
	NormalAccount(int ID, int money, char* name, int grade);
	void SetGrade(int grade);
	int GetGrade();
};

// ���� ����3 : ��޺� ��ü ������ ���� (ex) A - ����, B - 50%........)
class HighCreditAccount : Account {
private:
	int grade;
	double transferFee[3];
public:
	HighCreditAccount();
	HighCreditAccount(const HighCreditAccount& ref);
	HighCreditAccount(int ID, int money, char* name, int grade);
	void SetGrade(int grade);
	int GetGrade();
	void SetTransferFee(int grade, double transferFee);
	double GetTransferFee(int grade);
};