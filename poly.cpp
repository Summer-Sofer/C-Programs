#include<iostream>
#include <string>
#include <fstream>
using namespace std;

class Shape
{
public:
    virtual void jump() = 0;
};

class Rectangle: public Shape 
{
public:
     // constructor 1
     Rectangle() { length = width = 0; }
     // constructor 2
     Rectangle(double l, double w){setLength(l); setWidth(w);}
    // getter functions or methods
    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getArea() const { return length * width; }
    // setter functions
    void setLength(double l);
    void setWidth(double w);
  // destructor
  ~Rectangle() {}  // empty destructor

virtual void jump() const {cout<< "Rectangle Jumping"<<endl;}

  friend ostream& operator<<(ostream& os, const Rectangle& r);

protected:
    double length, width; // attributes
};


class Box: public Rectangle
{
private:
    double height;

public:
    Box(): Rectangle(){height = 0;}
    Box(double l, double w, double h): Rectangle(l, w){setHeight(h);}
    //setter function
    void setHeight(double h);
    //getter functions
    double getHeight() const {return height;}
friend ostream& operator<<(ostream& os, const Box& b);
void jump() const {cout << "Box Jumping"<<endl;}
};



int main()
{
Box b (1.0,2.0,3.0);
cout << b <<endl;
b.jump();

Rectangle MyRectangle(1.0,5.0);
cout << MyRectangle<<endl;
MyRectangle.jump();

Rectangle * pr = &b;
(*pr).jump();
    return 0;
}


void Rectangle::setLength(double l)
{
  if (l >= 0)
    length = l;
  else
  {
      cout << "NEGATIVE LENGTH exiting ..." << endl;
      exit(EXIT_FAILURE);
  }
}

void Rectangle::setWidth(double w)
{
  if (w >= 0)
    width = w;
  else
  {
      cout << "NEGATIVE WIDTH exiting ..." << endl;
      exit(EXIT_FAILURE);
  }
}

void Box::setHeight(double h)
{
  if (h >= 0)
    height = h;
  else
  {
      cout << "NEGATIVE height exiting ..." << endl;
      exit(EXIT_FAILURE);
  }
}

 ostream& operator <<(ostream& os, const Rectangle& r)
{
    os <<"("<<r.length<<","<<r.width<<")" <<endl;
    return  os;
}

ostream& operator<<(ostream& os, const Box& b)
{

    os << "[";
    os << "("<<b.length<<" ,"<<b.width<<")";
    os<<", "<< b.height<< "]"<<endl;
    return os;
}
