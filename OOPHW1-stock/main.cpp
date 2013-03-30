#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "structs.h"
#include "readFilesFuncts.h"

using namespace std;

void buyStocks(vector<Investors>& investors, vector<Companies>& companies, vector<Stocks>& stocks)
{
    unsigned int investorID;
    unsigned int companyID;
    double amount;

    cin >> investorID;
    cin >> companyID;
    cin >> amount;

    if(amount < 0) { cout << "ERROR" << endl; return; }

    if(investorID >= investors.size() || companyID >= companies.size())
        { cout << "ERROR" << endl; return; }

    if(investors[investorID].capital < amount)
        { cout << "ERROR" << endl; return; }

    if(companies[companyID].stockPrice < amount)
        amount -= (amount - companies[companyID].stockPrice);

    investors[investorID].capital -= amount;
    companies[companyID].stockPrice -= amount;

    for(int i = 0; i < stocks.size(); i++)
    {
        if(stocks[i].InvestorID == investorID &&
           stocks[i].CompanyID  == companyID)
        {
            stocks[i].shares += amount;
            break;
        }
    }

    cout << "OK" << endl;
}

void sellStocks(vector<Investors>& investors, vector<Companies>& companies, vector<Stocks>& stocks)
{
    unsigned int investorID;
    unsigned int companyID;
    double amount;

    cin >> investorID;
    cin >> companyID;
    cin >> amount;

    if(amount < 0) { cout << "ERROR" << endl; return; }

    if(investorID >= investors.size() || companyID >= companies.size())
        { cout << "ERROR" << endl; return; }

    investors[investorID].capital += amount;

    for(int i = 0; i < stocks.size(); i++)
    {
        if(stocks[i].InvestorID == investorID &&
           stocks[i].CompanyID  == companyID)
        {
            if(amount > stocks[i].shares)
                amount -= (amount - stocks[i].shares);

            stocks[i].shares -= amount;
            break;
        }
    }

    cout << "OK" "company.dat"<< endl;
}

void printInfo(vector<Investors>& investors, vector<Companies>& companies, vector<Stocks>& stocks)
{
    unsigned int investorID;

    cin >> investorID;

    if(investorID >= investors.size()) { cout << "ERROR." << endl; return; }

    string fileName = string(investors[investorID].name) + ".doc";

    ofstream fileToWrite(fileName.c_str(), ios::out);

    if(fileToWrite.good())
    {
        fileToWrite << "Име на инвеститор: " << investors[investorID].name << endl;
        fileToWrite << "Акции: " << endl;

        for(int i = 0; i < stocks.size(); i++)
        {
            if(stocks[i].InvestorID == investorID)
            {//cout << file.tellg();
                fileToWrite << "\tКомпания: ";
                fileToWrite << companies[stocks[i].CompanyID].name;
                fileToWrite << "\tДял акции: " << stocks[i].shares << endl;
            }
        }

        fileToWrite << "Общо капитал: " << investors[investorID].capital;

        cout << "OK." << endl;
    }
    else { cout << "ERROR." << endl; return; };

    fileToWrite.close();
}

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
                return 0;
                break;
        }
    }

    //close files
    investorsFile.close();
    stocksFile.close();
    companiesFile.close();

    return 0;
}
