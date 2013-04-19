#include <iostream>
#include <exception>
#include <cmath>
#include "Lib/RatDynamicArrayMethods.h"

using namespace std;

int main()
{
    Rational test(1,2);
    Rational test2(1,4);

    RationalDynamicArray arr;
    arr.push(test);
    arr.push(test2);

    typedef RationalDynamicArray::Iterator RatIt;

    RatIt end = arr.end();
    int k = 0;

    for (RatIt i = arr.begin(); (i != end); ++i) {
        i->get(k).print();
    }

    return 0;
}
