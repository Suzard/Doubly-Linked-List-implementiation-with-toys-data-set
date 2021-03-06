// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "QueueADT.h"
#include "StackADT.h"
//prints a nice menu for instructions to give to the user
void printWelcome()
{
	cout << "\n\n\t\t *~~*~~* WELCOME *~~*~~*\n\n"
		<< "\tTo the Stack and Queue Driver Program!\n\n"
		<< "\t\tThis program will: \n"
		<< "\t\t - Read and validate input\n"
		<< "\t\t - Test stack functions\n"
		<< "\t\t - Test queue functions\n"
		<< "\t\t - These are the following commands\n"
		<< "\t\t\t - I stands for insert. Must be followed by a valid double\n"
		<< "\t\t\t - D stands for delete\n"
		<< "\t\t\t - C displays the number of elements in the two stacks and two queues\n"
		<< "\t\t\t - T displays the top of the two stacks\n"
		<< "\t\t\t - R to display elements at end of queues\n"
		<< "\t\t\t - Q to quit the program\n";
		cout << "\t\t The ToyList is sorted in ascending order by ToyID\n\n";
} 
//checks if the inserted value is a double 
void check_double(string function, Stack<double> &inS, Queue<double> &inQ, Stack<double> &outS, Queue<double> &outQ) {
	string double_part = function.substr(function.find(" ") + 1);
	bool notdigit = false;
	bool first_period = true;
	for (char c : double_part) {
		if (!isdigit(c)) {
			if (c == '.' && first_period) {
				first_period = false;
			}
			else {
				notdigit = true;
				break;
			}

		}
	}
	if (notdigit)
		cout << "Please insert in the following format: I, space, then a double following after";
	else {
		
		inS.push(stod(double_part));
		inQ.enqueue(stod(double_part));
		cout << "Successfully inserted the values into the stack and queue " << endl;
	}
}

//deletes the nodes from inQ and inS and stuffs them in their respective out structures
void check_deletion(Stack<double> &inS, Queue<double> &inQ, Stack<double> &outS, Queue<double> &outQ) {

	double stack_value = NULL;
	double queue_value = NULL;
	inS.pop(stack_value);
	inQ.dequeue(queue_value);
	if (stack_value) {
		outS.push(stack_value);
		cout << "Successfully popped inS and stored the value in outS" << endl;
	}
	else
		cout << "inS was empty" << endl;
	if (queue_value) {
		outQ.enqueue(queue_value);
		cout << "Successfully popped inQ and stored the value in outQ" << endl;
	}
	else
		cout << "inQ was empty" << endl;
}
//prints out the top of the stack for inS and outS
void check_stack_top(Stack<double> &inS, Stack<double> &outS) {
	double stack_value;
	double stack_value2;

	if (inS.getTop(stack_value))
		cout << "The front element of inS is: " << stack_value << endl;
	else
		cout << "There is no front element for inS" << endl;
	if (outS.getTop(stack_value2))
		cout << "The front element of outS is: " << stack_value2 << endl;
	else
		cout << "There is no front element for outS" << endl;
}
//prints out the rear for inQ and outQ
void check_queue_rear(Queue<double> &inQ, Queue<double> &outQ) {
	double queue_value = NULL;
	double queue_value2 = NULL;
	inQ.queueRear(queue_value);
	outQ.queueRear(queue_value2);
	if (queue_value)
		cout << "The rear element of inQ is: " << queue_value << endl;
	else
		cout << "There is no rear element for inQ" << endl;
	if (queue_value2)
		cout << "The rear element of outQ is: " << queue_value2 << endl;
	else
		cout << "There is no rear element for outQ" << endl;
}
int main()
{
	Stack<double> inS;
	Stack<double> outS;
	Queue<double> inQ;
	Queue<double> outQ;
	
	printWelcome();
	//prompt in the beginning
	const string PROMPT = "Start entering D, C, T, R or I followed by a Double. \nEnter Q to quit anytime";

	string function;
	cout << PROMPT << endl;
	while (1) {
		//keep going until you reach Q
		getline(cin, function);
		function[0] = toupper(function[0]);
		if (function == "Q") {
			return 0;
		}
		else if (function[0] == 'I' && function.length() >=3 && function[1] == ' ') 
		{
			//begin input validation for integer
			//function length has to be greater than 2 because we should have a space betwen
			//I and the double. With only 2 values it can only be I and some invalid value.
			//
			check_double(function, inS, inQ, outS, outQ);

		}
		//deletes teh elements from inS and inQ then inserts them into outS and outQ
		else if (function == "D") {
			check_deletion(inS, inQ, outS, outQ);


		}
		//print current number of elements in each daata structure
		else if (function == "C") {
			cout << "The number of elements in inS is: " << inS.getCount() << endl;
			cout << "The number of elements in inQ is: " << inQ.getCount() << endl;
			cout << "The number of elements in outS is: " << outS.getCount() << endl;
			cout << "The number of elements in outQ is: " << outQ.getCount() << endl;
		}
		//print out top of the stacks
		else if (function == "T") {
			check_stack_top(inS, outS);

			
		}
		//print out rear of the queues
		else if (function == "R") {
			check_queue_rear(inQ, outQ);

		}
		//if none of the input matches
		else {
			cout << "Wrong input " << endl;
		}
		cout << PROMPT << endl;
	}
	
	
}

