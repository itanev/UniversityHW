#include <iostream>
#include "linkedList.h"
#include "stack.h"

using namespace std;

int main()
{
    Stack<int> test;
    test.push(10);
    test.push(11);
    test.push(12);
    test.push(13);
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.peek() << endl;

    return 0;
}
