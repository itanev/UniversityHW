#ifndef BLACK_PLAYER
#define BLACK_PLAYER

class BlackPlayer : public virtual Player, public virtual WhitePlayer
{
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
