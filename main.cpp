#include <iostream>
#include "FASTAreadset_LL.h"
#include <cstring>
#include <fstream>

using namespace std;

int main(int argc, char ** argv){



    //Questions for Chase
 // how to format and run in monsoon?
 // do I need to add additional destructors for question B?

 if(strcmp(argv[1], "1a") == 0) {


     //Question A
//const char *argv;
//argv = "/Users/ethanyackulic/CLionProjects/INF504/hw2/sample_hw_dataset.fa";
FASTAreadset_LL linked_list(argv[2]);
     const char *seq1;
     const char *seq2;
     const char *seq3;
     const char *seq4;
     const char *seq5;
  //   const char *last1;
     //
     seq1 = "CTAGGTACATCCACACACAGCAGCGCATTATGTATTTATTGGATTTATTT";
     seq2 = "GCGCGATCAGCTTCGCGCGCACCGCGAGCGCCGATTGCACGAAATGGCGC";
     seq3 = "CGATGATCAGGGGCGTTGCGTAATAGAAACTGCGAAGCCGCTCTATCGCC";
     seq4 = "CGTTGGGAGTGCTTGGTTTAGCGCAAATGAGTTTTCGAGGCTATCAAAAA";
     seq5 = "ACTGTAGAAGAAAAAAGTGAGGCTGCTCTTTTACAAGAAAAAGTNNNNNN";
  //   last1 = "AGCAGTCCAAAGTGATACATCTTGTGAAATTTTGAAGTAAATGCCGACTC";

     Node * result_node;
     Node * result_node2;
     Node * result_node3;
     Node * result_node4;
     Node * result_node5;
  //   const char * result_last;

    result_node = linked_list.searchNode(seq1);
     if(result_node != nullptr) {
         cout << "Match found! Sequence: " << result_node->sequence << endl;
         cout << " Node location is: " << &result_node->sequence <<endl;
     }else{
         cout << "Not Match Found :(" << endl;
     }
     result_node2 = linked_list.searchNode(seq2);
     if(result_node2 != nullptr) {
         cout << "Match found! Sequence: " << result_node2->sequence << endl;
         cout << " Node location is: " << &result_node2->sequence <<endl;
     }else{
         cout << "Not Match Found :(" << endl;
     }
     result_node3 = linked_list.searchNode(seq3);
     if(result_node3 != nullptr) {
         cout << "Match found! Sequence: " << result_node3->sequence << endl;
         cout << " Node location is: " << &result_node3->sequence <<endl;
     }else{
         cout << "Not Match Found :(" << endl;
     }
     result_node4 = linked_list.searchNode(seq4);
     if(result_node4 != nullptr) {
         cout << "Match found! Sequence: " << result_node4->sequence << endl;
         cout << " Node location is: " << &result_node4->sequence <<endl;
     }else{
         cout << "Not Match Found :(" << endl;
     }
     result_node5 = linked_list.searchNode(seq5);
     if(result_node5 != nullptr) {
         cout << "Match found! Sequence: " << result_node5->sequence << endl;
         cout << " Node location is: " << &result_node5->sequence <<endl;
     }else{
         cout << "Not Match Found :(" << endl;
     }
//     linked_list.printSequences();
//     linked_list.searchNode(seq1);
//     linked_list.searchNode(seq2);
//     linked_list.searchNode(seq3);
//     linked_list.searchNode(seq4);
//     linked_list.searchNode(seq5);
//     linked_list.singleArray(argv[3]);
//     linked_list.getSequences();
//     linked_list.searchNode2(last1);
//     linked_list.largeSearch(100);
//     linked_list.largeSearch(1000);
//     linked_list.largeSearch(10000);
//     linked_list.largeSearch(100000);
//     linked_list.largeSearch(NULL);


     //*known example*
//     cout << "known example" << endl;
//     const char *seq;
//     seq = "ATATTCATTTTGAACCTATTCACATACTTTTTCACAAATCCTATATTTCC";
//     linked_list.searchNode(seq);
 }
    if(strcmp(argv[1], "1b") == 0) {
        FASTAreadset_LL linked_list(argv[2]);
// Question B

        linked_list.singleArray(argv[3]);
        linked_list.getSequences();
//        linked_list.printSequences();
      // part 1
        linked_list.printLineCount();
// OPTIONAL: view single area
//   linked_list.printSingleArray();

// OPTIONAL: view sequences
// linked_list.printSequences();
        cout << "large results: " << endl;
        linked_list.largeSearch(10000);
    }
    return 0;
}
