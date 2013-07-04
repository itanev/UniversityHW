#ifndef PLAYER
#define PLAYER

class Player
{
    protected:
        static const int dimentions = 8;
        bool field[dimentions][dimentions];
    public:
        virtual bool moveFigure(int currRow, int currCol, int newRow, int newCol, Field& gameField) = 0;
};

#endif;
