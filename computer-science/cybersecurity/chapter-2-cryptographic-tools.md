# Chapter 2: Cryptographic Tools

I'm going to write this informally instead of following the book because I'm feeling extra lazy today.



## DES & AES

* DES was the original standard, but became insecure as computers became more powerful.

{% embed url="https://csrc.nist.gov/csrc/media/publications/fips/46/3/archive/1999-10-25/documents/fips46-3.pdf" %}

* AES 128 and AES 256 bit cannot be brute forced today.

### AES: Advanced Encryption

### Public Key Encryption Structure

* Proposed by Diffie Helman in 1976.
* Based on mathematical functions.
* Asymmetric: uses 2 separate keys (that is, public and private).

## Summary

1. Confidentiality with symmetric encryption
2. Message authentication and hash functions
3. Random and pseudo-random numbers
4. Two others... see slides.

## Homework

For the first question, we're going to have a random string of bits. It's going to ask if there's a flaw in this algorithm. XOR this together manually and XOR it with the channel/key and see if you can detect a flaw.

Second

Third, we're going to hash a message into some `n` bit hash value. Said differently, it'll take a long number a
