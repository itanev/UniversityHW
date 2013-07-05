#ifndef WHITE_PLAYER
#define WHITE_PLAYER

class WhitePlayer : public virtual Player
{
    void getPosibleMovesOneDiagonal(int currRow, int currCol)
    {
        if( (currRow + 1) < dimentions && (currCol + 1) < dimentions)
            field[currRow + 1][currCol + 1] = true;
        if(currRow - 1 >= 0 && currCol - 1 >= 0)
            field[currRow - 1][currCol - 1] = true;
        if(currRow + 1 < dimentions && currCol - 1 >= 0)
            field[currRow + 1][currCol - 1] = true;
        if(currRow - 1 >= 0 && currCol + 1 < dimentions)
            field[currRow - 1][currCol + 1] = true;
    }

    void getPosibleMovesEntireDiagonal(int currRow, int currCol)
    {
        int startRow = currRow;
        int startCol = currCol;
        while(startRow < dimentions && startCol < dimentions)
        {
            field[startRow][startCol] = true;
            ++startRow;
            ++startCol;
        }
        startRow = currRow;
        startCol = currCol;
        while(startRow >= 0 && startCol >= 0)
        {
            field[startRow][startCol] = true;
            --startRow;
            --startCol;
        }
    }

    void getPosibleMovesHorse(int currRow, int currCol)
    {
        if(currRow + 2 < dimentions && currCol + 1 < dimentions)
            field[currRow + 2][currCol + 1] = true;
        if(currRow + 2 < dimentions && currCol - 1 >= 0)
            field[currRow + 2][currCol - 1] = true;
        if(currRow - 2 >= 0 && currCol + 1 < dimentions)
            field[currRow - 2][currCol + 1] = true;
        if(currRow - 2 >= 0 && currCol - 1 >= 0)
            field[currRow - 2][currCol - 1] = true;
        if(currCol + 2 < dimentions && currRow + 1 < dimentions)
            field[currRow + 1][currCol + 2] = true;
        if(currCol + 2 < dimentions && currRow - 1 >= 0)
            field[currRow - 1][currCol + 2] = true;
        if(currCol - 2 >= 0 && currRow + 1 < dimentions)
            field[currRow + 1][currCol - 2] = true;
        if(currCol - 2 >= 0 && currRow - 1 >= 0)
            field[currRow - 1][currCol - 2] = true;
    }

    virtual void getPosibleMovesPawn(int currRow, int currCol, Field& gameField)
    {
        if(currRow == dimentions - 2 &&
           !gameField.getFigure(currRow, currCol).moved)
        {
            field[currRow - 1][currCol] = true;
            field[currRow - 2][currCol] = true;
        }

        gameField.getFigure(currRow, currCol).moved = true;

        if(currRow - 1 >= 0 &&
           currCol - 1 >= 0 &&
           !gameField.isCellFree(currRow - 1, currCol - 1))
        {
            field[currRow - 1][currCol - 1] = true;
        }

        if(currRow - 1 >= 0 &&
           currCol + 1 <= dimentions &&
           !gameField.isCellFree(currRow - 1, currCol + 1))
        {
            field[currRow - 1][currCol + 1] = true;
        }
    }

    void getPosibleMoves(std::vector<Moves> moves, int currRow, int currCol, Field& gameField)
    {
        for(int i = 0; i < moves.size(); ++i)
        {
            switch( moves[i] )
            {
                case OneForward:
                    if(currRow - 1 >= 0)
                        field[currRow - 1][currCol] = true;
                    break;
                case OneBackward:
                    if(currRow + 1 < dimentions)
                        field[currRow + 1][currCol] = true;
                    break;
                case OneLeft:
                    if(currCol - 1 >= 0)
                        field[currRow][currCol - 1] = true;
                    break;
                case OneRight:
                    if(currCol + 1 < dimentions)
                        field[currRow][currCol + 1] = true;
                    break;
                case OneDiagonal:
                    getPosibleMovesOneDiagonal(currRow, currCol);
                    break;
                case EntireRow:
                    for(int k = 0; k < dimentions; ++k)
                        field[currRow][k] = true;
                    break;
                case EntireCol:
                    for(int k = 0; k < dimentions; ++k)
                        field[k][currCol] = true;
                    break;
                case EntireDiagonal:
                    getPosibleMovesEntireDiagonal(currRow, currCol);
                    break;
                case Horse:
                    getPosibleMovesHorse(currRow, currCol);
                    break;
                case PawnMove:
                    getPosibleMovesPawn(currRow, currCol, gameField);
                    break;
            }
        }
    }

    bool inRange(int row, int col)
    {
        return (row < 0 ||
               row >= dimentions ||
               col < 0 ||
               col >= dimentions);
    }

protected:
    virtual bool validateColor(bool validColor, bool color)
    {
        return validColor == color;
    }

public:
    bool moveFigure(int currRow, int currCol, int newRow, int newCol, Field& gameField)
    {
        if(inRange(currRow, currCol) &&
           inRange(newRow, newCol)) return false;

        if(gameField.isCellFree(currRow, currCol)) return false;

        if(!gameField.isCellFree(newRow, newCol) &&
           gameField.getFigure(newRow, newCol).getSymbol() == 'K')
        {
            return false;
        }

        memset(field, false, sizeof(field));
        field[currRow][currCol] = true;
        Figure * currFigure = gameField.getFigure(currRow, currCol).clone();

        if( !validateColor(currFigure->getColor(), true) ) return false;

        if(! gameField.isCellFree(newRow, newCol))
        {
            Figure * figureOnNewCell = gameField.getFigure(newRow, newCol).clone();
            if(validateColor(true, figureOnNewCell->getColor())) return false;
        }

        getPosibleMoves( (*(currFigure->GetMoves())), currRow, currCol, gameField );

        if(field[newRow][newCol])
        {
            gameField.setFigure(currRow, currCol, NULL);
            gameField.setFigure(newRow, newCol, currFigure);
            delete currFigure;
            return true;
        }

        return false;
    }
};

#endif // WHITE_PLAYER
