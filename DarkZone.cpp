// File Name: DarkZone.cpp
//
// Authors: Callum Longenecker, Anand Valavalkar, Neal Davar
// Date: 4/8/2022
// Assignment Number 3
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This cpp file is the program that drives the
// DarkZone project program.

#include <iostream>
#include <string>
#include "Stack.h"
// #include "Queue.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>


using namespace std;


//***********************************************************
// getPercentUtil: method that returns the percent utilization
// via a float
//
// overallGuests:    overall number of guests
// numCapsules:      overall number of capsules present
// capacity:         total capsule capacity
// returns:          float number of percentage utilization
//***********************************************************
float getPercentUtil(int overallGuests, int numCapsules, int capacity){
    float result = 1.0 * (overallGuests) / (numCapsules *  capacity);
    return result;
}


//***********************************************************
// printResults: method to print the contents of the stack 
// in order by popping off each one individually
//
// stack:         resulting stack to print results from
// numCapsule:    current capsule number
// returns:       int number of total guests
//***********************************************************
int printResults(Stack *stack, int numCapsule){
    cout << "Capsule #" << numCapsule << endl;
   int totalGuests = 0;

   // pop off each node from the stack, printing information about
   // each party
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

//***********************************************************
// printSummary: method to print the summary of the results
//
// overallGuests:    overall number of guests
// numCapsules:      overall number of capsules present
// capacity:         total capsule capacity
// returns:          float number of percentage utilization
//***********************************************************
void printSummary(int overallGuests, int numCapsules, int capacity){
    cout << "Overall number of guests: " << overallGuests << endl;
    cout << "Overall number of capsules: " << numCapsules << endl;
    cout << "Capsule capacity: " << capacity << endl;
    float percentUtil = getPercentUtil(overallGuests, numCapsules, capacity);
    cout << "Percentage utilization: " << overallGuests << " / (" << numCapsules << " * " << capacity << ") = " << setprecision(3) << 100.0 * percentUtil << "%" << endl;
}



//***********************************************************
// main: runs the program to run the DarkZone simulation
// to fit people into space capsules
//
// returns: zero
//***********************************************************
int main(){
    
    int numCapsules;  
    Queue queue {};
    Stack stack {};
    int overallGuests = 0;

    // infile to read in the data from the file
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

        // iterated through the entire queue and adds contents to stack
        while (!queue.isEmpty() 
            && totalGuestsOnCapsule + queue.peekNextGroup() <= capsuleSize) 
        {
            totalGuestsOnCapsule += queue.peekNextGroup();
            stack.push(queue.dequeue());
        }
        cout << "Capsule #" << numCapsules << endl;

        // iterates through contents of stack and prints results and info
        while (!stack.isEmpty()) {
            Node *popResult = stack.pop();
            cout << popResult->getString() << " " 
                << popResult->getInt() << endl;
        }
        cout << "Total guests: " << totalGuestsOnCapsule << endl;
        cout << "Remaining capacity: " 
            << capsuleSize - totalGuestsOnCapsule << endl << endl;
    }
    printSummary(overallGuests, numCapsules, capsuleSize);
    return 0;
}

