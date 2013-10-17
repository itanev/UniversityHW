using namespace std;

//prototypes
void PrintGenre(Genre genre, fstream& file);
void EnterBookGenre(Book& theBook);
bool cmp(const char * str1, const char * str2);

//print book in readable format
void writeBook(const Book& book, fstream& file)
{
    file << "----------Book----------"                  << endl;
    file << "ISBN - "           << book.isbn            << endl;
    file << "Title - "          << book.title           << endl;
    file << "Author - "         << book.author          << endl;
    file << "Genre - ";            PrintGenre(book.genre, file);
    file << "Number of pages - "<< book.numberOfPages   << endl;
    file << "Publish year - "   << book.publishYear     << endl;
    file << "------------------------"                  << endl;
    file << endl;
}

//read information about the book - optimized
void readBook(Book& newBook)
{
    cout << "Enter ISBN: ";
    cin.getline(newBook.isbn, 14);

    cout << "Enter title: ";
    cin.getline(newBook.title, size+1);

    cout << "Enter Author: ";
    cin.getline(newBook.author, size+1);

    EnterBookGenre(newBook);

    cout << "Enter book pages: ";
    cin >> newBook.numberOfPages;

    cout << "Enter book publish year: ";
    cin >> newBook.publishYear;
}

//compare two books
void compare(const Book * firstBook, const Book * secondBook)
{
    //compare isbn
    if(cmp(firstBook->isbn, secondBook->isbn))
        cout << "ISBN - same" << endl;
    else
        cout << "ISBN - not the same" << endl;

    //compare titles
    if(cmp(firstBook->title, secondBook->title))
        cout << "Title - same" << endl;
    else
        cout << "Title - not the same" << endl;

    //compare authors
    if(cmp(firstBook->author, secondBook->author))
        cout << "Author - same" << endl;
    else
        cout << "Author - not the same" << endl;

    //compare genres
    if(firstBook->genre == secondBook->genre)
        cout << "Genres - same" << endl;
    else
        cout << "Genres - not the same" << endl;

    //compare number pages
    if(firstBook->numberOfPages == secondBook->numberOfPages)
        cout << "Number of pages - same" << endl;
    else
        cout << "Number of pages - not the same" << endl;

    //compare publish year
    if(firstBook->publishYear == secondBook->publishYear)
        cout << "Publish year - same" << endl;
    else
        cout << "Publish year - not the same" << endl;
}

//compare strings
bool cmp(const char * str1, const char * str2)
{
    int i = 0;

    while(str1[i] != '\0' || str2[i] != '\0')
    {
        if(str1[i] != str2[i])
            return false;

        i++;
    }

    return true;
}

//helper function for printing genre in readable format
void PrintGenre(Genre genre, fstream& file)
{
    switch(genre)
    {
        case 1 :
            file << "Criminal" << endl;
            break;
        case 2 :
            file << "Fairy Tale" << endl;
            break;
        case 3 :
            file << "Fantasy" << endl;
            break;
        case 4 :
            file << "Graphic Novel" << endl;
            break;
        case 5 :
            file << "Romance" << endl;
            break;
        case 6 :
            file << "Science Fiction" << endl;
            break;
        default :
            file << "Other" << endl;
            break;
    }
}

//helper function for entering book genre
int EnterGenreChoice()
{
    int genreIndex = 7;

    cout << "Enter Genre:"          << endl;
    cout << "1 for Criminal"        << endl;
    cout << "2 for Fairy Tale"      << endl;
    cout << "3 for Fantasy"         << endl;
    cout << "4 for Graphic Novel"   << endl;
    cout << "5 for Romance"         << endl;
    cout << "6 for Science Fiction" << endl;
    cout << "7 for Other"           << endl;
    cin >> genreIndex;

    return genreIndex;
}

//helper function for inputing book genre
void EnterBookGenre(Book& theBook)
{
    switch(EnterGenreChoice())
    {
        case 1 :
            theBook.genre = CRIMINAL;
            break;
        case 2 :
            theBook.genre = FAIRY_TALE;
            break;
        case 3 :
            theBook.genre = FANTASY;
            break;
        case 4 :
            theBook.genre = GRAPHIC_NOVEL;
            break;
        case 5 :
            theBook.genre = ROMANCE;
            break;
        case 6 :
            theBook.genre = SCIENCE_FICTION;
            break;
        default :
            theBook.genre = OTHER;
            break;
    }
}

