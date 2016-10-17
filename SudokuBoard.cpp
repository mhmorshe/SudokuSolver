#include <iostream>
#include "SudokuSquare.cpp"
using namespace std;
class SudokuBoard
{
  public:
    SudokuSquare* board [9][9];

    //create a blank sudoku board
    SudokuBoard()
    {
      for (int i = 0; i < 9; i++)
      {
        for (int j = 0; j < 9; j++)
        {
          board[i][j] = new SudokuSquare(0, i, j);
        }
      }
    }	  


    

  //this function will return true if the value in toCheck causes a violation in the row
  bool rowViolation(SudokuSquare* toCheck)
  {
    bool toReturn = false;

    //loop through the entire row and change the boolena flag if needed
    for(int i = 0; i < 9; i++)
    {
      if(board[toCheck->row][i] -> value == toCheck->value && toCheck->col != i)
      {
        toReturn = true;
      }
    }

    return toReturn;
  }





  //this function will return true if toCheck is in the given col,
  //and false otherwise
  bool colViolation(SudokuSquare* toCheck)
  {
    bool toReturn = false;

    //loop through the entire row and change the boolena flag if needed
    for(int i = 0; i < 9; i++)
    {
      if(board[i][toCheck->col] -> value == toCheck->value && toCheck->row != i)
      {
        toReturn = true;
      }
    }


    return toReturn;
  }





  //this function will return true if toCheck is in the given grid,
  //and false otherwise
  bool gridViolation(SudokuSquare* toCheck)
  {
    bool toReturn = false;

    int startRow = (toCheck->grid/3)*3;
    int startCol = (toCheck->grid%3)*3;

    for(int i = startRow; i < (startRow+3); i++)
    {
      for(int j = startCol; j < (startCol+3); j++)
      {
        if(board[i][j]->value == toCheck->value && (toCheck -> row != i || toCheck ->col != j) )
        {
          toReturn = true;
        }
      }
    }


    return toReturn;
  }




  //this method will determine if any violations occur from putting toCheck in the grid
  bool canPut(SudokuSquare* toCheck)
  {
    bool toReturn = false;

    if(gridViolation(toCheck) == false)
    {
      if(colViolation(toCheck) == false)
      {
        if(rowViolation(toCheck) == false)
        {
          toReturn = true;
        }
      }
    }

    if(toCheck->value == 0 || toCheck->value > 9)
    {
      return false;
    }


    return toReturn;

  }


  //this method will return the square in the next open spot on the board
  SudokuSquare* nextOpenSpot()
  {
    SudokuSquare* toReturn = NULL;

    for(int i = 0; i < 9; i++)
    {
      for(int j = 0; j < 9; j++)
      {
        if(board[i][j]-> value == 0)
        {
          toReturn = board[i][j];//assign the value

          //break the loop
          i = 9;
          j = 9;
        }
      }
    }

    return toReturn;

  
  }














  //print out the state of the sudoku board
  void printState()
  {
    for (int i = 0; i < 9; i++)
    {
      if(i%3 == 0)
      {
        cout<<"---------------------"<<endl;
      }

      for (int j = 0; j < 9; j++)
      {
        if(j%3 == 0)
        {
          cout << "|";
        }

        if(j != 8)
          cout << board[i][j]->value << " ";
        else
          cout << board[i][j]->value << "|";
      }
      cout << endl;
    }

    cout<<"---------------------"<<endl;
  }

};
