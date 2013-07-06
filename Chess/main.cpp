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
    Figure* pawnOne = new Pawn(false);
    Figure* pawnTwo = new Pawn(false);
    Figure* pawnThree = new Pawn(false);
    Figure* pawnFour = new Pawn(false);
    Figure* pawnFive = new Pawn(false);
    Figure* pawnSix = new Pawn(false);
    Figure* pawnSeven = new Pawn(false);
    Figure* pawnEight = new Pawn(false);

    int firstRow = 0, secondRow = 1;

    gameField.setFigure(firstRow,4, king);
    gameField.setFigure(firstRow,3, queen);
    gameField.setFigure(firstRow,2, leftOfficer);
    gameField.setFigure(firstRow,1, leftHorse);
    gameField.setFigure(firstRow,0, leftRook);
    gameField.setFigure(firstRow,5, rightOfficer);
    gameField.setFigure(firstRow,6, rightHorse);
    gameField.setFigure(firstRow,7, rightRook);

    gameField.setFigure(secondRow,0, pawnOne);
    gameField.setFigure(secondRow,1, pawnTwo);
    gameField.setFigure(secondRow,2, pawnThree);
    gameField.setFigure(secondRow,3, pawnFour);
    gameField.setFigure(secondRow,4, pawnFive);
    gameField.setFigure(secondRow,5, pawnSix);
    gameField.setFigure(secondRow,6, pawnSeven);
    gameField.setFigure(secondRow,7, pawnEight);
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
    Figure* pawnOne = new Pawn(true);
    Figure* pawnTwo = new Pawn(true);
    Figure* pawnThree = new Pawn(true);
    Figure* pawnFour = new Pawn(true);
    Figure* pawnFive = new Pawn(true);
    Figure* pawnSix = new Pawn(true);
    Figure* pawnSeven = new Pawn(true);
    Figure* pawnEight = new Pawn(true);

    int firstRow = gameField.getDimentions() - 1, secondRow = firstRow - 1;

    gameField.setFigure(firstRow,4, king);
    gameField.setFigure(firstRow,3, queen);
    gameField.setFigure(firstRow,2, leftOfficer);
    gameField.setFigure(firstRow,1, leftHorse);
    gameField.setFigure(firstRow,0, leftRook);
    gameField.setFigure(firstRow,5, rightOfficer);
    gameField.setFigure(firstRow,6, rightHorse);
    gameField.setFigure(firstRow,7, rightRook);

    gameField.setFigure(secondRow,0, pawnOne);
    gameField.setFigure(secondRow,1, pawnTwo);
    gameField.setFigure(secondRow,2, pawnThree);
    gameField.setFigure(secondRow,3, pawnFour);
    gameField.setFigure(secondRow,4, pawnFive);
    gameField.setFigure(secondRow,5, pawnSix);
    gameField.setFigure(secondRow,6, pawnSeven);
    gameField.setFigure(secondRow,7, pawnEight);
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
    Parser * reader = new ConsoleParser();

    while(input != "exit")
    {
        turnComplete = false;
        cout << endl;
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

    delete drawer;
    delete me;
    delete other;

    return 0;
}
