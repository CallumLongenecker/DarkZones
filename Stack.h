#include <string>
#include "Queue.h"


using namespace std;


class Stack {
    private:
        Node *dummy = new Node(nullptr, "", 0);
        int size = 0;
    public:
        void push(Node *);
        Node *pop();
        bool isEmpty();
};
