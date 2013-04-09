#include <iostream>
#include <exception>
#include <cmath>
#include "../Rational/Lib/Exception.h";
#include "../Rational/Lib/Rational.h";
#include "../Rational/Lib/RationalMethods.h";
#include "Lib/RatDynamicArray.h";
#include "Lib/RatDynamicArrayMethods.h";

using namespace std;

int main()
{
    Rational test(1,2);
    Rational test1(2,2);
    RatDynamicArray dynamicArr;
    dynamicArr.push(test);
    dynamicArr.insertAt(2, test1);
    //dynamicArr.pop();
    dynamicArr.get(2).print();
    dynamicArr.set(2, test);
    dynamicArr.get(2).print();
    return 0;
}
