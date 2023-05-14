#include <iostream>
#include<fstream>
#include<string>
#include <sstream>

using namespace std;

class student {

private :
	string snum;
protected:
	string stype, sname;
	int mark;
public:
	void input_student();
	void display_student();
	void writeRecord();
	void editRecord(string search);
	virtual void display();

};
//inheritance and polymorphism
class fullTimeStudent : public student {
	void display() {
		cout << endl << "Welcome to Full Time Student";
	}
};
class partTimeStudent : public student {
	void display() {
		cout << endl << "Welcome to Part Time Student";
	}
};
void student::display() {
	cout << "Welcome to our BUC student";
}
void student::input_student() {
	cout << "Student Name: ";
	cin >> sname;

	cout << "Student number:";
	cin >> snum;

	cout << "Student Type (Full-time or part time):";
	cin >> stype;

	cout << "Marks";
	cin >> mark;
}
void student::display_student() {
	cout << "Student Name :" << sname << endl;
	cout << "Student Number :" << snum << endl;
	cout << "Student Type :" << stype << endl;
	cout << "Marks :" << mark << endl;
}
void student::writeRecord() {
	ofstream myfile("student.txt", ios::app);

	if (myfile.is_open()) {
		myfile << sname << "" << snum << "" << stype << "" << mark << "\n";
		myfile.close();
		cout << "Write file complete!";
	}
	else
		cout << "Unable to open file";
} 
void student::editRecord(string search) {
	fstream inFile("student.txt", ios::in | ios::out);
	string myArray[4], testStr, line;
	size_t pos; //size of object in memory
	bool control = false;

	//inflie.is_open ();
	if (!inFile) {
		cout << "Unable to open file" << endl;
		exit(1);
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
			cout << "We found the following data!" << endl;
			cout << line << '/n';

			stringstream ss(line);
			// the provides a way to read and write string as if they were input /output streams
			int i = 0;
			while (getline(ss, testStr, ' ')) {
				myArray[i] = testStr;
				i++;
			}
			/*
			for (int i=0 ;i<4; i++){
			cout<< endl<<myArray [i]<<endl;}
			*/
			char control;
			cout << "1 for name" << endl;
			cout << "2 for type" << endl;
			cout << "3 for credit" << endl;

			cin >> control;
			switch (control) {
			case '1':
				cout << "Enter name" << endl; cin >> myArray[0];break;
			case'2':
				cout << "Enter type" << endl; cin >> myArray[2];break;
			case'3':
				cout << "Enter credit" << endl; cin >> myArray[3]; break;
			}
			inFile.close();
			break;
		}
	}
	if (control == false)cout << "not found" << endl;
	ifstream file;
	ofstream outfile;
	string lineN;

	file.open("student.txt");
	outfile.open("newS.txt", ios::app);

	while (getline(file, lineN)) {
		if ((lineN.find(search)) == string::npos)
			outfile << lineN << endl;
		else {
			outfile << myArray[0] << " " << myArray[1] << " " << myArray[2] << " " << myArray[3] << endl;
		}
	}
	outfile.close();
	file.close();
	remove("student.txt");
	rename("newS.txt", "student.txt");
}
int main()
{
	void addStudent();
	void displayStudent();
	void editStudent();
	char choice;
	student s, * spointer;
	fullTimeStudent fts;
	partTimeStudent pts;

	do {
		cout << endl
			<< "Choose 1 to add the new student.\n"
			<< "Choose 2 to edit the student info.\n"
			<< "Choose 3 to display student detials.\n"
			<< "Choose 4 to display welcome message.\n"
			<< "Choose 5 to exit this program.\n";
		cin >> choice;
		switch (choice) {
		case '1':
			addStudent();
			break;
		case '2':
			editStudent();
			break;
		case '3':
			displayStudent();
		case '4':
			spointer = &s;
			spointer->display();
			spointer = &fts;
			spointer->display();
			spointer = &pts;
			spointer->display();
			break;

		case '5':
			cout << endl << "End of Program " << endl;
			break;
		default:
			cout << "Not a vaild choice.\n"
				<< "Choose again.\n";
			break;
		}
	} while (choice != '5');
	return 0;
}
void addStudent() {
	student s;
	cout << "Input data" << endl;
	s.input_student();
	s.writeRecord();
}
void displayStudent() {
	string data, temp[4];
	ifstream myfile;

	myfile.open("student.txt");

	cout << "Displaying all students data" << endl;

	while (true) {
		for (int i = 0; i < 4; i++)
			myfile >> temp[i];

		if (myfile.eof()) break;

		cout << "Name :\t" << temp[0] << endl;
		cout << "ID: \t" << temp[1] << endl;
		cout << "Type : \t" << temp[3] << endl;
		cout << "----------------------------------" << endl;
	}
	myfile.close();
}
void editStudent() {
	student s;
	string search;
	cout << "Enter word to search for :";
	cin >> search;

	s.editRecord(search);

}
