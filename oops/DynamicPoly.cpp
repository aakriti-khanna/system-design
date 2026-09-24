// #include <iostream>
// using namespace std;

// class Car {
//     protected:
//     string brand;
//     string model;
//     bool isEngineOn;
//     int currentSpeed;
      
//     public:
//     Car(string brand ,string model){
//         this->brand=brand;
//         this->model=model;
//         this->isEngineOn=false;
//         this->currentSpeed=0;
//     }


//     void startEngine(){
//         isEngineOn=true;
//         cout<<brand<<" "<<model <<"engine started"<<endl;
//     }



//     void stopEngine(){
//         isEngineOn=false;
//         currentSpeed=0;
//         cout<<brand<<" "<<model <<"engine stop"<<endl;
//     }


//     virtual void accelerate()=0;
//     virtual void brake()=0;
//     virtual ~Car() {}

// };


// class ManualCar : public Car {
// private:
//  int currentGear;

//  public:
//   ManualCar(string brand ,string Model): Car( brand, model){
//     this->currentGear=0;
//   }

//   void shiftGear(int gear){
//     currentGear=gear;
//     cout<<brand<<" "<<model<<":shifted to gear"<<currentGear<<endl;
    
//   }
// // overriding accelerate dynamic poly
//   void accelerate(){
//     if(isEngineOn){
//         cout<< brand <<" "<<model<<":Cannot accelerate Engine is off."<<endl;
//         return;
//     }
//     currentSpeed+=20;
//       cout<< brand <<" "<<model<<": accelerate to ."<<currentSpeed<<"Km/h"<<endl;
//   }

// // overriding accelerate dynamic poly

//   void brake(){
//     currentSpeed-=20;
//     if(currentSpeed < 0){
//         currentSpeed=0;
//     }
//     cout<< brand <<" "<<model<<": brake to ."<<currentSpeed<<"Km/h"<<endl;
//   };


// };

// class ElectricCar: public Car
// {
// private:
//   int batteryLevel;
// public:
//     ElectricCar(string brand,string model):Car(brand,model){
//      this->batteryLevel=100;
//     }

//     void chargeBattery(){
//      batteryLevel=100;
//     cout<<brand<<" "<<model<<": Battery charged to "<<batteryLevel<<endl;
//     }


//     void accelerate(){
//         if(isEngineOn){
//         cout<< brand <<" "<<model<<":Cannot accelerate Engine is off."<<endl;
//         return;
//      }
//      if (batteryLevel<=0){
//         cout<<brand<<" "<< model<<":Cannot accelerate Battery is dead."<<endl;
//      }
//     batteryLevel+=15;
//     currentSpeed+=20;
//       cout<< brand <<" "<<model<<": accelerate to ."<<currentSpeed<<"Km/h"<< batteryLevel<< "%"<<endl;
//     }

//     void brake(){
//         currentSpeed-=15;
//        if (currentSpeed<0){
//         currentSpeed=0;
//        } 
//        cout<< brand <<" "<<model<<": Braking   to ."<<currentSpeed<<"Km/h"<< batteryLevel<< "%"<<endl;
//     }
    
//     ~ElectricCar();


// };

// int main(){
//     ManualCar* myManualCar=  new  ManualCar("ford","Mustang");
//     myManualCar->startEngine();
//     myManualCar->shiftGear(1);
//     myManualCar->accelerate();
//     myManualCar->shiftGear(2);
//     myManualCar->accelerate();
//     myManualCar->brake();
//     myManualCar->stopEngine();
    
//     delete myManualCar;

//     cout<<"-----"<<endl;

//     ElectricCar* myElectricCar = new  ElectricCar("Tesla","Model s");
//     myElectricCar->chargeBattery();
//     myElectricCar->startEngine();
//     // myElectricCar->shiftGear(1);
//     myElectricCar->accelerate();
//     myElectricCar->accelerate();
//     // myElectricCar->shiftGear(2);
//     // myElectricCar->accelerate();
//     myElectricCar->brake();
//     myElectricCar->stopEngine();
       
//     delete  myElectricCar;

//     return 0;

// }



