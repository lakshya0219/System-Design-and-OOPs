// Inheritance is a fundamental OOP concept where a class (derived/child class) inherits properties
//  and behaviors (data members and member functions) from another class (base/parent class).
//   It establishes an "is-a" relationship between classes, promoting code reusability and establishing
//    a hierarchical relationship between classes.

// Key Characteristics:
// Code Reusability: Derived classes reuse code from base classes

// Hierarchical Relationship: Creates a parent-child class structure

// Extensibility: Derived classes can add new features or modify existing ones

// Transitive Nature: Properties of base class are passed down the inheritance chain

//Common characteristics and behaviours of Car:
// brand, model,isEngineOn, currentSpeed, startEngine(), stopEngine(),accelerate(), brake()

// Individual characteristics and behaviour of Manual Car:
// currentGear, shiftGear() etc

//Individual characteristics and behaviour of Electric Car:
//  batteryLevel, chargeBattery() etc

// Case 1: class ManualCar = public Car{}
// iska matlab, Car me jitne bhi public member the, wo ManualCar me bhi public honge.
//  Car ke private members ManualCar me accessible nahi honge.
//  Car ke protected members ManualCar me accessible honge, but wo bhi public nahi honge, wo protected hi rahenge.

//Case 2: class ManualCar = private Car{}
// iska matlab, Car me jitne bhi public member the, wo ManualCar me private honge.
//  Car ke private members ManualCar me accessible nahi honge.
//  Car ke protected members ManualCar me protected rahenge

//Case 3: class ManualCar = protected Car{}
// iska matlab, Car me jitne bhi public member the, wo ManualCar me protected honge.
//  Car ke private members ManualCar me accessible nahi honge.
//  Car ke protected members ManualCar me protected rahenge

#include <iostream>
#include <string>
using namespace std;

class Car{
    protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    public:
        Car(string b, string a)
        {
            this->brand=b;
            this->model=a;
            isEngineOn=false;
            currentSpeed=0;
        }
        void startEngine()
        {
            isEngineOn=true;
            cout<<brand<<" "<<model<<" : Engine starts with a roar!"<<endl;
        }
        void stopEngine()
        {
            isEngineOn=false;   
            currentSpeed=0;
            cout<<brand<<" "<<model<<" : Engine stopped."<<endl;
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
            if(!isEngineOn)
            {
                cout<<brand<<" "<<model<<" : Engine is off. Cannot brake."<<endl;
                return;
            }
            currentSpeed-=10;;
            if(currentSpeed<0)
            currentSpeed=0;
            cout<<brand<<" "<<model<<" : Braking. Current speed: "<<currentSpeed<<" km/h"<<endl;
        }
        virtual ~Car() {} // Virtual destructor for proper cleanup of derived class objects
};
class ManualCar: public Car{
    private:
    int currentGear; //specific to ManualCar
    public:
    ManualCar(string b, string m): Car(b,m)
    {
        currentGear=0;
    }   
//specialized method for ManualCar
    void shiftGear(int gear)
    {
        currentGear=gear;
        cout<<brand<<" "<<model<<" : Shifted to gear "<<currentGear<<endl;
    }
};

class ElectricCar: public Car{
    private:
    int batteryLevel; //specific to ElectricCar
    public:
    ElectricCar(string b, string m): Car(b,m)
    {
        batteryLevel=100; // Fully charged
    }
    void chargeBattery()
    {
        batteryLevel=100;
        cout<<brand<<" "<<model<<" : Battery fully charged."<<endl;
    }
};

int main()
{
    ManualCar* myManualCar = new ManualCar("Honda", "Civic");
    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model 3");
    
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    
    cout << endl; // Just for better separation of output
    
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->chargeBattery();
    myElectricCar->stopEngine();
    
    delete myManualCar;
    delete myElectricCar;
    
    return 0;
}