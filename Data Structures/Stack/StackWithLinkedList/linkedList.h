template<class T>
class Node
{
    public:
        T data;
        Node* next;

        Node() { }
        Node(T info) : data(info) { }
        Node(T info, Node<T>* nextNode) : data(info), next(nextNode) { }

        void operator= (const Node* other)
        {
            data = other->data;
            next = other->next;
        }
};
