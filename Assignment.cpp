#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
#include <iomanip>
using namespace std;

class product {

private:
	string pID;
protected:
	string pCategory, pName;
	int quantity;
public:
	void input_product();
	void display_product();
	void writeRecord();
	void editRecord(string search);
	virtual void display();
};

// inheritance polymorphism
  

class Electronics: public product { //derived class
	void display() {
		cout << endl << "Electronic product: Printer,Hair_dryer,Vacuum_Cleaner,etc ";
	}
};
class Household: public product {  //derived class
	void display() {
		cout << endl << "Household products: Dishwasher,Washing_Machine,Refrigerator,etc";
	}
};
class Furniture: public product {  //derived class
	void display() {
		cout << endl << "Furniture: Couch,Shelvesardrobe,etc ";
	}
};

void product::display() {
	cout << "____________________";
}
void product::input_product() {
	cout << "(1)Please write down the product name\n ";
	cin >> pName;

	cout << "(2)Please write down the product ID\n";
	cin >> pID;

	cout << "(3)Please write down the type of the product (Electronics,Household and Furniture)\n";
	cin >> pCategory;

	cout << "(4)Please write down the quantity on hand of the product\n";
	cin >> quantity;
}


void product::display_product() {
	cout << "Product Name :" << pName << endl;
	cout << "Product ID :" << pID << endl;
	cout << "Product Category :" << pCategory << endl;
	cout << "Quantity on hand:" << quantity << endl;
}


void product::writeRecord() {
	ofstream myfile("product.txt", ios::app);

	if (myfile.is_open()) {
		myfile << pName << " " << pID << " " << pCategory<< " " << quantity << "\n";
		myfile.close();
		cout << "Writing file complete!";
	}
	else
		cout << "Unable to open the file";
}

void product::editRecord(string search) {
	fstream inFile("product.txt", ios::in | ios::out);
	string myArray[4], testStr, line;
	size_t pos; //size of object in memory
	bool control = false;

	//inflie.is_open ();
	if (!inFile) {
		cout << "Unable to open the file" << endl;
		//exit(1); 
	}

	while (inFile.good()) {
		getline(inFile, line);
		pos = line.find(search);
		/*
		returns the position of the first occurrence of a substring within a string, or string :: npos if the substring is
		not found
		*/

		if (pos != string::npos) { // the maximum value of the size_t type 
			control = true;
			cout << "We found the following data you want!" << endl;
			cout << line << "\n";

			stringstream ss(line);
			// the provides a way to read and write string as if they were input /output streams
			int i = 0;
			while (getline(ss, testStr, ' ')) {
				myArray[i] = testStr;
				i++;
			}
			for (int i=0 ;i<4; i++){
			cout<< endl<<myArray [i]<<endl;}
			
			char control;
			cout << "1 for name" << endl;
			cout << "2 for category" << endl;
			cout << "3 for quantity" << endl;

			cin >> control;
			switch (control) {
			case '1':
				cout << "Enter name" << endl; cin >> myArray[0];break;
			case '2':
				cout << "Enter id" << endl; cin >> myArray[2];break;
			case '3':
				cout << "Enter quantity" << endl; cin >> myArray[3]; break;
			}
			inFile.close();
			break;
		}
	}


	if (control == false)cout << " not found" << endl;
	ifstream file;
	ofstream outfile;
	string lineN;

	file.open("product.txt");
	outfile.open("newP.txt", ios::app);

	while (getline(file, lineN)) {
		if ((lineN.find(search)) == string::npos)
			outfile << lineN << endl;
		else {
			outfile << myArray[0] << " " << myArray[1] << " " << myArray[2] << " " << myArray[3] << endl;
		}
	}
	outfile.close();
	file.close();
	remove("product.txt");
	rename ("newP.txt", "product.txt");
}



int main(){
	void addProduct();
	void displayProduct();
	void editProduct();
	char choice;
	product p, * ppointer;
	Electronics E;
	Household H;
	Furniture F;
	do {
		cout << endl
			<< "        Audrey Products                \n"
			<< "____________________________________________________\n"
			<< "Enter 1 to add a new product to file.\n"
			<< "Enter 2 to modifiles the detail of an existig product.\n"
			<< "Enter 3 to edit the product details from the file.\n"
			<< "Enter 4 to display about the product story.\n"
			<< "Enter 5 to end this program.\n"
			<< "_______________________________________________________"<<endl;
		cin >> choice;
		switch (choice) {
		case '1':
			addProduct();
			break;
		case '2':
			editProduct();
			break;
		case '3':
			displayProduct();
		case '4':
			ppointer = &p;
			ppointer->display();
			ppointer = &E;
			ppointer->display();
			ppointer = &H;
			ppointer->display();
			ppointer = &F;
			ppointer->display();
			break;

		case '5':
			cout << endl << "This is the Ending of the program" << endl;
			cout << endl << "Thank You...." << endl;
			break;
		default:
			cout << "Not a vaild choice.\n"
				<< "Choose again.\n";
			break;
		}
	} while (choice != '5');
	return 0;
}

void addProduct() {
	product p;
	cout << "Input data" << endl;
	p.input_product();
	p.writeRecord();
}

void displayProduct() {
	string data, temp[4];
	ifstream myfile;

	myfile.open("product.txt");

	cout << "Displaying all the products data" << endl;

	while (true) {
		for (int i = 0; i < 3; i++)
			myfile >> temp[i];

		if (myfile.eof()) break;
		cout << "__________________________________" << endl;
		cout << "Name ::"<<right << setw(0) << endl;
		cout << "ID   :: "<<right << setw(0) << endl;
		cout << "Type :: "<<right << setw(0)  << endl;
	}

	myfile.close();
}
void editProduct() {
	product p;
	string search;
	cout << "Enter word to search for :";
	cin >> search;

	p.editRecord(search);
}
		
	
