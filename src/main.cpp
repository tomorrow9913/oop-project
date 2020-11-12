/****************************************************************
 * File Name:  main.cpp
 *
 * Description: ���� �ùķ��̼� ���� ���α׷�
 *
 * Extern File
 * Name         Description
 * ============ ================================================
 * Account.h	���� ���� Ŭ���� ����
 *
 * Extern Variables
 * Name         Type        Description
 * ============ =========== ====================================
 *
 * Global Variables
 * Name         Type        Description
 * ============ =========== ====================================
 * NAME_LEN		const int	�̸��� ���̸� ������
 *				enum
 ****************************************************************/
#include <iostream>
#include "Account.h"
#include "AccountHandler.h"

using namespace std;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

/*
 * ��Ʈ�� Ŭ���� AccountHandler �߽����� ����� main �Լ�
 */

int main(void)
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();
		cout << "����: ";
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