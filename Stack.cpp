// File Name: Stack.cpp
//
// Authors: Callum Longenecker, Anand Valavalkar, Neal Davar
// Date: 4/8/2022
// Assignment Number 3
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This cpp file is the program that models the Stack
// structure

#include <string>
#include "Stack.h"

using namespace std;

//***********************************************************
// push: pushes a new item onto the stack
//
// returns: nothing
//***********************************************************
void Stack::push(Node *toAdd)
{
    Node *temp = this->dummy->getNext();
    toAdd->setNext(temp);
    this->dummy->setNext(toAdd);
    
    this->size++;
}

//***********************************************************
// pop: pops the top element off the stack
//
// returns: a Node pointer to the popped element
//***********************************************************
Node *Stack::pop()
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
// isEmpty: checks if the stack is empty
//
// returns: a boolean value of whether the stack is empty
//***********************************************************
bool Stack::isEmpty() {
    return this->size==0;
}