/**
 * File Name: AccountHandler.h
 *
 * Description:
 * ��Ʈ��(Control) Ŭ����
 **/
#pragma once
#include "Account.h"

const int NAME_LEN = 20;
class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void TransferMoney(void);
	void WithdrawMoney(void);
	void AccountSuspension(void);
	void ShowAllAccInfo(void) const;
	void ShowTransactHistory(void) const;
	~AccountHandler();
};