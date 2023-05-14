
#include <iostream>
#include "Product.cpp"
#include <fstream>
using namespace std;

//global variable.................

string const PRODUCTS_FILE = "PRODUCT.txt";

vector<Product> products;
string productName,productID,productCategory;
int quantity;




void init(){
  Product product1("Calculator","P1001E","Electronics",10);
  Product product2("Vacuum_Cleaner","P1002E","Electronics",10);
  Product product3("Dinning_Table","P1003F","Furniture",5);
  Product product4("Bookshelf","P1004F","Furniture",0);
  Product product5("Pillow","P1005H","Household",100);
  Product product6("Cooking_Pot","P1006H","Household",75);
  products.push_back(product1);
  products.push_back(product2);
  products.push_back(product3);
  products.push_back(product4);
  products.push_back(product5);
  products.push_back(product6);

}

// void readFile(){
//   ifstream inputFile(PRODUCTS_FILE);
//   string line;
//   while(getline(inputFile, line)){
    
//   }
// }

void displayAll(){
  for(Product product:products){
    string productInfo = product.getProductName()+" "+product.getProductID()+" "+product.getProductCategory()+" "+to_string(product.getQuantity());
    cout<< productInfo+"\n";
  }
}

int main() { 
  fstream inFile("PRODUCT.txt", ios::in | ios::out);
  if(!inFile){
    init();
    ofstream MyDataFile(PRODUCTS_FILE,ios::app);
    for(Product product:products){
      MyDataFile << product.info()+"\n";
    }
    MyDataFile.close();
  }
  displayAll();
  cout << "Type product name: ";
  cin >> productName;

  cout << "Type product ID: ";
  cin >> productID;

  cout << "Type product Category: ";
  cin >> productCategory;

  cout << "Type product quantity: ";
  cin >> quantity;

  Product product(productName,productID,productCategory,quantity);

  product.display();

  ofstream MyFile("PRODUCT.txt",ios::app);

  MyFile << product.info()+"\n";

  products.push_back(product);
  return 0;
}





   