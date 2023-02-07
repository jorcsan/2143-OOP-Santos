/*****************************************************************************
 *
 *  Author:          Jorge Santos
 *  Email:           jorcsantos2@gmail.com
 *  Label:           P01
 *  Title:            Vector Class
 *  Course:           CMPS 2143
 *  Semester:         Spring 2023
 *
 *  Description:
 *        This program contains a class with three differet constructors to
 *initialize a vector. The class contains various methods in order to add or
 *remove items at different locations within the list. Usage: how to use the
 *program if necessary
 *
 *  Files:            (list of all source files used in this program)
 *****************************************************************************/
#include <fstream>
#include <iostream>

using namespace std;

struct Node {
  // Each node will have a number and next pointer

  int data;
  Node *next;

  // Parameterized constructor with num passed in
  Node(int num) {
    data = num;
    next = NULL;
  }
};

/**
 * Class Name
 *
 * Description:
 *      Description of your class and what it does
 *
 * Public Methods:
 *      - A list of
 *      - each public method
 *      - with return types
 *
 * Private Methods:
 *      - A list of
 *      - each private method
 *      - with return types
 *
 * Usage:
 *
 *      - examples of how
 *      - to use your class
 *
 */
class Vector {
private:
  Node *front;
  Node *tail;

  // variable will be useful when finding indexes
  int currentsize = 0;


/**
   * Privat : pushRear
   *
   * Description:
   *      this function will make a copy of a vector with new memory
   * Params:
   *      - const vector-  a vector that will be inserted at the end 
   * of the list
   * Returns:
   *      -void
*/
  Node *copyVector(const Vector &other) {
    Node *travel = other.front;
    Vector *newVector = new Vector;

    while (travel != nullptr) {
      newVector->pushRear(travel->data);
      travel = travel->next;
    }
    return newVector->front;
  }

public:
  
/**
   * Public : Vector
   *
   * Description:
   *      to initialize a Vector
   *       constructor
   * Params:
   *      none
   *
   * Returns:
   *      -no return?
   */
  Vector() { front = tail = nullptr; }

  /**
   * Public : Vector
   *
   * Description:
   *      Vector initializes a vector using array
   *
   * Params:
   *      array of integers
   *       int size of the array
   * Returns:
   *      -none
   */
  Vector(int *A, int size) {
    front = tail = nullptr;
    currentsize = size;

    for (int i = 0; i < size; i++) {
      Node *temp = new Node(A[i]);

      if (tail == nullptr) {
        front = tail = temp;
      }

      else {
        tail->next = temp;
        tail = temp;
      }
    }
  }

  /**
   * Public : Vector
   *
   * Description:
   *      To initialize a vector using a input file
   *
   * Params:
   *      ifstream infile
   *      string infilename
   * Returns:
   *      none
   */
  Vector(string FileName){
    int val;                         
    front = tail = NULL;              

      ifstream infile;                 
            infile.open(FileName);           

            while(!infile.eof()) {           
                infile >> val;               // pull in value
                pushRear(val);              // push the value to the vector
            }
        }

  /**
   * Public : Vector
   *
   * Description:
   *      initialize a Vector using another Vector
   *
   * Params:
   *      Node * &v1
   *
   * Returns:
   *      none
   */
  Vector(const Vector &v1) {
    this->front = copyVector(v1);

    Node* travel = this->front;
    while(travel->next){
      travel=travel->next;
    }

    this->tail = travel;
  
  }

  /**
   * Public : pushFront
   *
   * Description:
   *      To place a number at the front of the list
   *
   * Params:
   *      int val - number to be put in the list
   *
   * Returns:
   *      void
   */
  void pushFront(int val) {
    Node *temp = new Node(val);

    if (front == NULL) {
      front = temp;
      tail = temp;
      currentsize++;
    }

    else {
      temp->next = front;

      front = temp;
      currentsize++;
    }
  }

  /**
   * Public : pushFront
   *
   * Description:
   *      this function will place a vector at the front of another vector
   * Params:
   *      - const vector &other-  a vector that will be inserted at 
   *the end of the list
   * Returns:
   *      -void
*/
  void pushFront(const Vector &other) {

    Node* tempFront = copyVector(other);

    other.tail->next = this->front;

    this->front = other.front;

    currentsize = other.currentsize + currentsize;
    //point tail of "this" vector to the front of copied vector.

  }

