#ifndef RatDynamicMethods
#define RatDynamicMethods

//default constructor
RatDynamicArray::RatDynamicArray()
{
    capacity = 4;
    arraySize = 0;
    array = (Rational*) operator new[](sizeof(Rational) * capacity);
}

//copy constructor
RatDynamicArray::RatDynamicArray(const RatDynamicArray& otherArray)
{
    if (this != &otherArray)
    {
        RatDynamicArray temp(otherArray);
        swapFields(temp);
    }
}

//swap method
void RatDynamicArray::swapFields(RatDynamicArray& arr)
{
    std::swap(capacity, arr.capacity);
    std::swap(arraySize, arr.arraySize);
    std::swap(array, arr.array);
}

//resize method
void RatDynamicArray::resize()
{
    capacity *= 2;
    Rational * tempArr = (Rational*) operator new[](sizeof(Rational) * capacity);

    for(unsigned i = 0; i < arraySize; i++)
    {
        new (tempArr + i++) Rational(array[i]);
    }

    delete[] array;
    array = tempArr;
    delete[] tempArr;
}

//move elements method
void RatDynamicArray::moveElements(unsigned index)
{
    unsigned i = arraySize+1;

    if(arraySize >= capacity) resize();

    while(i >= index)
    {
        i--;
        swap(array[i], array[i+1]);
        if( i == 0 ) break;
    }
}

//getSize method
unsigned RatDynamicArray::getSize() const
{
    return arraySize;
}

//push method
void RatDynamicArray::push(const Rational& rat)
{
    if(arraySize < capacity)
        new(array + arraySize++) Rational(rat);
    else
    {
        resize();
        new(array + arraySize++) Rational(rat);
    }
}

//insertAt method
void RatDynamicArray::insertAt(int index, const Rational& rat)
{
    if(arraySize >= capacity) resize();

    while(index >= capacity) resize();

    arraySize++;
    if(index > arraySize)
    {
        arraySize = index;
        new(array + index) Rational(rat);
    }
    else
    {
        moveElements(index);
        new(array + index) Rational(rat);
    }
}

//pop method
void RatDynamicArray::pop()
{
    new(array + arraySize) Rational();
    arraySize--;
}

//removeAt method
void RatDynamicArray::removeAt(int index)
{
    if(index <= arraySize) new(array + index) Rational();
}

//get method - value can be changed
Rational& RatDynamicArray::get(int index)
{
    return array[index];
}

//get method - return read only value
const Rational& RatDynamicArray::get(int index) const
{
    return array[index];
}

//set element method
void RatDynamicArray::set(int index, const Rational& rat)
{
    array[index] = rat;
}

//predifine operator '=' using copy constructor implementation
RatDynamicArray& RatDynamicArray::operator=(const RatDynamicArray& other)
{
    if (this != &other)
    {
        RatDynamicArray temp(other);
        swapFields(temp);
    }

    return *this;
}

//destructor
RatDynamicArray::~RatDynamicArray()
{
    delete[] array;
}

#endif
