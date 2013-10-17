#ifndef RATIONAL_DYNAMIC_ARRAY_H
#define RATIONAL_DYNAMIC_ARRAY_H

#include <iterator>
#include "../../Rational/Lib/Exception.h"
#include "../../Rational/Lib/Rational.h"
#include "../../Rational/Lib/RationalMethods.h"

class RationalDynamicArray {
	Rational* arr;
	int capacity;
	int size;

	void copyArr(const Rational* arr);
	void ensureSpace();

public:
    class Iterator : public std::iterator <std::bidirectional_iterator_tag, Rational>
    {
        private:
            RationalDynamicArray * currArray;

            int index;

            Iterator(RationalDynamicArray& arr, int i)
                : currArray(&arr), index(i) {}

            friend class RationalDynamicArray;

        public:
            Iterator() { currArray = NULL; index = 0; }
            Iterator(const Iterator& other) { currArray = other.currArray; index = other.index; }
            ~Iterator() {}

            Rational& operator *() { return (*currArray)[index]; }
            Rational * operator ->() { return &(*currArray)[index]; }

            bool operator ==(const Iterator& currIterator) const
            {
                if( currArray == currIterator.currArray && index == currIterator.index) return true;
                return false;
            }

            bool operator !=(const Iterator& currIterator) const
            {
                if( !(*this == currIterator) ) return true;
                return false;
            }

            Iterator& operator ++() { ++index; return *this; }
            Iterator& operator --() { --index; return *this; }

            Iterator operator ++(int)
            {
                Iterator currIterator = *this;
                ++index;
                return currIterator;
            }

            Iterator operator --(int)
            {
                Iterator currIterator = *this;
                --index;
                return currIterator;
            }
    };

	RationalDynamicArray();
	RationalDynamicArray(const RationalDynamicArray& other);
	~RationalDynamicArray();
	RationalDynamicArray operator=(const RationalDynamicArray& other);

	void push(const Rational& rat);
	void insertAt(int index, const Rational& rat);
	void pop();
	void removeAt(int index);
	Rational& get(int index);
	const Rational& get(int index) const;
	void set(int index, const Rational& rat);
	int getSize() const;

	void swap(RationalDynamicArray& other);

	Rational& operator [](int index);
	const Rational& operator [](int index) const;

	void operator <<(const Rational& rat);
	void operator >>(Rational& rat);
	void operator <<(const RationalDynamicArray& other);

	operator bool() const;

	void operator ()(Rational (*f)(const Rational&));

    Iterator begin() {
        return Iterator(*this, 0);
    }

    Iterator end() {
        return Iterator(*this, size);
    }
};

#endif
