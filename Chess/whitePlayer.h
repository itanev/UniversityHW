#ifndef WHITE_PLAYER
#define WHITE_PLAYER

class WhitePlayer : public virtual Player
{
protected:
    virtual bool validateColor(bool validColor, bool color)
    {
        return validColor == color;
    }

private:
    bool notInRange(int row, int col)
    {
        return (row < 0 ||
               row >= dimentions ||
               col < 0 ||
               col >= dimentions);
    }

    bool isSameColorFigure(int row, int col, Field& gameField)
    {
        if(gameField.isCellFree(row, col)) return false;
        return validateColor(gameField.getFigure(row, col).getColor(), true);
    }

    void setCellForHorse(int row, int col, Field& gameField)
    {
        if(!notInRange(row, col) &&
           !isSameColorFigure(row, col, gameField))
            field[row][col] = true;
    }

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

    void getPosibleMovesEntireDiagonal(int startRow, int startCol, int row, int col, Field& gameField)
    {
        if(row >= dimentions || row < 0 || col >= dimentions || col < 0) return;

        if(startRow != row && startCol != col && isSameColorFigure(row, col, gameField)) return;

        if(startRow != row && startCol != col && field[row][col]) return;

        field[row][col] = true;
        getPosibleMovesEntireDiagonal(startRow, startCol, row + 1, col + 1, gameField);
        getPosibleMovesEntireDiagonal(startRow, startCol, row + 1, col - 1, gameField);
    }

    void getPosibleMovesHorse(int currRow, int currCol, Field& gameField)
    {
        setCellForHorse(currRow + 2, currCol + 1, gameField);
        setCellForHorse(currRow + 2, currCol - 1, gameField);
        setCellForHorse(currRow - 2, currCol + 1, gameField);
        setCellForHorse(currRow - 2, currCol - 1, gameField);
        setCellForHorse(currRow + 1, currCol + 2, gameField);
        setCellForHorse(currRow - 1, currCol + 2, gameField);
        setCellForHorse(currRow + 1, currCol - 2, gameField);
        setCellForHorse(currRow - 1, currCol - 2, gameField);
    }

    virtual void getPosibleMovesPawn(int currRow, int currCol, Field& gameField)
    {
        if(currRow == dimentions - 2 &&
           !gameField.getFigure(currRow, currCol).moved)
        {
            if(! isSameColorFigure(currRow - 1, currCol, gameField))
                field[currRow - 1][currCol] = true;
            if(! isSameColorFigure(currRow - 2, currCol, gameField))
                field[currRow - 2][currCol] = true;
        }

        gameField.getFigure(currRow, currCol).moved = true;

        if(currRow - 1 >= 0 &&
           currCol - 1 >= 0 &&
           !gameField.isCellFree(currRow - 1, currCol - 1))
        {
            if(! isSameColorFigure(currRow - 1, currCol - 1, gameField))
                field[currRow - 1][currCol - 1] = true;
        }

        if(currRow - 1 >= 0 &&
           currCol + 1 <= dimentions &&
           !gameField.isCellFree(currRow - 1, currCol + 1))
        {
            if(! isSameColorFigure(currRow - 1, currCol + 1, gameField))
                field[currRow - 1][currCol + 1] = true;
        }
    }

    void getPosibleMovesEntireRow(int startCol, int row, int col, Field& gameField)
    {
        if(col >= dimentions || col < 0) return;
        if(startCol != col && field[row][col]) return;
        if(startCol != col && isSameColorFigure(row, col, gameField)) return;

        field[row][col] = true;

        getPosibleMovesEntireRow(startCol, row, col + 1, gameField);
        getPosibleMovesEntireRow(startCol, row, col - 1, gameField);
    }

    void getPosibleMovesEntireCol(int startRow, int row, int col, Field& gameField)
    {
        if(row >= dimentions || row < 0) return;
        if(startRow != row && field[row][col]) return;
        if(startRow != row && isSameColorFigure(row, col, gameField)) return;

        field[row][col] = true;

        getPosibleMovesEntireCol(startRow, row + 1, col, gameField);
        getPosibleMovesEntireCol(startRow, row - 1, col, gameField);
    }

    void getPosibleMoves(std::vector<Moves> moves, int currRow, int currCol, Field& gameField)
    {
        for(int i = 0; i < moves.size(); ++i)
        {
            switch( moves[i] )
            {
                case OneForward:
                    if(currRow - 1 >= 0 &&
                       !isSameColorFigure(currRow - 1, currCol, gameField))
                        field[currRow - 1][currCol] = true;
                    break;
                case OneBackward:
                    if(currRow + 1 < dimentions &&
                       !isSameColorFigure(currRow + 1, currCol, gameField))
                        field[currRow + 1][currCol] = true;
                    break;
                case OneLeft:
                    if(currCol - 1 >= 0 &&
                       !isSameColorFigure(currRow, currCol - 1, gameField))
                        field[currRow][currCol - 1] = true;
                    break;
                case OneRight:
                    if(currCol + 1 < dimentions &&
                       !isSameColorFigure(currRow, currCol + 1, gameField))
                        field[currRow][currCol + 1] = true;
                    break;
                case OneDiagonal:
                    getPosibleMovesOneDiagonal(currRow, currCol);
                    break;
                case EntireRow:
                    getPosibleMovesEntireRow(currCol, currRow, currCol, gameField);
                    break;
                case EntireCol:
                    getPosibleMovesEntireCol(currRow, currRow, currCol, gameField);
                    break;
                case EntireDiagonal:
                    getPosibleMovesEntireDiagonal(currRow, currCol, currRow, currCol, gameField);
                    break;
                case HorseMove:
                    getPosibleMovesHorse(currRow, currCol, gameField);
                    break;
                case PawnMove:
                    getPosibleMovesPawn(currRow, currCol, gameField);
                    break;
            }
        }
    }

public:
    bool moveFigure(int currRow, int currCol, int newRow, int newCol, Field& gameField)
    {
        if(notInRange(currRow, currCol) &&
           notInRange(newRow, newCol)) return false;

        if(gameField.isCellFree(currRow, currCol)) return false;

        if(!gameField.isCellFree(newRow, newCol) &&
           gameField.getFigure(newRow, newCol).getSymbol() == 'K')
        {
            return false;
        }

        memset(field, false, sizeof(field));
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

#endif