/*


				 *~~*~~* WELCOME *~~*~~*

		To the Stack and Queue Driver Program!

				This program will:
				 - Read and validate input
				 - Test stack functions
				 - Test queue functions
				 - These are the following commands
						 - I stands for insert. Must be followed by a valid double
						 - D stands for delete
						 - C displays the number of elements in the two stacks and two queues
						 - T displays the top of the two stacks
						 - R to display elements at end of queues
						 - Q to quit the program
				 The ToyList is sorted in ascending order by ToyID

Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
Bleh
Wrong input
Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
I bleh
Please insert in the following format: I, space, then a double following afterStart entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
I
Wrong input
Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
I 38.Dog
Please insert in the following format: I, space, then a double following afterStart entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
I 40
Successfully inserted the values into the stack and queue
Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
C
The number of elements in inS is: 1
The number of elements in inQ is: 1
The number of elements in outS is: 0
The number of elements in outQ is: 0
Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
I 60.8021311
Successfully inserted the values into the stack and queue
Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
C
The number of elements in inS is: 2
The number of elements in inQ is: 2
The number of elements in outS is: 0
The number of elements in outQ is: 0
Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
D
Successfully popped inS and stored the value in outS
Successfully popped inQ and stored the value in outQ
Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
C
The number of elements in inS is: 1
The number of elements in inQ is: 1
The number of elements in outS is: 1
The number of elements in outQ is: 1
Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
T
The front element of inS is: 40
The front element of outS is: 60.8021
Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
R
The rear element of inQ is: 60.8021
The rear element of outQ is: 40
Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
D
Successfully popped inS and stored the value in outS
Successfully popped inQ and stored the value in outQ
Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
C
The number of elements in inS is: 0
The number of elements in inQ is: 0
The number of elements in outS is: 2
The number of elements in outQ is: 2
Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
T
There is no front element for inS
The front element of outS is: 40
Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
R
There is no rear element for inQ
The rear element of outQ is: 60.8021
Start entering D, C, T, R or I followed by a Double.
Enter Q to quit anytime
Q
Deleting Queue
You have successfully deleted queue node 40
You have successfully deleted queue node 60.8021
Deleting Queue
Deleting Stack
You have successfully deleted stack node 40
You have successfully deleted stack node 60.8021
Deleting Stack

C:\Users\etern\source\repos\Project3\Debug\Project3.exe (process 7224) exited with code 0.
Press any key to close this window . . .
*/