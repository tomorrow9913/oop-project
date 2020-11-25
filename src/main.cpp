/**
 * File Name:  main.cpp
 *
 * Description: ���� �ùķ��̼� ���� ���α׷�
 **/
#include <iostream>
#include "Account.h"
#include "AccountHandler.h"

using namespace std;

enum SelectMenu{ MAKE = 1, DEPOSIT, WITHDRAW, TRANSFER,INQUIRE, EXIT };

 /** 
 ��Ʈ�� Ŭ���� AccountHandler �߽����� ����� main �Լ�
 **/

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
		case TRANSFER:
			manager.TransferMoney();
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