//Name : Waiz Zubairi
//Roll no. i210751
#pragma once
#include<iostream>
#include"Admin.h"
#include"Customer.h"
#include"Manager.h"
#include"Inventory.h"
#include"Payment.h"
#include"User.h"
#include"Karachi_Inventory.h"
#include"Islamabad_Inventory.h"
#include"Product_Catalogue.h"
#include<string.h>
#include<iomanip>
using namespace std;
const char filename10[100] = "Cart.bin";
class Cart
{
private:
	char product[100];
	int price;
	int quantitty;
    int total_bill ;
public:
	Cart()
	{
		strcpy_s(product , "");
		price = 0;
		quantitty = 0;
		total_bill = 0;
	}
	Cart(string p, int pri, int q,int t)
	{
		strcpy_s(product, p.c_str());
		price = pri;
		quantitty = q;
		total_bill = t;
	}
	void set_Product(string pro)
	{
		strcpy_s(product, pro.c_str());
	}
	void set_price(int p)
	{
		price = p;
	}
	void set_quantity(int q)
	{
		quantitty = q;
	}
	string get_Product()
	{
		return product;
	}
	int get_Price()
	{
		return price;
	}
	int get_Quantity()
	{
		return quantitty;
	}
	void display()
	{
		cout << "Prouct : " << product << endl;
		cout << "Price : " << price << endl;
		cout << "Quantity : " << quantitty << endl;
	}

};
int calculateBill() {
	Cart temp;
	int totalBill = 0;
	ifstream myFile(filename10, ios::binary |ios::in);
	while (myFile.read((char*)&temp, sizeof(temp))) 
	{
		totalBill += temp.get_Price();
	}
	myFile.close();
	return totalBill;
}
void addToCart(string n,int q)
{
	bool checker=false;
	Cart cart1;
	Inventory temp;
	fstream myFile(filename6, ios::in | ios::out | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.get_pro() == n) {
			cart1.set_Product(temp.get_pro());
			cart1.set_price(temp.get_price()*q);
			checker = true;
			if (temp.get_quantity() == 0)
			{
				cout << "Product is Out of Stock" << endl;
				break;
			}
			else if (temp.get_quantity() < q)
			{
				cout << "Not Enough Quantity Avaiable" << endl;
				break;
			}
			else
			{
				int Quan_check = 0;
				Quan_check = temp.get_quantity() - q;
				updateObject_Product_karachi_Quantity(temp.get_pro(),Quan_check);
				cart1.set_quantity(q);
			}
			myFile.close();
		}
	}
	fstream myFil(filename7, ios::in | ios::out | ios::binary);
	while (myFil.read((char*)&temp, sizeof(temp))) {
		if (temp.get_pro() == n) {
			cart1.set_Product(temp.get_pro());
			cart1.set_price(temp.get_price()*q);
			checker = true;
			if (temp.get_quantity() == 0)
			{
				cout << "Product is Out of Stock" << endl;
				break;
			}
			else if (temp.get_quantity() < q)
			{
				cout << "Not Enough Quantity Avaiable" << endl;
				break;
			}
			else
			{
				int Quan_check = 0;
				Quan_check = temp.get_quantity() - q;
				updateObject_Product_Quantity_Islamabad(temp.get_pro(), Quan_check);
				cart1.set_quantity(q);
			}
			myFile.close();
		}
	}
	if (checker)
	{
		ofstream myfile(filename10, ios::binary | ios::app);
		if (myfile.write((char*)&cart1, sizeof(cart1)))
			cout << endl << "Item Added Successfully " << endl;
		else
			cout << endl << "Unable to add Item" << endl;
		myfile.close();
	}
	else 
	{
		cout << "Falied to add \nAdd again\n";
	}
}

