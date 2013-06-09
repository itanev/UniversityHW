#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Person/Person.cpp"
#include "Community/Community.cpp"

using namespace std;

void writeInFile(char* fileName, const Community& theCommunity)
{
    char* currFileName = new char[strlen(fileName) + 1];
    strcpy(currFileName, fileName);

    ofstream file(currFileName);

    if(file.is_open())
        file << theCommunity;

    file.close();

    delete[] currFileName;
}

int main()
{
    try
    {
        char* fileName = "test.txt";

        char name[] = "Pesho";
        Person pesho(name, "1239405521", "some address", Programmer, 10000);
        Person kiro("Kiro", "1239405421", "some address", Programmer, 10000);
        Person stamat("Stamat", "1249405421", "some address", Programmer, 10000);

        Community baiIvan("bai Ivan", "12.12.12", kiro, 5);
        baiIvan.addMember(stamat);
        baiIvan.addMember(pesho);

        Community Kirvan("Kiro Ivanov", "12.12.12", pesho, 5);
        Kirvan.addMember(pesho);

        writeInFile("test.txt", Kirvan);
    }
    catch(exception& ex)
    {
        cout << ex.what();
    }

	return 0;
}
