#include "HuffmanCoding.h"
#include <iostream>

int main() {
    HuffmanCoding huffman;
    int choice;
    std::string inFile, outFile;

    std::cout << "1. Compress\n2. Decompress\nEnter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter input file: ";
        std::cin >> inFile;
        std::cout << "Enter output file: ";
        std::cin >> outFile;
        huffman.compress(inFile, outFile);
    } else if (choice == 2) {
        std::cout << "Enter compressed file: ";
        std::cin >> inFile;
        std::cout << "Enter output file: ";
        std::cin >> outFile;
        huffman.decompress(inFile, outFile);
    } else {
        std::cout << "Invalid choice!\n";
    }
    return 0;
}
