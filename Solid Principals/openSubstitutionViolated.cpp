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

class ShoppingCart{
    private:
    vector<Product*> products;
    public: 
    void addProduct(Product *p){
        products.push_back(p);
    }
    const vector<Product*>& getProducts(){
        return products;
    }

  
    double calculateTotal(){
        double total=0;
        for (auto p : products){
            total+=p->price;

        }
        return total;
    }

};

class ShoppingCartPrinter {
    private:
    ShoppingCart* cart;
    public: 
    
    ShoppingCartPrinter(ShoppingCart* cart){
       this->cart=cart;
    }
    
    void printInvoice(){
        cout<<"Shopping cart Invoice:\n"; 
        for (auto p :cart->getProducts()){
            cout << p->name << "--$" <<p->price << endl;
        }
         cout<<"Total $"<<cart->calculateTotal()<<endl;
    }


};

class ShoppingCartDb{
private:
    ShoppingCart* cart;
public:
    ShoppingCartDb(ShoppingCart* cart){
       this->cart=cart;
    }

    void saveToSql(){
        cout<<"Saving this to our Sql DB ..."<< endl; 
    }

    void saveToMongoDb(){
        cout<<"Saving this to our Mongo db  ..."<< endl; 
    }


    void saveToFile(){
        cout<<"Saving this to our file ..."<< endl; 
    }
    
};


int main(){
    cout << "Program Open substitution Violated" << endl;
    ShoppingCart *cart= new ShoppingCart();
    cart->addProduct(new Product("laptop",100000));
    cart->addProduct(new Product("Mobile",150000));

    ShoppingCartPrinter *printer= new ShoppingCartPrinter(cart);
    printer-> printInvoice();

   ShoppingCartDb *saveData=new ShoppingCartDb(cart);
   saveData->saveToMongoDb();
   saveData->saveToFile();
   saveData-> saveToSql();
   return 0;


}