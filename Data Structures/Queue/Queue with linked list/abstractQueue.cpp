template<class T>
class AbstractQueue {
    public:
        virtual void enqueue(T value) = 0;
        virtual T dequeue() = 0;
        virtual T peek() = 0;
        virtual bool isEmpty() = 0;
};
