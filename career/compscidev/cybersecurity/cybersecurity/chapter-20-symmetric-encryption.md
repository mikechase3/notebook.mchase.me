# Chapter 20: Symmetric Encryption

## 20.3: AES Encryption Round

Know how this works - it'll be on the final!

![](<../../../../.gitbook/assets/CleanShot 2021-11-30 at 10.12.04@2x.jpg>)

![Don't worry about how mix columns work.](<../../../../.gitbook/assets/CleanShot 2021-11-30 at 10.11.45@2x.jpg>)

## 20.4: Steram Ciphers and RC4

## 20.5: Cipher Block Modes of Operation

## 20.6: Key Distribution

## Homework

1. No idea what he said about this.
2. Some bits get flipped. The C1 going into the decryption end is a corrupted version of C1 for whatever reason. This is going to corrupt whatever plaintext you get in P1 and P2, but will the error propagate to P3, P4, P5 to Pn? Does a propagation error in P1 disrupt the entire stream? That's really what this question was asking. The **2nd part** is asking how many errors does this cause in any cyphertext blocks that are produced on the encryption side and how does this manifest on the decryption side?
3. This is saying here's a mathematical description of what is going on. This is a functional description of the top two and that's what happens when you decrypt it. Fill it in a like-manner for CFB and CTR.
4. Discuss the security implications of a centralized key implication scheme. It's a short-answer.

## Works Cited

{% embed url="http://williamstallings.com/ComputerSecurity" %}
Computer security, principles and practice.
{% endembed %}
