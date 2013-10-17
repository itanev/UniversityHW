#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    ifstream file;
    string fileContent;
    string currNumber;

    file.open("input.txt");

    if(!file)
    {
        cout << "Something went wrong!";
        return 0;
    }

    int min, max, currNum;

    //we could use something like file.get(c) to get a single char
    while(file.good())
    {
        getline(file, fileContent);
        min = 32768;
        max = -32767;

        for(int i = 0; i < fileContent.size(); i++)
        {
            if( !isdigit(fileContent[i]) &&
                fileContent[i] != ' ' &&
                fileContent[i] != '-' &&
                fileContent[i] != '+' )
                break;

            currNumber += fileContent[i];
            currNum = atoi(currNumber.c_str());

            if(fileContent[i] == ' ')
            {
                if(currNum < min) min = currNum;
                if(currNum > max) max = currNum;

                currNumber.clear();
            }
        }

        cout << "Min/Max: " << min << "/" << max << endl;
    }

    file.close();

    return 0;
}
