#include <iostream>
#include <kDataFrame.hpp>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithms.hpp>

using namespace std;

int main(int argc, char **argv) {

    string index_prefix = "../idx_gencode.v33.pc_transcripts";
    string fasta_file = "../gencode.v33.pc_transcripts.fa";
    string names_file = fasta_file + ".names";
    int chunkSize = 1000;
    int kmerSize = 31;

    // Indexing

    kmerDecoder *KMERS = kProcessor::initialize_kmerDecoder(fasta_file, chunkSize, "kmers", {{"k_size", kmerSize}});
    kDataFrame *KF = new kDataFramePHMAP(kmerSize, 1);
    colored_kDataFrame* ckf= kProcessor::indexPriorityQueue(KMERS, names_file, KF);

    // Dumping
    // ckf->save("idx_phmap");

}