//
//  sixteenSquareTable.cpp
//  sudokuCommon_mk1
//
//  Created by Administrator on 23/01/2017.
//  Copyright © 2017 Administrator. All rights reserved.
//

#include "sixteenSquareTable.h"

sixteenDatabase sixbase;

int sixteenTable::sudokuRaw () //меняем местами две строки/столбца в одной зоне (первой/второй/третьей тройке)
{
    int area = rand();
    area %= this->squareSize;
    area *= this->squareSize;
    int firstswap  =  rand();
    firstswap      %= this->squareSize;
    int secondswap =  rand();
    secondswap     %= this->squareSize;
    while (secondswap == firstswap)
    {
        secondswap =  rand();
        secondswap %= this->squareSize;
    }
    for (int i = 0; i < this->bodySize; i++)
    {
        int first  = firstswap+area;
        int second = secondswap+area;
        int tmp    = this->body[first][i][0];
        this->body[first][i][0]  = this->body[second][i][0];
        this->body[second][i][0] = tmp;
    }
    return 0;
}

int sixteenTable::sudokuArea ()    //меняем местами две зоны (две тройки)
{
    int firstarea  =  rand();
    firstarea      %= this->squareSize;
    firstarea      *= this->squareSize;
    int secondarea =  rand();
    secondarea     %= this->squareSize;
    secondarea     *= this->squareSize;
    while (secondarea == firstarea)
    {
        secondarea =  rand();
        secondarea %= this->squareSize;
        secondarea *= this->squareSize;
    }
    secondarea -= firstarea;
    for (int i = firstarea; i < firstarea+this->squareSize; i++)
    {
        for (int j = 0; j < this->bodySize; j++)
        {
            int tmp = this->body[i][j][0];
            this->body[i][j][0] = this->body[i+secondarea][j][0];
            this->body[i+secondarea][j][0] = tmp;
        }
    }
    return 0;
}

int sixteenTable::sudokuTrans ()   //транспонирование
{
    for (int i = 0; i < this->bodySize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int tmp = this->body[i][j][0];
            this->body[i][j][0] = this->body[j][i][0];
            this->body[j][i][0] = tmp;
        }
    }
    return 0;
}

int sixteenTable::sudokuSwap ()    //особый путь перемешивания - берутся два случайных числа от 1 до 9 и меняются местами - те клетки, в которых стоит первое число меняются на те клетки, в которых стоит второе число. При такой замене правила не нарушаются
{
    int first = 0, second = 0;
    for (int k = 0; k < 50; k++)
    {
        int ver_hor_rand =  rand();
        ver_hor_rand     %= 2;
        if (ver_hor_rand) sudokuTrans ();
        first  =  rand();
        first  %= this->bodySize;
        first  += 1;
        while (first == 0)
        {
            first  =  rand();
            first  %= this->bodySize;
            first  += 1;
        }
        second =  rand();
        second %= this->bodySize;
        second += 1;
        while (second == first || second == 0)
        {
            second =  rand();
            second %= this->bodySize;
            second += 1;
        }
        for (int i = 0; i < this->bodySize; i++)
        {
            for (int j = 0; j < this->bodySize; j++)
            {
                if (this->body[i][j][0] == first) this->body[i][j][0] = -1;
            }
        }
        for (int i = 0; i < this->bodySize; i++)
        {
            for (int j = 0; j < this->bodySize; j++)
            {
                if (this->body[i][j][0] == second) this->body[i][j][0] = first;
            }
        }
        for (int i = 0; i < this->bodySize; i++)
        {
            for (int j = 0; j < this->bodySize; j++)
            {
                if (this->body[i][j][0] == -1) this->body[i][j][0] = second;
            }
        }
    }
    return 0;
}

int sixteenTable::sudokuShuffle () //используются перемешивания столбцов и зон в случайном порядке
{
    for (int i = 0; i < 100; i++)
    {
        int funcnum = rand();
        funcnum %= 2;
        switch (funcnum) {
            case 0:
            {
                int tmp = rand();
                tmp %= 5;
                for (int j = 0; j < tmp; j++)
                {
                    sudokuRaw ();
                }
                break;
            }
            case 1:
            {
                int tmp = rand();
                tmp %= 5;
                for (int j = 0; j < tmp; j++)
                {
                    sudokuArea ();
                }
                break;
            }
            default:
                return -1;
        }
    }
    return 0;
}

