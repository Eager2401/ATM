#include "TheTu.h"
#pragma once
class ID : public TheTu
{
public:
	string nameTK;
	int balance;
	string loaiTien;

	ID()
	{
		this->nameTK = " ";
		this->loaiTien = "VND";
		this->balance = 50000;
	}
	ID(string id, int balance, string loaiTien) : TheTu(id)
	{
		this->balance = 50000;
		this->loaiTien = "VND";
	}
	ID(string id, string nameTK, int balance, string loaiTien) : TheTu(id) {
		this->nameTK = nameTK;
		this->balance = balance;
		this->loaiTien = loaiTien;
	}
	void setNTK()
	{
		getline(cin, this->nameTK);
		cin.ignore();
	}
	void setBalance()
	{
		this->balance = 50000;
	}
	string getNameTK()
	{
		return nameTK;
	}
	void setLT()
	{
		this->loaiTien = "VND";
	}

	int getBalance()
	{
		return balance;
	}

	string getLT()
	{
		return loaiTien;
	}
	void display()
	{
		cout << getBalance() << " " << getLT();
	}
};

