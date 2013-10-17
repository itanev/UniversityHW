#include <iostream>
#include <exception>
#include <cmath>
#include "Lib/RatDynamicArrayMethods.h"

using namespace std;

int main()
{
    Rational test;
    Rational test2(1,4);

    RationalDynamicArray arr;
    arr.push(test);
    arr.push(test2);

    typedef RationalDynamicArray::Iterator RatIt;

    RatIt end = arr.end();
    int k = 0;

    return 0;
}