sixteenTable* sixteenTable::sudokuCtor ()
{
    sixteenTable* This = (sixteenTable*) malloc (300);
    return This;
}

int sixteenTable::sudokuScan (string input)     //создание таблицы судоку из строки чисел, роль пустых клеток играет '0'
{
    /*for (int i = 0; i < this->bodySize; i++)
    {
        for (int j = 0; j < this->bodySize; j++)
        {
            this->body[i][j].push_back( input[i*this->bodySize+j]-'0');
            //this->body[i][j][0] = input[i*this->bodySize+j]-'0';
        }
    }*/
    
    stringstream ss(input);
    string item;
    for (int i = 0; i < this->bodySize; i++)
    {
        for (int j = 0; j < this->bodySize; j++)
        {
            getline(ss, item, ' ');
            if (!item.empty())
            {
                int result = atoi(item.c_str());
                body[i][j].push_back(result);
            }
        }
    }
    return 0;
}

int sixteenTable::sudokuCheck ()   //проверка, есть ли элемент в строке/столбце/квадрате
{
    for (int i = 0; i < this->bodySize; i++)
    {
        for (int j = 0; j < this->bodySize; j++)
        {
            if (this->body[i][j][0] == 0)
            {
                for (int k = 1; k <= this->bodySize; k++)
                {
                    bool found = false;
                    for (int m = 0; m < this->bodySize; m++)
                    {
                        if (this->body[i][m][0] == k)
                        {
                            found = true;
                            break;
                        }
                        else if (this->body[m][j][0] == k)
                        {
                            found = true;
                            break;
                        }
                    }
                    for (int q = 0; q < this->squareSize; q++)
                    {
                        if (i < (q+1)*(this->squareSize))
                        {
                            for (int p = 0; p < this->squareSize; p++)
                            {
                                if (j < (p+1)*(this->squareSize))
                                {
                                    for (int m = q*this->squareSize; m < (q+1)*(this->squareSize); m++)
                                    {
                                        for (int n = p*this->squareSize; n < (p+1)*(this->squareSize); n++)
                                        {
                                            if (this->body[m][n][0] == k)
                                            {
                                                found = true;
                                                n = (p+1)*this->squareSize;
                                                m = (q+1)*this->squareSize;
                                            }
                                        }
                                    }
                                    p = this->squareSize;
                                }
                            }
                            q = this->squareSize;
                        }
                    }
                    if (!found)
                    {
                        vector<short>::iterator it;
                        it = find(this->body[i][j].begin(), this->body[i][j].end(), k);
                        if (it == this->body[i][j].end() && !this->bodyChanged) this->body[i][j].push_back (k);
                    }
                    else
                    {
                        vector<short>::iterator it;
                        it = find(this->body[i][j].begin(), this->body[i][j].end(), k);
                        if (it != this->body[i][j].end()) this->body[i][j].erase(it);
                    }
                }
            }
        }
    }
    return 0;
}

