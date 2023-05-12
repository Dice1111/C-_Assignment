#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Product {       
  private:             
    string productName;        
    string productID;  
    string productCategory;
    int quantity;

  public:  
    //Constructor...............
    Product(string productName,string productID, string productCategory, int quantity){
        this->productName = productName;
        this->productID = productID;
        this->productCategory = productCategory;
        this->quantity = quantity;
    }

    //Getter....................
    string getProductName(){
        return productName;
    }

    string getProductID(){
        return productID;
    }

    string getProductCategory(){
        return productCategory;
    }

    int getQuantity(){
        return quantity;
    }

    //Setter......................
    void setProductName(string productName){
        this->productName = productName;
    }

    void setProductID(string productID){
        this->productID = productID;
    }

    void setProductCategory(string productCategory){
        this->productCategory = productCategory;
    }

    void setQuantity(int quantity){
        this->quantity = quantity;
    }

    //display.......................

    void display(){
        string productInfo = productName+" "+productID+" "+productCategory+" "+to_string(quantity);
        cout<< productInfo;
    }

    string info(){
      string info = productName+" "+productID+" "+productCategory+" "+to_string(quantity);
      return info;
    }
};

// int main() {
//     // const int numProducts = 10;s
    
//     vector<Product> products;
//     string productName,productID,productCategory;
//     int quantity;

//     cout << "Type product name: ";
//     cin >> productName;

//     cout << "Type product ID: ";
//     cin >> productID;

//     cout << "Type product Category: ";
//     cin >> productCategory;

//     cout << "Type product quantity: ";
//     cin >> quantity;


//     Product product(productName,productID,productCategory,quantity);

//     product.display();

//     ofstream MyFile("PRODUCT.txt");

//     MyFile << product.info()+"\n";

//     products.push_back(product);
   
//     return 0;
// }










