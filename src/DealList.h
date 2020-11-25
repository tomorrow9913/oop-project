/**
 * File Name: DealList.h
 *
 * Description:
 * ���� ������ �����ϱ� ���� Ŭ���� ����
 **/

#pragma once
#include <string>

using namespace std;

class DealList
{
	friend ostream& operator<<(ostream& os, const DealList& dl);

private:
	int balance;			//�ܾ�
	int money;				//��ü �ݾ�
	int date, month, year;	//��,��,����  
	string addresseID;		//��ü ��� ���̵�
	string message;			//�޼��� 	

public:
	DealList();
	DealList(int balance, int money, int year, int month, int date, string addresseID, string message);
	DealList& getInfo();
	void setInfo(int balance, int money, int year, int month, int date, string addresseID, string message);	
};

