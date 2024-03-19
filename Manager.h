#pragma once
#include<iostream>
#include"User.h"
#include"Admin.h"
#include"Customer.h"
#include"Manager.h"
#include"Inventory.h"
#include"Payment.h"
#include"Product_Catalogue.h"
#include<iomanip>
#include<fstream>
#include<cstring>
using namespace std;
const char filename2[100] = "Manager.bin";
class Manager:public User
{
private:
	char cnic[100];
	char place[100];

public:

	Manager()
	{
		strcpy_s(cnic, "3630211879311");
		strcpy_s(place, "Lahore");
	}

	Manager(string n, string c, string p, string pl):User(n,p)
	{
		//strcpy_s(name, n.c_str());
		strcpy_s(cnic, c.c_str());
		//strcpy_s(passord, p.c_str());		
		strcpy_s(place, pl.c_str());

	}
	void setCnic(string c) {
		strcpy_s(cnic, c.c_str());
	}
	void setPlace(string pl) {
		strcpy_s(place, pl.c_str());
	}
	string getCNIC()
	{
		return cnic;
	}
	string getPlace()
	{
		return place;
	}
	void display()
	{
		cout << "Name : " << getName() << endl;
		cout << "CNIC : " << cnic << endl;
		cout << "Password : " << getPassord() << endl;
		cout << "Location : " << place << endl << endl;
	}
};

void insertObject_Manager( Manager M1) {
	ofstream myFile(filename2, ios::binary | ios::app);
	if (myFile.write((char*)&M1, sizeof(M1)))
		cout << "Manager Successfully Registered!" << endl;
	else
		cout << "Manager Registration Failed" << endl;
	myFile.close();
}
bool verify_Manager(string n, string p,string l)
{
	Manager M2;
	ifstream myFile(filename2, ios::binary);
	while (myFile.read((char*)&M2, sizeof(M2)))
	{
		if (M2.getName() == n) {


			if (M2.getPassord() == p)
			{
				if (M2.getPlace() == l)
				{

					cout << "Login successful!\n";
					myFile.close();
					return true;

				}
				else
				{
					cout << "Wrong Credentials\n";
					myFile.close();
					return false;
				}
			}


			
		}
	}
}
void retrieveAll_Manager() {
	Manager temp;
	ifstream myFile(filename2, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		temp.display();
	}
	myFile.close();
}
void deleteObject_Manager(string n,string c) {
	Manager temp;
	fstream myFile(filename2, ios::in | ios::out | ios::binary);
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
	remove(filename2);
	rename("temp.bin", filename2);
}