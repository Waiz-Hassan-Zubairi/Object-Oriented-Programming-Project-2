//Name : Waiz Zubairi
//Roll no. i210751
#pragma once
#include<iostream>
#include"Admin.h"
#include"Customer.h"
#include"Manager.h"
#include"Inventory.h"
#include"Payment.h"
#include"Product_Catalogue.h"
#include<iomanip>
using namespace std;
const char filename4[100] = "Inventory.bin";
class Inventory
{
private:
	char pro[100];
	int price;
	int Quantity;
public:
	Inventory()
	{
		strcpy_s(pro, "Milk");
		price = 120;
		Quantity = 10;
	}
	void set_pro(string p)
	{
		strcpy_s(pro, p.c_str());
	}
	void set_pric(int pri)
	{
		price = pri;
	}
	void set_quantity(int q)
	{
		Quantity = q;
	}
	string get_pro()
	{
		return pro;
	}
	int get_price()
	{
		return price;
	}
	int get_quantity()
	{
		return Quantity;
	}

	void display() {
		
		cout <<  pro<<    "                   " << Quantity <<"                       "<<price << endl;
	}
};
