# Experiment 1

## kProcessor cloning

- Branch: **PriorityQueueIndexing**

> You may need to build this twice cause the ntcard can't be imported in the CMake add_subdirectory().

```bash
git clone git@github.com:dib-lab/kProcessor.git
cd kProcessor
git checkout PriorityQueueIndexing
git submodule update --init --recursive -j 4

# mkdir build && cd build && cmake .. && make
```

## Data Preparation

### 1. Human Protein Coding Transcripts

```bash
echo "Downloading ..."

wget -c ftp://ftp.ebi.ac.uk/pub/databases/gencode/Gencode_human/release_33/gencode.v33.pc_transcripts.fa.gz

echo "Extracting"

gunzip gencode.v33.pc_transcripts.fa.gz

echo "Generating names file"

cat gencode.v33.pc_transcripts.fa | grep ">" | awk -F\, '{print (substr($0,2))"\t"substr($0,2)}' > gencode.v33.pc_transcripts.fa.names


<<STATS
file                           format  type  num_seqs      sum_len  min_len  avg_len  max_len
gencode.v33.pc_transcripts.fa  FASTA   DNA    100,551  220,258,851        8  2,190.5  109,224

Number of unique canoncial kmer (Jellyfish): 82,285,599

STATS

```

### 2. Unitigs

```bash

wget -c https://sra-download.ncbi.nlm.nih.gov/traces/sra51/SRR/010757/SRR11015356 -O SRR11015356.sra
fastq-dump --fasta 0 --split-files SRR11015356.sra

ls -1 *fasta > list_reads
bcalm -kmer-size 75 -max-memory 12000 -out SRR11015356_k75 -in list_reads

# Generating Names File
grep ">" SRR11015356_k75.unitigs.fa | cut -c2- |  awk -F' ' '{print $0"\t"$1}' > SRR11015356_k75.unitigs.fa.names


<<STATS
file                        format  type    num_seqs        sum_len  min_len  avg_len  max_len
SRR11015356_k75.unitigs.fa  FASTA   DNA   11,824,622  1,133,741,131       75     95.9    1,683

STATS

```

## Building binaries

```bash
mkdir build && cd build
cmake ..
make
```

## Running Executables

```bash
cd build
/usr/bin/time -v ./phmap_index &> phmap_index.log
/usr/bin/time -v ./phmap_indexPriorityQueue &> phmap_indexPriorityQueue.log
/usr/bin/time -v ./phmap_indexPriorityQueue2 &> phmap_indexPriorityQueue.log
```

---

## **Results**

### 1. kProcessor::index()

- Data: gencode_protein_coding
- System time (seconds): 1.70
- Elapsed (wall clock) time (h:mm:ss or m:ss): 2:27.30
- Maximum resident set size (kbytes): 3942932

### 2. kProcessor::indexPriorityQueue() *Failed ..*

#### **I've killed the job due to its huge memory consumption, to be runned again on HPC**

- Data: gencode_protein_coding
- System time (seconds): 21.32 +
- Elapsed (wall clock) time (h:mm:ss or m:ss): 6:32.84 +
- Maximum resident set size (kbytes): 17+ GB


### 3. kProcessor::indexPriorityQueue2() *Failed ..*

#### **I've killed the job due to its huge memory consumption, to be runned again on HPC**

- Data: gencode_protein_coding
- System time (seconds): 18.55 +
- Elapsed (wall clock) time (h:mm:ss or m:ss): 6:04.02 +
- Maximum resident set size (kbytes): 17+ GB
