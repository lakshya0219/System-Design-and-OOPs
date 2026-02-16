#include<iostream>
#include<string>
using namespace std;
class ManualCar{
    private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    public:
    ManualCar(string brand, string model)
    {
         this->brand=brand;
         this->model=model;
         this->isEngineOn=false;
         this->currentGear=0;
         this->currentSpeed=0;
    }
    void startEngine()
    {
        isEngineOn=true;
        cout<<"Engine started"<<endl;
    }
    void stopEngine()
    {
        isEngineOn=false;
        currentSpeed=0;
        cout<<"ENGINE turned off"<<endl;
    }
    //Overloading accelerate - Static polymorphism
    void accelerate()
    {
        if(!isEngineOn)
        {
            cout<<"Cannot accelerate as engine is OFF"<<endl;
            return;
        }
        currentSpeed+=20;
        cout<<"Car accelerating with speed: "<<currentSpeed<<endl;
    }
    void accelerate(int speed){
        if(!isEngineOn){
            cout<<"Cannot accelerate as engine is OFF"<<endl;
            return;
        }
        currentSpeed+= speed;
        cout<<"Car accelerating with speed: "<<currentSpeed<<endl;
    }
    void brake()
    {
        currentSpeed-=10;
        if(currentSpeed<0)
        currentSpeed=0;
        cout<<"Braking speed is now"<<currentSpeed<<endl;
    }
    void shiftGear(int gear)
    {
        currentGear=gear;
        cout<<"current gear is"<<currentGear<<endl;
    }
};
int main()
{
    ManualCar* myCar = new ManualCar("Suzuki", "WagornR");
    myCar->startEngine();
    myCar->accelerate();
    myCar->accelerate(40);
    myCar->brake();
    myCar->stopEngine();
    delete myCar;
    return 0;
}