int sixteenTable::sudokuNums ()    //проверка каждого варианта в клетке на корректность в новых условиях
{
    for (int i = 0; i < this->bodySize; i++)
    {
        for (int j = 0; j < this->bodySize; j++)
        {
            if (this->body[i][j][0] == 0)
            {
                for (int p = 1; p < (int)this->body[i][j].size(); p++)
                {
                    int k = this->body[i][j][p];
                    bool fstring  = true;
                    bool fcolumn  = true;
                    bool fsquare  = true;
                    for (int m = 0; m < this->bodySize; m++)
                    {
                        if (fcolumn && this->body[m][j][0] == 0 && m != i)
                        {
                            vector<short>::iterator it;
                            it = find(this->body[m][j].begin(), this->body[m][j].end(), k);
                            if (it != this->body[m][j].end()) fcolumn = false;
                        }
                        if (fstring && this->body[i][m][0] == 0 && m != j)
                        {
                            vector<short>::iterator it;
                            it = find(this->body[i][m].begin(), this->body[i][m].end(), k);
                            if (it != this->body[i][m].end()) fstring = false;
                        }
                    }
                    for (int q = 0; q < this->squareSize; q++)
                    {
                        if (i < (q+1)*(this->squareSize))
                        {
                            for (int r = 0; r < this->squareSize; r++)
                            {
                                if (j < (r+1)*(this->squareSize))
                                {
                                    for (int m = q*this->squareSize; m < (q+1)*(this->squareSize); m++)
                                    {
                                        for (int n = r*this->squareSize; n < (r+1)*(this->squareSize); n++)
                                        {
                                            if (fsquare && this->body[m][n][0] == 0 && (m != i || n != j))
                                            {
                                                vector<short>::iterator it;
                                                it = find(this->body[m][n].begin(), this->body[m][n].end(), k);
                                                if (it != this->body[m][n].end()) fsquare = false;
                                            }
                                        }
                                    }
                                    r = this->squareSize;
                                }
                            }
                            q = this->squareSize;
                        }
                    }
                    if (fsquare || fcolumn || fstring)
                    {
                        this->body[i][j][0] = k;
                        this->bodyChanged = true;
                    }
                    this->sudokuCheck();
                }
            }
        }
    }
    return 0;
}

int sixteenTable::sudokuSolve ()   //попытка решения с помощью банальных проверок
{
    this->bodyChanged = true;
    while (this->bodyChanged)
    {
        this->bodyChanged = false;
        this->sudokuCheck();
        this->sudokuNums();
        for (int i = 0; i < this->bodySize; i++)
        {
            for (int j = 0; j < this->bodySize; j++)
            {
                if (this->body[i][j][0] == 0 && this->body[i][j].size() == 2)
                {
                    this->body[i][j][0] = this->body[i][j][1];
                    this->body[i][j].pop_back();
                    this->bodyChanged = true;
                    this->sudokuCheck();
                }
            }
        }
    }
    return 0;
}

