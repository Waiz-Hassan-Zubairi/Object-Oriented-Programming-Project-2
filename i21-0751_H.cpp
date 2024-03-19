//Name : Waiz Zubairi
//Roll no. i210751
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
#include"time.h"
#include<chrono>
#include<iomanip>
using namespace std;


bool Cnic_check(string c)
{
	if (c.length() == 13)
	{
		return false;
	}
	return true;
}
bool OnlyNumberCheck(string n)
{
	bool noCheck = true;

	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] >= '0' && n[i] <= '9')
		{
			noCheck = false;
		}
		else {
			noCheck = true;
			break;
		}
	}
	return noCheck;
}
bool upperCaseCheck(string p)
{

	bool passwordCheck2 = true;
	for (int i = 0; i < p.length(); i++)
	{
		if (p[i] >= 'A' && p[i] <= 'Z') {
			passwordCheck2 = false;
			break;
		}
		else
		{
			passwordCheck2 = true;
		}
	}
	return passwordCheck2;
}
bool Password_check(string p)
{
	if (p.length() >= 9)
	{
		return false;
	}
	return true;
}
bool numberCheck(string n)
{

	bool passwordCheck1 = true;
	for (int i = 0; n[i] != '\0'; i++)
	{
		if (isdigit(n[i]))
		{
			passwordCheck1= false;
			break;
		}
	       passwordCheck1= true;
	}
	return passwordCheck1;

}


