#include <string>
#include "Queue.h"


using namespace std;


class Stack {
    private:
        // dummy variable used to initialize the stack
        Node *dummy = new Node(nullptr, "", 0);
        // size of the stack
        int size = 0;
    public:
        // method that will be used to push elements onto the stack
        void push(Node *);
        // method that will be used to pop elements off the stack
        Node *pop();
        // method that will be used to check if the stack is empty
        bool isEmpty();
};
