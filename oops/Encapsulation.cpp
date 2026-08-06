#include <iostream>
using namespace std;


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

var setTyre(string tyre){
    this.tyre = tyre
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


};


int main(){

    Car *myCar=  new SuperCar("ford","Mustang");
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
    
    cout<<myCar->setTyre("hello")

    delete myCar;

    return 0;




}