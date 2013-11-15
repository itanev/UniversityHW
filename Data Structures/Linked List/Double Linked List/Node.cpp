template<class T>
struct Node {
    T value;
    Node<T>* next;
    Node<T>* prev;

    Node() {
        next = NULL;
        prev = next;
        next = prev;
    }

    Node(T val) {
        value = val;
        next = NULL;
        prev = NULL;
    }

    Node(Node<T>* node) {
        value = node->value;
        next = node->next;
        prev = node->prev;
    }
};
