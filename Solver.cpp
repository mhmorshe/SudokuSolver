#include <iostream>
#include <fstream>//to read from input file
#include <stack>//for back track stack
#include "SudokuBoard.cpp"
using namespace std;
int main( int argc, char* argv[])
{


  if(argc != 2)
  {
    cout<< "Invalid inputs, the program should only take a text file as input"<<endl;
    return -1;
  }



  //create a blank sudoku board
  SudokuBoard puzzle = *(new SudokuBoard());

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
      puzzle.board[row][col]->value = currentInput;
    }

  }

  //print the unsolved puzzle
  puzzle.printState();
  cout<<endl<<endl;//end of line characters just for space



  /*After this point the Sudoku board should be filled with
   *the input values.  A value of 0 given to a 
   *square indicates taht the square has not been filled in yet
   */


  //create a stack for back tracking
  std::stack<SudokuSquare*> backtrack;
 
  //loop wile the sudoku is unsolved
  while(puzzle.nextOpenSpot() != NULL)
  { 
    //get the next empty spot
    SudokuSquare* next = puzzle.nextOpenSpot();
   
    //wile the next square does not have a valid value
    while(puzzle.canPut(next) == false)
    {
      //increment the value until a valid one is found
      next->value++;

      //if a valid value could not be found
      if(next->value > 9)
      {
        //reset the square to an empty square and pop the stack to backtrack
        next->value = 0;
        next = backtrack.top();
        next ->value++;
      
        backtrack.pop();
      }

    }  

 
    backtrack.push(next);
  }






  
  puzzle.printState();
  return 0;
}
