---
description: Subsection of Ch5 in Klienberg Algorithm Design
---

# Data Compression

## Encoding/Decoding Characters

How do we encode text with the fewest bits?

* Make the most used characters consume the least bits.
* Use **Prefix Code** which mean design the set in such way that&#x20;

### Prefix Codes

One example of a prefix code in data compression is the Huffman code. A Huffman code is a variable-length code that assigns shorter codewords to more frequent symbols. This is done by constructing a **binary tree** where the leaves of the tree represent the symbols and the internal nodes of the tree represent codewords. The codeword for a symbol is the path from the root of the tree to the leaf representing the symbol.

For example, consider the following Huffman code for the symbols 'a', 'b', and 'c':

```
Symbol | Codeword
------- | --------
a       | 0
b       | 10
c       | 11
```

In this code, the symbol 'a' is the most frequent symbol, so it is assigned the shortest codeword (0). The symbol 'c' is the least frequent symbol, so it is assigned the longest codeword (11).

To compress data using a Huffman code, we first need to construct the Huffman tree for the data. Once we have constructed the Huffman tree, we can compress the data by replacing each symbol with its corresponding codeword.

For example, to compress the following string using the Huffman code above:

```
"abcabc"
```

We would replace each symbol with its corresponding codeword, resulting in the following compressed string:

```
"01011111"
```

To decompress the compressed string, we simply need to reverse the process. We start at the root of the Huffman tree and follow the path corresponding to the codeword. When we reach a leaf node, we output the symbol represented by that leaf node.

For example, to decompress the following compressed string:

```
"01011111"
```

We would start at the root of the Huffman tree and follow the path 0 -> 1 -> 0 -> 1 -> 1. This path leads to the leaf node representing the symbol 'a'. We would then output the symbol 'a'. We would then follow the path 0 -> 1 -> 0 -> 1 -> 1 again, which would lead to the leaf node representing the symbol 'b'. We would then output the symbol 'b'. We would continue this process until we have decompressed the entire string.

Huffman codes are a very efficient way to compress data. They are used in a wide variety of applications, including file compression, data transmission, and streaming media.

### Optimal Prefix Codes



$$
ABL(c) = \sum_{x \in S}^{} f_x \times c(x)
$$

* The average bits per letter of a prefix code `c` is the sum overall all symbols of its frequency times the number of bits of its encoding.
* We'd like to find a prefix code that has the lowest average bits per letter as defined.