  /**
   * Public : pushRear
   *
   * Description:
   *      To insert a value at the end of the list
   *
   * Params:
   *      int val - number that will be inserted
   *
   * Returns:
   *      void
   */
  void pushRear(int val) {
    Node *temp = new Node(val);

    // If the list is empty, your new node is head
    if (front == NULL) {
      front = temp;
      tail = temp;
      currentsize++;
    }
    // If it is not empty, traverse list
    else {
      tail->next = temp;
      currentsize++;
    }

    tail = temp;
  }

/**
   * Public : pushRear
   *
   * Description:
   *      this function will place a vector at the end of another vector
   * Params:
   *      - const vector-  a vector that will be inserted at the end 
   * of the list
   * Returns:
   *      -void
*/
  void pushRear(const Vector &other) {
    Node* tempTail = copyVector(other);

    this->tail->next = other.front;

    this->tail = other.tail;

    currentsize = other.currentsize + currentsize;
  }

  /**
   * Public : pushAt
   *
   * Description:
   *     to insert a value at a certain index in the list.
   *
   * Params:
   *      - list params
   *      - one per line
   *      - with return type
   *      - and one line description
   *
   * Returns:
   *      - void
   */
  void pushAt(int loc, int val) {
    Node *temp = new Node(val);
    if (loc == 0) { // if location = 0
      pushFront(val);
    }

    else if (front == NULL) {
      front = temp;
      tail = temp;
      currentsize++;
    }

    else {
      Node *traverse = front;
      for (int i = 0; i < (loc - 1); i++) {

        traverse = traverse->next;
      }

      if (traverse->next == NULL)
        pushRear(val);

      else {
        temp->next = traverse->next;
        traverse->next = temp;
        currentsize++;
      }
    }
  }


/**
   * Public : ascending
   *
   * Description:
   *      this function will place a number int the list in the correct order if it is in ascending order.
   * Params:
   *      - int-val  a number that will be inserted in the list
   *
   * Returns:
   *      -void
*/
  void ascending(int val) {

    Node *temp = new Node(val);
    Node *traverse = front;

    if (traverse->data > val) {
      pushFront(val);
    }

    else {
      while (traverse->next != NULL && (traverse->next->data < val))
        traverse = traverse->next;

      if (traverse->next == NULL)
        pushRear(val);

      else {
        temp->next = traverse->next;
        traverse->next = temp;
        currentsize++;
      }
    }
  }


/**
   * Public : descending
   *
   * Description:
   *      this function will place a number int the list in the correct order if it is in descending order.
   * Params:
   *      - int-val  a number that will be inserted in the list
   *
   * Returns:
   *      -void
   */
  void descending(int val) {
    Node *temp = new Node(val);
    Node *traverse = front;
    
    if (val >= traverse->data) {
      pushFront(val);
    }

    else {
      while (traverse->next != NULL && (traverse->next->data < temp->data))
        traverse = traverse->next;

      if (traverse->next == NULL)
        pushRear(val);

      else {
        temp->next = traverse->next->next;
        traverse->next = temp;
        currentsize++;
      }
    }
  }
  

/**
   * Public : inOrderPush
   *
   * Description:
   *      this function will place a number int the list in the correct order by checking if it is in descending or ascending order. Then calling the respective function.
   * Params:
   *      - int-val  a number that will be inserted in the list
   *
   * Returns:
   *      -void
   */
  void inOrderPush(int val) {

    Node *temp = new Node(val);
    Node *traverse = front;
    
    // will hold the amount of times numbers are greater or less than
    // the next
    int asc = 0, des = 0;
    if (front == NULL) {
      front = temp;
      tail = temp;
      currentsize++;
    }

    while(traverse->data <= front->data || traverse != NULL){
      
      traverse = traverse->next;
    }

    if(traverse->data > front->data){
    ascending(val);
  }

  else
    descending(val);
    
    
  
      
  }

  /**
   * Public : popFront
   *
   * Description:
   *       Will remove the first item in the list and return it
   *
   * Params:
   *      - int-hold  the first item in the list
   *
   * Returns:
   *      hold int
   */
  int popFront() {
    int hold;

    if (front) {
      Node *temp = front;
      front = temp->next;

      hold = temp->data;
      delete temp;
      temp = NULL;

      return hold;
      currentsize -= 1;
    }

    else {

      return 0;
    }
  }


  /*
   * Public : popRear
   *
   * Description:
   *      will remove the last item(tail)
   *
   * Params:
   *      -none
   *
   * Returns:
   *      -int hold - last item in the list
   */
  int popRear() {
    int hold;

    if (front) {

      Node *traverse = front;
      Node *prev = NULL;
      while (traverse->next != NULL) {
        prev = traverse;
        traverse = traverse->next;
      }

      hold = traverse->data;
      delete traverse;
      traverse = NULL;
      prev->next = NULL;
      currentsize -= 1;

      return hold;
    }

    else {

      return -1;
    }
  }


