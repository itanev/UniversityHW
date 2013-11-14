#include <iostream>
#include "List.cpp"
#include "query.h"

using namespace std;

int main()
{
    Query<int> test;
    test.push(2);
    test.push(3);
    cout << test.pop() << endl;
    cout << test.peek() << endl;
    return 0;
}
