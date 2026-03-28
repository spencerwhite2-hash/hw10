#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Node
{
	string data; // the string data stored in the node
	Node* next; // pointer to the next node in the queue
};

class Queue // a queue implemented using a linked list
{
private:
	Node* front; // pointer to the front node of the queue
	Node* back; // pointer to the back node of the queue
	int count; // variable to keep track of the number of items in the queue

public:

    // constructor
	Queue() // initializes an empty queue

    {
		front = nullptr; // set front pointer to null
		back = nullptr; // set back pointer to null
		count = 0; // initialize count to 0
    }

    // destructor
	~Queue() // deallocates memory used by the queue
    {
		while (!isEmpty()) // while the queue is not empty
        {
			dequeue(); // remove the front node
        }
    }

	void enqueue(string data) // adds a new node with the given data to the back of the queue
    {
		Node* newNode = new Node; // create a new node
		newNode->data = data; // set the data of the new node
		newNode->next = nullptr; // set the next pointer of the new node to null

		if (isEmpty()) // if the queue is empty, set both front and back to the new node
        {
			front = newNode; // set front pointer to the new node
			back = newNode; // set back pointer to the new node
        }
        else 
        {
			back->next = newNode; // set the next pointer of the current back node to the new node
			back = newNode; // update the back pointer to the new node
        }

		count++; // increment the count of items in the queue
    }

	void dequeue() // removes the front node from the queue and deallocates its memory
    {
		if (!isEmpty()) // if the queue is not empty
        {
			Node* temp = front; // store the current front node in a temporary variable
			front = front->next; // update the front pointer to the next node in the queue
			delete temp; // deallocate memory of the old front nodeq
			count--; // decrement the count of items in the queue

			if (front == nullptr) // if the queue becomes empty after dequeuing, set back pointer to null
            {
				back = nullptr; // set back pointer to null
            }
        }
    }

	string peek() // returns the data of the front node without removing it from the queue
    {
		if (!isEmpty()) // if the queue is not empty
        {
			return front->data; // return the data of the front node
        }

		return ""; // return an empty string if the queue is empty
    }

	bool isEmpty() // returns true if the queue is empty, false otherwise
    { 
		if (front == nullptr) // if the front pointer is null, the queue is empty
        {
			return true; // return true if the queue is empty
        }

		return false; // return false if the queue is not empty
    }

	int size() // returns the number of items currently in the queue
    {
        return count;
    }

	void print() // prints the contents of the queue from front to back
    {
		if (isEmpty()) // if the queue is empty, print a message and return
        {
            cout << "Queue is empty" << endl; 
            return;
        }

		Node* temp = front; // start from the front node

		while (temp != nullptr) // traverse the queue until the end
        {
			cout << temp->data << " "; // print the data of the current node
			temp = temp->next; // move to the next node
        }

        cout << endl;
    }
};

#endif