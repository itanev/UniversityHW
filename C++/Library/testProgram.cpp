/*
#   Iliqn Tanev №44846
*/

#include <iostream>
#include "Lib/book.h"
#include "Lib/bookFunctions.h"
#include "Lib/library.h"
#include "Lib/libraryFunctions.h"

using namespace std;

void Menu(Library * lib);
void EnterChoice(char * choice);

int main()
{
   //empty library
    Library lib(0);
    cout << "Enter library name: ";
    cin.getline(lib.name, 25);

   //first book
    cout << endl << "--------Enter first book:--------" << endl;
    Book firstBook;
    readBook(firstBook);

    if(addBook(&lib, firstBook))
        cout << "Book added." << endl;
    else
        cout << "Library overload" << endl;

   //second book
    cout << endl << "--------Enter second book:--------" << endl;
    Book secondBook;

    cin.ignore(1000, '\n');
    readBook(secondBook);

    if(addBook(&lib, secondBook))
        cout << "Book added." << endl;
    else
        cout << "Library overload" << endl;

   //third book
    cout << endl << "--------Enter third book:--------" << endl;
    Book thirdBook;

    cin.ignore(1000, '\n');
    readBook(thirdBook);

    if(addBook(&lib, thirdBook))
        cout << "Book added." << endl;
    else
        cout << "Library overload" << endl;

    cout << endl;
   //menu
    Menu(&lib);

    int choice = 2;

    cout << "Enter 1 to get back to menu or 2 to exit: ";
    cin >> choice;

    bool eMatch = true, mMatch = true;

    while(choice)
    {
        if(choice == 1)
            Menu(&lib);
        else
        {
            cout << "Goodbye!";
            return 0;
        }

        cout << "Enter 1 to get back to menu or 2 to exit: ";
        cin >> choice;
    }

    return 0;
}

void PrintUIMenu()
{
    cout << "--------------Menu:--------------" << endl;
    cout << "Enter 1 to print entire library:"  << endl;
    cout << "Enter 2 to print books by ISBN:"   << endl;
    cout << "Enter 3 to print books by author:" << endl;
    cout << "Enter 4 to print books by genre:"  << endl;
    cout << "Enter 5 to sort books by genre:"   << endl;
    cout << "Enter 6 to find the difference in publish years"           << endl
         << "for book with minimum pages and book with maximum pages:"  << endl;
    cout << "Enter 7 to compare two books:"     << endl;
}

void Menu(Library * lib)
{
    int choice = 1;
    char isbn[13];
    char authorName[size];

    PrintUIMenu();

    cout << "Choice: ";
    cin >> choice;

    cin.ignore(1000, '\n');
    switch(choice)
    {
        case 1:
            printLibraryInfo(lib);
            break;
        case 2:
            cout << "Enter ISBN: ";
            cin.getline(isbn, 14);
            printBookByISBN(lib, isbn);
            break;
        case 3:
            cout << "Enter author name: ";
            cin.getline(authorName, size+1);
            printBookByAuthor(lib, authorName);
            break;
        case 4:
            printBookByGenre(lib, EnterGenreChoice());
            break;
        case 5:
            SortBooks(lib);
            break;
        case 6:
            minMaxYearDifference(lib);
            break;
        case 7:
            compare( &(lib->books[GetBookIndex(lib)]), &(lib->books[GetBookIndex(lib)]) );
            break;
    }
}
