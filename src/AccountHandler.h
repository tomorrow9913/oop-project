/****************************************************************
 * File Name: AccountHandler.h
 *
 * Description:
 * 컨트롤(Control) 클래스
 *
 * Extern File
 * Name         Description
 * ============ ================================================
 * Account.h    계좌 정보 클래스
 *
 * Global Variables
 * Name         Type        Description
 * ============ =========== =====================================
 * NAME_LEN     const int   이름의 최대 길이
 ****************************************************************/
#pragma once
#include "Account.h"

const int NAME_LEN = 20;

class AccountHandler
{
private:
	Account* accArr[100];       // 계좌 배열
	int accNum;                 // 계좌의 개수

public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	~AccountHandler();
};