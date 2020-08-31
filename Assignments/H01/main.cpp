///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Robert O'Brien
// Email:            stolen127@live.com
// Label:            H01
// Title:            Basic Project Organization
// Course:           CMPS 2143
// Semester:         Fall 2020
//
// Description:
//       This program implements a class that allows a linked list to be used 
//       just like an array. It overloads the [] to simulate accessing seperate 
//       array elements, but really it traverses the list to find the specified 
//       node using an index value. It also overloads the "+" and "-" signs 
//       allowing a user to "add" or "push" items onto the end of the list, as 
//       well as "pop" items off the end of our array. 
//       
// Usage:
//       None
//
// Files:          
//      main.cpp    :driver program
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>   

using namespace std;

int A[100];

/**
 * Struct Name: Node
 *
 * Description:
 *      Creates a node that holds an integer and pointer.
 *
 * Public Methods:
 *                  Node()
 *                  Node(val)
 * Private Methods:
 *      N/A
 *
 * Usage:
 *
 *      Node* Temp = new Node(val);     // a node set to specified value
 *      Node* Temp = Head;              // a node set to the value of head
 *
 */

struct Node
{
    int x;                  // an integer to be stored inside the node
    Node* next;             // Node pointer to point to the next node
    Node()                  // Default node constuctor 
    {
        x = -1;             // variable x to default to -1
        next = NULL;        // set next node to NULL
    }
    Node(int n)             // Contructor that accepts a specific value
    {
        x = n;              // store the value n into variable x
        next = NULL;        // pointer next points to NULL
    }
};

/**
 * Class Name: List
 *
 * Description:
 *      This class is able to generate a linked list with the ability
 *      to insert an integer in front or end of a list. Also able to
 *      combine lists in one and print the integers within the lists.
 *      Can be printed in order, Head, Tail, or selected location. 
 *
 * Public Methods:
 *                  List()
 *      void        Push(int val)
 *      void        Insert(int val)
 *      void        PrintTail()
 *      string      Print()
 *      int         Pop()
 *      list        operator+(const List& Rhs)
 *      int         operator[](int index)
 *      friend      ostream& operator<<(ostream& os, List L)
 *      
 * Private Methods:
 *      N/A
 * 
 * Usage:
 *      List " ";                // create a list
 *      Push(val);               // add a integer to end of list
 *      Insert(val);             // add a integer to start of list
 *      PrintTail();             // print a integer at end of list
 *      string Print();          // print entire list
 *      int Pop();               // removes integer from head of list
 * 
 */

class List
{
private:
    Node* Head;                 // pointer to the start of the list
    Node* Tail;                 // pointer to the end of the list
    int Size;                   // size of the list

public:
    List()                      // default contructor, creates empty list
    {
        Head = Tail = NULL;     // sets head and tail to NULL
        Size = 0;               // Size of list = 0
    }

    /**
     * Public: Push
     *
     * Description:
     *      inserts a new node at the end of the list
     *
     * Params:
     *      int     val: value to be inserted into node
     *
     * Returns:
     *      N/A
     * 
     */  

    void Push(int val)
    {
        
        Node* Temp = new Node(val);     // allocate new memory and init node

        if (!Head && !Tail)
        {
            Head = Tail = Temp;         // Both Head and Tail nodes equal the Temp node
        }
        else
        {
            Tail->next = Temp;          //  Tail node points to Temp
            Tail = Temp;                //  Value of Tail equals Temp
        }
        Size++;                         //  increase size of list by 1
    }

    /**
     * Public: Insert
     *
     * Description:
     *      Inserts a new node with a value in front of the list
     *
     * Params:
     *      int     val: value to be inserted into node
     *
     * Returns:
     *      N/A
     * 
     */

