#include "TheTu.h"
#pragma once
class ID : public TheTu
{
private:
	string nameTK;
	int balance;
	string loaiTien;
public:
	ID()
	{
		this->nameTK = " ";
		this->loaiTien = "VND";
		this->balance = 0;
	}
	ID(string id, int balance, string loaiTien) : TheTu(id)
	{
		this->balance = 0;
		this->loaiTien = "VND";
	}
	ID(string id, string nameTK, int balance, string loaiTien) : TheTu(id) {
		this->nameTK = nameTK;
		this->balance = balance;
		this->loaiTien = loaiTien;
	}
	void setNTK()
	{
		cout << "Nhap ten: "; getline(cin, this->nameTK);
		cin.ignore();
	}
	void setBalance()
	{
		this->balance = 0;
	}

	string getLT()
	{
		return loaiTien;
	}
	int getBalance()
	{
		return balance;
	}
	string getName()
	{
		return nameTK;
	}
	void display()
	{
		cout << balance << " " << loaiTien;
	}
};

