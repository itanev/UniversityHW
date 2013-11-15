template<class T>
class AbstractLinkedList {
    virtual void insert(T val) = 0;
    virtual void remove(T val) = 0;
    virtual void remove_front() = 0;
    virtual void remove_back() = 0;
    virtual Node<T>* search(T val) = 0;
    virtual bool contains(T val) = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
};
