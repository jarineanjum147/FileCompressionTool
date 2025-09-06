# FileCompressionTool

This is a C++ project for file compression and decompression using Huffman Coding.

## Features
- Compress files
- Decompress files
- User-friendly CLI

## How to Run
1. Compile the project:
   ```bash
   g++ src/main.cpp src/HuffmanCoding.cpp -I src -o FileCompressionTool
#run the executable file 
./FileCompressionTool

PS D:\FileCompressionTool> ./FileCompressionTool 
1. Compress
2. Decompress
Enter choice: 1
Enter input file: data/input.txt
Enter output file: data/output.bin
Compression complete. Output saved to data/output.bin

PS D:\FileCompressionTool> ./FileCompressionTool
1. Compress
2. Decompress
Enter choice: 2
Enter compressed file: data/output.bin
Enter output file: data/decompressed.txt
Decompression complete. Output saved to data/decompressed.txt
