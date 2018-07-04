#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
    int year;
    string make;
    double speed;
    string modle;
    unsigned int validate(int y);

public: //interface for the private
        //setter functions
    void setmake(string m) {make = m;}
    void setmodle(string m){modle = m;}
    void setyear(int y)    {year = validate(y);}
        //getter functions
    string getmake(){return make;}
    string getmodle(){return modle;}
    int    getyear(){return year;}
    double getspeed(){return speed;}
        //methods
    void initializespeed() {speed = 0;}
    void acceleration()    {speed +=5; }
    void brake();
};

int main()
{
    Car c;
    c.setmake("BMW");
    c.setmodle("i750");
    c.initializespeed();
    cout << c.getmake() << endl;
    cout << c.getmodle() << endl;
    cout << c.getspeed() << endl;
    c.acceleration();
    c.acceleration();
    cout << c.getspeed() << endl;


    return 0;
}
void Car::brake()
{
 speed -= 5;
 if (speed < 0)
     speed = 0;
}
unsigned int Car::validate(int y)
{
    int fyear = 2020;
    int lyear = 1900;
     if (y > fyear)
     exit(1);
     if (y < lyear)
     exit (1);
     return y;
}
