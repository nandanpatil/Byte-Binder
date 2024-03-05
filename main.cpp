#include "decrypt.h"
#include "encrypt.h"
using namespace std;
int main()
{
    Huffman en("large.txt");
    en.countFrequency();
    en.createHuffmanTree();
    en.encrypt();
    cout<<"Compressed";
    HuffmanDecrypt dc("output.cmp");
    dc.deserializeTree();
    dc.decrypt();
    cout<<"Decompressed";

}