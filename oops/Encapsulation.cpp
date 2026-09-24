#include <iostream>
using namespace std;

// Enacpsulation 
// provides data security using access modifiers
// and can acess by using getter func & setter func



// No need of creating a Parent class in  Encapsulation 

// class Car{
//     public :
//     virtual void startEngine() =0;
//     virtual void shiftGear( int gear) =0;
//     virtual void accelerate() =0;
//     virtual void brake() =0; 
//     virtual void stopEngine() =0;
//     virtual ~Car() {};

// };


//   Encapsulation  Class
// Encapsulation means wrapping data (variables) and the methods that operate on that data inside a class,
//  while restricting direct access to the data.

// Like we use in env variables in ecomm code by using of getter function to fetch the var
// and if we need to change the value we use setter functions but with certain validations
class SuperCar {
    // change this to Private since we can't directly access these parameter
 private: 
  
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre;
    //  used constructor for the same
public:
//  these are methods which have been implemented
    SuperCar ( string b,  string m) {
     this->brand=b;
     this->model=m;
     isEngineOn=false;
     currentSpeed=0;
     currentGear=0;
     tyre="MRF";

    }

void startEngine(){
    isEngineOn=true;
    cout<<brand << " " <<model <<" Engine : starts  "<<'\n';

}

int getCurrentSpeed(){
    return this->currentSpeed;
}

string  getTyre(){
 return this->tyre;
}

void setTyre(string tyre){
    this->tyre = tyre;
}

void shiftGear(int gear){
    if (!isEngineOn){
    cout<<brand << " " <<model <<" Engine : can't shift gear "<<'\n';
    }
    currentGear=gear;
    cout<<brand << " " <<model <<" shifted gear"<<'\n';

}
void accelerate(){
    if (!isEngineOn){
     cout<<brand << " " <<model <<" can't accelerate "<<'\n';
    }
    currentSpeed+=20;

  cout<<brand << " " <<model <<" : Accelerate to " << currentSpeed <<"km/h" << '\n';
}

void brake(){
     currentSpeed-=20;
     if (currentSpeed<0){
        currentSpeed=0;
     }
      cout<<brand << " " <<model <<" Breaking : speed is now "<< currentSpeed <<"km/h" << '\n';
}


void stopEngine(){
    isEngineOn=false;
    currentGear=0;
    currentSpeed=0;
    cout<<brand << " " <<model <<"Engine : stops "<<'\n';

}

  ~SuperCar(){}
};


int main(){

    SuperCar *myCar=  new SuperCar("ford","Mustang");
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    // before encapsulation we could have change the variable value
    //  myCar->currentSpeed=500

    // cout<< "Curr speed of my super car"<<myCar->currentSpeed <<endl;

   cout << "Current Speed: " << myCar->getCurrentSpeed() << endl;
   myCar->setTyre(" Pop");
   cout << "helo tyre"<< myCar->getTyre();
    delete myCar;

    return 0;




}