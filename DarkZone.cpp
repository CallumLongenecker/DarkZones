#include <iostream>
#include <string>
#include "Stack.h"
// #include "Queue.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>


using namespace std;

float getPercentUtil(int overallGuests, int numCapsules, int capacity){
    float result = 1.0 * (overallGuests) / (numCapsules *  capacity);
    return result;
}

//method to print the contents of the stack in order by popping off each one individually
int printResults(Stack *stack, int numCapsule){
    cout << "Capsule #" << numCapsule << endl;
   //pop off each node from the stack 
   int totalGuests = 0;
    while(!stack->isEmpty()){
        Node *party = stack->pop();
        string name = party->getString();
        int numPeople = party->getInt();
        totalGuests += numPeople; 
        cout << name << " " << numPeople << endl;
        cout << "Total Guests: " << totalGuests << endl;
    }
    return totalGuests;
}

void printSummary(int overallGuests, int numCapsules, int capacity){
    cout << "Overall number of guests: " << overallGuests << endl;
    cout << "Overall number of capsules: " << numCapsules << endl;
    cout << "Capsule capacity: " << capacity << endl;
    float percentUtil = getPercentUtil(overallGuests, numCapsules, capacity);
    cout << "Percentage utilization: " << overallGuests << " / (" << numCapsules << " * " << capacity << ") = " << 100.0 * percentUtil << "%" << endl;
}




int main(){
    
    int numCapsules;  
    Queue queue {};
    Stack stack {};
    int overallGuests = 0;

    ifstream infile;

    infile.open("darkZone.txt");
    int capsuleSize;

    if (infile)
    {
        // gets the capacity of capsule
        string capsuleSizeString;
        getline(infile, capsuleSizeString);
        // convers the string capacity to an integer
        capsuleSize = stoi(capsuleSizeString);
    }

    string inputString;
    int numGroups = 0;

    while (getline(infile, inputString))
    {
        numGroups++;
      // tokenize inputString into name and a number
        string name = inputString.substr(0, inputString.find(" "));
        string guestAmt = inputString.substr(inputString.find(" ") + 1);
        overallGuests += stoi(guestAmt);
        Node *toAdd = new Node(nullptr, name, stoi(guestAmt));
        queue.enqueue(toAdd);
    }




    numCapsules = 0;
    while (!queue.isEmpty()) {
        numCapsules++;
        // schedule new capsule
        int totalGuestsOnCapsule = 0;
        while (!queue.isEmpty() 
            && totalGuestsOnCapsule + queue.peekNextGroup() <= capsuleSize) 
        {
            totalGuestsOnCapsule += queue.peekNextGroup();
            stack.push(queue.dequeue());
        }
        cout << "Capsule #" << numCapsules << endl;
        while (!stack.isEmpty()) {
            Node *popResult = stack.pop();
            cout << popResult->getString() << " " 
                << popResult->getInt() << endl;
        }
        cout << "Total guests: " << totalGuestsOnCapsule << endl;
        cout << "Remaining capacity: " 
            << capsuleSize - totalGuestsOnCapsule << endl << endl;
    }



    // for(int i = 1; i <= numCapsules; i++){
    //     int totalGuests = printResults(&stack, i);
    //     int remainingCapacity = capacity - totalGuests; 
    //     overallGuests += totalGuests;
    //     cout << "Remaining Capacity: " << remainingCapacity << endl;
    //     cout << endl;
    // }

    printSummary(overallGuests, numCapsules, capsuleSize);
    return 0;
}

