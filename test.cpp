

#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include<sstream>

int main(){
    string str = "apple 1 fruit 100";
    istringstream ss(str);
    string name;
    string id;
    string category;
    int quantity;
    ss >> name >> id >> category >>quantity;  // Extract values from the stringstream
    cout << "Extracted values: " << name << ", " << id << ", " << category << ", "<< quantity << endl;
}




