/**
 * File Name: HighCreditAccount.h
 *
 * Description:
 * HighCreditAccount ������ �����ϱ� ���� Ŭ���� ����
 **/
#pragma once
#include "Account.h"

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
	void ShowAccInfo() const;
	int Transfer(int money, Account& accAccount);
	int Withdraw(int money);
	void NointerestRateDeposit(int money);
};
