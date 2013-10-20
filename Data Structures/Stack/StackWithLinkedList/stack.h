template<class T>
class Stack
{
    Node<T> * top;
    public:
        Stack()
        {
            top = NULL;
        }

        void push(T item)
        {
            Node<T> * newNode = new Node<T>(item, top);
            top = newNode;
        }

        T peek()
        {
            return top->data;
        }

        T pop()
        {
            T data = top->data;
            top = top->next;
            return data;
        }
};
