/**
 * File Name: NormalAccount.h
 *
 * Description:
 * NormalAccount�� Ŭ���� ���� ����
 **/
#pragma once
#include "Account.h"

// ���� ����2 :  �߰� ���� �ִ� �� (high) - A��� (�⺻ ���� + A ����), B��� (�⺻ ���� + B ����), C��� (�⺻ ���� + C����)
class NormalAccount : public Account {
private:
	double addInterestRate;
public:
	NormalAccount();
	NormalAccount(const NormalAccount& ref);
	NormalAccount(int ID, int money, char* name);
	void Deposit(int money);
	void ShowAccInfo() const;
};

