using namespace std;

//prototypes
int abs(int yearDifference);

//add book
bool addBook(Library * library, const Book& book)
{
    library->numberOfBooks++;

    if(library->numberOfBooks <= LIBRARY_CAPACITY)
    {
        library->books[library->numberOfBooks-1] = book;
        return true;
    }
    else
        return false;
}

//print library info
void printLibraryInfo(const Library * library)
{
    cout << endl << "--------" << library->name << "--------" << endl;

    for(int i = 0; i < library->numberOfBooks; i++)
    {
        printBook(library->books[i]);
    }
}

//print book by isbn - !!!isbn number must be 13 characters
void printBookByISBN(const Library * library, const char * isbn)
{
    bool match = true;
    int k = 0;

    for(int i = 0; i < library->numberOfBooks; i++)
    {
        match = true;
        k = 0;

        while(library->books[i].isbn[k] != '\0' || isbn[k] != '\0')
        {
            if( library->books[i].isbn[k] != isbn[k] )
            {
                match = false;
                break;
            }
            k++;
        }

        if(match)
            printBook(library->books[i]);
    }
}

//print book by author
void printBookByAuthor(const Library * library, const char * author)
{
    bool match = true;
    int k = 0;

    for(int i = 0; i < library->numberOfBooks; i++)
    {
        match = true;
        k = 0;

        while(author[k] != '\0')
        {
            if( library->books[i].author[k] != author[k] )
            {
                match = false;
                break;
            }
            k++;
        }

        if(match)
            printBook(library->books[i]);
    }
}

//print book by genre
void printBookByGenre(const Library * library, const int &gen)
{
    for(int i = 0; i < library->numberOfBooks; i++)
    {
        if(library->books[i].genre == gen)
            printBook(library->books[i]);
    }
}

//sort books
void SortBooks(Library * library)
{
    int next = 0;
    int j = 0;

    //bubble sort
    for(int i = 0; i < library->numberOfBooks; i++)
    {
        for(int k = i; k < library->numberOfBooks; k++)
        {
            next = k + 1;
            j = 0;

            //swap books if genres are different
            if(library->books[k].genre > library->books[next].genre && next < library->numberOfBooks)
                swap(library->books[k], library->books[next]);

            //sort by title if genres are the same
            if(library->books[k].genre == library->books[next].genre && next < library->numberOfBooks)
            {
                while( library->books[k].title[j] != '\0' ||
                       library->books[next].title[j] != '\0')
                {
                    if(library->books[k].title[j] > library->books[next].title[j])
                    {
                        swap(library->books[k], library->books[next]);
                        break;
                    }
                    j++;
                }
            }
        }
    }
}

// year difference between books with min/max pages
void minMaxYearDifference(const Library * library)
{
    int min = 0, max = 0;
    int currMinPages = library->books[0].numberOfPages;
    int currMaxPages = library->books[0].numberOfPages;

    for(int i = 1; i < library->numberOfBooks; i++)
    {
        if(library->books[i].numberOfPages < currMinPages)
        {
            currMinPages = library->books[i].numberOfPages;
            min = i;
        }

        if(library->books[i].numberOfPages > currMaxPages)
        {
            currMaxPages = library->books[i].numberOfPages;
            max = i;
        }
    }

    cout << "Year difference: " << abs((library->books[min].publishYear - library->books[max].publishYear)) << endl;
}

//get the absolute value (abs in cmath)
int abs(int yearDifference)
{
    if(yearDifference < 0)
        return yearDifference*(-1);

    return yearDifference;
}

//get book index
int GetBookIndex(const Library * library)
{
    int choice = 0;

    cout << "Enter a number between 1 and " << library->numberOfBooks << endl;
    cin >> choice;

    while(choice < 1 || choice > library->numberOfBooks)
    {
        cout << "Wrong choice!" << endl;
        cout << "Enter a number between 1 and " << library->numberOfBooks << endl;
        cin >> choice;
    }

    return choice-1;
}
