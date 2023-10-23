#include<iostream>
#include<fstream>
using namespace std;
#pragma once
class Admin
{
public:
	string user;
	string pass;

	Admin()
	{

	}

	Admin(string user, string pass)
	{
		this->user = user;
		this->pass = pass;
	}

	
	bool operator== (const Admin & other)
	{
		return this->user == other.user && this->pass == pass;
	}
	bool operator!=(const Admin& other)
	{
		return this->user != other.user || this->pass != pass;
	}
};




