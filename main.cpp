#include "encrypt.h"
using namespace std;
int main()
{
    Huffman h("large.txt");
    h.countFrequency();
    h.createHuffmanTree();
    h.printHuffTable();
    h.encrypt();
}