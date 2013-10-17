#ifndef KING
#define KING

class King : public Figure
{
public:
    King(bool color)
    {
        moved = false;
        symbol = 'K';
        this->color = color;
        moves.push_back(OneDiagonal);
        moves.push_back(OneForward);
        moves.push_back(OneBackward);
        moves.push_back(OneLeft);
        moves.push_back(OneRight);
    };

    King* clone() const
    {
        return new King(*this);
    }
};

#endif // KING
