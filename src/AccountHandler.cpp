/**
 * File Name: AccountHandler.cpp
 *
 * Description:
 * AccountHandler 클래스 정의 파일
 **/

#include <iostream>
#include "AccountHandler.h"

using namespace std;
/**
* Function Name: ShowMenu
* Description: 메인 메뉴를 출력한다.
* @param: void
* @return: void
*
* Author: -
**/
void AccountHandler::ShowMenu(void) const
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 송    금" << endl;
	cout << "5. 계좌정보 전체 출력" << endl;
	cout << "6. 프로그램 종료" << endl;
}

/**
* Function Name: MakeAccount
* Description: 계좌 개설.
* @param: void
* @return: void
*
* Author: -
**/
void AccountHandler::MakeAccount(void)
{
	int id;
	int type;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "\t1. 입출금계좌(NormalAccount)" << endl;
	cout << "\t2. 신용계좌(HighCreditAccount)" << endl;
	cout << "계좌 항목 선택 : "; cin >> type; cout << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << "입금액: ";	cin >> balance;
	cout << endl;

	if (type == 1) {
		accArr[accNum++] = new NormalAccount(id, balance, name);
	}
	else if (type == 2) {
		accArr[accNum++] = new HighCreditAccount(id, balance, name);
	}
}

/**
* Function Name: DepositMoney
* Description: 입금.
* @param: void
* @return: void
*
* Author: -
**/
void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "[입    금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "입금액: ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

/**
* Function Name: WithdrawMoney
* Description: 출금.
* @param: void
* @return: void
*
* Author: -
**/
void AccountHandler::WithdrawMoney(void)
{ 
	int money;
	int id;

	cout << "[출    금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "출금액: ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) < 0)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

/**
* Function Name:TransferMoney
* Description: 송금
* @param: void
* @return: void
*
* Author: - 남유정, 박주용
**/
void AccountHandler::TransferMoney(void) {
	int money;
	int id, accid;

	cout << "[송    금]" << endl;
	cout << "내 계좌ID: ";	cin >> id;
	cout << "받을 계좌ID: "; cin >> accid;
	cout << "송금액 ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)//id를 찾는 if문
		{
			for (int j = 0; j < accNum; j++)
			{
				if (accArr[j]->GetAccID() == accid)//accd를 찾는 if문
				{
					if (int returnMoney = accArr[i]->Transfer(money, *accArr[j]) > 0) {           
						cout << "송금완료" << endl << endl;
						return;
					}
					cout << "잔액부족" << endl << endl;
					return;
				}				
			}
			cout << "유효하지 않은 ID 입니다." << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

// 동일 계좌를 입력시

/**
* Function Name: ShowAllAccInfo
* Description: 전체 계좌 출력.
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

AccountHandler::AccountHandler() : accNum(0)
{  }

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}