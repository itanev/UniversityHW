#ifndef BLACK_PLAYER
#define BLACK_PLAYER

class BlackPlayer : public virtual Player, public virtual WhitePlayer
{
    void getPosibleMovesPawn(int currRow, int currCol, Field& gameField)
    {
        if(currRow == 1 &&
           !gameField.getFigure(currRow, currCol).moved)
        {
            field[currRow + 1][currCol] = true;
            field[currRow + 2][currCol] = true;
        }

        gameField.getFigure(currRow, currCol).moved = true;

        if(currRow + 1 < dimentions &&
           currCol + 1 < dimentions &&
           !gameField.isCellFree(currRow + 1, currCol + 1))
        {
            field[currRow + 1][currCol + 1] = true;
        }

        if(currRow + 1 < dimentions &&
           currCol - 1 >= 0 &&
           !gameField.isCellFree(currRow + 1, currCol - 1))
        {
            field[currRow + 1][currCol - 1] = true;
        }
    }

protected:
    bool validateColor(bool validColor, bool color)
    {
        return validColor != color;
    }

public:
    bool moveFigure(int currRow, int currCol, int newRow, int newCol, Field& gameField)
    {
        return WhitePlayer::moveFigure(currRow, currCol, newRow, newCol, gameField);
    }
};

#endif // BLACK_PLAYER
