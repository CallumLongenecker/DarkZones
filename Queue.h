#include <string>

using namespace std;

class Node {
    private:
        // the next node element of this node
        Node *next;
        // the string data associated with the current node
        string strData;
        // the integer data associated with the current node
        int intData;
    public:
        // constructor
        Node(Node *nextNode, string stringData, int integerData);

        // getters
        // get the next element in the queue
        Node *getNext() const;
        // get the string component of the first element in the queue
        string getString() const;
        // get the int component of the first element in the queue
        int getInt() const;

        // setters
        // set the next element in the queue
        void setNext(Node *newNext);
        // set the string component of the next element in the queue
        void setString(string newString);
        // set the int component of the next element in the queue
        void setInt(int newInt);
};

class Queue {
    private:
        // refers to a dummy node in the queue
        Node *dummy = new Node(nullptr, "", 0);
        // points to the dummy node which will be the last node
        Node *last = dummy;
        // the size of the queue
        int size = 0;
    public:
        // add a new node to the queue
        void enqueue(Node *);
        // remove the first node from the queue
        Node *dequeue();
        // boolean that represents whether the queue is empty or not
        bool isEmpty();
}; 