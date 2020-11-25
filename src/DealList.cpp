/**
 * File Name: DealList.cpp
 *
 * Description:
 * ���� ���� �����ϴ� DealList�� �Լ� ����
 **/

#include <iostream>
#include "DealList.h"

using namespace std;

/**
* Function Name: DealList ������
* Description: ������
* @param: int balance, int money, int year, int month, int date, string addresseID, string message
* @return: x
*
* Author: Jeong MinGyu
**/
DealList::DealList(int balance, int money, int year, int month, int date, string addressID, string message) {
    this->balance = balance;
    this->money = money;
    this->year = year;
    this->month = month;
    this->date = date;

    this->addressID = addressID;
    this->message = message;
}

DealList::DealList() {
    this->balance = 1900;
    this->money = -1;
    this->year = 1;
    this->month = 1;
    this->date = 1;

    this->addressID = "";
    this->message = "";
}

/**
* Function Name: setInfo
* Description: ����Ʈ ���� ����
* @param: int balance, int money, int year, int month, int date, string addresseID, string message
* @return: void
*
* Author: Jeong MinGyu
**/
void DealList::setInfo(int balance, int money, int year, int month, int date, string addresseID, string message) {
    this->balance = balance;
    this->money = money;
    this->year = year;
    this->month = month;
    this->date = date;

    this->addressID = addresseID;
    this->message = message;
}

/**
* Function Name: getInfo
* Description: DealList ������ ������
* @param: void
* @return: DealList&
*
* Author: Jeong MinGyu
**/
DealList& DealList::getInfo() {
    return *this;
}

/**
* Function Name: operator<< 
* Description: DealList�� << ������ �ߺ� (friend)
* @param: ostream&
* @return: ostream& os, const DealList& dl
*
* Author: Jeong MinGyu
**/
ostream& operator<<(ostream& os, const DealList& dl)
{
    os << "=============================" << endl;
    os << dl.year << "/" << dl.month << "/" << dl.date << "\t" << dl.addressID << "\t" << dl.message << "\t" << dl.money << "\t" << dl.balance << endl;
    return os;
}
