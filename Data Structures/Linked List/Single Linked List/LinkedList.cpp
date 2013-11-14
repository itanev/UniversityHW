template<class T>
class LinkedList : public AbstractLinkedList<T> {
    Node<T>* head;
    Node<T>* tail;
    public:
        LinkedList() {
            head = NULL;
            tail = NULL;
        }

        void insert(T value) {
            if(isEmpty()) {
                head = new Node<T>(value);
                tail = head;
            }
            else {
                Node<T>* newNode = new Node<T>(value);
                tail->next = newNode;
                tail = newNode;
            }
        }

        T remove_front() {
            T val = 0;
            if(head != NULL) {
                val = head->value;
                head = head->next;
            }

            return val;
        }

        void remove(T value) {
            if(head->value == value) {
                remove_front();
                return;
            }

            Node<T>* pivot = head;
            while(pivot != NULL) {
                if(pivot->next->value == value) break;
                pivot = pivot->next;
            }

            pivot->next = pivot->next->next;
        }

        Node<T>* search(T value) {
            Node<T>* pivot = head;
            while(pivot != NULL && pivot->value != value) {
                pivot = pivot->next;
            }

            return pivot;
        }

        bool isEmpty() {
            if(head == NULL) return true;
            return false;
        }
};
