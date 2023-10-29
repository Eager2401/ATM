#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#pragma once
class TheTu
{
public:
	string id;
	string pass;

	TheTu()
	{
		this->id = " ";
		this->pass = "123456";
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

};



