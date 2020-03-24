# kProcessor_tests

This repo should contains the usecases and reproducible benchmarking stuff with proper documentation to keep tracking the performance ups and downs.

## 1. [Experiment 1](./exp1)

Data: protein coding human transcripts.
KF : PHMAP
kSize : 31
batch size : 1000

Benchmarking index functions:
    - kProcessor::index()
    - kProcessor::indexPriorityQueue()
    - kProcessor::indexPriorityQueue2()

