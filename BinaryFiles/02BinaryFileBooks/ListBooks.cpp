#include <iostream>
#include <fstream>
#include "book.h";
#include "bookFunctions.h";

using namespace std;

int main()
{
    fstream listBooks("listBooks.bin", ios::in|ios::out|ios::binary|ios::app);

    if(listBooks.is_open())
    {
        for(int i = 0; i < 10; i++)
        {
            //read book
            cout << "--------Enter book #" << i << "--------" << endl;
            Book currBook;
            if(i != 0) cin.ignore(1000, '\n');
            readBook(currBook);
            cout << "-----------------------------------" << endl;

            //write book to file
            writeBook(currBook, listBooks);
        }

        cout << "Books successfully written to file. ";
    }

    listBooks.close();
    return 0;
}
