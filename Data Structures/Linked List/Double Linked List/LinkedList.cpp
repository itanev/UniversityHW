template<class T>
class LinkedList {
    Node<T>* sentinel;
    int count;

    void createEmptySentinel() {
        delete sentinel;
        sentinel = new Node<T>();
        count = 0;
    }

    public:
        LinkedList() {
            sentinel = new Node<T>();
            count = 0;
        }

        void insert(T val) {
            Node<T>* newNode = new Node<T>(val);
            if(isEmpty()) {
                sentinel->next = newNode;
                sentinel->prev = newNode;
                newNode->next = sentinel->next;
                newNode->prev = sentinel;
            }
            else {
                newNode->next = sentinel->next;
                sentinel->next->prev = newNode;
                sentinel->next = newNode;
                newNode->prev = sentinel;
            }
            count++;
        }

        void remove(T val) {
            Node<T>* nodeToRemove = search(val);
            nodeToRemove->next->prev = nodeToRemove->prev;
            nodeToRemove->prev = nodeToRemove->next;
            delete nodeToRemove;
            count--;
        }

        void remove_front() {
            count--;
            if(sentinel->prev == sentinel->next) {
                createEmptySentinel();
            }
            else {
                sentinel->next = sentinel->next->next;
                delete sentinel->next->prev;
                sentinel->next->prev = sentinel;
            }
        }

        void remove_back() {
            count--;
            if(sentinel->prev == sentinel->next) {
                createEmptySentinel();
            }
            else {
                sentinel->prev = sentinel->prev->prev;
                delete sentinel->prev->next;
                sentinel->prev->next = sentinel;
            }
        }

        Node<T>* search(T val) {
            Node<T>* pivot = sentinel;
            bool found = false;

            for(int i = 0; i <= count; i++) {
                if(pivot->value == val) {
                    found = true;
                    break;
                }

                pivot = pivot->next;
            }

            if(!found) return sentinel;
            else return pivot;
        }

        int size() {
            return count;
        }

        bool contains(T val) {
            return search(val) != sentinel;
        }

        bool isEmpty() {
            if(count == 0) return true;
            return false;
        }
};
