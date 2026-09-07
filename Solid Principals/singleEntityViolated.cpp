#include <iostream>
#include <vector>
using namespace std;


class Product {
   public :
   string name;
   double price;

    Product (string name , double price ){
        this->name=name;
        this->price=price;

    }
};
// shopping cart is handling multiple responsibilities
class ShoppingCart {
    private: 
     vector<Product*> products;
    public:
    void addProduct( Product* p){
      products.push_back(p);
    }

    const vector<Product*> &getProducts(){
        return products;
    }

    double calculateTotal(){
        double total=0;
        for (auto p: products){
            total+= p->price;
        }
        return total;
    }


    void printInvoice(){
        cout<<"Shopping cart Invoice:\n"; 
        for (auto p:products){
            cout << p->name << "--$" <<p->price << endl;
        }
         cout<<"Total $"<<calculateTotal()<<endl;
    }

    void saveToDB(){
        cout<<"Saving this to our DB ..."<< endl; 
    }
};


int main(){
    ShoppingCart* cart=new ShoppingCart() ;

    cart-> addProduct( new Product("Laptop",5000));
    cart-> addProduct( new Product("Watch", 500));

    cart->printInvoice();
    cart->saveToDB();

    

    return 0;
}
// g++ ~/Documents/system-design/oops/inheritance.cpp -o inheritance
// ./inheritanc