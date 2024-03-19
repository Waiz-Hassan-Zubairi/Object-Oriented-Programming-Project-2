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
const char filename7[100] = "Inventory_Islamabad.bin";
class Inventory_Islamabad:public Inventory
{
private: 
	Manager* M1;
	char pro[100];
	int price;
	int Quantity;
public:
	Inventory_Islamabad()
	{
		strcpy_s(pro, "Milk");
		price = 120;
		Quantity = 10;
	}

};
void retrieveObject_Product(string name) {
	Inventory temp;
	bool flag1 = true;
	ifstream myFile(filename7, ios::binary);
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
void insertObject_Product(Inventory I1) {

	ofstream myFile(filename7, ios::binary | ios::app);
	if (myFile.write((char*)&I1, sizeof(I1)))
		cout << "Object Successfully Inserted!" << endl;
	else
		cout << "Object Insertion Failed" << endl;
	myFile.close();
}
void retrieveAll_Product() {
	Inventory temp;
	ifstream myFile(filename7, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		temp.display();
	}
	myFile.close();
}
void deleteObject_Product(string name) {
	Inventory temp;
	fstream myFile(filename7, ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.get_pro() != name) {
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
	}
	myFile.close();
	myFile_temp.close();
	remove(filename7);
	rename("temp.bin", filename7);
}
void updateObject_Product(string name, string Name, int price,int q) {
	Inventory temp;
	fstream myFile(filename7, ios::in | ios::out | ios::binary);
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
void updateObject_Product_Quantity_Islamabad(string name,  int q) {
		Inventory temp;
		fstream myFile(filename7, ios::in | ios::out | ios::binary);
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