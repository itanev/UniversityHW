#ifndef structs
#define structs

using namespace std;

struct Investors
{
    unsigned int ID;
    char name[30];
    double capital;
};

struct Stocks
{
    unsigned int InvestorID;
    unsigned int CompanyID;
    double shares;
};

struct Companies
{
    unsigned int ID;
    char name[30];
    double stockPrice;
};

#endif
