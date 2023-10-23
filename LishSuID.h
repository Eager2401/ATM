#include "TheTu.h"
#include "ID.h"
#pragma once
class LishSuID : public ID
{
private:
	int amount;
public:

	LishSuID(string id, int balance, string loaiTien)
		: ID(id, balance, loaiTien)
	{

	}

	void setAmount()
	{
		cout << "So tien giao dich: ";
		cin >> amount;
	}
	/*int chuyenTien()
	{
		setAmount();
		return getBalance() +=  amount;
	}

	int rutTien()
	{
		setAmount();
		return getBalance() -= amount;
	}

	int guiTien()
	{
		setAmount();
		return setBalance() += amount;
	}*/
};

