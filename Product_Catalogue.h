#pragma once
#include<iostream>
#include"Admin.h"
#include"Customer.h"
#include"Manager.h"
#include"Inventory.h"
#include"Payment.h"
#include"Product_Catalogue.h"
const char filename8[100] = "Product_Catalogue.bin";
using namespace std;
class Product_Catalogue
{
private:
	char type1[100];
	char t1p1[100];
	char t1p2[100];
	char type2[100];
	char t2p1[100];
	char t2p2[100];

public:
	Product_Catalogue()
	{
		strcpy_s(type1, "Snacks");
		strcpy_s(t1p1, "Lays");
		strcpy_s(t1p2, "Slanty");
	}
	Product_Catalogue(string t1, string T1P1, string T1P2)
	{
		strcpy_s(type1, t1.c_str());
		strcpy_s(t1p1, T1P1.c_str());
		strcpy_s(t1p2, T1P2.c_str());
	}
	void set_Type1(string T1)
	{
		strcpy_s(type1, T1.c_str());
	}
	void set_T1P1(string type1p1)
	{
		strcpy_s(t1p1, type1p1.c_str());
	}
	void set_T1P2(string type1p2)
	{
		strcpy_s(t1p2, type1p2.c_str());
	}
	string get_Type1()
	{
		return type1;
	}
	string get_t1p1()
	{
		return t1p1;
	}
	string get_t1p2()
	{
		return t1p2;
	}
	void display()
	{
		cout << "--> " << type1 << endl;
		cout << "         * " << t1p1 << endl;
		cout << "         * " << t1p2 << endl << endl;
	}
};
void insertObject_Catalogue(Product_Catalogue PC1) {

	ofstream myFile(filename8, ios::binary | ios::app);
	if (myFile.write((char*)&PC1, sizeof(PC1)))
		cout << "Object Successfully Inserted!" << endl;
	else
		cout << "Object Insertion Failed" << endl;
	myFile.close();
}
void retrieveAll_Catalogue() {
	Product_Catalogue temp;
	ifstream myFile(filename8, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		temp.display();
	}
	myFile.close();
}
void deleteObject_Catalogue_Catagory(string name) {
	Product_Catalogue temp;
	fstream myFile(filename8, ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.get_Type1() != name) {
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
	}
	myFile.close();
	myFile_temp.close();
	remove(filename8);
	rename("temp.bin", filename8);
}
void retrieveAll_Product_Catalogue() {
     Product_Catalogue temp;
	ifstream myFile(filename8, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		temp.display();
	}
	myFile.close();
}
void deleteObject_Catalogue_Catagory_Object(string name) {
	Product_Catalogue temp;
	fstream myFile(filename8, ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.get_t1p1() != name) {
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
		else if(temp.get_t1p2() != name) {
			myFile_temp.write((char*)&temp, sizeof(temp));
		}

	}
	myFile.close();
	myFile_temp.close();
	remove(filename8);
	rename("temp.bin", filename8);
}
void updateObject_Catalogue_Catagory(string name, string Name) {
	Product_Catalogue temp;
	fstream myFile(filename8, ios::in | ios::out | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.get_t1p1() == name) 
		{
			temp.set_T1P1(Name);
			int current = myFile.tellg();
			int oneblock = sizeof(temp);
			myFile.seekg(current - oneblock);
			myFile.write((char*)&temp, sizeof(temp));
			myFile.close();
		}
	}
}