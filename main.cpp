#include <iostream>
#include "FASTAreadset_LL.h"

using namespace std;

int main(){



    //Questions for Chase
 // how to format and run in monsoon?
 // how to return null pointer (Question A)
 // am I returning correct pointer for hits?
 // do I need to add additional destructors for question B?

 //Question A
const char *argv;
argv = "/Users/ethanyackulic/CLionProjects/INF504/hw2/sample_hw_dataset.fa";
FASTAreadset_LL linked_list(argv);
const char * seq1; const char * seq2; const char * seq3; const char * seq4; const char * seq5;

    seq1 = "CTAGGTACATCCACACACAGCAGCGCATTATGTATTTATTGGATTTATTT";
    seq2 = "GCGCGATCAGCTTCGCGCGCACCGCGAGCGCCGATTGCACGAAATGGCGC";
    seq3 = "CGATGATCAGGGGCGTTGCGTAATAGAAACTGCGAAGCCGCTCTATCGCC";
    seq4 = "CGTTGGGAGTGCTTGGTTTAGCGCAAATGAGTTTTCGAGGCTATCAAAAA";
    seq5 = "ACTGTAGAAGAAAAAAGTGAGGCTGCTCTTTTACAAGAAAAAGTNNNNNN";

    linked_list.searchNode(seq1);
    linked_list.searchNode(seq2);
    linked_list.searchNode(seq3);
    linked_list.searchNode(seq4);
    linked_list.searchNode(seq5);

    //*known example*
    const char * seq;
    seq = "ATATTTTTTCTTGTTTTTTATATCCACAAACTCTTTTCGTACTTTTACACAGTATATCGTGTTGTGGACA";
   linked_list.searchNode(seq);

// Question B
   const char *test;
   test = "/Users/ethanyackulic/CLionProjects/INF504/hw2/test_genome.fasta";
   linked_list.singleArray(test);
   linked_list.getSequences();

// OPTIONAL: view single area
//   linked_list.printSingleArray();

// OPTIONAL: view sequences
// linked_list.printSequences();

 linked_list.largeSearch();

    return 0;
}
