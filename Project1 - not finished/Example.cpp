#include <iostream>
#include <stdlib.h>
#include "Person/Person.cpp"
#include "Community/Community.cpp"

using namespace std;

int main()
{
    try
    {
        char name[] = "Pesho";

        Person pesho("Pesho", "1239405521", "some address", Programmer, 10000);
        Person kiro("Kiro", "1239405421", "some address", Programmer, 10000);
        Person kiro1("Kiro", "1249405421", "some address", Programmer, 10000);
        cout << pesho << endl;
        pesho = kiro;
        cout << pesho;

        //Community baiIvan("baiIvan", "12.12.12", kiro, 0);
       // baiIvan.addMember(pesho);
        //baiIvan.addMember(kiro1);

        //cout << baiIvan.getName();
    }
    catch(exception& ex)
    {
        cout << ex.what();
    }

	return 0;
}
