#include <iostream>
#include <exception>
#include <cmath>
#include "Lib/Exception.h";
#include "Lib/Rational.h";
#include "Lib/RationalMethods.h";

using namespace std;

int main()
{
    try
    {
        Rational num1(-2, 1);
        Rational num2(0,4);

        if(num2.multiply(&num1).isPos()) cout << "true" << endl;
        else cout << "false" << endl;

        num1.divide(&num2).print();

        num1.opposite().print();
    }
    catch(InvalidDenom& e)
    {
        cout << e.msg() << endl;
    }
    return 0;
}
