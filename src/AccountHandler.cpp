/**
 * File Name: AccountHandler.cpp
 *
 * Description:
 * AccountHandler 클래스 정의 파일
 **/

#include <iostream>
#include "AccountHandler.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"

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
	cout << "6. 계좌정지" << endl;
	cout << "7. 프로그램 종료" << endl;
}

/**
* Function Name: MakeAccount
* Description: 계좌 개설.
* @param: void
* @return: void
*
* Author: - 남유정, 박주용
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
rewrite:
	cout << "계좌ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << "입금액: ";	cin >> balance;
	cout << endl;
	
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id) {
			cout << "동일 계좌ID가 있습니다." << endl;
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
		if(!accArr[i]->GetStatus()){
			cout << "정지된 계좌입니다." << endl << endl;
			return;
		}
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
			if(!accArr[i]->GetStatus()){
				cout << "정지된 계좌입니다." << endl << endl;
				return;
			}
			//TODO 비번 틀린거 횟수 조절하는 함수 기호 상수로 바꿔주세요
			if (accArr[i]->GetPW() != accArr[i]->InputPw()) {
				cout << "비밀번호가 다릅니다.";
				cout << "(" << accArr[i]->ChageWorngPW(1) << "회 틀림)" << endl << endl;
				return;
			}
			else accArr[i]->ChageWorngPW(0);
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
	
	do {
		cout << "받을 계좌ID: "; cin >> accid;
		if (id != accid) break;
		cout << "같은ID로 송금할 수 없습니다." << endl;
	} while (id == accid);

	cout << "송금액 ";	cin >> money;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			//TODO 비번 틀린거 횟수 조절하는 함수 기호 상수로 바꿔주세요
			if (accArr[i]->GetPW() != accArr[i]->InputPw()) {
				cout << "비밀번호가 다릅니다.";
				cout << "(" << accArr[i]->ChageWorngPW(1) << "회 틀림)" << endl << endl;
				return;
			}
			else accArr[i]->ChageWorngPW(0);
			if(!accArr[i]->GetStatus()){
				cout << "정지된 계좌입니다." << endl << endl;
				return;
			}
			for (int j = 0; j < accNum; j++)
			{
				if (accArr[j]->GetAccID() == accid)
				{
					if(!accArr[i]->GetStatus()){
						cout << "정지된 계좌입니다." << endl << endl;
						return;
					}
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

/**
* Function Name: AccountSuspension
* Description: 계좌 정지 설정.
* @param: void
* @return: void
*
* Author: Jeong MinGyu
**/
void AccountHandler::AccountSuspension(void) {
	int id, answer = 0;
	cout << "[계좌 정지]" << endl;
	cout << "계좌ID: ";	cin >> id;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			do{
				cout << "계좌 활성화 여부를 변경하시겠습니까?"<< endl;
				cout << "현재 계좌 상태 : " << accArr[i]->GetStatus() << endl;
				cout << "1. 변경" << endl;
				cout << "2. 취소" << endl;

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
	cout << "유효하지 않은 ID 입니다." << endl << endl;

}

AccountHandler::AccountHandler() : accNum(0)
{  }

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}