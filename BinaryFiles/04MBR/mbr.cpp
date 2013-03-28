#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

int sumBytes(unsigned char * sector)
{
    return ((int)sector[0] | ((int)sector[1] << 8) | ((int)sector[2] << 16) | ((int)sector[3] << 24));
}

int main()
{
    //just put the name of the file here
    ifstream file("sdabeginning.img", ios::in|ios::binary);
    int size = 0;
    char * signature = new char[2];

    unsigned char * oneBytes = new unsigned char[1];
    unsigned char * sector = new unsigned char[4];

    if(file.is_open())
    {
        //get file size
        file.seekg(0, ios::end);
        size = file.tellg();

        //check file size
        if(size >= 512)
        {
            //get the signature
            file.seekg(-2, ios::end);
            file.read(signature, 2);

            //check the signature
            if(int(signature[0]) == 85 && int(signature[1]) == -86);
            {
                delete[] signature; //free the memory
                int startByte = 446;
                for(int i = 0; i < 4; i++)
                {
                    cout << endl << "Partition " << i << endl;

                    //active flag
                    file.seekg(startByte, ios::beg);
                    file.read((char*)(oneBytes), 1);

                    if(int(*oneBytes) == 128) cout << "Active flag set" << endl;

                    //partition type
                    cout << "Partition type: ";
                    startByte += 4;

                    file.seekg(startByte, ios::beg);
                    file.read((char*)(oneBytes), 1);

                    switch(int(*oneBytes))
                    {
                        case 0:
                            cout << "Empty partition entry";
                            continue;
                            break;
                        case 5:
                        case 15:
                            cout << "0x05 (Extended partition)";
                            break;
                        case 7:
                            cout << "0x07 (NTFS partition)";
                            break;
                        case 130:
                            cout << "0x82 (Linux swap partition)";
                            break;
                        case 131:
                            cout << "0x83 (Linux partition)";
                            break;
                        default:
                            cout << "Unknown type partition";
                            break;
                    }

                    //starting byte
                    startByte += 4;
                    file.seekg(startByte, ios::beg);
                    file.read((char*)sector, 4);
                    cout << endl << "Starting byte: " << sumBytes(sector) * 512ull << endl;
                    //number of bytes
                    startByte += 4;
                    file.seekg(458, ios::beg);
                    file.read((char*)(sector), 4);
                    cout << "Number of bytes: " << sumBytes(sector) * 512ull << endl;
                    startByte += 4;
                }
            }
        }
    }
    else
        cout << "Something went wrong!";
    return 0;
}
