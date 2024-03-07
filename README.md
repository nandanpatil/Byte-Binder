# # Byte-Binder
# Easy text file compressor
ByteBinder is a command-line tool designed for efficiently compressing .txt files using Huffman lossless compression.

- **Huffman Lossless Compression:** ByteBinder utilizes the Huffman coding algorithm to compress .txt files, ensuring no loss of data during compression.
- **Optimized Storage:** Generates compressed versions of text files with optimal storage utilization, reducing file sizes significantly.
- **Data Integrity:** Maintains data integrity throughout the compression process, preserving all original information.
- **User-Friendly Interface:** Offers a simple and intuitive command-line interface for seamless compression operations.
- **Targeted File Format:** Specifically tailored for compressing .txt files, making it suitable for various textual data compression needs.


## Usage

To compress a .txt file using ByteBinder, follow these simple steps:

1. Download ByteBinder zip on your system.
2. Open a terminal or command prompt.
3. Compile the main program using :
```sh
     g++ main.cpp -o bytebinder
```
**Compressing the file**
```sh
    ./bytebinder -c file_name.txt
```
**Decompressing the file**
```sh
     ./bytebinder -dc compressed.cmp
```

