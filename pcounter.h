// class counter header file pcounter.h

#ifndef _PCOUNTER_H_
#define _PCOUNTER_H_

// a class to hold a pointer to an integer counter

class Counter
{
public:
    // constructors
    Counter(int k);
    Counter(const Counter& rhs);  // copy constructor

    // overloading operators =
    Counter& operator=(const Counter& rhs);

    // overloading of operator +=, -=, and *=
    Counter& operator+=(const Counter& rhs);
    Counter& operator-=(const Counter& rhs);
    Counter& operator*=(const Counter& rhs);

    // overloading of binary operator +, -, *

    Counter operator+(const Counter& rhs) const;
    Counter operator-(const Counter& rhs) const;
    Counter operator*(const Counter& rhs) const;

    // overloading of comparison operators == and !=
    bool operator==(const Counter& rhs) const;
    bool operator!=(const Counter& rhs) const;

    // increment and decrement functions
    void increment();
    void decrement();

    // get function
    int getCount() const;

    //destructor
    ~Counter();

private:
    int* _p; // holds the pointer to a dynamically allocated integer count
};

#endif // _PCOUNTER_H_
