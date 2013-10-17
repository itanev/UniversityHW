#ifndef QUEEN
#define QUEEN

class Queen : public Figure
{
public:
    Queen(bool color)
    {
        moved = false;
        symbol = 'Q';
        this->color = color;
        moves.push_back(EntireCol);
        moves.push_back(EntireRow);
        moves.push_back(EntireDiagonal);
    };

    Queen* clone() const
    {
        return new Queen(*this);
    }
};

#endif
