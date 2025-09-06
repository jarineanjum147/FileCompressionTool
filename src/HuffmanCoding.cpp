#include "HuffmanCoding.h"
#include <fstream>
#include <iostream>

void HuffmanCoding::encode(Node* root, const std::string& str) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
        reverseCode[str] = root->ch;
    }
    encode(root->left, str + "0");
    encode(root->right, str + "1");
}

void HuffmanCoding::buildHuffmanTree(const std::string& text) {
    std::unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;

    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;
        pq.push(sum);
    }

    encode(pq.top(), "");
    freeTree(pq.top());
}

void HuffmanCoding::freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void HuffmanCoding::compress(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream in(inputFile, std::ios::binary);
    if (!in) { std::cerr << "Cannot open input file!\n"; return; }
    std::string text((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    buildHuffmanTree(text);

    std::string encoded = "";
    for (char ch : text) encoded += huffmanCode[ch];

    std::ofstream out(outputFile, std::ios::binary);
    out << encoded;
    out.close();

    std::cout << "Compression complete. Output saved to " << outputFile << "\n";
}

void HuffmanCoding::decompress(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream in(inputFile, std::ios::binary);
    if (!in) { std::cerr << "Cannot open compressed file!\n"; return; }
    std::string encoded((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    std::string decoded = "";
    std::string current = "";
    for (char bit : encoded) {
        current += bit;
        if (reverseCode.find(current) != reverseCode.end()) {
            decoded += reverseCode[current];
            current = "";
        }
    }

    std::ofstream out(outputFile, std::ios::binary);
    out << decoded;
    out.close();

    std::cout << "Decompression complete. Output saved to " << outputFile << "\n";
}
