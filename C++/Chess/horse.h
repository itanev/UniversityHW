#ifndef HORSE
#define HORSE

class Horse : public Figure
{
public:
    Horse(bool color)
    {
        moved = false;
        symbol = 'H';
        this->color = color;
        moves.push_back(HorseMove);
    };

    Horse* clone() const
    {
        return new Horse(*this);
    }
};

#endif

