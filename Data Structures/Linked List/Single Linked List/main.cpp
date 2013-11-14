#include <iostream>
#include "Node.cpp"
#include "AbstractLinkedList.cpp"
#include "LinkedList.cpp"

int main() {
    LinkedList<int> list;
    list.insert(5);
    list.insert(6);
    list.insert(7);

    list.remove_front();
    list.remove(6);

    if(list.isEmpty()) std::cout << "The list is empty." << std::endl;
    else std::cout << "The list is not empty." << std::endl;
    return 0;
}
