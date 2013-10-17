static const int size = 50;

enum Genre {
    CRIMINAL = 1, FAIRY_TALE, FANTASY, GRAPHIC_NOVEL, ROMANCE, SCIENCE_FICTION, OTHER
};

struct Book
{
    char isbn[13];
    char title[size];
    char author[size];
    Genre genre;
    int numberOfPages;
    int publishYear;
};
