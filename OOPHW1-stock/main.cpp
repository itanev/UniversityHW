#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "structs.h"
#include "readFilesFuncts.h"
#include "commands.h"
#include "writeFilesFuncts.h"

using namespace std;

int main ( int argc , char* argv[])
{
    //specify files
    ifstream investorsFile(argv[1],    ios::in|ios::binary);
    ifstream stocksFile   (argv[3],    ios::in|ios::binary);
    ifstream companiesFile(argv[2],    ios::in|ios::binary);

    //file info containers
    vector<Investors> investors;
    vector<Stocks> stocks;
    vector<Companies> companies;

    //read files
    readData<Investors> (investors, investorsFile);
    readData<Companies> (companies, companiesFile);
    readData<Stocks>    (stocks,    stocksFile);

    //read commands
    char command;

    while(true)
    {
        cin >> command;

        switch(command)
        {
            case 'b':
                buyStocks(investors, companies, stocks);
                break;

            case 's':
                sellStocks(investors, companies, stocks);
                break;

            case 'p':
                printInfo(investors, companies, stocks);
                break;

            default:
                ofstream investorsFileOut(argv[1],    ios::out|ios::binary);
                ofstream stocksFileOut   (argv[3],    ios::out|ios::binary);
                ofstream companiesFileOut(argv[2],    ios::out|ios::binary);
                writeData<Investors>(investors, investorsFileOut);
                writeData<Companies>(companies, companiesFileOut);
                writeData<Stocks>   (stocks, stocksFileOut);
                return 0;
                break;
        }
    }

    return 0;
}
