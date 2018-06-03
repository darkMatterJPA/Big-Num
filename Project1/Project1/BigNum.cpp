#include "stdafx.h"
#pragma once
#include <iostream>
using namespace std;

//Node class
class node
{
	//Private function and Member variables for node class 
private:
	int data;
	node* next;
	friend class BigNum;  //Friend to the BigNum class

						  //constructor for node
	node(int value, node* nxt = nullptr)
	{
		data = value;
		next = nxt;
	}


};


class BigNum {

private:
	node * head;
	node* tail;
	int size;

	void destroy()
	{
		while (head != nullptr)
		{
			node* doomed = head;
			head = head->next;
			delete doomed;
		}
		head = tail = nullptr;
		size = 0;
	}

	//Reverse Coppy meathod to coppy a BigNum in reverse order 
	void rCopy(const BigNum& rhs)
	{
		head = tail = nullptr;
		size = 0;
		node* lead = rhs.head;
		while (lead != nullptr)
		{
			addFirst(lead->data);
			lead = lead->next;
		}
	}



public:
	//constructor for BigNum with out value
	BigNum()
	{
		head = tail = nullptr;
		size = 0;
	}

	//constructor for BigNum with value
	BigNum(string sNum)
	{
		//access each character and convert to integer value
		for (int i = 0; i <= sNum.size() - 1; i++)
		{
			addFirst((sNum[i] - '0'));
		}
	}

	//ADD
	BigNum operator+(const BigNum& opd2) const
	{
		BigNum result;
		int carry = 0;
		node* temp1;
		node* temp2;
		temp1 = head;
		temp2 = opd2.head;
		int tempResult;

		//adds opd1 and opd2 
		while ((temp1 != nullptr) && (temp2 != nullptr))
		{
			tempResult = ((temp1->data + temp2->data) + carry);
			carry = (tempResult / 10);
			tempResult = (tempResult % 10);
			result.addLast(tempResult);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}

		//appends the rest of opd1 to the end of the result
		while (temp1 != nullptr)
		{
			tempResult = temp1->data + carry;
			carry = (tempResult / 10);
			tempResult = (tempResult % 10);
			result.addLast(tempResult);
			temp1 = temp1->next;

		}

		//appends the rest of opd2 to the end of the result
		while (temp2 != nullptr)
		{
			tempResult = temp2->data + carry;
			carry = (tempResult / 10);
			tempResult = (tempResult % 10);
			result.addLast(tempResult);
			temp2 = temp2->next;
		}

		//appends the carry to the end
		if (carry > 0)
		{
			result.addLast(carry);
		}
		return result;
	}

	BigNum operator-(const BigNum& opd2) const
	{
		BigNum result;
		int carry = 0;
		node* temp1;
		node* temp2;
		temp1 = head;
		temp2 = opd2.head;
		int tempResult;


		//adds opd1 and opd2 
		while ((temp1 != nullptr) && (temp2 != nullptr))
		{
			//tempResult = ((temp1->data - temp2->data) + carry);
			carry = (tempResult / 10);
			tempResult = (tempResult % 10);
			result.addLast(tempResult);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}

		//appends the rest of opd1 to the end of the result
		while (temp1 != nullptr)
		{
			tempResult = temp1->data + carry;
			carry = (tempResult / 10);
			tempResult = (tempResult % 10);
			result.addLast(tempResult);
			temp1 = temp1->next;

		}

		//appends the rest of opd2 to the end of the result
		while (temp2 != nullptr)
		{
			tempResult = temp2->data + carry;
			carry = (tempResult / 10);
			tempResult = (tempResult % 10);
			result.addLast(tempResult);
			temp2 = temp2->next;
		}

		//appends the carry to the end
		if (carry > 0)
		{
			result.addLast(carry);
		}
		return result;
	}


	// MULTIPLY
	BigNum operator*(const BigNum& opd2) const
	{
		BigNum result;

		int carry = 0;
		node* temp1;
		node* temp2;
		temp2 = opd2.head;
		int tempResult;
		int count = 0;
		result.addFirst(0);


		while ((temp2 != nullptr))
		{
			// create temporary big number 
			BigNum tempBN;

			// add zeros to the temporary based on the position in operand2
			for (int i = 0; i < count; i++)
			{
				tempBN.addLast(0);
			}
			count++;

			temp1 = head;
			// process each digit in operand1 * current digit in operand2
			while (temp1 != nullptr)
			{
				tempResult = (temp2->data * temp1->data) + carry;
				carry = (tempResult / 10);
				tempResult = (tempResult % 10);
				

				tempBN.addLast(tempResult);

				temp1 = temp1->next;
			}
			// if carry > 0 must add another digit
			if (carry > 0)
			{
				tempBN.addLast(carry);
				carry = 0;
			}

		
			//adds product together 
			result = result + tempBN;			
			temp2 = temp2->next;
			
			
		}

		return result;
	}

	//POWER
	BigNum operator^(const BigNum& opd2) const
	{
		BigNum result("1");
		node* temp2;
		temp2 = opd2.head;
		int p10 = 1;
		int count = 0;
		
		

		//makes an int from the opd2 BigNum
		while ((temp2 != nullptr))
		{
			count = count + temp2->data * p10;
			p10 *= 10;

			temp2 = temp2->next;
		}

		//checks if count is more than 0 then calls the * operation "count" amount of times 
		if (count != 0)
		{
			for (int i = 0; i < count; i++)
			{
				result = result * (*this);
			}
		}
		


		return result;
	}

	//copy constructor for BigNum 
	BigNum(const BigNum& rhs)
	{
		head = tail = nullptr;
		size = 0;

		node* lead = rhs.head;

		while (lead != nullptr)
		{
			
			addLast(lead->data);
			lead = lead->next;
		}
	}

	~BigNum()
	{
		destroy();
	}

	BigNum& operator=(const BigNum& rhs)
	{
		if (this != &rhs)
		{
			destroy(); 
						
			head = tail = nullptr;
			size = 0;

			node* lead = rhs.head;

			while (lead != nullptr)
			{
				
				addLast(lead->data);
				lead = lead->next;
			}

		}
		return *this;
	}

	//appends a value to the start of BigNum
	void addFirst(int value)
	{
		if (empty())
		{
			head = tail = new node(value);
		}
		else
		{
			head = new node(value, head);
		}
		size++;
	}

	//appends a value tothe end of BigNum
	void addLast(int value)
	{

		if (empty())
		{
			addFirst(value);
		}
		else
		{
			tail = tail->next = new node(value);
		}
		size++;
	}

	//checks if BigNum is empty
	bool empty() const
	{
		return size == 0;
	}

	//prints BigNum
	void print() const
	{
		node* lead = head;
		
		while (lead != nullptr)
		{
			cout << lead->data;
			lead = lead->next;
		}
		cout << endl;
	}

	//reverse print it calls the reverse copy then the print function 
	void rPrint() const
	{
		BigNum temp;
		temp.rCopy(*this);
		temp.print();

	}

	//end of BigNum
};