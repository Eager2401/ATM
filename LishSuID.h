#include "TheTu.h"
#include "ID.h"
#pragma once
class LishSuID : public ID
{
private:
	int amount;
public:

	LishSuID(string id, int balance, string loaiTien, int amount)
		: ID(id, balance, loaiTien)
	{
		this->amount = amount;

	}
	
	void setAmount()
	{
		cout << "So tien giao dich: ";
		cin >> amount;
	}
	int chuyenTien()
	{
		setAmount();
		return ID::balance = ID::balance - (amount + 50000);
	}

	int rutTien()
	{
		setAmount();
		return ID::balance = ID::balance - (amount + 50000);
	}

	int guiTien()
	{
		setAmount();
		return ID::balance = ID::balance + (amount + 50000);
	}
};

