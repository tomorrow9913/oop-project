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
	string timestamp;		//��,��,����
	string addressID;		//��ü ��� ���̵�
	string message;			//�޼��� 

public:
	DealList();
	DealList(int balance, int money, string addresseID, string message);
	DealList& getInfo();
	void setInfo(int balance, int money, string timestamp, string addresseID, string message);
};