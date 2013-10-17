#ifndef ROOK
#define ROOK

class Rook : public Figure
{
public:
    Rook(bool color)
    {
        moved = false;
        symbol = 'R';
        this->color = color;
        moves.push_back(EntireCol);
        moves.push_back(EntireRow);
    };

    Rook* clone() const
    {
        return new Rook(*this);
    }
};

#endif

