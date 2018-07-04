// implementation of the class counter

#include <iostream>
#include "pcounter.h"

using namespace std;

Counter::Counter(int k)
{
    _p = new int;
    if (_p == NULL)
    {
      cout << "ERROR: Memory allocation failed." << endl;
      exit(1);
    }
    *_p = k;
}

Counter::~Counter()
{
    delete _p;
}

Counter::Counter(const Counter& rhs)
{
    _p = new int;
    *_p = *(rhs._p);
}

Counter& Counter::operator=(const Counter& rhs)
{
    if(this != &rhs) {
        *_p= *(rhs._p);
    }
    return *this;
}
Counter& Counter::operator+=(const Counter& rhs)
{
    *_p = *_p + *(rhs._p);
  return *this;
}

Counter& Counter::operator-=(const Counter& rhs)
{
    *_p = *_p - *(rhs._p);
   return *this;
}

Counter& Counter::operator*=(const Counter& rhs)
{
    *_p = *_p * *(rhs._p);
      return *this;
}

Counter Counter::operator+(const Counter& rhs) const
{
    Counter result = *this;
       result += rhs;
       return result;
}

Counter Counter::operator-(const Counter& rhs) const
{
    Counter result = *this;
        result -= rhs;
        return result;

}

Counter Counter::operator*(const Counter& rhs) const
{
    Counter result = *this;
    result *= rhs;
    return result;
}

bool Counter::operator==(const Counter& rhs) const
{
    return (*_p == *(rhs._p));
}

bool Counter::operator!=(const Counter& rhs) const
{
    return !(*this == rhs);
}

void Counter::increment()
{
     *_p= *_p + (1);
}

void Counter::decrement()
{
    *_p= *_p + (-1);
}

int Counter::getCount() const
{
    return *_p;
}

int main() {
    Counter c(10);
    cout << "Counter value is: " << c.getCount() << endl << endl;

    cout << "Testing '=' operator: c=15 : c should be 15" << endl;
    c=15;
    cout << "Counter value is: " << c.getCount() << endl << endl;

    cout << "Testing '+=' operator: c+=5 : c should be 20" << endl;
    c+=5;
    cout << "Counter value is: " << c.getCount() << endl << endl;

    cout << "Testing '-=' operator: c-=10 : c should be 10" << endl;
    c-=10;
    cout << "Counter value is: " << c.getCount() << endl << endl;

    cout << "Testing '*=' operator: c*=6 : c should be 60" << endl;
    c*=6;
    cout << "Counter value is: " << c.getCount() << endl << endl;

    cout << "Testing '+' operator: c+2 : c should be 62" << endl;
    c = c + 2;
    cout << "Counter value is: " << c.getCount() << endl << endl;

    cout << "Testing '-' operator: c-12 : c should be 50" << endl;
    c = c - 12;
    cout << "Counter value is: " << c.getCount() << endl << endl;

    cout << "Testing '*' operator: c*2 : c should be 100" << endl;
    c = c * 2;
    cout << "Counter value is: " << c.getCount() << endl << endl;

    cout << "Testing '==' operator: c==100 : should return true(1)" << endl;
    bool x;
    if(c.getCount()==100)
        x = true;
    cout << "Returns: "<< x << endl << endl;

    cout << "Testing '!=' operator: c!=100 : should return false(0)" << endl;
    if(c!=10)
        x = false;
    cout << "Returns: "<< x << endl << endl;

    cout << "Testing increment(): c.increment(): c should be 101" << endl;
    c.increment();
    cout << "Counter value is: "<< c.getCount() << endl << endl;

    cout << "Testing decrement(): c.decrement(): c should be 100" << endl;
    c.decrement();
    cout << "Counter value is: "<< c.getCount() << endl << endl;

    cout << "Testing copy constructor: a : value should be 50" << endl;
    c=50;
    Counter a(c);
    cout << "Counter value is: "<< a.getCount() << endl << endl;

    return 0;
}
