// Encapsulation is the bundling of data (variables/characteristics) and methods (functions/behaviours) that operate on 
// that data into a single unit (class), while restricting direct access to some of the object's components. It's 
// like a protective shield that prevents data from being accessed directly by code outside the class.

// Key Concepts
// Data Hiding: Hide internal state from outside access

// Controlled Access: Provide public methods to access/modify data

// Single Unit: Bundle related data and behavior together

// Protection: Prevent accidental or unauthorized modification

#include <iostream>
#include <string>
using namespace std;

// class Car{
//     public:
//     virtual void startEngine() = 0; // pure virtual function
//     virtual void stopEngine() = 0; // pure virtual function
//     virtual void shiftGear(int gear) = 0; // pure virtual function
//     virtual void accelerate() = 0; // pure virtual function
//     virtual void brake() = 0; // pure virtual function
//     virtual ~Car() {} // virtual destructor
// };
class SportsCar{
    private:
      string brand;
      string model;
      bool isEngineOn;
      int currentSpeed;
      int currentGear;
      string tyre;
    public:
      SportsCar(string b, string a)
      {
        this->brand=b;
        this->model=a;
        isEngineOn=false;
        currentSpeed=0;
        currentGear=0;
        tyre="MRF";
      }
      //getters and setters
      int getCurrentSpeed()
      {
        return this->currentSpeed;
      }
      string getTyre()
      {
        return this->tyre;
      }
      void setTyre(string t)
      {
        this->tyre=t;
      }
      void startEngine()
      {
        isEngineOn=true;
        cout<<brand<<" "<<model<<" : Engine starts with a roar!"<<endl;
      }
      void shiftGear(int gear)
      {
        if(!isEngineOn)
        {
            cout<<brand<<" "<<model<<" : Engine is off. Cannot shift gears."<<endl;
            return;
        }
        currentGear=gear;
        cout<<brand<<" "<<model<<" : Shifted to gear "<<currentGear<<endl;
      }
      void accelerate()
      {
        if(!isEngineOn)
        {
            cout<<brand<<" "<<model<<" : Engine is off. Cannot accelerate."<<endl;
            return;
        }
        currentSpeed+=10;
        cout<<brand<<" "<<model<<" : Accelerating. Current speed: "<<currentSpeed<<" km/h"<<endl;
      }
      void brake()
      {
        currentSpeed-=10;;
        if(currentSpeed<0)
        currentSpeed=0;
        cout<<brand<<" "<<model<<" : Braking. Current speed: "<<currentSpeed<<" km/h"<<endl;
      }
      void stopEngine()
      {
        isEngineOn=false;
        currentSpeed=0;
        currentGear=0;
        cout<<brand<<" "<<model<<" : Engine stopped."<<endl;
      }
      ~SportsCar() {
};

int main()
{
    SportsCar* myCar = new SportsCar("Ferrari", "488 Spider");
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();
    cout<<"Current Speed: "<<myCar->getCurrentSpeed()<<" km/h"<<endl;
    delete myCar;
    //Ab hum iss car ko chala paa rahe without knowing andar kaise functionality run ho rahi hai
}