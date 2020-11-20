/**
 * File Name: Account.h
 *
 * Description:
 * 계정 정보를 저장하기 위한 클래스 정의
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

// 통장 유형2 :  추가 이자 있는 거 (high) - A등급 (기본 이자 + A 이자), B등급 (기본 이자 + B 이자), C등급 (기본 이자 + C이자)
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

// 통장 유형3 : 등급별 이체 수수료 차등 (ex) A - 없음, B - 50%........)
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