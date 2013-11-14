#include <iostream>
#include <string>

template <class T>
class List {
    T * arr;
    int size = 4;
    int count = 0;

    public:
        List() {
            this->arr = new T[4];
        }

        T& first() {
            return arr[1];
        }

        void removeFirst() {
            T * newArr = new T[size];

            for(int i = 1; i < size; i++) {
                newArr[i - 1] = this->arr[i];
            }

            this->arr = new T[size];

            for(int i = 0; i < size; i++) {
                this->arr[i] = newArr[i];
            }

            delete newArr;
        }

        void push_back(T item) {
            count++;
            if(size <= count) {
                T * extended = new T[size];
                size *= 2;

                for(int i = 0; i < count; i++) {
                    extended[i] = this->arr[i];
                }

                delete this->arr;
                this->arr = new T[size * 2];

                for(int i = 0; i < count; i++) {
                    this->arr[i] = extended[i];
                }

                delete extended;
            }

            this->arr[count] = item;
        }

        T& pop_back() {
            T item = this->arr[count];
            count--;
            return item;
        }

        T& back() {
            if(this->empty()) {
                throw (std::string)"The stack is empty.";
            }
            else {
                return this->arr[count];
            }
        }

        bool empty() {
            if(count == 0) {
                return true;
            }

            return false;
        }
};
