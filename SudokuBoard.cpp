#include <iostream>
#include "SudokuSquare.cpp"
using namespace std;
class SudokuBoard
{
  public:
    SudokuSquare* board [9][9];

    SudokuBoard()
    {
      for (int i = 0; i < 9; i++)
      {
        for (int j = 0; j < 9; j++)
        {
          board[i][j] = new SudokuSquare();
        }
      }
    }



  void updateAll()
  {
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        board[i][j]->update();
      }
    }
  }


  int numSet()
  {
    int toReturn = 0;
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        if (board[i][j]->set)
        {
          toReturn++;
        }
      }
    }
    return toReturn;
  }
	


  //this function eliminates all the wrong possiblilites based on rows
  void doRows()
  {

    for (int row = 0; row < 9; row++)
    {
      for (int col = 0; col < 9; col++)
      {
        if (board[row][col]->set)
        {
          int currValue = board[row][col]->value;
          for (int rowIndex = 0; rowIndex < 9; rowIndex++)
          {
            board[row][rowIndex]->removePoss(currValue);
          }
        }
      }
    }	
  }


	
  //this function eliminates all the wrong possiblilites based on cols
  void doColumns()
  {
    for (int col = 0; col < 9; col++)
    {
      for (int row = 0; row < 9; row++)
      {
        if (board[row][col]->set)
        {
          int currValue = board[row][col]->value;
          for (int colIndex = 0; colIndex < 9; colIndex++)
          {
            board[colIndex][col]->removePoss(currValue);
          }
        }
      }
    }
  }




  
  //this function eliminates all the wrong possiblilites based on Cells
  void doCells()
  {
    for (int i = 0; i < 9; i++)//loop through all 9 cells
    {
      //assign the row to start at for the current cell
      int startRow;
      if (i < 3)
      {
        startRow = 0;
      }
      else if (i < 6)
      {
        startRow = 3;
      }
      else
      {
        startRow = 6;
      }
      //assign the column to start at for the current cell
      int startCol = (i /3)*3;

      //loop through the current cell
      for (int r = startRow; r < (startRow + 3); r++)
      {
        for (int c = startCol; c < (startCol + 3); c++)
        {
          if (board[r][c]->set)
          {
            int currVal = board[r][c]->value;

            //loop through the cell and update
            for (int r2 = startRow; r2 < (startRow + 3); r2++)
	    {
	      for (int c2 = startCol; c2 < (startCol + 3); c2++)
	      {
                board[r2][c2]->removePoss(currVal);
	      }
	    }
          }
        }
      }
    }
  }








  //this methos will determine if a posibility appreas only once in a set of
  //9 suck as a row or a col or a cell, and set the value of squares
  //if needed
  void doOnlys(SudokuSquare* group[9] )
  {
    //this array will holds the number of times a possibility
    //appears in a group.  The index of the array + 1 hold the
    //possibility and the number in the index will be the count
    int count[9] = {0,0,0,0,0,0,0,0,0};
    for(int i = 0; i<9; i++)//loop through the group
    {
      //loop through all the posible numbers
      for(int j = 1; j <= 9; j++)
      {
        if((group[i]->isAPoss(j)))
        {
          count[j - 1]++;
        }
      }
    }



    //make sure values taht are set have a count of 0.
    //this should not be an issue if the function is called correctly
    //but double check just in case
    
    for(int i = 0; i < 9; i++)//loop through the group
    {
      if(group[i]->set)//if a value is set
      {
        //make its count 0 in the array
        count[((group[i]->value)-1)] = 0;
      }
    }



    //loop through the count array and check if any possibility
    //occurs just once
    //if it does update the value of that cell
    for(int i = 0; i < 9; i++)
    {
      if(count[i] == 1)//if a possibility occurs just once
      {
        //find which cell has that possibility
        for(int j = 0; j < 9; j++)
        {
          if(group[j]->isAPoss(i+1))//set its value
          {
            group[j] ->setVal(i+1);
          }
        }
      }
    }
  }


  void doOnlyByRow()
  {
    SudokuSquare* curRow[9];
    
    for(int i = 0; i < 9; i++)//loop through all the rows
    {
      curRow[0] = board[i][0];
      curRow[1] = board[i][1];
      curRow[2] = board[i][2];
      curRow[3] = board[i][3];
      curRow[4] = board[i][4];
      curRow[5] = board[i][5];
      curRow[6] = board[i][6];
      curRow[7] = board[i][7];
      curRow[8] = board[i][8]; 
      doOnlys(curRow);
    }
  }





  void doOnlyByCol()
  {
    SudokuSquare* curCol[9];
    
    for(int i = 0; i < 9; i++)//loop through all the cols
    {
      curCol[0] = board[0][i];
      curCol[1] = board[1][i];
      curCol[2] = board[2][i];
      curCol[3] = board[3][i];
      curCol[4] = board[4][i];
      curCol[5] = board[5][i];
      curCol[6] = board[6][i];
      curCol[7] = board[7][i];
      curCol[8] = board[8][i];
      doOnlys(curCol);
    }
  }






  //this function eliminates all the wrong possiblilites based on Cells
  void doOnlyByCell()
  {
    for (int i = 0; i < 9; i++)//loop through all 9 cells
    {
      //assign the row to start at for the current cell
      int startRow;
      if (i < 3)
      {
        startRow = 0;
      }
      else if (i < 6)
      {
        startRow = 3;
      }
      else
      {
        startRow = 6;
      }
      //assign the column to start at for the current cell
      int startCol = (i /3)*3;



      
      SudokuSquare* currCell [9];
      int i = 0;//int for the current index of currCell



      //loop through the current cell
      for (int r = startRow; r < (startRow + 3); r++)
      {
        for (int c = startCol; c < (startCol + 3); c++)
        {
          currCell[i] = board[r][c];
          i++;    
        }
      }


      doOnlys(currCell);




    }
  }






















  //print out the state of the sudoku board
  void printState()
  {
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        cout << board[i][j]->value << " ";
      }
      cout << endl;
    }
  }

};
