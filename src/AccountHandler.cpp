/**
 * File Name: AccountHandler.cpp
 *
 * Description:
 * AccountHandler Ŭ���� ���� ����
 **/

#include <iostream>
#include "AccountHandler.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"
#include "DesignSet.h"
#include <iomanip>

using namespace std;
/**
* Function Name: ShowMenu
* Description: ���� �޴��� ����Ѵ�.
* @param: void
* @return: void
*
* Author: - Ȳ����
**/
void AccountHandler::ShowMenu(void) const
{
	printLogo();
	cout << endl;
	cout << "\t\t    �ݰ����ϴ�. ������ �ּ����� �̵��� ���� ���� Min Bank�Դϴ�." << endl;
	cout << "\t\t\t\t ������ "; changeColor(yellow);  cout << "������ ��ȣ"; changeColor(darkWhite); cout << "�� �Է����ּ���.\n" << endl;
	cout << "\t+-------------------+  +------------------+  +------------------+  +------------------+  " << endl;
	cout << "\t|   1. ���°���     |  |     2. �� ��     |  |     3. �� ��     |  |     4. �� ��     |  " << endl;
	cout << "\t+-------------------+  +------------------+  +------------------+  +------------------+  " << endl;
	cout << endl;
	cout << "\t+-------------------+  +------------------+  +------------------+  +------------------+" << endl;
	cout << "\t| 5. ��ü ���� ��� |  |   6. ���� �̷�   |  |   7. ���� ����   |  |     8. �� ��     |" << endl;
	cout << "\t+-------------------+  +------------------+  +------------------+  +------------------+" << endl;
	cout << endl;
}

/**
* Function Name: MakeAccount
* Description: ���� ����.
* @param: void
* @return: void
*
* Author: - ������, ���ֿ�
**/
void AccountHandler::MakeAccount(void)
{
	int id;
	int type;
	char name[NAME_LEN];
	int balance;

	string content = "���°���";
	printContent(content);
	printAccontMenu(0);
	cout << "\n\t\t\t\t\t���� ���� ���� : "; cin >> type; cout << endl;
	system("cls");
rewrite:
	printContent(content);
	printAccontMenu(type);

	changeColor(darkWhite);
	cout << "\n";
	cout << "\t\t\t\t\t���� ���� ���� : "; changeColor(lightGreen); cout << type << endl; changeColor(darkWhite);
	cout << "\t\t\t\t\t����ID: "; changeColor(lightGreen); cin >> id;  changeColor(darkWhite);
	cout << "\t\t\t\t\t��  ��: "; changeColor(lightGreen); cin >> name; changeColor(darkWhite);
	cout << "\t\t\t\t\t�Աݾ�: "; changeColor(lightGreen); cin >> balance; changeColor(darkWhite);
	cout << endl;
	
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id) {
			system("cls"); changeColor(lightRed);
			cout << "���"; changeColor(darkWhite);
			cout << " : ���� ����ID�� �̹� �����մϴ�.";
			goto rewrite;
		}
	}

	if (type == 1) {
		accArr[accNum++] = new NormalAccount(id, balance, name);
	}
	else if (type == 2) {
		accArr[accNum++] = new HighCreditAccount(id, balance, name);
	}
}

/**
* Function Name: DepositMoney
* Description: �Ա�.
* @param: void
* @return: void
*
* Author: -
**/
void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	string content = "�� ��";
	printContent(content);
	cout << "\t\t\t\t\t����ID: "; changeColor(lightGreen); cin >> id; changeColor(darkWhite);
	cout << "\t\t\t\t\t�Աݾ�: "; changeColor(lightGreen); cin >> money; changeColor(darkWhite);

	for (int i = 0; i < accNum; i++)
	{
		if(!accArr[i]->GetStatus()){
			system("cls");
			changeColor(lightRed); cout << "���"; changeColor(darkWhite);
			cout << " : ������ �����Դϴ�.";
			return;
		}
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			system("cls");
			changeColor(lightGreen); cout << "�˸�"; changeColor(darkWhite);
			cout << " : �ԱݿϷ�";
			return;
		}
	}
	system("cls");
	changeColor(lightRed); cout << "���"; changeColor(darkWhite);
	cout << " : ��ȿ���� ���� ID �Դϴ�.";
}

