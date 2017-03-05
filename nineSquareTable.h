//
//  nineSquareTable.hpp
//  sudokuCommon_mk1
//
//  Created by Administrator on 22/01/2017.
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

using namespace std;

class nineTable
{
public:
    
    nineTable* sudokuCtor    ();
    int        sudokuScan    (string input);
    int        sudokuCheck   ();
    int        sudokuNums    ();
    int        sudokuSolve   ();
    int        sudokuSquare  ();
    int        sudokuPrint   ();
    int        sudokuDtor    ();
    int        sudokuCopy    (nineTable* from, nineTable* to);
    int        sudokuCompare (nineTable* first, nineTable* second);
    int        sudokuTrans   ();
    int        sudokuRaw     ();
    int        sudokuArea    ();
    int        sudokuSwap    ();
    int        sudokuShuffle ();
    int        sudokuGen     (int* level);
    int        sudokuClear   ();

    const static int bodySize    = 9;
    const static int squareSize  = 3;
    bool             solved      = false;
    bool             bodyChanged = false;
    string sample = "8 1 2 7 5 3 6 4 9 9 4 3 6 8 2 1 7 5 6 7 5 4 9 1 2 8 3 1 5 4 2 3 7 8 9 6 3 6 9 8 4 5 7 2 1 2 8 7 1 6 9 5 3 4 5 2 1 9 7 4 3 6 8 4 3 8 5 2 6 9 1 7 7 9 6 3 1 8 4 5 2\n";
    vector <short> body[bodySize][bodySize];
    
};

class nineDatabase
{
public:
    nineDatabase*   SDbCtor   ();
    int             SDbInsert (nineTable* toInsert);
    int             SDbPop    ();
    int             SDbPrint  ();
    int             SDbClear  ();
    int             SDbDtor   ();
    int             getSDbSize();
    int             renderingSolutions (nineTable* This);
    int             fastRenderingSolutions (nineTable* This);

    vector <nineTable> database;
    int  SDbSize = 0;
};


