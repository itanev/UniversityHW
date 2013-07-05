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
#include "queen.h"
#include "horse.h"
#include "rook.h"
#include "officer.h"
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

void setFigures(bool color, Field& gameField)
{
    Figure* king = new King(color);
    Figure* queen = new Queen(color);
    Figure* leftHorse = new Horse(color);
    Figure* rightHorse = new Horse(color);
    Figure* leftRook = new Rook(color);
    Figure* rightRook = new Rook(color);
    Figure* leftOfficer = new Officer(color);
    Figure* rightOfficer = new Officer(color);

    int firstRow = 0, secondRow = 1;
    if(!color)
    {
        firstRow = gameField.getDimentions();
        secondRow = firstRow - 1;
    }

    gameField.setFigure(firstRow,4, king);
    gameField.setFigure(firstRow,3, queen);
    gameField.setFigure(firstRow,2, leftOfficer);
    gameField.setFigure(firstRow,1, leftHorse);
    gameField.setFigure(firstRow,0, leftRook);
    gameField.setFigure(firstRow,5, rightOfficer);
    gameField.setFigure(firstRow,6, rightHorse);
    gameField.setFigure(firstRow,7, rightRook);

    //Figure* pawnOne = new Pawn(color);
    //gameField.setFigure(secondRow,0, pawnOne);
}

int main()
{
    Field gameField;

    setFigures(true, gameField);
    //setFigures(false, gameField);

    Figure* pawnOne = new Pawn(false);
    gameField.setFigure(1,0, pawnOne);

    Renderer* drawer = new ConsoleRenderer();
    Player* me = new WhitePlayer();
    Player* other = new BlackPlayer();

    bool turn = true;
    bool turnComplete = false;

    drawer->DrawField(gameField);
    string input;
    getline(cin, input);

    while(input != "exit")
    {
        turnComplete = false;
        cout << endl;

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
            {
                turnComplete = true;
                drawer->DrawField(gameField);
            }
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
            {
                turnComplete = true;
                drawer->DrawField(gameField);
            }
        }

        getline(cin, input);
        if(turnComplete) turn = !turn;
    }

    return 0;
}
