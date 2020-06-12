#include "History.h"
#include "Arena.h"
#include "Game.h"
#include <iostream>
using namespace std;

History::History(int nRow, int nCols)
{
    m_rows = nRow;
    m_cols = nCols;
    for (int k = 1; k <= m_rows; k++)
    {
        for (int j = 1; j <= m_cols; j++)
        {
            m_grid[k-1][j-1] = '.';
        }
    }
}

bool History::record(int r, int c)
{
    if (r <= 0  ||  c <= 0  ||  r > m_rows  ||  c > m_cols)
        return false;
    char& gridChar = m_grid[r-1][c-1];
    switch (gridChar)
    {
        case '.': gridChar = 'A'; break;
        case 'Z': break;
        default: gridChar++; break;  // 'A' through 'Z'
    }
    return true;
    
}

void History::display() const
{
    clearScreen();
    int r, c;
    for (r = 1; r <= m_rows; r++)
    {
        for (c = 1; c <= m_cols; c++)
            cout << m_grid[r-1][c-1];
        cout << endl;
    }
    cout << endl;
}
