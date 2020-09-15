/*****************************************************************************
*
* Authoer:      Robert O'Brien
* Email:        stolen127@live.com
* Label:        P01
* Title:        Stack Upgrade
* Course:       2143 OOP
* Semester:     Fall 2020
*
* Description: 
*       This program implements a linear data structure, stack. This program
*       is able to push and pop values on and off the stack. Prints the start,
*       max, and ending size of the stack. If the stack reaches it's max
        capacity, the program will double the size of the stack to accomdate.
*        
* Usage:
*       Peeling bananas 
* Files:
*       main.cpp        : main driver
*       Stack.cpp       : class header and implementation
*       input.txt       : commands and values to be read
* 
*****************************************************************************/

#include <iostream>	
#include <fstream>
#include "Stack.hpp";
using namespace std;

/////////////////////////////////////////////////////////
//            Function prototypes                      //
/////////////////////////////////////////////////////////
void pushorpop(fstream &in, Stack &S1);
void openfiles(fstream &in, ofstream &out);
void closefiles(fstream& in, ofstream &out);
void studentheader(ofstream &out);
void StartSize(Stack &S1, ofstream &out);
void MaxSize(Stack& S1, ofstream& out);
void EndSize(Stack& S1, ofstream& out);

/////////////////////////////////////////////////////////
//                  MAIN                               //
/////////////////////////////////////////////////////////
int main()
{
    fstream in;             // input variable
    ofstream out;           // output variable
    Stack S1;               // create new stack variable

    openfiles(in, out);     // open input and output files
    studentheader(out);     // print student header
    pushorpop(in, S1);      // push or pop to the stack
    StartSize(S1, out);     // print start size of stack
    MaxSize(S1, out);       // print max size of stack
    EndSize(S1, out);       // print end size of stack
    closefiles(in, out);    // close input and output files

    return 0;
}

/////////////////////////////////////////////////////////
//                 Function Definitions                //
/////////////////////////////////////////////////////////
/**
     * Public: pushorpop
     *
     * Description:
     *      Reads file command and values if "push" command.
     *      Selects with method from Stack.hpp to use and execute.
     *
     * Params:
     *      fstream     : file input variable
     *      Stack       : Initialised stack
     * Returns:
     *      NONE
     */
void pushorpop(fstream &in, Stack &S1)
{
    string command;             // command read from input
    int value;                  // value read from input "push" command

    while (!in.eof())           // read to end of file
    {
        in >> command;           // read push or pop  
        if (command == "push")   
        {
            in >> value;         // read in value
            S1.push(value);      // use stack push method, pass value
        }
        else
            S1.pop();            // if not push, use pop method
    }
}

/**
     * Public: openfiles
     *
     * Description:
     *      Opens input and output files.
     *
     * Params:
     *      fstream     : file input varibale
     *      ofstream    : file output variable
     *
     * Returns:
     *      NONE
     */
void openfiles(fstream &in, ofstream &out)
{
    in.open("input.txt");
    out.open("output.txt");
}

/**
     * Public: closefiles
     *
     * Description:
     *      Closes input and output files.
     *
     * Params:
     *      fstream     : file input variable
     *      ofstream    : file output variable
     *
     * Returns:
     *      NONE
     */
void closefiles(fstream &in, ofstream &out)
{
    in.close();
    out.close();
}

/**
     * Public: studentheader
     *
     * Description:
     *      Prints student head to screen and output file.
     *
     * Params:
     *      ofstream    : file output variable
     *
     * Returns:
     *      NONE
     */
void studentheader(ofstream &out)
{
    // print header to screen
    cout << "Name: Robert O'Brien" << '\n';     
    cout << "Program: P01 - Stack Upgrade" << '\n';
    cout << "Date: Sep 15 2020" << '\n';
    cout << "\n\n";

    // print header to output file
    out << "Name: Robert O'Brien" << '\n';      
    out << "Program: P01 - Stack Upgrade" << '\n';
    out << "Date: Sep 15 2020" << '\n';
    out << "\n\n";
}

/**
     * Public: StartSize
     *
     * Description:
     *      Prints starting size of the stack.
     *
     * Params:
     *      Stack       : array based data structure
     *      ofstream    : file output variable
     *
     * Returns:
     *      NONE
     */
void StartSize(Stack& S1, ofstream &out)
{
        // starting size of the stack
    out << "Start Size: " << S1.StartofStack(); 
    out << '\n';
}

/**
     * Public: MaxSize
     *
     * Description:
     *      Prints maximum size of the stack.
     *
     * Params:
     *      Stack       : array based data structure
     *      ofstream    : file output variable
     *
     * Returns:
     *      NONE
     */
void MaxSize(Stack& S1, ofstream& out)
{
        // max size of the stack
    out << "Max Size: " << S1.MaxofStack();      
    out << '\n';
}

/**
     * Public: EndSize
     *
     * Description:
     *      Prints ending size of the stack.
     *
     * Params:
     *      Stack       : array based data structure
     *      ofstream    : file output variable
     *
     * Returns:
     *      NONE
     */
void EndSize(Stack& S1, ofstream& out)
{
        // end size of the stack
    out << "Ending Size: " << S1.EndofStack();      
    out << '\n';
}
