#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class shope {
public:
	void control_panel();
	void add_item();
	void show_item();
	void searchItem();
	void updateItem();
	void delItem();
};


void shope::control_panel()
{
	system("cls");
	cout << "\n\n\t\t\t\tCONTROL PANEL";
	cout << "\n\n1. ADD NEW ITEM";
	cout << "\n2. DISPLAY All ITEMS";
	cout << "\n3. CHECK PARTICULAR ITEM";
	cout << "\n4. UPDATE ITEM";
	cout << "\n5. DELETE ITEM";
	cout << "\n6. EXIT";
}

void shope::add_item()
{
	system("cls");
	fstream file;
	int no_copy, price;
	string i_name, company;
	cout << "\n\n\t\t\t\tADD Items";
	cout << "\n\n item name : ";
	cin >> i_name;
	cout << "\nWhich company : ";
	cin >> company;
	cout << "\nEnter no of copies : ";
	cin >> no_copy;
	cout << "\nEnter price : ";
	cin >> price;


	file.open("abc.txt",
			ios::out | ios::app);
	file << " " << i_name << " "<< company << " " << no_copy  << " " << price << "\n";
	file.close();
}

void shope::show_item()
{
	system("cls");
	fstream file;
	int no_copy, price;
	string i_name, company;
	cout << "\n\n\t\t\t\t\tAll ITEMS";


	file.open("abc.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\n\nItem name\tcompany" << "\t\tno_copy\t\tprice \n\n";
		file >>  i_name >> company;
		file >> no_copy >> price;


		while (!file.eof()) {

			cout << " " << i_name
				<< "\t\t" << company
				<< "\t\t" << no_copy
				<< "\t\t" << price
				<< "\n\n";
			file >> i_name >> company;
			file >> no_copy >> price;
		}

		system("pause");


		file.close();
	}
}


void shope::searchItem()
{
	system("cls");
	fstream file;
	int no_copy,price, count = 0;
   string i_name, company,iname;
	cout << "\n\n\t\t\t\tCheck "
		<< "Particular Item";


	file.open("abc.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nItem Name : ";
		cin >> iname;
           file >> i_name >> company;
			file >> no_copy >> price;
		while (!file.eof()) {

			if (iname == i_name) {

				system("cls");
				cout << "\n\n\t\t\t\t"
					<< "Check Particular Item";
				cout << "\n\nItem Name : "
					<< i_name;
				cout << "\nCompany : "
					<< company;
				cout << "\nNo of copies : "
					<< no_copy;
				cout << "\nprice : "
					<< price;
				cout << endl
					<< endl;
				count++;
				break;
			}
			 file >> i_name >> company;
			file >> no_copy >> price;
		}
		system("pause");
		file.close();
		if (count == 0)
			cout << "\n\nItem  Not"
				<< " Found...";
	}
}

void shope::updateItem()
{
	system("cls");
	fstream file, file1;
    int no_copy,ncopy, price,nprice,count = 0;
	string i_name,nname, company,ncompany;


	cout << "\n\n\t\t\t\tUpdate item Record";
	file1.open("tempo.txt",
			ios::app | ios::out);
	file.open("abc.txt", ios::in);

	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\n item name : ";
		cin >> nname;
       file >> i_name >> company;
        file >> no_copy >> price;
		// Till end of file is reached
		while (!file.eof()) {
			if (nname == i_name) {
				system("cls");
				cout << "\t\t\t\t" << "Update ITEM Record";
				cout << "\n\nNew Company Name : ";
				cin >> ncompany;
				cout << "\n New no Of copies : ";
				cin >> ncopy;
				cout << "\nNew price : ";
				cin >> nprice;
    file1 << " " << nname << " " << ncompany << " " << ncopy << " " << nprice << "\n\n";
				count++;
			}
			else
				file1 << " " << i_name << " " << company	<< " " << no_copy << " " << price << "\n\n";

		  file >> i_name >> company;
        file >> no_copy >> price;
		}
		if (count == 0)
			cout << "\n\nItem name"
				<< " Not Found...";
	}
	cout << endl;
	system("pause");

	// Close the files
	file.close();
	file1.close();
	remove("abc.txt");
	rename("tempo.txt" , "abc.txt");
}

void shope::delItem()
{
	system("cls");
	fstream file, file1;

	int no_copy, price,count = 0;
	string i_name, company,nname;

	cout << "\n\n\t\t\t\tDelete an ITEM";


	file1.open("tempo.txt",
			ios::app | ios::out);
	file.open("abc.txt",
			ios::in);

	if (!file)
		cout << "\n\nFile Opening Error...";
	else {

		cout << "\n\nItem Name : ";
		cin >> nname;
		 file >> i_name >> company;
        file >> no_copy >> price;
		while (!file.eof()) {

			if (nname == i_name) {

				system("cls");
				cout << "\n\n\t\t\t\t"
					<< "Delete an Item";
				cout << "\n\nItem is Deleted "
						"Successfully...\n\n";
				count++;
			}
			else
				file1 << " " << i_name << " " << company << " " << no_copy << " " << price << "\n\n";
			 file >> i_name >> company;
             file >> no_copy >> price;
		}
		if (count == 0)
			cout << "\n\nItem Name  "
				<< "Not Found...";
	}
	system("pause");


	file.close();
	file1.close();
	remove("abc.txt");
	rename("tempo.txt",
		"abc.txt");
}

void ShopRecord()
{
	int choice;
	char x;
	shope b;

	while (1) {

		b.control_panel();
		cout << "\n\nEnter your choice : ";
		cin >> choice;
		switch (choice) {

		case 1:
			do {

				b.add_item();
				cout << "\n\nWant to add"
					<< " another item? "
						"(y/n) : ";
				cin >> x;
			} while (x == 'y');
			break;

		case 2:
			b.show_item();
			break;

		case 3:
			b.searchItem();
			break;
		case 4:
			b.updateItem();
			break;

		case 5:
			b.delItem();
			break;

		case 6:
			exit(0);
			break;

		default:
			cout << "\n\nINVALID CHOICE\n";
		}
	}
}

int main()
{
	ShopRecord();

	return 0;
}
