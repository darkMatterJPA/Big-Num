// Project1.cpp : Defines the entry point for the console application.
//Project 1 for CS 3100 – Data Structures and Algorithms 
//

/*
	Name: Alton J Panton
	Date Due: 02/12/18
	
*/

#include "stdafx.h"
#include <iostream>
#include "StackCLass.cpp"
#include <string>

using namespace std;

//Main Program
int main()
{
	MyStack stack;
	string str;
	BigNum value;
	

	try
	{
		while (true)
		{
			bool print(true);

			cout << "Enter a BigNum Value in reverse polish notation."<< endl 
				<< "Enter Q to end the line and QQ to end the program" << endl;

			cin >> str;
			while (str != "Q")
			{

				//Remove leading 0's from input if any.
				try
				{
					if (str.length() != 1)
					{
						int i = 0;
						while (str[i])
						{
							if (str[0] == '0')
								str.erase(str.begin());
							else
								break;


							i++;
						}
					}
				}
				catch (exception e)
				{

				}




				if (str == "+")
				{
					
					try
					{
						//checks if there atleast 2 operands to do task
						if ((stack.top - 2) >= -1)
						{
							stack.Push((stack.Pop() + stack.Pop()));
						}
						else
						{
							print = false; //set print to false because no task could be completed 
							throw exception("Not Enough operands to complete task");

						}
					}
					catch (exception e)
					{
						cout << e.what() << endl;
					}
				}
				else if (str == "*")
				{
					
					try
					{
						//checks if there atleast 2 operands to do task
						if ((stack.top - 2) >= -1)
						{
							stack.Push((stack.Pop() * stack.Pop()));
						}
						else
						{
							print = false; //set print to false because no task could be completed
							throw exception ("Not Enough operands to complete task");

						}
					}
					catch (exception e)
					{
						cout << e.what() << endl;
					}
				}
				else if (str == "^")
				{
					try
					{
						//checks if there atleast 2 operands to do task
						if ((stack.top - 2) >= -1)
						{
							stack.Push((stack.Pop() ^ stack.Pop()));
						}
						else
						{
							print = false; //set print to false because no task could be completed
							throw exception("Not Enough operands to complete task");
							
						}
					}
					catch (exception e)
					{
						cout << e.what() << endl;
					}
				}
				else if (str == "QQ")
				{
					return 0;
				}
				else
				{
					try
					{
						if (str[0] != 'Q')
						{
							//checks if str is a number before pushing on to the stack
							int i = 0;
							while (str[i])
							{
								if ((str[i]-'0' < 0 || str[i]-'0' > 9))
								{
									print = false; //set print to false because no task could be completed
									throw exception("You entered something that's not a number.");
								}
							
								i++;
							}

						
							BigNum value2 = BigNum(str);
							stack.Push(value2);
						}

					}
					catch (exception e)
					{
						cout << e.what() << endl; 
					}


				}

				cin >> str;
			}

			try
			{
				if (stack.top == 0)
				{
					//checks if the print bool is true
					if (print)
					{
						value = stack.Pop();
						value.rPrint();
						cout << endl;
					}
					else
					{
						stack.Pop();
					}

				}
				else
				{
					throw exception("Irrgular number of operands.");
				}
			}
			catch (exception e)
			{
				cout << e.what() << endl;
			}


		}
	}
	catch (exception e)
	{

	}
	

    return 0;
}



