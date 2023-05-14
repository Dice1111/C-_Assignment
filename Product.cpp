#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;


class Product{
    private:
        string productName;
        string productID;
        string productCategory;
        int quantity;

    public:

        //constructor............
        Product(){};
        Product(string productName, string productID, string productCategory, int quantity){
            this->productName = productName;
            this->productID = productID;
            this->productCategory = productCategory;
            this->quantity = quantity;
        }

        //getter.................
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

        //setter...................
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

        //Display.......................
        void displayDetail(){
            cout << "Product Name: " << productName << "\n";
            cout << "Product ID: " << productID << "\n";
            cout << "Product Category: " << productCategory << "\n";
            cout << "Product Quantity: " << quantity << "\n";
        }

        virtual void display(){
            cout << endl << "All product: " << endl;  
            cout << "------------------------------" << endl;
            //Table Header...................
            cout << setw(20) << "Product Name";
            cout << setw(20) << "Product ID";
            cout << setw(20) << "Product Category";
            cout << setw(20) << "Quantity" << endl;
            ifstream inputFile("product.txt");
            string line;
            while(getline(inputFile, line)){
                istringstream oneline(line);
                string productName, productID, productCategory;
                int quantity;

                oneline >> productName >> productID >> productCategory >> quantity;  // Extract values from the stringstream
                //Table Row...................
                cout << setw(20) << productName;
                cout << setw(20) << productID;
                cout << setw(20) << productCategory;
                cout << setw(20) << quantity << endl;
            }  
        }

};


// inheritance polymorphism

class Electronics: public Product { //derived class
	public:
    void display() {
		cout << endl << "All product: " << endl;  
        cout << "------------------------------" << endl;
        //Table Header...................
        cout << setw(20) << "Product Name";
        cout << setw(20) << "Product ID";
        cout << setw(20) << "Product Category";
        cout << setw(20) << "Quantity" << endl;
        ifstream inputFile("product.txt");
        string line;
        while(getline(inputFile, line)){
            istringstream oneline(line);
            string productName, productID, productCategory;
            int quantity;

            oneline >> productName >> productID >> productCategory >> quantity;  // Extract values from the stringstream
    
            if(productCategory=="Electronics"){
                //Table Row...................
                cout << setw(20) << productName;
                cout << setw(20) << productID;
                cout << setw(20) << productCategory;
                cout << setw(20) << quantity << endl;
            }
            
        } 
	}
};
class Household: public Product {  //derived class
	public:
    void display() {
		cout << endl << "All product: " << endl;  
        cout << "------------------------------" << endl;
        //Table Header...................
        cout << setw(20) << "Product Name";
        cout << setw(20) << "Product ID";
        cout << setw(20) << "Product Category";
        cout << setw(20) << "Quantity" << endl;
        ifstream inputFile("product.txt");
        string line;
        while(getline(inputFile, line)){
            istringstream oneline(line);
            string productName, productID, productCategory;
            int quantity;

            oneline >> productName >> productID >> productCategory >> quantity;  // Extract values from the stringstream
    
            if(productCategory=="Household"){
                //Table Row...................
                cout << setw(20) << productName;
                cout << setw(20) << productID;
                cout << setw(20) << productCategory;
                cout << setw(20) << quantity << endl;
            }
            
        }
	}
};
class Furniture: public Product {  //derived class
	public:
    void display() {
		cout << endl << "All product: " << endl;  
        cout << "------------------------------" << endl;
        //Table Header...................
        cout << setw(20) << "Product Name";
        cout << setw(20) << "Product ID";
        cout << setw(20) << "Product Category";
        cout << setw(20) << "Quantity" << endl;
        ifstream inputFile("product.txt");
        string line;
        while(getline(inputFile, line)){
            istringstream oneline(line);
            string productName, productID, productCategory;
            int quantity;

            oneline >> productName >> productID >> productCategory >> quantity;  // Extract values from the stringstream
    
            if(productCategory=="Furniture"){
                //Table Row...................
                cout << setw(20) << productName;
                cout << setw(20) << productID;
                cout << setw(20) << productCategory;
                cout << setw(20) << quantity << endl;
            }
            
        }
	}
};


vector <Product> products; // resizableArray

