// File Name: Queue.cpp
//
// Authors: Callum Longenecker, Anand Valavalkar, Neal Davar
// Date: 4/8/2022
// Assignment Number 3
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This cpp file is the program that models the queue 
// structure

#include "Queue.h"
#include <string>
using namespace std;

// Constructor for a Node
Node::Node(Node *nextNode, string stringData, int integerData)
{
    next = nextNode;
    strData = stringData;
    intData = integerData;
}

//***********************************************************
// getNext: gets the next element in the queue
//
// returns: the Node that is next in the queue
//***********************************************************
Node *Node::getNext() const
{
    return this->next;
}

//***********************************************************
// getString: gets the string component of the first element in the queue
//
// returns: the string component of the first element in the queue
//***********************************************************
string Node::getString() const
{
    return this->strData;
}

//***********************************************************
// getInt: gets the integer component of the first element in the queue
//
// returns: gets the integer component of the first element in the queue
//***********************************************************
int Node::getInt() const
{
    return this->intData;
}

//***********************************************************
// setNext: sets the next element in the queue
//
// returns: nothing
//***********************************************************
void Node::setNext(Node *newNext)
{
    this->next = newNext;
}

//***********************************************************
// setString: sets the string component of the first element in the queue
//
// returns: nothing
//***********************************************************
void Node::setString(string newString)
{
    this->strData = newString;
}

//***********************************************************
// setInt: sets the integer component of the first element in the queue
//
// returns: nothing
//***********************************************************
void Node::setInt(int newInt)
{
    this->intData = newInt;
}

//***********************************************************
// enqueue: enqueues a new element to the queue
//
// returns: nothing
//***********************************************************
void Queue::enqueue(Node *toAdd)
{
    this->last->setNext(toAdd);
    this->last = this->last->getNext();
    this->size++;
}

//***********************************************************
// dequeue: dequeues the first element in the queue
//
// returns: the first element in the queue
//***********************************************************
Node *Queue::dequeue()
{
    if (this->size == 0)
    {
        return nullptr;
    }
    Node *temp = this->dummy->getNext();
    this->dummy->setNext(temp->getNext());
    this->size--;
    return temp;
}

//***********************************************************
// peekNextGroup: peeks at the number of people in the next group
//
// returns: the number of people in the next group
//***********************************************************
int Queue::peekNextGroup()
{
    if (this->size == 0)
    {
        return 0;
    }
    return dummy->getNext()->getInt();
}

//***********************************************************
// isEmpty: checks if the queue is empty
//
// returns: a boolean value of whether the queue is empty
//***********************************************************
bool Queue::isEmpty() {
    return this->size==0;
}