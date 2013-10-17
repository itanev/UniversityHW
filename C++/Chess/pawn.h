#ifndef PAWN
#define PAWN

class Pawn : public Figure
{
public:
    Pawn(bool color)
    {
        moved = false;
        symbol = 'P';
        this->color = color;
        moves.push_back(OneDiagonal);
        moves.push_back(OneForward);
        moves.push_back(PawnMove);
    };

    Pawn* clone() const
    {
        return new Pawn(*this);
    }
};

#endif // PAWN
