#include <iostream>
using namespace std;

int addvalue(int a,int b )
{
        a*=2;
        b*=2;
        return a+b;
}

int addvalue_by_ref(int& a,int& b )
{
        a*=2;
        b*=2;
        return a+b;
}

int main()
{
        int x=1,y=2,z;
        z=addvalue(x,y);
        cout << "by value\n";
        cout << "x=" << x << ",y=" << y << ",z=" << z;
        x=1,y=2,z=0;
        z=addvalue_by_ref(x,y);
        cout <<"\nby refence \n";
        cout << "x=" << x << ",y=" << y << ",z=" << z;

}
