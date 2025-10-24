/******************************************************************************
# Author:            Ari P.
# Assignment:        Midterm Exam
# Date:              10/23/25
# Description:       This program allows the user to add or remove values from
#                    a queue until they quit.
# Input:             option (char), val (int)
# Output:            queue (int array)
# Sources:           Midterm Exam specifications
#*****************************************************************************/

#include <iostream>
using namespace std;

const int MAX = 3; // maximum size of queue

void welcome();
int enqueue(int queue[], int &size, int val);
int dequeue(int queue[], int &size, int val);
void remove(int queue[], int &size, int val);
void printQueue(int queue[], int size);
void goodbye();

int main() {
   int queue[MAX]; // integer array for queue
   int size = 0;   // contains number of elements in queue
   char option = ' ';
   int val = 0;
   int test = 0;

   welcome();
   cout << endl;
   while (option != 'q') {
      cout << "Enter option: ";
      cin >> option;
      while ( cin.fail() || (option != '+' && option != '-' && option != 'p' && option != 'q') ) {
         cin.clear();
         cout << "Invalid option." << endl << endl;
         cout << "Enter option: ";
         cin >> option;
      }
      if (option == '+') {
         cout << "Integer: ";
         cin >> val;
         test = enqueue(queue, size, val);
         if (test == 1) {
            cout << "Error: Queue Overflow!" << endl;
         }
         printQueue(queue, size);
         cout << endl;
      }
      else if (option == '-') {
         cout << "Integer: ";
         cin >> val;
         test = dequeue(queue, size, val);
         if (test == 1) {
            cout << "Queue Empty." << endl;
         }
         else if (test == 2) {
            cout << val << " is not in the queue." << endl;
         }
         printQueue(queue, size);
         cout << endl;
      }
      else if (option == 'p') {
         if (size > 0) {
            printQueue(queue, size);
         }
         else {
            cout << "Queue Empty." << endl;
         }
         cout << endl;
      }
   }
   cout << endl;
   goodbye();
   return 0;
}

// Name:    welcome()
// Desc:    This function prints a welcome message
// input:   None
// output:  None
// return:  void
void welcome() {
   cout << "Welcome to the FIFO Queue program!" << endl;
}

// Name:    enqueue()
// Desc:    This function adds a value to the end of the queue
// input:   None
// output:  None
// return:  status (int)
int enqueue(int queue[], int &size, int val) {
   if (size == MAX) {
      return 1;
   }
   queue[size] = val;
   size++;
   return 0;
}

// Name:    dequeue()
// Desc:    This function removes a value from the start of the queue, as well
//          as everything before it
// input:   None
// output:  None
// return:  status (int)
int dequeue(int queue[], int &size, int val) {
   int pos = -1;
   if (size == 0) {
      return 1;
   }
   for (int i = 0; i < size && pos < 0; i++) {
      if (queue[i] == val) {
         pos = i;
      }
      else if (i == size - 1) {
         return 2;
      }
   }

   for (int i = pos; i >= 0; i--) {
      remove(queue, size, i);
   }
   return 0;
}

// Name:    remove()
// Desc:    This function removes a value at a specific position from the queue
// input:   None
// output:  queue (int array)
// return:  void
void remove(int queue[], int &size, int pos) {
   if (size > 1) {
      for (int i = pos; i < size - 1; i++) {
         queue[i] = queue[i + 1];
      }
   }
   size--;
   queue[size] = 0;
}

// Name:    printQueue()
// Desc:    This function prints the queue
// input:   None
// output:  queue (int array)
// return:  void
void printQueue(int queue[], int size) {
   cout << "[";
   for (int i = 0; i < size; i++) {
      cout << queue[i];
      if (i != size - 1) {
         cout << ", " ;
      }
    }
    cout << "]" << endl;
}

// Name:    goodbye()
// Desc:    This function prints a goodbye message
// input:   None
// output:  None
// return:  void
void goodbye() {
   cout << "Goodbye!" << endl;
}