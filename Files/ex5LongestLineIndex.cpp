#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //get path
    string path;
    cout << "Enter path to file: ";
    getline(cin, path);
    if(path.empty()) path = "input.txt";

    //open file stream
    ifstream file;
    string currLine;

    file.open(path.c_str());

    if(!file)
    {
        cout << "Something went wrong!";
        return 0;
    }

    int lineIndex = 0, maxLength = 0, maxIndex = 1;

    //get index of longest line
    while(file.good())
    {
        lineIndex++;
        getline(file, currLine);

        if(currLine.size() > maxLength)
        {
            maxLength = currLine.size();
            maxIndex = lineIndex;
        }
    }

    cout << "Index of longest row: " << maxIndex;

    return 0;
}
