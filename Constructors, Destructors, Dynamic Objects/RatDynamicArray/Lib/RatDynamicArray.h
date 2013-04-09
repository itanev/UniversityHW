#ifndef RatDynamic
#define RatDynamic

class RatDynamicArray {
    private:
        unsigned arraySize;
        unsigned capacity;
        Rational * array;

        void swapFields(RatDynamicArray& arr);
        void resize();
        void moveElements(unsigned index);
    public:
        RatDynamicArray();
        RatDynamicArray(const RatDynamicArray& otherArray);

        RatDynamicArray& operator=(const RatDynamicArray& other);
        void push(const Rational& rat);
        void insertAt(int index, const Rational& rat);
        void pop();
        void removeAt(int index);
        Rational& get(int index);
        const Rational& get(int index) const;
        void set(int index, const Rational& rat);
        unsigned getSize() const;

        ~RatDynamicArray();
};

#endif // RatDynamicArray

