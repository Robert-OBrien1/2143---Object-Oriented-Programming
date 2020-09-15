#include <iostream>
#include <string>
using namespace std;

/**
 * Class Name
 *
 * Description:
 *      This class implements a stack based data structure.
 *      Able to store and remove data from the stack using
 *      push and pop. If capacity of the stack is reached,
 *      the stack can be doubled in size and halfed in size
 *      when using the pop method. 
 *      
 * Public Methods:
 *                  Stack();             
 *                  Stack(int);         
 *      void        push(int);         
 *      int         pop();
 *      bool        empty();
 *      bool        full();
 *      void        print();
 *      int         StartofStack();
 *      int         MaxofStack();
 *      int         EndofStack();
 *      void        doublestack();
 *      void        halfstack();
 *
 * Private Methods:
 *      NONE
 *
 * Usage:
 *      Stack S1            creates instance of Stack
 *      Stack S1(4)         creates instance of stack with capacity set to 4
 *      push(42)            add 42 to top of stack
 *      pop()               remove value at top of stack
 *      print()             print values within the stack
 *      StartofStack()      print starting size of the stack
 *      MaxofStack()        print max size of the stack
 *      EndofStack()        print ending size of the stack
 *      doublestack()       double the size of the stack
 *      halfstack()         half the size of the stack
 */

class Stack
{
private:
    int* S;             // array pointer
    int capacity;       // max stack size
    int top;            // current top (index)
    int size;           // current num items 
    int min;            // Minimum size of stack
    int max;            // Maximum size of array
public:
    Stack();            // default constructor 
    Stack(int);         // constructor
    void push(int);         
    int pop();
    bool empty();
    bool full();
    void print();
    int StartofStack();
    int MaxofStack();
    int EndofStack();
    void doublestack();
    void halfstack();
};

/**
     * Public: Stack()
     *
     * Description:
     *      creates default instance of stack
     *
     * Params:
            NONE
     * Returns:
     *      NONE
     */
Stack::Stack()
{
    capacity = 10;          // set array size
    S = new int[capacity];  // allocate new memory
    top = -1;               // initialize top of stack
    size = 0;               // set stack to empty
    min = capacity;         // initialize minimum stack size to capacity
    max = min;              // initialize maximum stack size to the minimum
}

/**
     * Public: Stack(cap)
     *
     * Description:
     *      creates instance of a stack set to a alternate capacity
     *
     * Params:
     *      int     capacity of the stack
     * Returns:
     *      NONE
     */
Stack::Stack(int cap)
{
    capacity = cap;         // set array size      
    S = new int[capacity];  // allocate new memory
    top = -1;               // initialize top of stack
    size = 0;               // set stack to empty
    min = capacity;         // initialize minimum stack size to capacity
    max = min;              // initialize maximum stack size to the minimum
}

/**
     * Public: push
     *
     * Description:
     *      inserts value on top of the stack.
     *
     * Params:
     *      int     value read from file to be added to the stack
     *
     * Returns:
     *      NONE
     */
void Stack::push(int data)
{
    if (full())         // before executing push, check if stack is full
        doublestack();  // double the stack

    top++;              // move top of stack up
    size++;             // increment size
    S[top] = data;      // add item to array

    if ((capacity != min) && (size < capacity / 2))    
        halfstack();

}

/**
     * Public: pop
     *
     * Description:
     *      removes value from top of the stack
     *
     * Params:
     *      NONE
     *
     * Returns:
     *      int     value popped from top of the stack
     */
int Stack::pop()
{
    if (empty())        // check if stack is empty
    {
        cout << "Error: Stack empty!\n\n";      // print error message
        return -1;
    }
    int data = S[top];  // pull item from stack
    top--;              // shrink the stack
    size--;             // update our size
    return data;        // send item back
}

bool Stack::empty()
{
    return size == 0;
}

bool Stack::full()
{
    return top == capacity - 1;
}

/**
     * Public: print
     *
     * Description:
     *      prints the values stored in the stack
     *
     * Params:
     *      NONE
     *
     * Returns:
     *      NONE
     */
void Stack::print()
{
    for (int i = top; i >= 0; i--) 
    {
        cout << S[i] << endl;
    }
}

/**
     * Public: StartofStack
     *
     * Description:
     *      returns value of the starting size of the stack to main
     *
     * Params:
     *      NONE
     *
     * Returns:
     *      int     value to be returned to main
     */
int Stack::StartofStack()
{
    return min;
}

/**
     * Public: MaxofStack
     *
     * Description:
     *      returns value of the max size of the stack to main
     *
     * Params:
     *      NONE
     *
     * Returns:
     *      int     value to be returned to main
     */
int Stack::MaxofStack()
{
    return max;
}

/**
     * Public: EndofStack
     *
     * Description:
     *      returns value of the ending size of the stack to main
     *
     * Params:
     *      NONE
     *
     * Returns:
     *      int     value to be returned to main
     */
int Stack::EndofStack()
{
    return capacity;
}

/**
     * Public: doublestack
     *
     * Description:
     *      doubles the size of the stack and prints the current
     *      size to screen and output file
     *
     * Params:
     *      NONE
     *
     * Returns:
     *      NONE
     */
void Stack::doublestack()
{
    int i;      // index for loop

    int *tempstack = new int[capacity * 2];     // double size the stack
    for (i = 0; i < capacity; i++)
    {
        tempstack[i] = S[i];        // set values of the tempstack to original
    }
    delete[] S;                     // delete values in original stack   
    S = tempstack;                  // set values in tempstack to original 

    // print to screen current size of stack after resize
    cout << "+ : " << capacity << " -> " << capacity * 2 << '\n';

    capacity *= 2;                  // double size of the stack  

    if (max < capacity)     
        max = capacity;
}

/**
     * Public: halfstack
     *
     * Description:
     *      decreases the size of the stack by half. prints the current
     *      size of the stack to screen and output file.
     *
     * Params:
     *      NONE
     *
     * Returns:
     *      NONE
     */
void Stack::halfstack()
{
    int i;      // index for loop

    // New stack with half previous size
    int *tempstack = new int[capacity / 2]; 

    for (i = 0; i < capacity / 2; i++)
    {
        tempstack[i] = S[i];    // Fill new stack with current values
    }
    delete[] S;                 // Delete previous stack

    S = tempstack;              // Point to new stack

    // print to screen current size of stack after resize
    cout << "- : " << capacity << " -> " << capacity / 2 << '\n';

    capacity /= 2;              // Half size of the stack
}