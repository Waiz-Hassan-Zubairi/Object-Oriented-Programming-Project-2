//Name : Waiz Zubairi
//Roll no. i210751
#pragma once
#include<iostream>
#include<fstream>
#include"Admin.h"
#include"Customer.h"
#include"Manager.h"
#include"Inventory.h"
#include"Payment.h"
#include"Product_Catalogue.h"
#include<cstring>
#include<iomanip>

using namespace std;
const char filename1[100] = "Admin.bin";
class Admin :public User
{
private:

public:



};

//void insertObject_Admin(Admin A1) 
//{
//	ofstream myFile(filename1, ios::binary | ios::app);
//	if (myFile.write((char*)&A1, sizeof(A1)))
//		cout << "Object Successfully Inserted!" << endl;
//	else
//		cout << "Object Insertion Failed" << endl;
//	myFile.close();
//}
bool verify_Admin(string n, string p)
{
	Admin A2;
	ifstream myFile(filename1, ios::binary);
	while (myFile.read((char*)&A2, sizeof(A2))) 
	{
		Admin A3;
		if (A3.getName() == n) 
		{
	
			Admin A5;
			if (A5.getPassord() == p)
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
				
				
			
			return false;
		}
		return false;
	}
}
