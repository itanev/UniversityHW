#include <iostream>
#include "Node.cpp"
#include "AbstractLinkedList.cpp"
#include "LinkedList.cpp"

int main() {
    LinkedList<int> test;

    test.insert(5);
    test.insert(6);

    std::cout << test.contains(5) << std::endl;
    test.remove(5);
    std::cout << test.contains(5) << std::endl;

    if(test.isEmpty()) {
        std::cout << "list is empty" << std::endl;
    }
    else {
        std::cout << "list is not empty" << std::endl;
    }

    return 0;
}
