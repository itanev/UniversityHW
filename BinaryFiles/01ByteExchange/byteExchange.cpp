#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file("test.bin", ios::in|ios::out|ios::binary|ios::app);

    long size;
    //alocate memory for bytes
    char *firstByte = new char[1];
    char *secondByte = new char[1];

    //is_open() open the files and returns true
    //otherwise returns false
    if(file.is_open())
    {
        //get and check size
        file.seekg(0, ios::end);
        size = file.tellg();

        if(size <= 7)
        {
            cout << "File is too small." << endl;
            return 0;
        }

        //read bytes
        file.seekg(7, ios::beg);
        file.read(firstByte, 1);

        file.seekg(-7, ios::end);
        file.read(secondByte, 1);

        //write bytes
        file.seekp(7, ios::beg);
        file.write(secondByte, 1);

        file.seekp(-7, ios::end);
        file.write(firstByte, 1);

        cout << "Successful byte exchange!" << endl;
    }
    else
    {
        cout << "File cannot be opened!";
    }

    //optional
    file.close();
    delete[] firstByte;
    delete[] secondByte;

    return 0;
}
