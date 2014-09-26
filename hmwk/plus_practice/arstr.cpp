#include <iostream>
using namespace std;

int main()
{
    cout << "begin.. \n";

    cout<<"string practice \n";
    
    char mystring[]={'H','e','l','l','o',
            '\0'}; //\0 impact the string 's end

    char mystring2[]="Hello";
    cout <<"mystring=>"<< mystring <<"      mystring2==>"<<mystring2<<"\n";

    //string copy
    char myName[5] ;
    strcpy(myName,"tianx");
    cout <<myName;
    return 0;

}

