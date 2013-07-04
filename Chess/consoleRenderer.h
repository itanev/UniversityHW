#ifndef CONSOLE_RENDERER
#define CONSOLE_RENDERER

class ConsoleRenderer : public Renderer
{
public:
    void DrawFigure(Figure* figure)
    {
        std::cout << figure->getSymbol();
    }

    void DrawField(Field& gameField)
    {
        system("cls");
        for(int i = 0; i < gameField.getDimentions() * 2 + 1; ++i)
            std::cout << '-';
        std::cout << std::endl;

        for(int row = 0; row < gameField.getDimentions(); ++row)
        {
            std::cout << "|";
            for(int col = 0; col < gameField.getDimentions(); ++col)
            {
                if(gameField.isCellFree(row, col))
                    std::cout << " |";
                else
                {
                    if(! gameField.getFigure(row, col).getColor())
                        rlutil::setColor(8);
                    else
                        rlutil::setColor(15);
                    std::cout << gameField.getFigure(row, col).getSymbol() << "|";
                    rlutil::setColor(7);
                }
            }
            std::cout << std::endl;
        }
        for(int i = 0; i < gameField.getDimentions() * 2 + 1; ++i)
            std::cout << '-';
        std::cout << std::endl;
    }
};

#endif // CONSOLE_RENDERER
