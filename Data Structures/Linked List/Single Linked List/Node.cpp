template<class T>
struct Node {
    T value;
    Node<T>* next;

    Node(T val) {
        value = val;
        next = NULL;
    }

    Node(Node<T>* node) {
        value = node->value;
        next = node->next;
    }
};
