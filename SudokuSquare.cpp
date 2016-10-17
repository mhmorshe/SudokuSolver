#include <iostream>
#include <list>
using namespace std;
class SudokuSquare
{

  public:
    int value;//holds the value given to the square
    int row;//holds the row the square is in
    int col;//holds the column the square is in
    int grid;//holds the 3 by 3 gris the cell is in


    //constuctor for a square
    SudokuSquare(int toSet, int rowSet, int colSet)
    {
      value = toSet;
      row = rowSet;
      col = colSet;
      grid = (col/3) + 3*(row/3);
    }


};
