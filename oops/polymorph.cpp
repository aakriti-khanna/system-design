#include <iostream>
using namespace std;

class Car {
 protected: 
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

public: 
    //  used constructor for the same
    Car ( string b,  string m) {
     this->brand=b;
     this->model=m;
     isEngineOn=false;
     currentSpeed=0;
     currentGear=0;

    }

void startEngine(){
    isEngineOn=true;
    cout<<brand << " " <<model <<" Engine : starts  "<<'\n';

}

void shiftGear(int gear){
    if (!isEngineOn){
      cout<<brand << " " <<model <<" Engine : can't shift gear "<<'\n';
    }
    currentGear=gear;
    cout<<brand << " " <<model <<" shifted gear"<<'\n';

}



void stopEngine(){
    isEngineOn=false;
    currentGear=0;
    currentSpeed=0;
    cout<<brand << " " <<model <<"Engine : stops "<<'\n';

}
virtual void accelerate()=0;
virtual void brake()=0;
virtual ~Car() {}

};

class ManualCar : public Car {
    private: 
    int currentGear;

    public:
    ManualCar(string b, string m): Car(b,m){
            currentGear=0;
    }
    void shiftGear(int gear){
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

};

class ElectricCar : public Car {
private: 
    int battery;
 
public: 
   ElectricCar(string b, string m): Car(b,m){
            battery=100;
    }

    void chargeBattery(){
        battery=100;
        cout<<brand << " " <<model <<" Battery fully Charged"<<'\n';
    }

    // overriding accelerate

     void accelerate(){
      if (!isEngineOn){
        cout<<brand << " " <<model <<" can't accelerate "<<'\n';
      }

      if (battery <= 0){
         cout<<brand << " " <<model <<" Car can't accelerate "<<'\n';
         return;
      }
        battery-=15;
        currentSpeed+=15;

      cout<<brand << " " <<model <<" : Accelerate to " << currentSpeed <<"km/h" << '\n';
    }

    void brake(){
        currentSpeed-=20;
        if (currentSpeed<0){
            currentSpeed=0;
        }
        cout<<brand << " " <<model <<" Breaking : speed is now "<< currentSpeed <<"km/h" << '\n';
    }

};

int main(){

    ManualCar* myManualCar=  new  ManualCar("ford","Mustang");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->shiftGear(2);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    
    delete myManualCar;

    cout<<"-----"<<endl;

    ElectricCar* myElectricCar = new  ElectricCar("Tesla","Model s");
    myElectricCar->chargeBattery();
    myElectricCar->startEngine();
    // myElectricCar->shiftGear(1);
    myElectricCar->accelerate();
    // myElectricCar->shiftGear(2);
    // myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
       
    delete  myElectricCar;

    return 0;




}