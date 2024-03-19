//Name : Waiz Zubairi
//Roll no. i210751
#pragma once
#include<iostream>
#include"Admin.h"
#include"Customer.h"
#include"Manager.h"
#include"Cart.h"
#include"Inventory.h"
#include"Payment.h"
#include"User.h"
#include"Karachi_Inventory.h"
#include"Islamabad_Inventory.h"
#include"Product_Catalogue.h"
#include<ctime>
#include<chrono>
#include<iomanip>
const char filename14[100] = "Time.bin";
class Time
{
private:
	char N[100];//Name
	float Seconds;
public:
	void setSeconds(float s)
	{
		Seconds = s;
	}
	void setNaam(string n)
	{
		strcpy_s(N, n.c_str());
	}
	float getSeconds()
	{
		return Seconds;
	}
	string getNaam()
	{
		return N;
	}
	void display()
	{
		cout << "Name : " << N << endl;
		cout << "Time consumed : " << Seconds <<" Seconds" << endl;
	}
};
void insertObject_Time(Time T1) {//for time insertion

	ofstream myFile(filename14, ios::binary | ios::app);
	if (myFile.write((char*)&T1, sizeof(T1)))
		cout << "Time Successfully Inserted!" << endl;
	else
		cout << "Time Insertion Failed" << endl;
	myFile.close();
}
void retrieveAll_Time() {// display all customer time
	Time temp;
	ifstream myFile(filename14, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		temp.display();
	}
	myFile.close();
}