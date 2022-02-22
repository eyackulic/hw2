//
// Created by Ethan Yackulic on 2/21/22.
//

#ifndef HW2_FASTAREADSET_LL_H
#define HW2_FASTAREADSET_LL_H

#include <iostream>

using namespace std;
struct Node{
   const char * sequence;
   Node * next;
};


class FASTAreadset_LL {

private:

Node *first = nullptr;
Node *last = nullptr;


public:
//default constructor;
    FASTAreadset_LL();

// custom constructor;

//destructor
   ~FASTAreadset_LL ();

//print function

    void addNode(const char *);
    void printLL();
    void print_first();
    void print_last();

};


#endif //HW2_FASTAREADSET_LL_H
