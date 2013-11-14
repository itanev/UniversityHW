template<class T>
struct Node {
    T value;
    Node* next = NULL;

    Node(T val) {
        value = val;
    }

    Node(Node<T>* node) {
        value = node->value;
        next = node->next;
    }
};
