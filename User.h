#pragma once
#include<iostream>
#include<fstream>
#include"User.h"
#include"Admin.h"
#include"Customer.h"
#include"Manager.h"
#include"Inventory.h"
#include"Payment.h"
#include"Product_Catalogue.h"
#include<cstring>
#include<iomanip>
class User
{
private:
	char name[100];
	char passord[100];
public:

	User()
	{
		strcpy_s(name, "waiz");
		strcpy_s(passord, "Waizhassan09");
	}

	User(string n,string p)
	{
		strcpy_s(name, n.c_str());
		strcpy_s(passord, p.c_str());
	}
	void setName(string n) {
		strcpy_s(name, n.c_str());
	}
	void setPassword(string p) {
		strcpy_s(passord, p.c_str());
	}
	string getName()
	{
		return name;
	}
	string getPassord()
	{
		return passord;
	}
};