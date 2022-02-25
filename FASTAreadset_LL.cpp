//
// Created by Ethan Yackulic on 2/21/22.
//

#include "FASTAreadset_LL.h"
#include <fstream>
#include <iostream>

using namespace std;
//constructor
FASTAreadset_LL::FASTAreadset_LL() {

}

//custom constructor
FASTAreadset_LL::FASTAreadset_LL(const char *filename) {
    cout << "The custom constructor ran \n";

    ifstream input;        //create filestream to read the file
    input.open(filename);        //initialize the filestream by pointing it to the right file
    char *temp_head;
    char *temp_read;
    genome_array = nullptr;
    new_seq = new char *[1000];
    while (input.good()) {
        temp_head = new char[51];
        temp_read = new char[51];
        input >> temp_head;    //read in the header line
        input >> temp_read;
        addNode(temp_read);
    }
}

//destructor
FASTAreadset_LL::~FASTAreadset_LL() {
cout << "in destructor" << endl;
    if (first == nullptr) {
        cout << "destructor: empty list" << endl;
    } else {
        Node *current_ptr = first;
        Node *next_ptr = first->next;

        while (next_ptr != last) {
            next_ptr = current_ptr->next;
            delete current_ptr;
            current_ptr = next_ptr;
        }
        delete last;
    }
    cout << "in destructor2" << endl;
    for(int i = 0; i < line; i++){
        delete[] new_seq[i];
    }


    cout << "in destructor3" << endl;
    delete[] genome_array;
    delete[] new_seq;
//    delete[] temp_head;
//    delete[] temp_read;
    cout << "in destructor4" << endl;
}

// functions
void FASTAreadset_LL::addNode(const char *input_seq) {

    Node *new_node = new Node;
    new_node->sequence = input_seq;


    if (first == nullptr) {
        first = new_node;
        last = new_node;
    } else {

        Node *current_ptr;
        current_ptr = last;

        current_ptr->next = new_node;
        last = new_node;
    }
}

bool FASTAreadset_LL::isEqual(const char * seq1, const char * seq2) {
    int i = 0;
    while (i < 50){
        if (seq1[i] == seq2[i]) {
            i++;
        } else {
            return false;
        }
    }
    return true;
}

void FASTAreadset_LL::singleArray(const char *filename) {
    ifstream input(filename);
    genome_array = new char[6000000]; // should be big enough to hold it
    char *temp_buffer = new char[100];
    char current_char;
   genome_index = 0;

//skip first line
    input >> temp_buffer;
    while (input.get(current_char)) {
        if (current_char == 'A' || current_char == 'G' || current_char == 'T' || current_char == 'C' ||
            current_char == 'N') {
            //fill array
            genome_array[genome_index] = current_char;
            //increment count
            genome_index++;
        }
    }
}

void FASTAreadset_LL::getSequences() {

    new_seq = new char *[genome_index];
    for (int z = 0; z < genome_index; z++) {
        new_seq[z] = new char[50];
    }
    int start = 0;
    int end = 50;
    line = 0;
    while(end <= genome_index){
        int i = 0;
        while (i < 50) {
            new_seq[line][i] = genome_array[start + i];
            i++;
        }
        line++;
        start += 1;
        end += 1;
    }
}

void FASTAreadset_LL::printLL() {

    if (first != nullptr) {
        Node *current_ptr;
        current_ptr = first;
        while (current_ptr != nullptr) {
            cout << current_ptr->sequence << endl;
            current_ptr = current_ptr->next;
        }
    } else {
        cout << "The list is empty" << endl;
    }
}

void FASTAreadset_LL::print_first() {
    if (first == nullptr) {
        cout << "list is empty" << endl;
    } else {
        cout << "printed first : " <<endl;
        cout << first->sequence << endl;
    }
}

void FASTAreadset_LL::print_last() {
    if (last == nullptr) {
        cout << "list is empty" << endl;
    } else {
        cout << "printed last : " <<endl;
        cout << last->sequence << endl;
    }
}

void FASTAreadset_LL::printArray() {
    cout << "array is: " << endl;
        cout << genome_array << endl;
}



void FASTAreadset_LL::printSequences() {
    int i = 0;
    while (i < line){
        cout << new_seq[i] << endl;
        i++;
    }
}




Node * FASTAreadset_LL::searchNode(const char *input) {
//takes a 51 character array input of A,C,T,G
//returns match where found in instance
    if (first == nullptr) {
        cout << "cannot search empty list" << endl;
        return nullptr;
    } else {
        Node *current_ptr = first;
        while (current_ptr->next != nullptr) {
            if (isEqual(current_ptr->sequence, input) == true) {
                cout << "match found! Node location is: " << &current_ptr->sequence << endl;
                return current_ptr;
            } else {
                current_ptr = current_ptr->next;
            }
        }
        cout << "No match found" << endl;
        return nullptr;
    }
}

void FASTAreadset_LL::abridgedSearch(const char * input){
    if (first == nullptr) {
        cout << "cannot search empty list" <<endl;
    } else{
        Node *current_ptr = first;
        while (current_ptr->next != nullptr) {
            if (isEqual(current_ptr->sequence, input)==true) { ;
                cout << "match found! Node location is: " << &current_ptr->sequence << endl;
                cout << "match sequence is: " << current_ptr->sequence <<endl;
                matches +=1;
                current_ptr = current_ptr->next;

            }else{
                current_ptr = current_ptr->next;
            }
        }
    }
}

void FASTAreadset_LL::largeSearch() {
   matches = 0;
    for(int q = 0; q < line; q++) {
        abridgedSearch(new_seq[q]);
    }
       if (matches == 0) {
           cout << "No matches found" << endl;
           // cout << nullptr << endl;
       }else if (matches == 1){
           cout << matches <<" match found" << endl;
       }else{
           cout << matches <<" total matches found" << endl;
       }

cout << "search complete" << endl;
}
//