  /*
   * Public : popAt
   *
   * Description:
   *       will remove a number at a certain location and return it
   *
   * Params:
   *      - int loc - the index of the item
   *
   * Returns:
   *      -int - the value at the index
   */
  int popAt(int loc) {
    int val = 0;

    if (loc == 0)
      return popFront();

    else if (front == NULL) {
      cout << "no items";
      return 0;
    }

    else {
      Node *traverse = front;
      for (int i = 0; i < (loc - 1); i++) {

        traverse = traverse->next;
      }

      if (traverse->next == NULL)
        return popRear();

      else {
        
        Node *temp = traverse->next;
        traverse->next = traverse->next->next;
        val = temp->data;
        
        delete temp;
        currentsize -= 1;
        return val;
      }
    }
  }


  /*
   * Public : find
   *
   * Description:
   *       will find a certain value in the list and use popAt()
   *remove it
   * Params:
   *      int val - the number that we find
   *
   * Returns:
   *      -void
   */
  int find(int val) {

    Node *traverse = front;
    int index = 0;
    int i;
    
    while (traverse->next != NULL) {
      if(traverse->data == val){
        int i = index;
        return popAt(i);
      }
      traverse = traverse->next;
      index++;
      
    }

    
    
    if (index == 0) {
      
      return -1;
    }

    return i;
  
  }


  /*
   * Public : print
   *
   * Description:
   *       will print to std:out and outfile
   *
   * Params:
   *      - ostream &outfile-gives the ability to use outfile
   *
   * Returns:
   *      -void
   */
  void print(ostream &outfile) {
    Node *traverse = front;
    outfile << "[";
    cout << "[";
    while (traverse != NULL) {
      outfile << traverse->data << " ";
      cout << traverse->data << " ";
      traverse = traverse->next;
    }
    outfile << "]" << endl;
    cout << "]" << endl;
  }


  /*
   * Public : print
   * Description:
   *       will print to std:out 
   * Params:
   *     none
   * Returns:
   *      -void
   */
  void print() {
    Node *traverse = front;
    cout << "[";
    while (traverse != NULL) {
      cout << traverse->data << " ";
      traverse = traverse->next;
    }
    cout << "]" << endl;
  }
};

/*
   * Public : printheader
   * Description:
   *       will print header to outfile
   * Params:
   *     ostream & outfile
   * Returns:
   *      -void
   */
void printheader(ostream &outfile) {
  outfile << "Jorge Santos" << endl
          << "February 7, 2023"
          << "Spring 2143";
}



int main() {
  ofstream outfile;
  outfile.open("test.out");
  
  
int x = 0;

Vector v1;
v1.pushFront(18);
v1.pushFront(20);
v1.pushFront(25);
v1.pushRear(18);
v1.pushRear(20);
v1.pushRear(25);
v1.print(outfile);
// [25, 20, 18, 18, 20, 25]

int A[] = {11,25,33,47,51};
Vector v2(A,5);
v2.print(outfile);
// [11, 25, 33, 47, 51]

v2.pushFront(9);
v2.inOrderPush(27);
v2.pushRear(63);
v2.print(outfile);
// [9, 11, 25, 27 33, 47, 51, 63]

v1.pushRear(v2);
v1.print(outfile);
// [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

x = v1.popFront();
x = v1.popFront();
x = v1.popFront();
v1.print(outfile);
// [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
cout<<x<<endl;
outfile<<x<<endl;
// 18

x = v1.popRear();
x = v1.popRear();
x = v1.popRear();
v1.print(outfile);
// [18, 20, 25, 9, 11, 25, 27, 33]
cout<<x<<endl;
outfile<<x<<endl;
// 47

x = v2.popAt(3);
v2.print(outfile);
// [9, 11, 25, 33, 47, 51, 63]
cout<<x<<endl;
outfile<<x<<endl;
// 27

x = v2.find(51);
cout<<x<<endl;
outfile<<x<<endl;
// 5

x = v2.find(99);
cout<<x<<endl;
outfile<<x<<endl;
// -1

Vector v3(v1);
v3.print(outfile);
// [18, 20, 25, 9, 11, 25, 27, 33]

v3.pushFront(v2);
v3.print(outfile);
//[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

Vector v4("input.dat");
v4.pushRear(v3);
v4.print(outfile);
// [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]


}