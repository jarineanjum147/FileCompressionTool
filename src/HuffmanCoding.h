#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

// Node structure for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

class HuffmanCoding {
public:
    void compress(const std::string& inputFile, const std::string& outputFile);
    void decompress(const std::string& inputFile, const std::string& outputFile);

private:
    void buildHuffmanTree(const std::string& text);
    void encode(Node* root, const std::string& str);
    void freeTree(Node* root);

    std::unordered_map<char, std::string> huffmanCode;
    std::unordered_map<std::string, char> reverseCode;
};

#endif
