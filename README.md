itch4csv
========

A parser for the NASDAQ ITCH4 Market Information

Usage: ./itch4parser [input NASDAQ file] [output CSV file]

Compile with: g++ -O3 -o [binary name] main.cpp

Makefile soon! 

Something to note
====
Your processor must be little-endian for this to work, because the numbers are read in byte-by-byte.  Endian independence is coming shortly.