int main()
{


	string name;
	string cnic;
	string password;
	string Cpassword;
	string location;
	int Start_time = 0;
	int End_time = 0;
	int Total_time = 0;
	int choice = 0;
	int Revenue = 0;
	int Admin_option = 0,Manager_Option=0,Customer_option=0;
	bool flag = false;
	while (1)
	{   //////////////////////////////////
		//Start
		/////////////////////////////////
		cout << "---------------------Welcome to New Age Grocery Store--------------------" << endl;
		cout << "Press 1 if you are Admin : \nPress 2 if you are Manager : \nPress 3 if you are Customer : \nPress 0 if you want to exit\n";
		cin >> choice;

		if (choice == 1)
		{
			cout  << "---------------------------------Welcome to Admin Panel----------------------------------\n";
			while (1)
			{
				Admin A1;
				//insertObject_Admin(A1);
				cout << "---LOGIN---\n";
				cout << "Enter your name : ";
				cin >> name;
				cout << "Enter your password : ";
				cin >> password;
				flag=verify_Admin(name, password);
				if (flag)
				{
					while (1)
					{
						cout << setw(40) << "Welcome Admin " << endl;
						cout << setw(40) << "Press 1 to Register Manager" << endl;
						cout << setw(40) << "Press 2 to Register Customer" << endl;
						cout << setw(40) << "Press 3 to Remove Manager" << endl;
						cout << setw(40) << "Press 4 to Remove customer " << endl;
						cout << setw(40) << "Press 5 to add in Catalogue " << endl;
						cout << setw(40) << "Press 6 to remove in Catalogue_Catagory " << endl;
						cout << setw(40) << "Press 7 to remove in Catalogue_Catagory_Object " << endl;
						cout << setw(40) << "Press 8 to Update Catalogue Catagory_Object " << endl;
						cout << setw(40) << "Press 9 to view Catalogue " << endl;
						cout << setw(40) << "Press 10 to view all Manager " << endl;
						cout << setw(40) << "Press 11 to view all FeedBack " << endl;
						cout << setw(40) << "Press 12 to Delete a FeedBack " << endl;
						cout << setw(40) << "Press 13 to Check Time Duration of Customers " << endl;
						cout << setw(40) << "Press 14 to Logout "<< endl;
						cin >> Admin_option;
						if (Admin_option == 1)
						{
							cout << "Enter Manager's Name : ";
							cin >> name;

							cout << "Enter Manager's CNIC : ";
							cin >> cnic;
							while (Cnic_check(cnic))
							{
								cout << "CNIC should be 13 digits : ";
								cin >> cnic;
							}
							while (OnlyNumberCheck(cnic))
							{
								cout << "CNIC should only be numbers : ";
								cin >> cnic;
							}
							cout << "Enter Password : ";
							cin >> password;
							while (Password_check(password))
							{
								cout << "Passwrod should atleast 9 digits : ";
								cin >> password;
							}
							while (upperCaseCheck(password))
							{
								cout << "Passwrod should contain Upper Case : ";
								cin>>password;

							}
							while (numberCheck(password))
							{
								cout << "Passwrod should contain atleast one number : ";
								cin >> password;

							}


							cout << "Confirm Password : ";
							cin >> Cpassword;
							if (Cpassword != password)
							{
								while (password != Cpassword)
								{
									cout << "Password not matched type again : ";
									cin >> Cpassword;
								}
							}
							if (password == Cpassword)
							{

								cout << "Enter Location : ";
								cin >> location;
								Manager M1;
								M1.setName(name);
								M1.setCnic(cnic);
								M1.setPassword(password);
								M1.setPlace(location);
								insertObject_Manager(M1);
							}

							
						}
						else if (Admin_option == 2)
						{

						cout << "Enter Customer's Name : ";
						cin >> name;

						cout << "Enter Customer's CNIC : ";
						cin >> cnic;
						while (Cnic_check(cnic))
						{
							cout << "CNIC should be 13 digits : ";
							cin >> cnic;
						}
						while (OnlyNumberCheck(cnic))
						{
							cout << "CNIC should only be numbers : ";
							cin >> cnic;
						}
						cout << "Enter Password : ";
						cin >> password;
						while (Password_check(password))
						{
							cout << "Passwrod should atleast 9 digits : ";
							cin >> password;
						}
						while (upperCaseCheck(password))
						{
							cout << "Passwrod should contain Upper Case : ";
							cin >> password;

						}
						while (numberCheck(password))
						{
							cout << "Passwrod should contain atleast one number : ";
							cin >> password;

						}


						cout << "Confirm Password : ";
						cin >> Cpassword;
						if (Cpassword != password)
						{
							while (password != Cpassword)
							{
								cout << "Password not matched type again : ";
								cin >> Cpassword;
							}
						}
						if (password == Cpassword)
						{

							cout << "Enter Location : ";
							cin >> location;
							Customer C1;
							C1.setName(name);
							C1.setCnic(cnic);
							C1.setPassword(password);
							insertObject_Customer(C1);
						}
						}
						else if (Admin_option == 3)
						{
						cout << "Enter Manager Name : ";
						cin >> name;
						cout << "Enter CNIC of Manager : ";
						cin >> cnic;
						deleteObject_Manager(name, cnic);

						}
						else if (Admin_option == 4)
						{
						cout << "Enter Customer's Name : ";
						cin >> name;
						cout << "Enter CNIC of Customer : ";
						cin >> cnic;
						deleteObject_Customer(name, cnic);
						}
						else if (Admin_option == 5)
						{
						Product_Catalogue PC1;
						cout << "Enter Catagory Name : ";
						cin >> name;
						PC1.set_Type1(name);
						cout << "Enter 1st Product Name : ";
						cin >> name;
						PC1.set_T1P1(name);
						cout << "Enter 2nd Product Name : ";
						cin >> name;
						PC1.set_T1P2(name);
						insertObject_Catalogue(PC1);
						}
						else if (Admin_option == 6)
						{
						cout << "Enter Catagory Name : ";
						cin >> name;
						deleteObject_Catalogue_Catagory(name);
						}
						else if (Admin_option == 7)
						{
						cout << "Enter Catagory's Object Name : ";
						cin >> name;
						deleteObject_Catalogue_Catagory_Object(name);
						}
						else if (Admin_option == 8)
						{
						string name2;
						cout << "Enter Product's Name you want to change : ";
						cin >> name;
						cout << "Enter New Name : ";
						cin >> name2;
						updateObject_Catalogue_Catagory(name,name2);
						}
						else if (Admin_option == 9)
						{
						retrieveAll_Product_Catalogue();
						}
						else if (Admin_option == 10)
						{
						retrieveAll_Manager();
						}
						else if (Admin_option == 11)
						{
						retrieveAll_FeedBack();
						}
						else if (Admin_option == 12)
						{
						char feed[100];
						cout << "Enter feedBack you want to remove : ";
						cin >> feed;
						deleteObject_FeedBack(feed);
						}
						else if (Admin_option == 13)
						{
						retrieveAll_Time();
						}
						else if (Admin_option == 14)
						{
						break;
						}
					}
					break;
				}
				else
				{
				cout << setw(40) << "Wrong Credentials! " << endl << setw(40) << "Login Again" << endl;
				}
			}
		}
		else if (choice == 2)
		{
			cout<< "---------------------------------Welcome to Manager Panel---------------------------------\n";
			while (1)
			{
					cout << "---LOGIN---\n";
					cout << "Enter your name : ";
					cin >> name;
					cout << "Enter your password : ";
					cin >> password;
					cout << "Enter your location : ";
					cin >> location;
					flag = verify_Manager(name, password, location);
				
					if (flag)
					{
						if (location == "Islamabad")
						{
							int p_option = 0;
							while (1)
							{
								Inventory_Karachi Ik;
								int price = 0;
								int quan=0;
								cout << "/////////////////////WELCOME TO ISLAMABAD INVENTORY////////////////////////////" << endl<<endl;
								cout << "Press 1 to add Product \nPress 2 to remove Product\nPress 3 to update product\nPress 4 to view Inventory\nPress 5 to search product\nPress 6 to see Karachi's Store Inventory \nPress 7 to search Product in Karachi's Inventory\nPress 8 to Logout\n";
								cin >> p_option;
								if (p_option == 1)
								{
									Inventory I1;

									cout << "Enter Product name : ";
									cin >> name;
									cout << "Enter Product Price : ";
									cin >> price;
									cout << "Enter PRoduct Quantity : ";
									cin >> quan;
									I1.set_pro(name);
									I1.set_pric(price);
									I1.set_quantity(quan);
									insertObject_Product(I1);
								}
								if (p_option == 2)
								{
									cout << "Enter Product name : ";
									cin >> name;
									deleteObject_Product(name);
								}
								if (p_option == 3)
								{
									int quantity = 0;
									char name2[100];
									cout << "Enter Product's Name you want to change : ";
									cin >> name;
									cout << "Enter new name : ";
									cin >> name2;
									cout << "Enter new price : ";
									cin >> price;
									cout << "Enter Quantity :";
									cin >> quantity;
									updateObject_Product(name, name2, price,quantity);
								}
								if (p_option == 4)
								{
									retrieveAll_Product();
								}
								if (p_option == 5)
								{
									cout << "Enter Product's Name you want to See : ";
									cin >> name;
									retrieveObject_Product(name);
								}
								if (p_option == 6)
								{
									retrieveAll_Product_karachi();
								}
								if (p_option == 7)
								{
									cout << "Enter Product's Name you want to See : ";
									cin >> name;
									retrieveObject_Product_karachi(name);
								}
								if (p_option == 8)
								{
									break;
								}
							}
						}
						else if (location == "Karachi")
						{
							int p_option1 = 0;
							while (1)
							{
								int price = 0;
								int quantity = 0;
								cout << "/////////////////////WELCOME TO KARACHI INVENTORY////////////////////////////" << endl << endl;
								cout << "Press 1 to add Product \nPress 2 to remove Product\nPress 3 to update product\nPress 4 to view Inventory\nPress 5 to search product\nPress 6 to see Islamabad's Store Inventory \nPress 7 to search Product in Islamabad's Inventory\nPress 8 to Logout\n";
								cin >> p_option1;
								if (p_option1 == 1)
								{
									Inventory_Karachi I2;

									cout << "Enter Product name : ";
									cin >> name;
									cout << "Enter Product Price : ";
									cin >> price;
									cout << "Enter PRoduct Quantity : ";
									cin >> quantity;
									I2.set_pro(name);
									I2.set_pric(price);
									I2.set_quantity(quantity);
									insertObject_Product_karachi(I2);
								}
								if (p_option1 == 2)
								{
									cout << "Enter Product name : ";
									cin >> name;
									deleteObject_Product_karachi(name);
								}
								if (p_option1 == 3)
								{
									int quantity = 0;
									char name2[100];
									cout << "Enter Product's Name you want to change : ";
									cin >> name;
									cout << "Enter new name : ";
									cin >> name2;
									cout << "Enter new price : ";
									cin >> price;
									cout << "Enter Quantity :";
									cin >> quantity;
									updateObject_Product_karachi(name, name2, price,quantity);
								}
								if (p_option1 == 4)
								{
									retrieveAll_Product_karachi();
								}
								if (p_option1 == 5)
								{
									cout << "Enter Product's Name you want to See : ";
									cin >> name;
									retrieveObject_Product_karachi(name);
								}
								if (p_option1 == 6)
								{
									retrieveAll_Product();
								}
								if (p_option1 == 7)
								{
									cout << "Enter Product's Name you want to See : ";
									cin >> name;
									retrieveObject_Product(name);
								}
								if (p_option1 == 8)
								{
									break;
								}
							}
						}

					}
					else
					{
						cout << setw(40) <<endl<< "Wrong Credentials! " << endl << setw(40) << "Login Again" << endl;
					}
					break;
			}

		}
		else if (choice == 3)
		{
			int c = 0;
			cout << "---------------------------------Welcome to Customer Panel---------------------------------\n";
			
			while (1)
			{
				cout << "Press 1 for Login \nPress 2 for registration\nPress 3 to Logout " << endl;
				cin >> c;
				if (c == 1)
				{
					//Customer C1;
					//insertObject_Customer(C1);
					cout << "Enter your name :";
					cin >> name;
					cout << "Enter your password :";
					cin >> password;
					flag = verify_Customer(name, password);
					if (flag)
					{
						/////////////////////////////////////
						/////Starting Time//////////////////
						auto start = std::chrono::system_clock::now();
						////////////////////////////////////
						///////////////////////////////////
						cout << endl;
						cout << endl;
						cout << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/" << endl;
						cout << endl;
						cout << endl;

						cout << "Product's Name     Product's Quantity     Product's Price" << endl;
						retrieveAll_Product_karachi();

						cout << endl;
						cout << endl;
						cout << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/" << endl;
						cout << endl;
						cout << endl;

						cout << "Product's Name     Product's Quantity     Product's Price" << endl;
						retrieveAll_Product();
						
						cout << endl;
						while (1)
						{
							int select;

							cout << "Press ""1"" to continue \nPress ""2"" to View Your Cart \nPress ""3"" to remove from cart\nPress ""4"" to clear Cart \nPress ""5"" to Logout \nPress ""0"" to Checkout " << endl;
							cin >> select;

							if (select == 1)
							{
								
								int quantity;
								cout << "Enter Prodct Name  ";
								cin >> name;
								cout << "Enter Prodct's Quantity ";
								cin >> quantity;
								addToCart(name, quantity);

							}
							else if (select==2)
							{
								retrieveAll_Cart();
							}
							else if (select ==3)
							{
								cout << "Enter product name : ";
								cin >> name;
								deleteObject_Product_cart(name);
							}
							else if(select==0)
							{
								
								Revenue += calculateBill();
								cout <<"Total bill is : Rs " << calculateBill()<<"\\-" << endl;
								shop_online(Revenue);
								
							}
							else if (select == 4)
							{
								Clear_cart();
							}
							else if (select == 5)
							{
								Time T1;
								
								// Some computation here
								auto end = std::chrono::system_clock::now();
								////// Time Ending 
								std::chrono::duration<double> elapsed_seconds = end - start;
								std::time_t end_time = std::chrono::system_clock::to_time_t(end);
								Total_time = elapsed_seconds.count();
								T1.setSeconds(Total_time);
								T1.setNaam(name);
								insertObject_Time(T1);
								std::cout << "Total time : " << elapsed_seconds.count() << "s" <<endl;

								break;
							}
						}
						break;
					}
					else
					{
						cout << setw(40) << "Wrong Credentials! " << endl ;
					}


				}
				else if (c == 2)
				{
					cout << "Enter your Name : ";
					cin >> name;

					cout << "Enter your CNIC : ";
					cin >> cnic;
					while (Cnic_check(cnic))
					{
						cout << "CNIC should be 13 digits : ";
						cin >> cnic;
					}
					while (OnlyNumberCheck(cnic))
					{
						cout << "CNIC should only be numbers : ";
						cin >> cnic;
					}
					cout << "Enter Password : ";
					cin >> password;
					while (Password_check(password))
					{
						cout << "Passwrod should atleast 9 digits : ";
						cin >> password;
					}
					while (upperCaseCheck(password))
					{
						cout << "Passwrod should contain Upper Case : ";
						cin >> password;

					}
					while (numberCheck(password))
					{
						cout << "Passwrod should contain atleast one number : ";
						cin >> password;

					}


					cout << "Confirm Password : ";
					cin >> Cpassword;
					if (Cpassword != password)
					{
						while (password != Cpassword)
						{
							cout << "Password not matched type again : ";
							cin >> Cpassword;
						}
					}
					if (password == Cpassword)
					{

						cout << "Enter Location : ";
						cin >> location;
						Customer C1;
						C1.setName(name);
						C1.setCnic(cnic);
						C1.setPassword(password);
						insertObject_Customer(C1);
					}
					else
					{
						cout << "Invalid Option select again.";
					}
				}
				else if (c == 3)
				{
					break;
				}
				break;
			}
		}
		else if (choice==0)
		{
			cout << "----------------Good Bye Dear User-----------------------\n";
			break;
		}
	}
}