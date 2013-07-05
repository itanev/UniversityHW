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

void setBlackFigures(Field& gameField)
{
    Figure* king = new King(false);
    Figure* queen = new Queen(false);
    Figure* leftHorse = new Horse(false);
    Figure* rightHorse = new Horse(false);
    Figure* leftRook = new Rook(false);
    Figure* rightRook = new Rook(false);
    Figure* leftOfficer = new Officer(false);
    Figure* rightOfficer = new Officer(false);

    int firstRow = 0, secondRow = 1;

    gameField.setFigure(firstRow,4, king);
    gameField.setFigure(firstRow,3, queen);
    gameField.setFigure(firstRow,2, leftOfficer);
    gameField.setFigure(firstRow,1, leftHorse);
    gameField.setFigure(firstRow,0, leftRook);
    gameField.setFigure(firstRow,5, rightOfficer);
    gameField.setFigure(firstRow,6, rightHorse);
    gameField.setFigure(firstRow,7, rightRook);

    Figure* pawnOne = new Pawn(false);
    gameField.setFigure(secondRow,1, pawnOne);
}

void setWhiteFigures(Field& gameField)
{
    Figure* king = new King(true);
    Figure* queen = new Queen(true);
    Figure* leftHorse = new Horse(true);
    Figure* rightHorse = new Horse(true);
    Figure* leftRook = new Rook(true);
    Figure* rightRook = new Rook(true);
    Figure* leftOfficer = new Officer(true);
    Figure* rightOfficer = new Officer(true);

    int firstRow = gameField.getDimentions() - 1, secondRow = firstRow - 1;

    gameField.setFigure(firstRow,4, king);
    gameField.setFigure(firstRow,3, queen);
    gameField.setFigure(firstRow,2, leftOfficer);
    gameField.setFigure(firstRow,1, leftHorse);
    gameField.setFigure(firstRow,0, leftRook);
    gameField.setFigure(firstRow,5, rightOfficer);
    gameField.setFigure(firstRow,6, rightHorse);
    gameField.setFigure(firstRow,7, rightRook);

    Figure* pawnOne = new Pawn(true);
    gameField.setFigure(secondRow,1, pawnOne);
}

int main()
{
    Field gameField;

    setWhiteFigures(gameField);
    setBlackFigures(gameField);

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
