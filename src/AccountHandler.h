/****************************************************************
 * File Name: AccountHandler.h
 *
 * Description:
 * ��Ʈ��(Control) Ŭ����
 *
 * Extern File
 * Name         Description
 * ============ ================================================
 * Account.h    ���� ���� Ŭ����
 *
 * Global Variables
 * Name         Type        Description
 * ============ =========== =====================================
 * NAME_LEN     const int   �̸��� �ִ� ����
 ****************************************************************/
#pragma once
#include "Account.h"

const int NAME_LEN = 20;

class AccountHandler
{
private:
	Account* accArr[100];       // ���� �迭
	int accNum;                 // ������ ����

public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	~AccountHandler();
};