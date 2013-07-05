#ifndef OFFICER
#define OFFICER

class Officer : public Figure
{
public:
    Officer(bool color)
    {
        moved = false;
        symbol = 'O';
        this->color = color;
        moves.push_back(EntireDiagonal);
    };

    Officer* clone() const
    {
        return new Officer(*this);
    }
};

#endif


