/*****************************************************************************
*
*  Author:           Terry Griffin
*  Email:            terry.griffin@msutexas.edu
*  Label:            A03
*  Title:            circular array queue
*  Course:           2043
*  Semester:         spring 2023

*  Description:
*        This program implements a class to store arrays inside a circular
queue. It overloads various objects to make the implementation of the queue more seamless when adding items to it. And finally at the end it will cout the queues contents
*
*  Usage: Storing numbers that you want the first ones stored in to be the first ones printed out
*
*
*  Files:           main.cpp
*****************************************************************************/
#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 *
 * Description:
 *      It stores arrays inside a circular queue.
 *
 * Public Methods:
 *      CircularArrayQue()
 *      void             Push(int item)
 *      int              pop()
 *
 * Private Methods:
 *      void        init(int size = 0)
 *      bool        full
 *
 * Usage:
 *    CircularArrayQue(10)      //creates a queue that will hold 10   * items
 *    C1.Push(1)                //will insert the integer one into the queue
 *     C1.pop()                 //takes the first item out of the queue
 *
 */
class CircularArrayQue {
private:
  int *Container;  // holds integers
  int Front;       // front of the queue
  int Rear;        // item in back of the queue
  int QueSize;     // items in the queue
  int CurrentSize; // current size of the queue

  /**
   * Private : init
   *
   * Description:
   *      intitializes the variables front, rear, currentsize, and Quesize
   *
   * Params:
   *      int size
   *
   * Returns:
   *      nothing it is a constructor
   */
  void init(int size = 0) {
    Front = Rear = CurrentSize = 0;
    QueSize = size;
  }

  /**
   * Private : Full
   *
   * Description:
   *      checks if the queue is full
   *
   * Params:
   *      none
   *
   * Returns:
   *     true         bool
   */
  bool Full() { return CurrentSize == QueSize; }

public:
  /**
   * Public : CircularArrayQue
   *
   * Description:
   *      creates a queue and array with the size of 10
   *
   * Params:
   *      none
   *
   * Returns:
   *      nothing it is a constructor
   */
  CircularArrayQue() {
    Container = new int[10];
    init(10);
  }
  /**
   * Public : CircularArrayQue
   *
   * Description:
   *      creates a queue and array with the size of 10
   *
   * Params:
   *      int size
   *
   * Returns:
   *      nothing it is a constructor
   */
  CircularArrayQue(int size) {
    Container = new int[size];
    init(size);
  }

  /**
   * Public : Push
   *
   * Description:
   *    inserts item into the queue
   *
   * Params:
   *      int item
   *
   * Returns:
   *      void
   */
  void Push(int item) {
    if (!Full()) {
      Container[Rear] = item;
      Rear = (Rear + 1) % QueSize;
      CurrentSize++;
    } else {
      cout << "FULL!!!!" << endl;
    }
  }

  /**
     * Public : pop
     * 
     * Description:
     *    takes out the first item that was put in the queue
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      the first number put in the queue      type:int
     */
  int Pop() {
    int temp = Container[Front];
    Front = (Front + 1) % QueSize;
    CurrentSize--;
    return temp;
  }
  friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

// overloading the + opperator
ostream &operator<<(ostream &os, const CircularArrayQue &other) {

  for (int i = other.Front; i < other.CurrentSize;
       i = (i + 1) % other.QueSize) {
    os << other.Container[i] << " ";
  }
  os << endl;
  return os;
}

/**
 * Main Driver
 *
 * For this program, the main driver was used to test the CircularArrayQue class
 *
 */
int main() {
  CircularArrayQue C1(5);

  // C1.Push(34);
  // C1.Push(38);
  // C1.Push(44);
  // C1.Push(22);
  // C1.Push(99);
  // C1.Push(100);

  //will put the numbers 1, 2, and 3 in the queue
  C1.Push(1);
  C1.Push(2);
  C1.Push(3);
  // C1.Push(6);
  // C1.Push(7);
  cout << C1 << endl;

  // C1.Push(1);
  // C1.Push(2);
  // C1.Push(3);

  cout << C1 << endl;
}