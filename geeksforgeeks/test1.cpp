#include <iostream>
using namespace std;

class A
{
public:
    virtual void fun()
    {
        cout << "abstract class" << endl;
    }
};

class B : public A
{
public:
    void fun()
    {
        cout << "inherited class" << endl;
    }
};

int main()
{
    A a;
    A *aptr = &a;
    B b;
    B *bptr = &b;

    aptr->fun();
    aptr = bptr;
    aptr->fun();
}