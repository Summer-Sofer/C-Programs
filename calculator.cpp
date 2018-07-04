#include <iostream>
#include <cstdlib>

using namespace std;


// FUNCTION PROTOTYPES
//function reads two ints in to a and b..
void read_2_Int( int& a, int&  b);
// returns the sum of a and b
int add(int a, int b);

// returns the product of a and b
int  multiply(int a, int b);

// returns the difference a- b
int subtract(int a, int b);

// performs float division a/b if b is not 0;
// otherwise, the function displays an error
// message and exits the whole program
float divide(int a, int b);

// displays the calculator menu options for:
// 1. add; 2. multiply; 3. subtract; 4. divide and 5. quit
void display_calculator_menu();

// reads the user's selection, validates it, and
// returns the user's menu choice
int getMenuSelection();

// implements the simple calculator function
void my_simple_calculator();

// main function will launch the calculator
// DO NOT CHNAGE the main program
int main()
{
    my_simple_calculator();
    return 0;
}


// FUNCTION IMPLEMENTATIONS
int add(int a, int b)
{
    return (a + b);
}

// returns the product of a and b
int  multiply(int a, int b)
{
    return( a * b);
}

// returns the difference a- b
int subtract(int a, int b)
{
    return(a - b);
}

// performs float division a/b if b is not 0;
// otherwise, the function displays an error
// message and exits the whole program
float divide(int a, int b)
{
    if (b==0)
    {
        cout <<"ERROR."<<endl;
        exit(1);}

    else
    return a / b;
    // CODE goes here
}

// displays the calculator menu options for:
// 1. add; 2. multiply; 3. subtract; 4. divide and 5. quit
void display_calculator_menu()
{
    cout<<endl;
    cout<<"1. ADD"<<endl;
    cout<<"2. MULTIPLY"<<endl;
    cout<<"3. SUBTRACT"<<endl;
    cout<<"4 DIVIDE"<< endl;
    cout<<"5. QUIT"<<endl;  // CODE goes here
}

// reads the user's selection, validates it, and
// returns the user's menu choice
int getMenuSelection()
{
    int choice;
    cout << "Enter your selection (1, 2, 3, 4, or 5): ";
    cin >> choice;

    if (choice < 1 || choice > 5)
    {
        cout << "Try again (1, 2, 3, 4, or 5): ";
        cin >> choice;
    }

    return choice;


}

    // CODE goes here

// implements the simple calculator function
void my_simple_calculator()
{

    display_calculator_menu();
    int choice = getMenuSelection();
    // read two numbers
    int x;
    int y;

    read_2_Int(x,y);

    if (choice == 1)
        {cout<< "Lets ADD."<<endl;
    cout << add(x,y)<<endl;}

    else if (choice == 2)
        {cout<< "Lets MULTIPLY."<<endl;
    cout<< multiply(x,y)<<endl;}

    else if (choice == 3)
        {cout<< "Lets SUBTRACT."<<endl;
    cout<< subtract(x,y)<<endl;}

    else if (choice == 4)
        {cout<< "Lets DIVIDE."<<endl;
    cout<< divide(x,y)<<endl;}
    // CODE goes here
    else
    {
    return exit(1);
    }
}



void read_2_Int( int& a, int& b)
{
    cout << "Please enter two intergers"<<endl;
    cin >> a >> b;
}