void retrieveAll_Cart() {
	Cart temp;
	ifstream myFile(filename10, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		cout << endl;
		cout << endl;
		temp.display();
		cout << endl;
		cout << endl;
	}
	myFile.close();
}
void Clear_cart() {
	Inventory temp;
	remove(filename10);
	ofstream myFile_temp(filename10, ios::app | ios::binary);
}
void deleteObject_Product_cart(string name) {
	Inventory temp;
	fstream myFile(filename10, ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.get_pro() != name) {
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
	}
	myFile.close();
	myFile_temp.close();
	remove(filename10);
	rename("temp.bin", filename10);
}
const char filename12[100] = "Feedback.bin";
class FeedBack
{
private:
	char feedback[100];
public:
	void setFeedback(string feed)
	{
		strcpy_s(feedback, feed.c_str());
	}
	string getFeedback()
	{
		return feedback;
	}
	void display()
	{
		cout << feedback << endl;
	}
};
void insertObject_FeedBack(FeedBack B1) {
	ofstream myFile(filename12, ios::binary | ios::app);
	if (myFile.write((char*)&B1, sizeof(B1)))
		cout << "FeedBack Saved " << endl;
	else
		cout << "Unable to save feedback" << endl;
	myFile.close();
}
void retrieveAll_FeedBack() {
	FeedBack temp;
	ifstream myFile(filename12, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		temp.display();
	}
	myFile.close();
}
void deleteObject_FeedBack(string name) {
	Inventory temp;
	fstream myFile(filename12, ios::in | ios::out | ios::binary);
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
class Payment
{
private:
	int Balance = 5000;

public:
	void setBalance(int b)
	{
		Balance = b;
	}
	int getBalance()
	{
		return Balance;
	}
	int Deduction(int bill)
	{
		Balance -= bill;
		cout << endl << "Deduction Successfull!" << endl;
		return Balance;
	}
};
class JazzCash :public Payment
{

};
class DebitCard :public Payment
{

};
void shop_online(int Total_bill)
{
	int selection = 10;
	cout << endl;
	cout << endl;
	cout << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/" << endl;
	cout << endl;
	cout << endl;
	cout << "///////////////////// Please Select Payment Method /////////////////////////////" << endl;
	cout << "Press 1 for Cash on Delivery\nPress 2 for Online Transaction\n";
	cin >> selection;
	if (selection == 1)
	{
		char house[100];
		string city;
		cout << "----------Enter Your Address---------- " << endl;
		cout << "Enter house no. :" << endl;
		cin >> house;
		cout << "Enter City : " << endl;
		cin >> city;
		if (city == "Karachi")
		{
			Cart temp2;
			int totalBill = 0;
			bool foo = true;
			Inventory_Karachi temp4;
			ifstream myFil(filename6, ios::binary);
			ifstream myFile(filename10, ios::binary | ios::in);
			while (myFile.read((char*)&temp2, sizeof(temp2)))
			{
				if (foo)
				{
					while (myFil.read((char*)&temp4, sizeof(temp4))) {

						if (temp4.get_pro() == temp2.get_Product())
						{
							foo = true;
							break;
						}
						else
						{
							foo = false;
							break;
						}
					}
					myFile.close();
				}
			}
			myFile.close();
			if (foo)
			{
				Total_bill += 30;
				cout << "******************************************" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "*    Your Total Bill : Rs " << Total_bill << "\\-             *" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "******************************************" << endl;


			}
			else
			{
				Total_bill += 50;
				cout << "******************************************" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "*    Your Total Bill : Rs " << Total_bill << "\\-             *" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "******************************************" << endl;
			}
		}
		else if (city == "Islamabad")
		{
			Cart temp2;
			int totalBill = 0;
			bool foo = true;
			Inventory_Islamabad temp4;
			ifstream myFil(filename7, ios::binary);
			ifstream myFile(filename10, ios::binary | ios::in);
			while (myFile.read((char*)&temp2, sizeof(temp2)))
			{

				while (myFil.read((char*)&temp4, sizeof(temp4))) {

					if (temp4.get_pro() == temp2.get_Product())
					{
						foo = true;
					}
					else
					{
						foo = false;
						break;
					}
				}
				myFile.close();

			}
			myFile.close();
			if (foo)
			{
				FeedBack F1;
				char feedback[100];
				char select;
				Total_bill += 30;
				cout << "******************************************" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "*    Your Total Bill : Rs " << Total_bill << "\\-        *" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "******************************************" << endl;
				cout << "-------------- Wanna give Feedback -------------------" << endl;
				cout <<endl<< "Press Y or N" << endl;
				cin >> select;
				if (select == 'Y')
				{
					cin>>feedback;
					F1.setFeedback(feedback);
					insertObject_FeedBack(F1);
				}
				else if (select == 'N')
				{
					cout << endl << "------------------ Thanks a lot for Shopping --------------------" << endl;
					
				}

			}
			else
			{
				FeedBack F1;
				char feedback[100];
				char select;
				Total_bill += 50;
				cout << "******************************************" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "*    Your Total Bill : Rs " << Total_bill << "\\-        *" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "*                                        *" << endl;
				cout << "******************************************" << endl;
				cout <<endl<< "-------------- Wanna give Feedback -------------------" << endl;
				cout << "Press Y or N" << endl;
				cin >> select;
				if (select == 'Y')
				{
					cout << "Enter your feedback :";
					cin>>feedback;
					F1.setFeedback(feedback);
					insertObject_FeedBack(F1);
				}
				else if (select == 'N')
				{
					cout << endl << "------------------ Thanks a lot for Shopping --------------------" << endl;
				}
			}
		}
	}
	else if (selection == 2)
	{
	JazzCash J1;
	DebitCard D1;
	int pay = 0;
	cout << "Press 1 for Debit Card\nPress 2 for Jazz Cash\n";
	cin >> pay;
	if (pay == 1)
	{
		FeedBack F1;
		char feedback[100];
		char select;
		D1.Deduction(Total_bill);
		cout << "Remaining Balance is " << D1.getBalance() << "\-" << endl;
		cout << endl;
		cout << "-------------- Wanna give Feedback -------------------" << endl;
		cout << "Press Y or N" << endl;
		cin >> select;
		if (select == 'Y')
		{
			cout << "Enter your feedback :";
			cin>>feedback;
			F1.setFeedback(feedback);
			insertObject_FeedBack(F1);
		}
		else if (select == 'N')
		{
			cout << endl << "------------------ Thanks a lot for Shopping --------------------" << endl;
		}

	}
	else if (pay == 2)
	{
		FeedBack F1;
		char feedback[100];
		char select;
		J1.Deduction(Total_bill);
		cout << "Remaining Balance is " << J1.getBalance() << "\-" << endl;
		cout << endl;
		cout << "-------------- Wanna give Feedback -------------------" << endl;
		cout << "Press Y or N" << endl;
		cin >> select;
		if (select == 'Y')
		{
			cout << "Enter your feedback :";
			cin>>feedback;
			F1.setFeedback(feedback);
			insertObject_FeedBack(F1);
		}
		else if (select == 'N')
		{
			cout << endl << "------------------ Thanks a lot for Shopping --------------------" << endl;
		}
	}
	}


}