void writeRecord(){
    ofstream myfile("product.txt");

	if (myfile.is_open()) {
        for(Product& product: products){
            myfile << product.getProductName() << " " << product.getProductID() << " " << product.getProductCategory() << " " << product.getQuantity() << "\n";
        }
        myfile.close();
		cout << "Writing file complete!";
	}
	else{
		cout << "Unable to open the file";
    }

}

void readRecord(){
    ifstream inputFile("product.txt");
    string line;
    while(getline(inputFile, line)){
        istringstream oneline(line);
        string productName, productID, productCategory;
        int quantity;
        oneline >> productName >> productID >> productCategory >> quantity;  // Extract values from the stringstream
        Product product(productName, productID, productCategory, quantity);
        products.push_back(product);
    }    
}

void createProduct(){
    string productName, productID, productCategory;
    int quantity;

    cout << "Enter Product Name: \n";
    cin >> productName;

    cout << "Enter Product ID: \n";
    cin >> productID;

    cout << "Enter Product Category: \n";
    cin >> productCategory;

    cout << "Enter quantity: \n";
    cin >> quantity;

    Product product(productName,productID,productCategory,quantity);
    products.push_back(product); // products = {obj,obj,obj,...}
    writeRecord();

}

void editProduct(){
    string name;
    cout << "Enter Produce name to edit: ";
    cin >> name;

    for(Product& product: products){
        if( name == product.getProductName()){
            product.displayDetail();
            char choice;
            cout << "1 for name" << endl;
            cout << "2 for id" << endl;
			cout << "3 for category" << endl;
			cout << "4 for quantity" << endl;

            cin >> choice;
            string newName,newID,newCategory;
            int newQuantity;
            switch (choice)
            {
                case '1':
                    cout << "Enter new name: \n";
                    cin >> newName;
                    product.setProductName(newName);
                    cout << "Name has been changed!" << endl;
                    break;

                case '2':
                    cout << "Enter new id: \n";
                    cin >> newID;
                    product.setProductID(newID);
                    cout << "ID has been changed!" << endl;
                    break;
                case '3':
                    cout << "Enter new Category: \n";
                    cin >> newCategory;
                    product.setProductCategory(newCategory);
                    cout << "Category has been changed!" << endl;
                    break;
                case '4':
                    cout << "Enter new quantity: \n";
                    cin >> newQuantity;
                    product.setQuantity(newQuantity);
                    cout << "Quantity has been changed!" << endl;
                    break;
                default:break;
               
            }
            writeRecord();
            return;
        }
    }
    cout << "Product not found!";
}   

void displayProductDetail(){
    string name;
    cout << "Enter Produce name to display: ";
    cin >> name;
    for(Product product: products){
        if(name == product.getProductName()){
            product.displayDetail();
            return;
        }
    }
    cout << "Product Not Found!" << endl;
}

void displayProductFromCategory(){
    Product product;
    Electronics electronics;
    Household household;
    Furniture furniture;


    char choice;
    cout << "1. Show all Product Data\n";
    cout << "2. Show all Electronics Product Data\n";
    cout << "3. Show all Household Product Data\n";
    cout << "4. Show all Furniture Product Data\n";
    cin >> choice;

    switch (choice)
    {
    case '1': product.display();break;
    case '2': electronics.display();break;
    case '3': household.display();break;
    case '4': furniture.display();break;
    default:break;
        
    }

}

void mainMenu(){
    char choice;
    do{
        cout << endl
             << "   MAIN MENU                                    \n"
             << "--------------------------------------------------\n"
             << "1. Add a new product to the file.\n"
             << "2. Modifies the details of an existing product.\n"
             << "3. Displays the product details from the file.\n"
             << "4. Displays all product from a category.\n"
             << "5. Exist\n"
             << "--------------------------------------------------"<<endl;
        cin >> choice;

        switch (choice){
            case '1': createProduct();break;
            case '2': editProduct();break;
            case '3': displayProductDetail();break;
            case '4': displayProductFromCategory();break;
            case '5': break;
            // default:
			// cout << "Not a vaild choice.\n"
			// 	 << "Choose again.\n";
			// break;
		}

    }while(choice != '5');
}






//Run.............................
int main(){
    readRecord();
    mainMenu(); 
    return 0;
}

