//
//  sixteenSquareTable.hpp
//  sudokuCommon_mk1
//
//  Created by Administrator on 23/01/2017.
//  Copyright © 2017 Administrator. All rights reserved.
//


#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>

//#include "nineSquareTable.h"
using namespace std;

class sixteenTable
{
public:
    sixteenTable*    sudokuCtor    ();
    int              sudokuScan    (string input);
    int              sudokuCheck   ();
    int              sudokuNums    ();
    int              sudokuSolve   ();
    int              sudokuSquare  ();
    int              sudokuPrint   ();
    int              sudokuDtor    ();
    int              sudokuCopy    (sixteenTable* from, sixteenTable* to);
    int              sudokuCompare (sixteenTable* first, sixteenTable* second);
    int              sudokuTrans   ();
    int              sudokuRaw     ();
    int              sudokuArea    ();
    int              sudokuSwap    ();
    int              sudokuShuffle ();
    int              sudokuGen     (int* level);
    const static int bodySize                 = 16;
    const static int squareSize               = 4;
    bool             bodyChanged              = false;
    bool             solved                   = false;
    string sample = "9 11 2 1 10 7 12 4 15 16 5 13 3 6 14 8 4 8 10 14 2 9 3 15 6 12 1 11 13 5 7 16 13 15 5 7 14 8 16 6 10 2 4 3 1 11 9 12 16 12 3 6 11 13 5 1 9 14 8 7 4 2 10 15 2 4 11 5 8 1 10 12 7 13 9 15 16 3 6 14 12 13 8 16 5 2 6 9 4 10 3 14 15 1 11 7 6 3 15 10 4 16 7 14 11 8 2 1 5 13 12 9 1 7 14 9 3 11 15 13 12 6 16 5 2 4 8 10 14 2 16 8 1 4 11 5 13 15 7 12 9 10 3 6 10 9 7 4 6 14 2 16 5 3 11 8 12 15 13 1 15 1 12 13 7 10 9 3 14 4 6 16 11 8 2 5 11 5 6 3 12 15 13 8 1 9 10 2 14 7 16 4 8 10 1 15 13 5 14 7 3 11 12 9 6 16 4 2 5 16 4 12 15 3 8 11 2 7 14 6 10 9 1 13 3 14 9 2 16 6 1 10 8 5 13 4 7 12 15 11 7 6 13 11 9 12 4 2 16 1 15 10 8 14 5 3\n";
    vector<short>    body[bodySize][bodySize];
};

class sixteenDatabase
{
public:
    sixteenDatabase*   SDbCtor   ();
    int                SDbInsert (sixteenTable* toInsert);
    int                SDbPop    ();
    int                SDbPrint  ();
    int                SDbClear  ();
    int                SDbDtor   ();
    int                renderingSolutions (sixteenTable* This);
    int                fastRenderingSolutions (sixteenTable* This);
    int                getSDbSize();

    vector <sixteenTable> database;
    int  SDbSize = 0;
};
