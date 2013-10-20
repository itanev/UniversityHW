#include <iostream>
#include <vector>
#include <string>
#include "List.cpp"
#include "myStack.cpp"
#include "stack.cpp"

using namespace std;

int main() {
    try {
        List<int> pesho;
        pesho.push_back(4);
        pesho.push_back(4);
        pesho.push_back(4);

        cout << pesho.back();
        cout << pesho.pop_back();
        cout << pesho.pop_back();
        cout << pesho.pop_back();
        cout << pesho.back();
    }
    catch(string ex) {
        cout << endl << ex;
    }

    return 0;
}
