///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Robert O'Brien
// Email:            stolen127@live.com
// Label:            P01
// Title:            Program 1 - Stack Upgrade
// Course:           2143
// Semester:         Fall 2020
//
// Description:
//       Example implementation of an array based stack that holds integers.
//
// Usage:
//       Nothing special right now.
//
// Files:            
//       None
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
 * Stack
 *
 * Description:
 *      Integer array based stack implementation
 *
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 *
 * Private Methods:
 *      - None
 *
 * Usage:
 *
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
 *
 */
class Stack {
private:
    int* S;       //array pointer
    int capacity; //max stack size
    int top;      //current top (index)
    int size;     //current num items
public:
    /**
     * Stack:
     *    Constructor.
     * Params:
     *    void
     *
     * Returns:
     *     Void
     */
    Stack() {
        capacity = 10;          // set array size
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
    }

    /**
     * Stack:
     *    Constructor.
     * Params:
     *    int : capacity
     *
     * Returns:
     *     Void
     */
    Stack(int cap) {
        capacity = cap;         // set array size      
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
    }

    /**
     * Push:
     *    Push item onto stack.
     * Params:
     *    int : data
     *
     * Returns:
     *     Void
     */
    void Push(int data) {
        int i;                // variable for loop index
        if(FullStack()) {     // check if stack is full
            int* stack2 = new int[capacity * 2];    // double size of the stack
            for (i = 0; i < capacity; i++) {        
                stack2[i] = S[i];                   // store orig values into new stack
            }

            delete[] S;     // point old stack to new stack
            S = stack2;     // update capacity of stack
            capacity *= 2;  // delete old stack
            

        }
        
        top++;              // move top of stack up
        size++;             // increment size
        S[top] = data;      // add item to array
    }
    
    /**
     * Pop:
     *    remove item from stack.
     * Params:
     *    void
     *
     * Returns:
     *     int
     */
    int Pop() {
        if (EmptyStack()) {                     // Check if stack is empty
            cout << "Error: Stack empty!";      // Print error
            return -1;
        }
        
        int data = S[top];  // pull item from stack
        top--;              // shrink the stack
        size--;             // update our size

        if (HalfStack()) {
            int i;
            int* stack2 = new int[capacity / 2];    // half size of the stack
            for (i = 0; i < capacity; i++) {
                stack2[i] = S[i];                   // store orig values into new stack
            }
            delete[] S;     // delete old stack
            S = stack2;     // point old stack to new stack
            capacity / 2;   // update capacity of stack
            
            
        }
        return data;        // send item back
    }
    /**
    * HalfStack:
    *       is the stack half capacity?
    * Params:
    *       none
    * Returns:
    *       bool
    */
    bool HalfStack() {
        if (top == capacity / 2)
            return 1;
        else
            return 0;
    }
    /**
     * Empty:
     *    is the stack empty?
     * Params:
     *    void
     *
     * Returns:
     *     bool : true == stack is empty
     */
    bool EmptyStack() {
        //return size == 0;
        return top == -1;
    }

    /**
     * Full:
     *    is the stack full?
     * Params:
     *    void
     *
     * Returns:
     *     bool : true == stack is full
     */
    bool FullStack() {
        return top == capacity - 1;
    }

    /**
     * Print:
     *    Used so we can inspect our stack.
     * Params:
     *    void
     *
     * Returns:
     *     void
     */
    void Print() {
        for (int i = top; i >= 0; i--) {
            cout << S[i] << endl;
        }
    }

    /**
     * Overloaded ostream <<
     *    Lets us print a stack using cout
     * Params:
     *    ostream &os   : instance of ostream passed in by reference
     *    const Stack   : instance of stack passed in using const so
     *                    it cannot be changed
     *
     * Returns:
     *     ostream
     */
    friend ostream& operator<<(ostream& os, const Stack s) {
        os << "Overloaded!!" << endl;
        for (int i = s.top; i >= 0; i--) {
            os << s.S[i] << endl;
        }
        return os;
    }
};

/**
 * Person
 *
 * Description:
 *      Example struct that represents a person.
 *
 * Usage:
 *
 *  Person P1;
 *
 *  P1.fname = "firstName";
 *  P1.lname = "lastName";
 *  P1.age = 99
 *  cout<<P1<<endl;
 *
 *  Person P2("billy","bob",11);
 *  cout<<P2<<endl;
 */
struct Person {
    string fname;
    string lname;
    int age;

    Person();
    Person(string, string, int);

    friend ostream& operator<<(ostream& os, const Person p) {
        os << p.fname << "," << p.lname << " : " << p.age << endl;
        return os;
    }
};

/**
 * Constructor:
 *    Constructs the person structure
 * Params:
 *    void
 *
 * Returns:
 *     void
 */
Person::Person() {
    fname = "";
    lname = "";
    age = 0;
}

/**
 * Constructor:
 *    Constructs the person structure
 * Params:
 *    string    : first name
 *    string    : last name
 *    int       : persons age
 *
 * Returns:
 *     void
 */
Person::Person(string f, string l, int a) {
    fname = f;
    lname = l;
    age = a;
}

int main() {
    Stack S1;                   // create new stack variable
    int num;                    // variable to read in num from input file

    ifstream infile;            // variable to read in from file
    infile.open("input.txt");   // open input file

    S1.Pop();                   // pop to trigger empty stack message
    cout << endl;

    while (infile >> num) {     // read in integer to end of file
        S1.Push(num);           // add integer into stack
    }
    
    cout << "Stack before pop\n";

    S1.Print();                 // print current stack

    S1.Pop();                   // remove an integer from top of stack
    S1.Pop();
    S1.Pop();

    cout << endl;

    cout << "Stack after pop\n";
    S1.Print();                 // print stack after pop
                               
    return 0;
}
