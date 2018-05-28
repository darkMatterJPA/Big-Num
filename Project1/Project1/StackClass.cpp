 #include "stdafx.h"
#include <iostream>
#include "BigNum.cpp"

using namespace std;

class MyStack {
private:
	
	int capacity = 100; 
	BigNum* arr; ;




public:

	int top = -1;

	MyStack()
	{
		top = -1;
		arr = new BigNum[capacity];
	}

	const MyStack(MyStack& rhs)
	{
		capacity = rhs.capacity;
		arr = new BigNum[capacity];
		top = rhs.top;

		for (int i = 0; i < rhs.top; i++)
		{
			arr[i] = rhs.arr[i];
		}
	}

	~MyStack()
	{
		delete arr;
	}

	void Push(BigNum item)
	{
		if (top == capacity - 1)
		{
			
			capacity += 50;
			BigNum* temp = new BigNum[capacity];
			for (int i = 0; i < (capacity-50); i++)
			{
				temp[i] = arr[i];
			}

			delete arr;

			arr = new BigNum[capacity];

			arr = temp;

			delete temp;

		}

		top++;

		arr[top] = item;
	}

	BigNum Pop()
	{
		if (!isStackEmpty())
		{
			BigNum data = arr[top];
			top--;

			return data;
			
		}
		else
		{
			cout << endl << "Stack is empty";
		}
		
		
		
	}

	bool isStackEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}




	//end of myStack
};
