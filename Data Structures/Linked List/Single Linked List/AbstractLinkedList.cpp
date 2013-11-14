template<class T>
class AbstractLinkedList {
    public:
        virtual void insert(T value) = 0;
        virtual T remove_front() = 0;
        virtual void remove(T value) = 0;
        virtual Node<T>* search(T value) = 0;
        virtual bool isEmpty() = 0;
};
