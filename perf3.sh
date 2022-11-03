#!/bin/sh
perf stat -e 'branch-instructions,branch-misses' release/bpred3