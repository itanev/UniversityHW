template<class T>
class Queue : public AbstractQueue<T>
{
    Node<T>* head;
    Node<T>* tail;

    public:
        Queue() {
            head = NULL;
            tail = NULL;
        }

        void enqueue(T value) {
            if(tail == NULL) {
                tail = new Node<T>(value);
                head = tail;
            }
            else {
                Node<T> *newNode = new Node<T>(value);
                tail->next = newNode;
                tail = tail->next;
            }
        }

        T dequeue() {
            Node<T>* currHead(head);
            head = currHead->next;
            return currHead->value;
        }

        T peek() {
            if(isEmpty()) return NULL;
            return head->value;
        }

        bool isEmpty() {
            if(head == NULL) return true;
            return false;
        }
};
