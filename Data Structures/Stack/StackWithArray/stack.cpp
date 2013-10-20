class Stack : public StackAbstract {
    private: List<int> conn;
    public:
        void push(int item) {
            conn.push_back(item);
        }

        int& top() {
            return conn.back();
        }

        int& pop() {
            int lastElement = conn.back();
            conn.pop_back();
            return lastElement;
        }

        bool isEmpty() {
            return conn.empty();
        }
};
