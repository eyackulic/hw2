//
// Created by Ethan Yackulic on 2/21/22.
//

#ifndef HW2_FASTAREADSET_LL_H
#define HW2_FASTAREADSET_LL_H
#include <iostream>
#include <fstream>

using namespace std;
struct Node{
   const char * sequence;
   Node * next = nullptr;
};


class FASTAreadset_LL {

private:

Node *first = nullptr;
Node *last = nullptr;

char *genome_array;
char **new_seq;

// CHASE // add destructors for ^^ arrays?


int genome_index;
int line;
int matches;

public:
//default constructor;
    FASTAreadset_LL();

// custom constructor;
   FASTAreadset_LL(const char *filename);

//destructor
   ~FASTAreadset_LL ();

  //class methods
    void addNode(const char *input_seq);
    bool isEqual(const char * seq1, const char * seq2);
    void singleArray(const char *filename); // build array
    void getSequences(); // grab all sequences

    //print function
    void printLL();
    void print_first();
    void print_last();
    void printArray();
    void printSequences();

    //searches
    void largeSearch();
    Node * searchNode(const char * input);
    void abridgedSearch(const char * input);

};


#endif //HW2_FASTAREADSET_LL_H
