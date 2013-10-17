#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Symbols //symbol holder
{
    char symbol;
    int numOccurrences;
};

//helper function
void insertSymbol(vector<Symbols>& uniqSymbols, char& c)
{
    Symbols firstSymbol;
    firstSymbol.symbol = c;
    firstSymbol.numOccurrences = 1;
    uniqSymbols.push_back(firstSymbol);
}

int main()
{
    //get path
    string path;
    cout << "Enter path to file: ";
    getline(cin, path);
    if(path.empty()) path = "stats.txt";

    //open file stream
    ifstream file;
    file.open(path.c_str());

    char c;
    int count = 0;
    vector<Symbols> uniqSymbols;

    //get unique symbols and their occurrences
    while(file.get(c).good())
    {
        if(c == '\n') continue;

        bool exist = false;
        count++;

        if(uniqSymbols.empty()) insertSymbol(uniqSymbols, c);
        else
        {
            for(int i = 0; i < uniqSymbols.size(); i++)
            {
                if(c == uniqSymbols[i].symbol)
                {
                    uniqSymbols[i].numOccurrences++;
                    exist = true;
                    break;
                }
            }

            if(exist) continue;
            else insertSymbol(uniqSymbols, c);
        }
    }

    file.close();

    //create the statistic
    for(int i = 0; i < uniqSymbols.size(); i++)
    {
        cout.precision(2);
        cout << "Symbol: " << uniqSymbols[i].symbol << " - " << (double)uniqSymbols[i].numOccurrences/count * 100 << "%" << endl;
    }

    return 0;
}
