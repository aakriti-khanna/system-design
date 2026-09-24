//==================================== Definition

//Create a private __private_constructor
// Create a static instance GetInstance that return the same instance every time

// Real world usage  Configurations ,Db connection,Logging Mechanism





#include <iostream>

using namespace std;

// class Singleton{
 
//     public: 
   
//     Singleton(){
//             cout <<"Singleton object creater , no constructor called."<<endl ;
//     }

// };


// Now this will return us only 1 object how 
// since we have created an instance & through that instance 
// sbse phle ye s1 call hoga  ->   Singleton *s1= Singleton::getInstance();
// ye getInstance(); ko call krega 
// then it will validate ki hmara instance joh hai woh null ptr ko call kra h mtlb heap mai new object create krega
// then instance ko assign kradega or woh below method
// instance return krdega

//  static Singleton* getInstance(){
//         if(instance == nullptr){
//             instance= new Singleton();
//         }
//         return instance;
//     }


//  Singleton *s2= Singleton::getInstance();
// again call hoga then it will check the same if it has one object then it will only return 1
// this is single threaded example if multiple threads comes & does it will do // execution tehn it will create multiple objects
// to cure that we will use locking mechanism
 

//==================================== Single threaded
// class Singleton{
 
//     private:
//     static Singleton* instance;
//     Singleton(){
//             cout <<"Singleton object creater , no constructor called."<<endl ;
//     }

//     public: 
//     static Singleton* getInstance(){
//         if(instance == nullptr){
//             instance= new Singleton();
//         }
//         return instance;
//     }
// };
// //  this has been mde to hold the object 
// Singleton* Singleton::instance =nullptr;

// int main(){
//     //   Singleton *s1=new Singleton()
//     Singleton *s1= Singleton::getInstance();
//     Singleton *s2= Singleton::getInstance();
//    cout<<(s1 ==s2)<<endl;
// }


//==================================== MultiThreaded
class Singleton{
 
    private:
    static Singleton* instance;
    static mutex mtx;
    Singleton(){
            cout <<"Singleton object creater , no constructor called."<<endl ;
    }

    public: 
    static Singleton* getInstance(){
        // lock_guard<mutex>lock(mtx); //lock for theread safe   
        if(instance == nullptr){
             lock_guard<mutex>lock(mtx); //   (kept here bcz we can check also phle agr
            //   we dont have object in heap then post lock otherwise toh no need )
             if(instance == nullptr){ // we need to keep this cond again kyuki lock release hogya 
                // toh fir dbara thodi check hoga ki object hai ki nhi it will create multiple instance 
                instance= new Singleton();
             }
        }
        return instance;
    }
};
//  this has been mde to hold the object 
Singleton* Singleton::instance =nullptr;
mutex Singleton::mtx;

int main(){
    //   Singleton *s1=new Singleton()
    Singleton *s1= Singleton::getInstance();
    Singleton *s2= Singleton::getInstance();
   cout<<(s1 ==s2)<<endl;
}