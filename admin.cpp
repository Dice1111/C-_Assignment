
#include <iostream>
#include "Product.cpp"
#include <fstream>
using namespace std;

int main() {  
    vector<Product> products;
    string productName,productID,productCategory;
    int quantity;

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

    ofstream MyFile("PRODUCT.txt");

    MyFile << product.info()+"\n";

    products.push_back(product);
    return 0;
}  
   