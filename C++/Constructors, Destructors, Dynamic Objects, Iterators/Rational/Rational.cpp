#include <iostream>
#include <exception>
#include <cmath>
#include "Lib/Exception.h"
#include "Lib/Rational.h"
#include "Lib/RationalMethods.h"

using namespace std;

int main()
{
    try
    {
        Rational num1(4,2);
        Rational num2(1,2);

        num1 += 1;
        cout << num1;
    }
    catch(InvalidDenom& e)
    {
        cout << e.msg() << endl;
    }
    return 0;
}
