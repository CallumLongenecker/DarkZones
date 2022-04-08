#include <string>
// #include "Queue.h"
#include "Stack.h"

using namespace std;

void Stack::push(Node *toAdd)
{
    Node *temp = this->dummy->getNext();
    toAdd->setNext(temp);
    this->dummy->setNext(toAdd);
    
    this->size++;
}

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

bool Stack::isEmpty() {
    return this->size==0;
}