#ifndef FIGURE
#define FIGURE

class Figure
{
protected:
    std::vector<Moves> moves;
    char symbol;
    bool color;
public:
    bool moved;

    Figure(){}

    Figure(char symbol, bool color)
    {
        this->symbol = symbol;
        this->color = color;
    }

    Figure(const Figure* other)
    {
        this->moves = other->moves;
    }

    virtual Figure& operator =(const Figure& other)
    {
        this->moves = other.moves;
        return *this;
    }

    virtual Figure* clone() const = 0;

    virtual const std::vector<Moves>* GetMoves() const
    {
        return &moves;
    }

    char getSymbol()
    {
        return symbol;
    }

    bool getColor()
    {
        return color;
    }

    virtual ~Figure() {}
};

#endif // FIGURE
