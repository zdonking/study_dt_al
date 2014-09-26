#include <iostream>
using namespace std;

int main()
{
        int va=31;
        int *v;
        v=&va;

        cout <<"va="<<va<<"\n" ;
        *v=10;
        cout <<"exec *v=10, va="<<va ;


}

