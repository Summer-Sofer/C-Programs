#include<iostream>
using namespace std;
#include<string>

// this function returns the reverse of string s. hello becomes olleh.
string Sreverse(string s);

int main()
    {
 string greetings = "Hello World!";
 cout << Sreverse(greetings)<<endl;

        return 0;
    }

    string Sreverse(string s)
{
    string rev; //empty
    int n = s.size();

    for (int i = n; i >= 0; i--)
{
        rev += s[i];
    }
        return rev;

}
