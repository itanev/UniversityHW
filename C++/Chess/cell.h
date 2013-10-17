#ifndef CELL
#define CELL

class Cell
{
    Figure* figure;
public:
    bool free;

    Cell()
    {
        free = true;
        figure = NULL;
    }

    void setFigure(Figure* someFigure)
    {
        if(someFigure == NULL)
        {
            delete figure;
            figure = NULL;
            free = true;
        }
        else
        {
            free = false;
            delete figure;
            figure = someFigure->clone();
        }
    }

    Figure& getFigure()
    {
        return *figure;
    }

    ~Cell()
    {
        delete figure;
    }
};

#endif // CELL
