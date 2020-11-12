/****************************************************************
 * File Name:  main.cpp
 *
 * Description: 은행 시뮬레이션 메인 프로그램
 *
 * Extern File
 * Name         Description
 * ============ ================================================
 * Account.h	계좌 관련 클래스 정의
 *
 * Extern Variables
 * Name         Type        Description
 * ============ =========== ====================================
 *
 * Global Variables
 * Name         Type        Description
 * ============ =========== ====================================
 * NAME_LEN		const int	이름의 길이를 설정함
 *				enum
 ****************************************************************/
#include <iostream>
#include "Account.h"
#include "AccountHandler.h"

using namespace std;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

/*
 * 컨트롤 클래스 AccountHandler 중심으로 변경된 main 함수
 */

int main(void)
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}

	return 0;
}