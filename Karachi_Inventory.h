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
const char filename6[100] = "Karachi_Inventory.bin";
class Inventory_Karachi:public Inventory
{
private:
	Manager* M1;
	char pro_karachi[100];
	int price_karachi;
public:
	Inventory_Karachi()
	{
		strcpy_s(pro_karachi, "Milk");
		price_karachi = 120;
	}

};
void retrieveObject_Product_karachi(string name) {
	Inventory_Karachi temp;
	bool flag1 = true;
	ifstream myFile(filename6, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.get_pro() == name) {
			temp.display();
			flag1 = false;
			myFile.close();
			break;
		}
	}
	if (flag1)
	{
		cout << "Not Available" << endl;
	}
}
void insertObject_Product_karachi(Inventory_Karachi I1) {

	ofstream myFile(filename6, ios::binary | ios::app);
	if (myFile.write((char*)&I1, sizeof(I1)))
		cout << "Object Successfully Inserted!" << endl;
	else
		cout << "Object Insertion Failed" << endl;
	myFile.close();
}
void retrieveAll_Product_karachi() {
	Inventory_Karachi temp;
	ifstream myFile(filename6, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		
		temp.display();
	}
	myFile.close();
}
void deleteObject_Product_karachi(string name) {
	Inventory_Karachi temp;
	fstream myFile(filename6, ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.get_pro() != name) {
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
	}
	myFile.close();
	myFile_temp.close();
	remove(filename6);
	rename("temp.bin", filename6);
}
void updateObject_Product_karachi(string name, string Name, int price,int q) {
	Inventory_Karachi temp;
	fstream myFile(filename6, ios::in | ios::out | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.get_pro() == name) {
			temp.set_pro(Name);
			temp.set_pric(price);
			temp.set_quantity(q);
			int current = myFile.tellg();
			int oneblock = sizeof(temp);
			myFile.seekg(current - oneblock);
			myFile.write((char*)&temp, sizeof(temp));
			myFile.close();
		}
	}
}
void updateObject_Product_karachi_Quantity(string name, int q) {
	Inventory_Karachi temp;
	fstream myFile(filename6, ios::in | ios::out | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.get_pro() == name) {
			temp.set_quantity(q);
			int current = myFile.tellg();
			int oneblock = sizeof(temp);
			myFile.seekg(current - oneblock);
			myFile.write((char*)&temp, sizeof(temp));
			myFile.close();
		}
	}
}