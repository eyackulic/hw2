#include <iostream>
#include "FASTAreadset_LL.h"

using namespace std;

int main() {

    FASTAreadset_LL linked_list;

    linked_list.addNode("ATC");
    linked_list.addNode("GCA");
    linked_list.addNode("TGG");

    linked_list.printLL();
    linked_list.print_first();
    linked_list.print_last();

//    cout << seq1.sequence << endl;
//    cout << seq2.sequence <<endl;
//    cout << seq1.next->sequence << endl;
//    cout << (*seq1.next).sequence << endl;

    return 0;
}
