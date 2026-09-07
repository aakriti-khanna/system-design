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

class DbPersistence{
private:
    ShoppingCart* cart;
public:
   virtual void save(ShoppingCart* cart)=0;
};

class SqlPersistence: public DbPersistence{
 public:
  void save (ShoppingCart* cart) override{
        cout<<"Saving this to our Sql DB ..."<< endl; 
    }
};
   
class MongoPersistence :public DbPersistence{
    public:
     void save (ShoppingCart* cart) override{
        cout<<"Saving this to our Mongo db  ..."<< endl; 
    }

};

  
class FilePersistence :public DbPersistence{
   public: 
   void save (ShoppingCart* cart) override{
        cout<<"Saving this to our file ..."<< endl; 
    }
    
};


int main(){
    cout << "Program Open substitution Followed started" << endl;
    ShoppingCart *cart= new ShoppingCart();
    cart->addProduct(new Product("laptop",100000));
    cart->addProduct(new Product("Mobile",150000));

    ShoppingCartPrinter *printer= new ShoppingCartPrinter(cart);
    printer-> printInvoice();

   DbPersistence*  db= new SqlPersistence();
   DbPersistence*  mongo= new MongoPersistence();
   DbPersistence*  file = new FilePersistence();

  db->save(cart);
  mongo->save(cart);
  file-> save(cart);
   return 0;


}