/**
* Function Name: WithdrawMoney
* Description: ���.
* @param: void
* @return: void
*
* Author: -
**/
void AccountHandler::WithdrawMoney(void)
{ 
	int money;
	int id;

	string content = "�� ��";
	printContent(content);
	cout << "\t\t\t\t\t����ID: "; changeColor(lightGreen); cin >> id; changeColor(darkWhite);
	cout << "\t\t\t\t\t��ݾ�: "; changeColor(lightGreen); cin >> money; changeColor(darkWhite);

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if(!accArr[i]->GetStatus()){
				system("cls");
				changeColor(lightRed); cout << "���"; changeColor(darkWhite);
				cout << " : ������ �����Դϴ�.";
				return;
			}
			//TODO ��� Ʋ���� Ƚ�� �����ϴ� �Լ� ��ȣ ����� �ٲ��ּ���
			if (accArr[i]->GetPW() != accArr[i]->InputPw()) {
				system("cls");
				changeColor(lightRed); cout << "���"; changeColor(darkWhite);

				cout << " : ��й�ȣ�� �ٸ��ϴ�.";
				cout << "("; changeColor(lightRed);
				cout << accArr[i]->ChageWorngPW(1); changeColor(darkWhite);
				cout << "ȸ Ʋ��)";
				return;
			}
			else accArr[i]->ChageWorngPW(0);
			if (accArr[i]->Withdraw(money) < 0)
			{
				system("cls");
				changeColor(lightRed); cout << "���"; changeColor(darkWhite);
				cout << " : �ܾ��� �����մϴ�." << endl << endl;
				return;
			}
			system("cls");
			changeColor(lightGreen); cout << "�˸�"; changeColor(darkWhite);
			cout << " : ��ݿϷ�";
			return;
		}
	}
	system("cls");
	changeColor(lightRed); cout << "���"; changeColor(darkWhite);
	cout << " : ��ȿ���� ���� ID �Դϴ�.";
}

/**
* Function Name:TransferMoney
* Description: �۱�
* @param: void
* @return: void
*
* Author: - ������, ���ֿ�
**/
void AccountHandler::TransferMoney(void) {
	int money;
	int id, accid;

	string content = "�� ��";
	printContent(content);
	cout << "\t\t\t\t\t�� ����ID: "; changeColor(lightGreen); cin >> id; changeColor(darkWhite);
	
	do {
		cout << "\t\t\t\t\t���� ����ID: "; changeColor(lightGreen); cin >> accid;  changeColor(darkWhite);
		if (id != accid) break; {
			changeColor(lightRed); cout << "\t\t\t\t���"; changeColor(darkWhite);
			cout << " : ����ID�� �۱��� �� �����ϴ�.\n" << endl;
		}
	} while (id == accid);

	cout << "\t\t\t\t\t�۱ݾ�: "; changeColor(lightGreen); cin >> money; changeColor(darkWhite);
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			//TODO ��� Ʋ���� Ƚ�� �����ϴ� �Լ� ��ȣ ����� �ٲ��ּ���
			if (accArr[i]->GetPW() != accArr[i]->InputPw()) {
				system("cls");
				changeColor(lightRed); cout << "���"; changeColor(darkWhite);

				cout << " : ��й�ȣ�� �ٸ��ϴ�.";
				cout << "("; changeColor(lightRed);
				cout << accArr[i]->ChageWorngPW(1); changeColor(darkWhite);
				cout << "ȸ Ʋ��)";
				return;
			}
			else accArr[i]->ChageWorngPW(0);
			if(!accArr[i]->GetStatus()){
				system("cls");
				changeColor(lightRed); cout << "���"; changeColor(darkWhite);
				cout << " : ������ �����Դϴ�.";
				return;
			}
			for (int j = 0; j < accNum; j++)
			{
				if (accArr[j]->GetAccID() == accid)
				{
					if(!accArr[j]->GetStatus()){
						system("cls");
						changeColor(lightRed); cout << "���"; changeColor(darkWhite);
						cout << " : ��ü ��밡 ������ �����Դϴ�.";
						return;
					}
							
					if (accArr[i]->Transfer(money, *accArr[j]) > 0) { 
						system("cls");
						changeColor(lightGreen); cout << "�˸�"; changeColor(darkWhite);
						cout << " : �۱ݿϷ�";
						return;
					}
					system("cls");
					changeColor(lightRed); cout << "���"; changeColor(darkWhite);
					cout << " : �ܾ��� �����մϴ�.";
					return;
				}
			}
			system("cls");
			changeColor(lightRed); cout << "���"; changeColor(darkWhite);
			cout << " : ��ȿ���� ���� ID �Դϴ�.";
			return;
		}
	}
	system("cls");
	changeColor(lightRed); cout << "���"; changeColor(darkWhite);
	cout << " : ��ȿ���� ���� ID �Դϴ�.";
}

