#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "../02BinaryFileBooks/book.h";
#include "../02BinaryFileBooks/bookFunctions.h";

using namespace std;

void copy(string& str, char* prop) {
    for(int i = 0; i < str.size(); i++)
    {
        prop[i] = str[i];
    }

    delete[] prop;
}

Genre getGenre(string prop) {
    if(prop == "Criminal")              return CRIMINAL;
    else if(prop == "Fairy Tale")       return FAIRY_TALE;
    else if(prop == "Fantasy")          return FANTASY;
    else if(prop == "Graphic Novel")    return GRAPHIC_NOVEL;
    else if(prop == "Romance")          return ROMANCE;
    else if(prop == "Science Fiction")  return SCIENCE_FICTION;
    else return OTHER;
}

//sry for the long method
void readBook(Book& newBook, ifstream& file) {
    string entireLine, actualInfo;

    unsigned splitIndex = 0;
    int i = 0;
    string property;

    for(int k = 0; k < 6; k++)  //six is the number of properties book has
    {
        getline(file, entireLine);

        splitIndex = entireLine.find(" - ");

        i = 0;
        while(splitIndex+3+i < entireLine.size())
        {
            property.push_back(entireLine[splitIndex+3+i]);
            i++;
        }
        //write book to struct
        switch(k)
        {
            case 0:
                copy(property, newBook.isbn);
                break;
            case 1:
                copy(property, newBook.title);
                break;
            case 2:
                copy(property, newBook.author);
                break;
            case 3:
                newBook.genre = getGenre(property);
                break;
            case 4:
                newBook.numberOfPages = atoi( property.c_str() );
                break;
            case 5:
                newBook.publishYear = atoi( property.c_str() );
                break;
        }
        property.clear();
     }
     getline(file, entireLine);  //ignore line
     getline(file, entireLine);  //ignore line
}

void writeBookToFile(Book& theBook, fstream& file) {
    if(theBook.genre == CRIMINAL) return;

    if(theBook.publishYear < 1999)
    {
        theBook.numberOfPages += 20;
        writeBook(theBook, file);
    }
}

int main() {
    ifstream listBooks("../02BinaryFileBooks/listBooks.bin", ios::in|ios::binary);
    fstream correctList("correctList.bin", ios::out|ios::binary);
    string temp;

    if(listBooks.is_open() && correctList.good())
    {
        Book newBook;

        while(getline(listBooks, temp))
        {
            readBook(newBook, listBooks);
            writeBookToFile(newBook, correctList);

            //empty the char arrays (c++ 11)
            newBook.isbn = {};
            newBook.author = {};
            newBook.title = {};
        }
    }
    else
        cout << "File not fount.";

    return 0;
}
