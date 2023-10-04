// TITLE        ACC COSC-2436 - Lab 2
// AUTHOR:      Andrew Graziano
// Professor:   Kathryn Rehfield
// DESCRIPTION: This program allows for a user to enter a file name, and find the largest bid
//              amount from the acution, if file deosn't exist, tells the user to enter another file

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Node.h"
#include "LinkedStack.h"

using namespace std;

int main()
{
   //creates a new stack object
   LinkedStack<int> stack;

   string file; //used to hold the name of the file the user want to enter
   ifstream reader_file; //file for reading from
   string file_heading; //used to find the name of the item being sold
   int bid_amount; //used to find bid amount from the file and add to stack
   bool file_valid = false; 

   //gets the file the user wnats to open, checks to make certain it can be opened
   //if file does not exit or can't be opened, continies while
   while(file_valid == false)
   {
      cout << "Enter the auction file name: \n";
      cin >> file;
      reader_file.open(file); //opens the file

      //check to see if the file exist and can be opened
      if(reader_file)
      {
         file_valid = true; //ends loop
         cout << "The file you entered is opening. \n"; 
      }
      else
      {
         cout << "The file you entered does not exist. \n";
      }//end if
   }//end while loop

   getline(reader_file, file_heading); //gets the item being acutioned, string on first line
   
   //goes through file and compares highest amount on 
   //top of stack to the cureent bid amount
   while(reader_file >> bid_amount)
   {
      //if stack is empty puts the bid amount on the stack
      //or if the top amount on stack is less than the bid amount,
      //bid amount is put on the top of the stack
      if (stack.isEmpty() || bid_amount > stack.peek())
      {
         stack.push(bid_amount);//puts highest bid amount on stack 
      }// end if
   }// end while loop

   //displays the largest nid amount along with the item being sold
   cout << "The item sold: " << file_heading << "\n";
   cout << "The highest bid was $" << stack.peek() << '\n';

   reader_file.close();
}