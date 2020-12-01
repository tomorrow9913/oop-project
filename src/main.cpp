/**
 * File Name:  main.cpp
 *
 * Description: ���� �ùķ��̼� ���� ���α׷�
 **/
#include <iostream>
#include "Account.h"
#include "AccountHandler.h"
#include "DesignSet.h"

using namespace std;	

enum SelectMenu{ MAKE = 1, DEPOSIT, WITHDRAW, TRANSFER,INQUIRE, HISTORY,SUSPENSION, EXIT };

int main(void)
{
	AccountHandler manager;
	int choice;

	system("mode con cols=105 lines=50");
	
	while (1)
	{
		manager.ShowMenu();
		cout << "\t\t\t\t\t\t- ����: "; changeColor(lightGreen);
		cin >> choice;  changeColor(darkWhite);
		cout << endl;

		switch (choice)
		{
		case MAKE:
			system("cls");
			manager.MakeAccount();
			break;
		case DEPOSIT:
			system("cls");
			manager.DepositMoney();
			break;
		case WITHDRAW:
			system("cls");
			manager.WithdrawMoney();
			break;
		case TRANSFER:
			system("cls");
			manager.TransferMoney();
			break;
		case INQUIRE:
			system("cls");
			manager.ShowAllAccInfo();
			system("cls");
			break;
		case HISTORY:
			system("cls");
			manager.ShowTransactHistory();
			system("cls");
			break;
		case SUSPENSION:
			system("cls");
			manager.AccountSuspension();
			break;
		case EXIT:
			return 0;
		default:
			system("cls");
			changeColor(red);
			cout << "���";
			changeColor(darkWhite);
			cout << " : �ùٸ� ���� ��ȣ�� �������ּ���.";
		}
	}

	return 0;
}