int sixteenTable::sudokuPrint ()   //распечатка на stdio
{
    for (int i = 0; i < this->bodySize; i++)
    {
        for (int j = 0; j < this->bodySize; j++)
        {
            int tmp = this->body[i][j][0];
            printf ("%d ", tmp);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

int sixteenTable::sudokuCopy (sixteenTable* from, sixteenTable* to)
{
    to->bodyChanged = from->bodyChanged;
    for (int i = 0; i < from->bodySize; i++)
    {
        for (int j = 0; j < from->bodySize; j++)
        {
            to->body[i][j] = from->body[i][j];
        }
    }
    return 0;
}

int sixteenTable::sudokuCompare (sixteenTable* first, sixteenTable* second)  //сравнение двух судоку для database
{
    if (first->bodySize != second->bodySize) return -1;
    int res = 0;
    for (int i = 0; i < first->bodySize; i++)
    {
        for (int j = 0; j < first->bodySize; j++)
        {
            if (first->body[i][j][0] != second->body[i][j][0]) res++;
        }
    }
    return res;
}

int sixteenTable::sudokuDtor ()
{
    free (this);
    return 0;
}

sixteenDatabase* sixteenDatabase::SDbCtor ()
{
    sixteenDatabase* This = (sixteenDatabase*) malloc (256);
    This->SDbSize = 0;
    return This;
}

int sixteenDatabase::SDbInsert (sixteenTable* toInsert) //вставка решения в database
{
    if (this->SDbSize == 0)
    {
        this->database.push_back (*toInsert);
        this->SDbSize++;
    }
    else
    {
        bool found = false;
        for (int i = 0; i < this->SDbSize; i++)
        {
            int tmp = this->database[i].sudokuCompare (&this->database[i], toInsert);
            if (tmp == 0)
            {
                found = true;
            }
        }
        if (!found)
        {
            this->database.push_back (*toInsert);
            this->SDbSize++;
        }
    }
    return this->SDbSize;
}

int sixteenDatabase::SDbPop ()     //удаление решения из database
{
    if (this->SDbSize <= 0) return -1;
    this->database.pop_back();
    this->SDbSize--;
    return this->SDbSize;
}

int sixteenDatabase::SDbClear ()
{
    while (this->SDbSize > 0)
    {
        SDbPop();
    }
    return 0;
}

int sixteenDatabase::SDbPrint ()   //распечатка всех решений, внесенных в database
{
    for (int i = 0; i < this->SDbSize; i++)
    {
        this->database[i].sudokuPrint();
    }
    printf ("%d\n", this->SDbSize);
    return 0;
}

int sixteenDatabase::renderingSolutions (sixteenTable* This)  //генерация решений - сначала простым методом, затем перебор. все решения записываются в database
{
    This->sudokuSolve();
    for (int i = 0; i < This->bodySize; i++)
    {
        for (int j = 0; j < This->bodySize; j++)
        {
            if (This->body[i][j][0] != 0)
            {
                continue;
            }
            else
            {
                if (This->body[i][j].size() > 2)
                {
                    for (int k = 1; k < (int)This->body[i][j].size(); k++)
                    {
                        sixteenTable copyThis = *This;
                        copyThis.body[i][j][0] = This->body[i][j][k];
                        renderingSolutions(&copyThis);
                        if (!This->solved) continue;
                        else return 0;
                    }
                    if (!This->solved) return -1;
                }
                else
                {
                    return -1;
                }
                
            }
        }
    }
    SDbInsert(This);
    This->solved = true;
    return 0;
}

int sixteenDatabase::fastRenderingSolutions (sixteenTable* This)  //генерация решений - сначала простым методом, затем перебор. все решения записываются в database
{
    This->sudokuSolve();
    for (int i = 0; i < This->bodySize; i++)
    {
        for (int j = 0; j < This->bodySize; j++)
        {
            if (This->body[i][j][0] != 0)
            {
                continue;
            }
            else
            {
                if (This->body[i][j].size() > 2)
                {
                    for (int k = 1; k <(int)This->body[i][j].size(); k++)
                    {
                        sixteenTable copyThis = *This;
                        copyThis.body[i][j][0] = This->body[i][j][k];
                        fastRenderingSolutions(&copyThis);
                        if (this->SDbSize > 1) return -2;
                        if (!This->solved) continue;
                        else return 0;
                    }
                    if (!This->solved) return -1;
                }
                else
                {
                    return -1;
                }
                
            }
        }
    }
    SDbInsert(This);
    This->solved = true;
    if (this->SDbSize > 1) return -2;
    return 0;
}

int sixteenTable::sudokuGen (int* level)   //генерация поля судоку в зависимости от сложности (level)
{
    srand(time(0));
    this->sudokuScan(this->sample);
    for (int i = 0; i < 50; i++)
    {
        sudokuShuffle();
        sudokuSwap ();
    }
    int count = 0;
    while (count < *level) //нужна переменная "уровень сложности" от 5 до 20 с увеличивающимися шагами
    {
        sudokuShuffle ();
        sudokuSwap ();
        int i_arr[5];
        int j_arr[5];
        for (int i = 0; i < 5; i++)
        {
            i_arr[i] =  rand();
            i_arr[i] %= this->bodySize;
            j_arr[i] =  rand();
            j_arr[i] %= this->bodySize;
        }
        bool iszero = false;
        for (int i = 0; i < 5; i++)
        {
            if (this->body[i_arr[i]][j_arr[i]][0] == 0)
            {
                count++;
                iszero = true;
                i = 5;
            }
        }
        /*if (this->body[i1][j1][0] == 0 || this->body[i2][j2][0] == 0 || this->body[i3][j3][0] == 0 )//|| this->body[i5][j5][0] == 0)
        {
            count++;
        }*/
        if (!iszero)
        {
            sixteenTable copyThis = *this;
            for (int i = 0; i < 5; i++)
            {
                copyThis.body[i_arr[i]][j_arr[i]][0] = 0;
            }
            sixbase.fastRenderingSolutions(&copyThis);
            int res = sixbase.getSDbSize();
            sixbase.SDbClear();
            if (res != 1)
            {
                count += 5;
            }
            else
            {
                count = 0;
                for (int i = 0; i < 5; i++)
                {
                    this->body[i_arr[i]][j_arr[i]][0] = 0;
                }
            }
        }
    }
    sudokuShuffle ();
    return 0;
}

int sixteenDatabase::getSDbSize ()
{
    return this->SDbSize;
}
