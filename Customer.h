//Name : Waiz Zubairi
//Roll no. i210751
#pragma once
#include<iostream>
#include"Admin.h"
#include"Customer.h"
#include"Manager.h"
#include"Inventory.h"
#include"Payment.h"
#include"Cart.h"
#include"Product_Catalogue.h"
#include<iomanip>
using namespace std;
const char filename3[100] = "Customer.bin";
class Customer:public User
{
private:
	char cnic[100];
	int Balance = 5000;
public:

	Customer()
	{
		strcpy_s(cnic, "3630211879399");
		Balance = 5000;
	}

	Customer(string n, string c, string p)
	{
		strcpy_s(cnic, c.c_str());
	}
	void setCnic(string c) {
		strcpy_s(cnic, c.c_str());
	}

	string getCNIC()
	{
		return cnic;
	}
	void setBalance(int b)
	{
		Balance=b;
	}
	int getBalance()
	{
		return Balance;
	}
};

void insertObject_Customer(Customer C1) {

	ofstream myFile(filename3, ios::binary | ios::app);
	if (myFile.write((char*)&C1, sizeof(C1)))
		cout << "Customer Successfully Registered!" << endl;
	else
		cout << "Customer Registration Failed" << endl;
	myFile.close();
}
bool verify_Customer(string n, string p)
{
	bool con = false;
	Customer C2;
	ifstream myFile(filename3, ios::binary);
	while (myFile.read((char*)&C2, sizeof(C2)))
	{
		if (C2.getName() == n) 
		{
			if (C2.getCNIC() == p)
			{

				cout << "Login successful!\n";
				myFile.close();
				con= true;

			}
			else
			{
				cout << setw(40) << "Wrong credentials" << endl;
				myFile.close();
				con=false;
			}
			
		}
	}
	return con;
}
void deleteObject_Customer(string n, string c) {
	Customer temp;
	fstream myFile(filename3, ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.getName() != n)
		{
			if (temp.getCNIC() != c) {
				myFile_temp.write((char*)&temp, sizeof(temp));
			}
		}
	}
	myFile.close();
	myFile_temp.close();
	remove(filename3);
	rename("temp.bin", filename3);
}