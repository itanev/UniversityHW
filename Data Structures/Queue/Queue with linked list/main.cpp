#include <iostream>
#include "node.cpp"
#include "abstractQueue.cpp"
#include "queue.cpp"

int main() {
    Queue<int> test;
    test.enqueue(5);
    test.enqueue(4);
    test.enqueue(6);
    std::cout << test.dequeue() << std::endl;
    std::cout << test.dequeue() << std::endl;
    std::cout << test.peek() << std::endl;

    if(test.isEmpty()) std::cout << "the queue is empty" << std::endl;
    else std::cout << "the queue is not empty" << std::endl;

    std::cout << test.dequeue() << std::endl;
    std::cout << test.isEmpty() << std::endl;

    return 0;
}
