#include "Queue.h"
#include <string>
using namespace std;

Node::Node(Node *nextNode, string stringData, int integerData)
{
    next = nextNode;
    strData = stringData;
    intData = integerData;
}

// get the next element in the queue
Node *Node::getNext() const
{
    return this->next;
}

// get the string component of the first element in the queue
string Node::getString() const
{
    return this->strData;
}

// get the int component of the first element in the queue
int Node::getInt() const
{
    return this->intData;
}

// set the next element in the queue
void Node::setNext(Node *newNext)
{
    this->next = newNext;
}

// set the string component of the next element in the queue
void Node::setString(string newString)
{
    this->strData = newString;
}

// set the int component of the next element in the queue
void Node::setInt(int newInt)
{
    this->intData = newInt;
}

// add a new node to the queue
void Queue::enqueue(Node *toAdd)
{
    this->last->setNext(toAdd);
    this->last = this->last->getNext();
    this->size++;
}

// remove the first node from the queue
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

int Queue::peekNextGroup()
{
    if (this->size == 0)
    {
        return 0;
    }
    return dummy->getNext()->getInt();
}

bool Queue::isEmpty() {
    return this->size==0;
}