/**
* Function Name: ShowAllAccInfo
* Description: ��ü ���� ���.
* @param: void
* @return: void
*
* Author: -
**/
void AccountHandler::ShowAllAccInfo(void) const
{
	printContent("��ü ����");
	cout << " " << left << setw(15)
		<< "����ID" << left << setw(15)
		<< "��  ��" << left << setw(15)
		<< "��  ��" << left << setw(15)
		<< "���� ����" << left << setw(15)
		<< "��  ��" << left << setw(15)
		<< "��  ��" << left << setw(15)
		<< "���� Ȱ��" << left << setw(15);
	cout << endl;
	cout << " ---------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
		//accArr[i]->PrintDealList();
	}
	cout << "\n\n >> Ű �Է½� ���� ȭ������ ���ư��ϴ�....";
	cin.ignore(50, '\n');
	cin.get();
}

void AccountHandler::ShowTransactHistory(void) const
{
	printContent("�ŷ� �̷�");
	for (int i = 0; i < accNum; i++)
	{
		changeColor(lightGreen);
		cout << accArr[i]->GetAccID(); changeColor(darkWhite);
		cout << " ���� �ŷ����� �Դϴ�.\n\n";
		
		cout << " " << left << setw(25)
			<< "��  ��" << left << setw(15)
			<< "�ŷ� ����" << left << setw(25)
			<< "�޽���" << left << setw(15)
			<< "���� �ݾ�" << left << setw(15)
			<< "��  ��";
		cout << endl;

		cout << " ===================================================================================================" << endl;
		accArr[i]->PrintDealList();
		cout << endl;
		cout << " ===================================================================================================" << endl << endl << endl;
	}
	cout << "\n\n >> Ű �Է½� ���� ȭ������ ���ư��ϴ�....";
	cin.ignore(50, '\n');
	cin.get();
}

/**
* Function Name: AccountSuspension
* Description: ���� ���� ����.
* @param: void
* @return: void
*
* Author: Jeong MinGyu
**/
void AccountHandler::AccountSuspension(void) {
	int id, answer = 0;
	string content = "���� ����";
	printContent(content);
	cout << "\t\t\t\t\t\t ����ID: "; changeColor(lightGreen); cin >> id; changeColor(darkWhite);
	cout << endl;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			do{
				cout << "\t\t\t\t    ���� Ȱ��ȭ ���θ� �����Ͻðڽ��ϱ�?\n\n"<< endl;
				cout << "\t\t\t\t\t���� ���� ���� : ";
				if (accArr[i]->GetStatus()) {
					changeColor(lightBlue); cout << "���� Ȱ��ȭ"; changeColor(darkWhite);
				}
				else {
					changeColor(lightRed); cout << "���� ����"; changeColor(darkWhite);
				}
				cout << endl << endl;;
				printSuspension(0);


				cout << "\n\n\t\t\t\t\t\t- ����: "; changeColor(lightGreen);
				cin >> answer;  changeColor(darkWhite);

				switch(answer){
				case 1:
					if(!accArr[i]->GetStatus()) {
					//TODO ��� Ʋ���� Ƚ�� �����ϴ� �Լ� ��ȣ ����� �ٲ��ּ���
					if (accArr[i]->GetPW() != accArr[i]->InputPw()) {
						system("cls");
						changeColor(lightRed); cout << "���"; changeColor(darkWhite);

						cout << " : ��й�ȣ�� �ٸ��ϴ�.";
						cout << "("; changeColor(lightRed);
						cout << accArr[i]->ChageWorngPW(1); changeColor(darkWhite);
						cout << "ȸ Ʋ��)";
						return;
					}
					else accArr[i]->ChageWorngPW(0);
					}
					accArr[i]->ToggleStatus();
					system("cls");
				case 2:
					system("cls");
					return;
				default:
					system("cls");
					break;
				} 
			} while (1);
			
			return;
		}
	}
	system("cls");
	changeColor(lightRed); cout << "���"; changeColor(darkWhite);
	cout << " : ��ȿ���� ���� ID �Դϴ�.";
}

AccountHandler::AccountHandler() : accNum(0)
{  }

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}