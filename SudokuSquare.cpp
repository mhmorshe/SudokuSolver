#include <iostream>
#include <list>
using namespace std;
class SudokuSquare
{

  public:
    bool set;//determin if the value of this square has been set yet
    list<int> possible;
    int value;

    SudokuSquare()
    {
      set = false;
      for (int i = 1; i <= 9; i++)
      {
        possible.push_back(i);
      }
    }

    SudokuSquare(int toSet)
    {
      set = true;
      value = toSet;
      possible.push_back(toSet);
    }

    //this method will update the value of the square
    void update()
    {
      if (!set)
      {
        if (possible.size() == 1)//if there is only one possiblility
        {
          value = possible.front();
          set = true;
          //cout << "Updated to " << value << " ";
        }
      }
    }


    //this method will remove a possibility when needed
    void removePoss(int poss)
    {
      if (!set)
      {
        possible.remove(poss);
      }
    }


    void setVal(int val)
    {
      for (int i = 1; i <= 9; i++)
      {
        if (val != i)
        {
          removePoss(i);
        }
      }

      update();

    }



    //return true if num is a possibility, false otherwise
    bool isAPoss(int num)
    {
      bool toReturn = false;
      if (!set)
      {
        std::list<int>::const_iterator iterator;
        for (iterator = possible.begin(); iterator != possible.end(); ++iterator) 
        {
          if ((*iterator) == num)
          {
            toReturn = true;
          }
        }
        return toReturn;
      }
    }



};
