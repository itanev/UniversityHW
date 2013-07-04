#ifndef FIELD
#define FIELD

class Field
{
    static const int fieldDimentions = 8;
    std::vector<Cell> field[fieldDimentions];
public:
    Field()
    {
        for(int row = 0; row < fieldDimentions; ++row)
        {
            for(int col = 0; col < fieldDimentions; ++col)
            {
                Cell currCell;
                field[row].push_back(currCell);
            }
        }
    }

    bool isCellFree(int row, int col)
    {
        return field[row][col].free;
    }

    void setFigure(int row, int col, Figure* figure)
    {
        field[row][col].setFigure(figure);
    }

    int getDimentions()
    {
        return (int)fieldDimentions;
    }

    Figure& getFigure(int row, int col)
    {
        return field[row][col].getFigure();
    }
};

#endif // FIELD
