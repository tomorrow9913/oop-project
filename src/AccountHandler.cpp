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

using namespace std;
/**
* Function Name: ShowMenu
* Description: ���� �޴��� ����Ѵ�.
* @param: void
* @return: void
*
* Author: -
**/
void AccountHandler::ShowMenu(void) const
{
	cout << "-----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. ��    ��" << endl;
	cout << "5. �������� ��ü ���" << endl;
	cout << "6. ��������" << endl;
	cout << "7. ���α׷� ����" << endl;
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

	cout << "[���°���]" << endl;
	cout << "\t1. ����ݰ���(NormalAccount)" << endl;
	cout << "\t2. �ſ����(HighCreditAccount)" << endl;
	cout << "���� �׸� ���� : "; cin >> type; cout << endl;
rewrite:
	cout << "����ID: ";	cin >> id;
	cout << "��  ��: ";	cin >> name;
	cout << "�Աݾ�: ";	cin >> balance;
	cout << endl;
	
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id) {
			cout << "���� ����ID�� �ֽ��ϴ�." << endl;
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
	cout << "[��    ��]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "�Աݾ�: ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if(!accArr[i]->GetStatus()){
			cout << "������ �����Դϴ�." << endl << endl;
			return;
		}
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
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

	cout << "[��    ��]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "��ݾ�: ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if(!accArr[i]->GetStatus()){
				cout << "������ �����Դϴ�." << endl << endl;
				return;
			}
			//TODO ��� Ʋ���� Ƚ�� �����ϴ� �Լ� ��ȣ ����� �ٲ��ּ���
			if (accArr[i]->GetPW() != accArr[i]->InputPw()) {
				cout << "��й�ȣ�� �ٸ��ϴ�.";
				cout << "(" << accArr[i]->ChageWorngPW(1) << "ȸ Ʋ��)" << endl << endl;
				return;
			}
			else accArr[i]->ChageWorngPW(0);
			if (accArr[i]->Withdraw(money) < 0)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
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

	cout << "[��    ��]" << endl;
	cout << "�� ����ID: ";	cin >> id;
	
	do {
		cout << "���� ����ID: "; cin >> accid;
		if (id != accid) break;
		cout << "����ID�� �۱��� �� �����ϴ�." << endl;
	} while (id == accid);

	cout << "�۱ݾ� ";	cin >> money;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			//TODO ��� Ʋ���� Ƚ�� �����ϴ� �Լ� ��ȣ ����� �ٲ��ּ���
			if (accArr[i]->GetPW() != accArr[i]->InputPw()) {
				cout << "��й�ȣ�� �ٸ��ϴ�.";
				cout << "(" << accArr[i]->ChageWorngPW(1) << "ȸ Ʋ��)" << endl << endl;
				return;
			}
			else accArr[i]->ChageWorngPW(0);
			if(!accArr[i]->GetStatus()){
				cout << "������ �����Դϴ�." << endl << endl;
				return;
			}
			for (int j = 0; j < accNum; j++)
			{
				if (accArr[j]->GetAccID() == accid)
				{
					if(!accArr[i]->GetStatus()){
						cout << "������ �����Դϴ�." << endl << endl;
						return;
					}
					if (int returnMoney = accArr[i]->Transfer(money, *accArr[j]) > 0) {
						cout << "�۱ݿϷ�" << endl << endl;
						return;
					}
					cout << "�ܾ׺���" << endl << endl;
					return;
				}
			}
			cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
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
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
		accArr[i]->PrintDealList();
	}
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
	cout << "[���� ����]" << endl;
	cout << "����ID: ";	cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			do{
				cout << "���� Ȱ��ȭ ���θ� �����Ͻðڽ��ϱ�?"<< endl;
				cout << "���� ���� ���� : " << accArr[i]->GetStatus() << endl;
				cout << "1. ����" << endl;
				cout << "2. ���" << endl;

				cin >> answer;

				switch(answer){
				case 1:
					accArr[i]->ToggleStatus();
				case 2:
					return;
				default:
					break;
				} 
			} while (1);
			
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;

}

AccountHandler::AccountHandler() : accNum(0)
{  }

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}