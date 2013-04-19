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

            Iterator(RationalDynamicArray * arr, int i)
                : currArray(arr), index(i) { }

            friend class RationalDynamicArray;

        public:
            Iterator() { currArray = NULL; index = 0; }
            ~Iterator() { delete[] currArray; }

            RationalDynamicArray * getCurrArrayIterator() { return this->currArray + this->index; }

            RationalDynamicArray& operator *() { return currArray[index]; }
            RationalDynamicArray * operator ->() { return currArray + index; }

            bool operator ==(Iterator& currIterator)
            {
                if(currIterator.getCurrArrayIterator() == ( currArray + index ) ) return true;
                else return false;
            }

            bool operator !=(Iterator& currIterator)
            {
                if(currIterator.getCurrArrayIterator() != ( currArray + index ) ) return true;
                else return false;
            }

            RationalDynamicArray* operator ++() { ++index; return currArray + index; }
            RationalDynamicArray* operator --() { --index; return currArray + index; }

            RationalDynamicArray* operator ++(int)
            {
                int currIndex = index;
                ++index;
                return currArray + currIndex;
            }

            RationalDynamicArray* operator --(int)
            {
                int currIndex = index;
                --index;
                return currArray - currIndex;
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
        return Iterator(this, 0);
    }

    Iterator end() {
        return Iterator(this, size);
    }
};

#endif
