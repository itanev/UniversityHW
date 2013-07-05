#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "coloring/rlutil.h"
#include "moves.h"
#include "figure.h"
#include "king.h"
#include "pawn.h"
#include "cell.h"
#include "field.h"
#include "renderer.h"
#include "consoleRenderer.h"
#include "player.h"
#include "whitePlayer.h"
#include "blackPlayer.h"
#include "parser.h"
#include "consoleParser.h"

using namespace std;

void setFigures(bool color)
{
    //instances
    //positions
}

int main()
{
    Figure* king = new King(true);
    Figure* king2 = new King(false);
    Figure* pawn = new Pawn(true);

    Field gameField;
    gameField.setFigure(3,2, king);
    gameField.setFigure(5,2, king2);
    gameField.setFigure(6,1, pawn);

    Renderer* drawer = new ConsoleRenderer();
    Player* me = new WhitePlayer();
    Player* other = new BlackPlayer();

    bool turn = true;

    drawer->DrawField(gameField);
    string input;
    getline(cin, input);

    while(input != "exit")
    {
        Parser * reader = new ConsoleParser();
        vector<int> coords = reader->Parse(input);

        if(turn)
        {
            if(! me->moveFigure(coords[0], coords[1], coords[2], coords[3], gameField))
            {
                rlutil::setColor(4);
                cout << "invalid move" << endl;
                rlutil::setColor(7);
            }
            else
                drawer->DrawField(gameField);
        }
        else
        {
            if(! other->moveFigure(coords[0], coords[1], coords[2], coords[3], gameField))
            {
                rlutil::setColor(4);
                cout << "invalid move" << endl;
                rlutil::setColor(7);
            }
            else
                drawer->DrawField(gameField);
        }

        getline(cin, input);
        turn = !turn;
    }

    return 0;
}
