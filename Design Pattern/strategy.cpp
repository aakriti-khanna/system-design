// Lets  say we have a Robot class


// Robot :class
// walk()
// Talk()
// Projection() 
 

    // FlyableRobot  :class Robo              Companion Robo   :class               Worker Robo:class
// Fly()                                // Projection()                 // Projection() 


// sparrow Robot  :class             // CrowRobot :class          // Jet Robot :class
         // Fly()                          Fly()                    Fly()         


//  Now inheritance is being messed up since fly robot differes for Jet robo since it has 
// different way of flying 
// now this class will override the fly behaviour class then heirarchy will be complicated




#include <iostream>

using namespace std;



class WalkableRobot
{
public:
   virtual void walk()=0;
    virtual~WalkableRobot();
};

class Normalwalk : public WalkableRobot{
public:

     void walk() override {
      cout <<"walking Normally ...."<<endl;
     }
};

class NoWalk : public WalkableRobot{
public:

     void walk() override {
      cout <<" cannot walk...."<<endl;
     }
};

 class TalkableRobot
{
public:
   virtual void talk()=0;
   virtual~TalkableRobot();
};

class Normaltalk: public TalkableRobot {
    public:
      void talk() override {
         cout <<"talking Normally ...."<<endl;
      }
};

class Notalk: public TalkableRobot {
    public:
      void talk() override {
         cout <<"Not talking  ...."<<endl;
      }
};

class FlyableRobot{
    public:
    virtual void fly()=0;
    virtual~FlyableRobot();
};

class NormalFly : public FlyableRobot{
  public:
   void fly() override{
        cout <<"Flying  ...."<<endl;
   }

};
 
class NoFly : public FlyableRobot{
  public:
   void fly() override{
        cout <<"Not Flying  ...."<<endl;
   }

};


class Robot{
    protected: 
        WalkableRobot* walkBehaviour;
        TalkableRobot* talkBehaviour;
        FlyableRobot* flyBehaviour;

    public: 
    Robot(WalkableRobot *w ,TalkableRobot* t,FlyableRobot* f){
        this->walkBehaviour=w;
        this->talkBehaviour=t;
        this->flyBehaviour=f;
    }

    void walk(){
          walkBehaviour->walk();
    }

     void talk(){
          talkBehaviour->talk();
    }

     void fly(){ 
          flyBehaviour->fly();
    }

    virtual void projection()=0;
};


 