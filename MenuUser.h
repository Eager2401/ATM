#pragma once
#include "ID.h"
#include"LishSuID.h"
#include"TheTu.h"
#include <string> 


//void DNUser();
//void LogInUser();
//void showUser(ID dsid[]);
//void RutTien();
//void chuyenTien();
//void showInfoTransaction();
//void ChangePin();
//bool checkFileID();
//int slIDco();


void LoginUser()
{
	for (int i = 0; i < 26; i++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "\tDANG NHAP USER\n";
	for (int i = 0; i < 26; i++)
	{
		cout << "*";
	}
	cout << endl;
	MenuUser();
}
void MenuUser()
{
	ID dsid[100];

	int check = true;
	while (check)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "*";
		}
		cout << "Menu";
		for (int i = 0; i < 10; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "1. Xem thong tin tai khoan.\n";
		cout << "2. Rut tien.\n";
		cout << "3. Chuyen TIen.\n";
		cout << "4. Xem noi dung giao dich.\n";
		cout << "5. Doi ma pin.\n";
		cout << "6. Thoat.\n";
		int nhap;
		cin >> nhap;
		switch (nhap)
		{
		case 1:
			for (int i = 0; i < slIDco(); i++)
			{
				showUser(dsid);
			}
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			check = false;
			break;
		}
	}
}

void showUser(ID dsid[])
{
	ifstream filein;
	filein.open("ID.txt", ios_base::in);
	if (checkFileID())
	{
		cout << "File rong";
	}
	else {
		for (int i = 0; i < slIDco(); i++)
		{
			cout << "----------ID thu " << i + 1 << "----------: \n";
			getline(filein, dsid->id, ',');
			cout << "Id: " << dsid->id << endl;
		}
	}
	filein.close();
}

void RutTien()
{

}

void chuyenTien()
{

}

void showInfoTransaction()
{

}

void ChangePin()
{

}
bool checkFileID()
{
	ifstream filein;
	filein.open("IDtxt", ios_base::in);
	string line;

	//Doc tung dong trong file
	while (getline(filein, line))
	{

		if (!line.empty())
		{
			return false;
		}

	}
	return true;
	filein.close();
}

int slIDco()
{
	int count = 0;
	ifstream filein;
	filein.open("ID.txt", ios_base::in);
	string line;
	while (getline(filein, line))
	{
		if (!line.empty()) {
			count++;
		}
	}
	filein.close();
	return count;
}
