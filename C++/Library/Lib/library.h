static const int LIBRARY_CAPACITY = 10;

struct Library
{
    char name[24];
    Book books[LIBRARY_CAPACITY];
    int numberOfBooks;

    Library(int numberBooks)
    {
        numberOfBooks = numberBooks;
    }
};
