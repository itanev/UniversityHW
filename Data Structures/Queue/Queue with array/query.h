#include<iostream>
template <class T>
class Query
{
    List<T> con;
    public:
        void push(T item)
        {
            con.push_back(item);
        }

        T pop()
        {
            T item = con.first();
            con.removeFirst();
            return item;
        }

        T peek()
        {
            return con.first();
        }
};
