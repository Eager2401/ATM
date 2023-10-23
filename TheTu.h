#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#pragma once
class TheTu
{
private:
	string id;
	string pass;
public:
	TheTu()
	{

	}
	TheTu(string id)
	{
		this->id = id;
	}

	TheTu(string id, string pass)
	{
		this->id = id;
		this->pass = pass;
	}

	void setId()
	{
		do {
			getline(cin, this->id);
			cin.ignore();
			if (this->id.size() != 14)
				cout << "Id phai co du 14 chu so";
		} while (this->id.size() != 14);
		
	}

	void setPass()
	{
		do {
			getline(cin, this->pass);
			if (this->pass.size() != 6)
			{
				cout << "Mat khau phai co du 6 ky tu\n";
			}
		} while (this->pass.size() == 6);
	}
	
	string getPass()
	{
		return pass;
	}

	string getId()
	{
		return id;
	}
};



