/**
 * File Name: DealList.h
 *
 * Description:
 * 계정 정보를 저장하기 위한 클래스 정의
 **/

#pragma once
#include <string>

using namespace std;

class DealList
{
	friend ostream& operator<<(ostream& os, const DealList& dl);

private:
	int balance;			//잔액
	int money;				//이체 금액
	int date, month, year;	//일,월,연도  
	string addresseID;		//이체 대상 아이디
	string message;			//메세지 	

public:
	DealList();
	DealList(int balance, int money, int year, int month, int date, string addresseID, string message);
	DealList& getInfo();
	void setInfo(int balance, int money, int year, int month, int date, string addresseID, string message);	
};

