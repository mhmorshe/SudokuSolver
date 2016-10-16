#include <iostream>
#include <fstream>
#include "SudokuBoard.cpp"
using namespace std;
int main( int argc, char* argv[])
{

  if(argc != 2)
  {
    cout << "Invalid input \n"<<"input should be a single text file"<<endl;
    return -1;
  }



  //create a blank sudoku board
  SudokuBoard temp = *(new SudokuBoard());

  //open the input file
  ifstream inputFile(argv[1]);
  if(!inputFile)
  {
    cout << "Could not open the input file"<<endl;
    return -1;
  }


  int currentInput;//this int will hold the current input value 
  //loop through each square on the board
  //and set values of squares form file input
  for(int row = 0; row < 9; row++)
  {
    for(int col = 0; col < 9; col++)
    {
      inputFile >> currentInput;
      if(currentInput != 0)
      {
        temp.board[row][col]->setVal(currentInput);
      }
    }

  }
/*	
  temp.board[0][1]->setVal(9);
  temp.board[0][3]->setVal(5);
  temp.board[0][4]->setVal(6);
  temp.board[0][6]->setVal(7);
  temp.board[1][2]->setVal(4);
  temp.board[1][3]->setVal(3);
  temp.board[1][4]->setVal(9);
  temp.board[2][1]->setVal(5);
  temp.board[2][2]->setVal(2);
  temp.board[2][4]->setVal(8);
  temp.board[2][5]->setVal(7);
  temp.board[3][1]->setVal(1);
  temp.board[3][2]->setVal(7);
  temp.board[3][3]->setVal(6);
  temp.board[3][5]->setVal(4);
  temp.board[3][6]->setVal(5);
  temp.board[4][3]->setVal(2);
  temp.board[5][5]->setVal(8);
  temp.board[5][6]->setVal(4);
  temp.board[5][7]->setVal(7);
  temp.board[6][0]->setVal(3);
  temp.board[6][2]->setVal(1);
  temp.board[6][8]->setVal(9);
  temp.board[7][0]->setVal(9);
  temp.board[7][2]->setVal(6);
  temp.board[7][4]->setVal(2);
  temp.board[7][8]->setVal(3);
  temp.board[8][1]->setVal(8);
  temp.board[8][4]->setVal(1);
  temp.board[8][7]->setVal(2);
*/
  temp.updateAll();

  temp.printState();
  cout << endl;
  

  while (temp.numSet() < 81)
  {
    cout << temp.numSet() << endl;
    temp.printState();


    temp.doRows();
    temp.doColumns();
    temp.doCells();
    temp.updateAll();
    temp.doOnlyByRow();
    temp.doOnlyByCol();
    temp.doOnlyByCell();
    temp.updateAll();
  }

  temp.printState();
  cin.get();
  return 0;
}
