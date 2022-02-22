//
// Created by Ethan Yackulic on 2/21/22.
//

#include "FASTAreadset_LL.h"

using namespace std;

FASTAreadset_LL::FASTAreadset_LL() {

}


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
        cout << first->sequence << endl;
    }
}

void FASTAreadset_LL::print_last() {
    if (last == nullptr) {
        cout << "list is empty" << endl;
    } else {
        cout << last->sequence << endl;
    }
}


FASTAreadset_LL::~FASTAreadset_LL() {
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
