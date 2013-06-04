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

        Community baiIvan("bai Ivan", "12.12.12", kiro, 5);
        baiIvan.addMember(pesho);
        baiIvan.addMember(kiro1);
        baiIvan.addMember(kiro);

        cout << baiIvan.getName();
    }
    catch(exception& ex)
    {
        cout << ex.what();
    }

	return 0;
}
