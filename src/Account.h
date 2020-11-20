/**
 * File Name: Account.h
 *
 * Description:
 * ���� ������ �����ϱ� ���� Ŭ���� ����
 **/
#pragma once

class Account
{
protected:
	int accID;
	int balance;
	char* cusName;
	double interestRate;
public:
	Account();
	int GetAccID() const;
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

Account::Account() {
	
}

// ���� ����2 :  �߰� ���� �ִ� �� (high) - A��� (�⺻ ���� + A ����), B��� (�⺻ ���� + B ����), C��� (�⺻ ���� + C����)
class NormalAccount : Account {
private:
	int grade;
public:
	NormalAccount();
	NormalAccount(int ID, int money, char* name, int grade);
	void SetGrade(int grade);
	int GetGrade();
};

NormalAccount::NormalAccount() {};
NormalAccount::NormalAccount(int ID, int money, char* name, int grade) {
	this->accID = ID;
	this->balance = money;
	this->cusName = name;
	this->grade = grade;
}

void NormalAccount::SetGrade(int grade) {
	this->grade = grade;
}
int NormalAccount::GetGrade() {
	return this->grade;
}

// ���� ����3 : ��޺� ��ü ������ ���� (ex) A - ����, B - 50%........)
class HighCreditAccount : Account {
private:
	int grade;
	double transferFee[3];
public:
	HighCreditAccount();
	HighCreditAccount(int ID, int money, char* name, int grade);
	void SetGrade(int grade);
	int GetGrade();
	void SetTransferFee(int grade, double transferFee);
	int GetTransferFee(int grade);
};

HighCreditAccount::HighCreditAccount() {
	transferFee[0] = 1.0;
	transferFee[1] = 1.2;
	transferFee[2] = 1.5;
};
HighCreditAccount::HighCreditAccount(int ID, int money, char* name, int grade) {
	this->accID = ID;
	this->balance = money;
	this->cusName = name;
	this->grade = grade;
	transferFee[0] = 1.0;
	transferFee[1] = 1.2;
	transferFee[2] = 1.5;
}

void HighCreditAccount::SetGrade(int grade) {
	this->grade = grade;
}
int HighCreditAccount::GetGrade() {
	return this->grade;
}
void HighCreditAccount::SetTransferFee(int grade, double transferFee) {
	this->transferFee[grade - 1] = transferFee;
}
int HighCreditAccount::GetTransferFee(int grade) {
	return this->transferFee[grade - 1];
}