    void Insert(int val)
    {

        Node* Temp = new Node(val);     // allocate new memory and init node

        // figure out where it goes in the list

        Temp->next = Head;              // point Temp to Head
        Head = Temp;                    // set Temp node to Head
        if (!Tail)                     
        {
            Tail = Head;                // Tail node equals Head node
        }
        Size++;                         // increase size of list by 1
    }

    /**
     * Public: PrintTail
     *
     * Description:
     *      Prints the value stored in the tail node
     *
     * Params:
     *      N/A
     *
     * Returns:
     *      N/A
     * 
     */

    void PrintTail()
    {
        cout << Tail->x << endl;        // output value of the tail node
    }

    /**
     * Public: Print
     *
     * Description:
     *      Prints out the list
     *
     * Params:
     *      N/A
     *
     * Returns:
     *      string      list: string of the integers stored in the list
     * 
     */

    string Print()
    {
        Node* Temp = Head;                          // pointer set to Head node
        string list;                                // string holding the integers within the list

        while (Temp != NULL)                        // loop if not at end of the list
        {
            list += to_string(Temp->x) + "->";      // add the integer from node into the string list
            Temp = Temp->next;                      // go to next node
        }

        return list;                                // return the list of integers
    }

    /**
     * Public: Pop
     *
     * Description:
     *      Not implemented
     *
     * Params:
     *     N/A
     *
     * Returns:
     *      int     Unkown:
     * 
     */

    int Pop()   
    {
        Size--;         // decrease size of list by 1
        return 0;                                   
    }

    /**
     * Public: operator+
     *
     * Description:
     *      Combines two lists into one
     *
     * Params:
     *      const List&     Rhs: memory address of a new list      
     *
     * Returns:
     *      List            NewList: a new list that combines two others
     */

    List operator+(const List& Rhs)
    {
        
        List NewList;               // Create new list that will contain both when done

        
        Node* Temp = Head;          // Get a reference to beginning of local list

        
        while (Temp != NULL)        // Loop through local list and Push values onto new list
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        
        Temp = Rhs.Head;            // Get a reference to head of Rhs

        
        while (Temp != NULL)        // Same as above, loop and push
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        
        return NewList;             // Return new concatenated version of lists
    }

    /**
     * Public: operator[]
     *
     * Description:
     *      Implementation of [] operator.  This function returns an 
     *      int value as if the list were an array.
     *
     * Params:
     *      int     index: max length to search the list
     *
     * Returns:
     *      int     Temp: an integer stored in Temp node
     */

    

    int operator[](int index)
    {
        Node* Temp = Head;                              // set Temp node to Head

        if (index >= Size)                              // check index is larger or equal to size of list
        {
            cout << "Index out of bounds, exiting";    
            exit(0);                                    // program implodes
        }
        else
        {

            for (int i = 0; i < index; i++)             // search list 
            {
                Temp = Temp->next;                      // point Temp node to the next node
            }
            return Temp->x;                             // return integer stored in Temp
        }
    }

    /**
     * Public: operator<<
     *
     * Description:
     *      Print the list utilizing the Print function
     *
     * Params:
     *      ostream&    os: output to screen
            List        L: list sent to output
     *
     * Returns:
     *      ostream&      os: I'm unsure what this does
     */

    friend ostream& operator<<(ostream& os, List L)
    {
        os << L.Print();    // Print list of integers
        return os;              
    }
};

int main(int argc, char** argv)
{
    List L1;                // New List named L1
    List L2;                // New List named L2

    for (int i = 0; i < 25; i++)
    {
        L1.Push(i);         // Add value i from 0 to 24 into L1
    }

    for (int i = 50; i < 100; i++)
    {
        L2.Push(i);         // Add value i from 50-99 into L2
    }   

    
    L1.PrintTail();         // output value of end position of L1
    L2.PrintTail();         // output value of end position of L2

    List L3 = L1 + L2;      // Create new list L3, combines L1 and L2
    cout << L3 << endl;     // output the list in L3

    cout << L3[5] << endl;  // output the 5th value in L3
    return 0;
}