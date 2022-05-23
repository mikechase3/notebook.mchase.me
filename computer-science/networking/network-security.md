# Network Security

## 8.1 What is network Security?

## 8.2: Principles of Cryptography

### 8.2.1: Symmetric Key Cryptography

### 8.2.2: Public Key Encryption

## 8.3: Message Integrity and Digital Signatures

### 8.3.1: Cryptographic Hash Functions

### 8.3.2: Message Authentication Code

### 8.3.3: Digital Signatures

## 8.4: End-Point Authentication

## 8.5: Securing Email

### 8.5.1: Secure Email

#### Goal: Confidentiality

![](<../../.gitbook/assets/image (376).png>)

#### Message Integrity

![](<../../.gitbook/assets/image (377).png>)

* Alice digitally signs her message.
* Alice's digital signature is $$K_a^-(H(m))$$&#x20;
  * It's encrypted with Alice's private key, so you need her private key to receive it.
* Alice's message is sent with the hash code and the plain text.

_Bob's Decryption_

Bob will use the has algorithm using Alice's public key to decrypt the digital signature. Then he'll compare the two messages to make sure they're the same.

#### Secrecy, Sender Authentication, and Message Integrity

![](<../../.gitbook/assets/image (378).png>)

{% hint style="warning" %}
We cannot send 'm' in plaintext for Bob to decrypt.
{% endhint %}

1. Alice will encrypt the symmetric key using Bob's public key.
2. We will attach Alice's digital signature with the message before encrypting it to Bob.

How do you combine both?

1. Alice hashes the message, so _m_ becomes $$H(m)$$&#x20;
2. Alice will encrypt the message with her private key to create a digital signature. $$K_A^-(H(m))$$&#x20;
3. Alice will append the digital signature along with the email.
4. Encrypt the whole thing (both message and digital signature) with a symmetric key $$K_s(m_{key} | K_A^-(H(m)))$$
5. Encrypt this all with Bob's public key: $$K_B^+(K_s)$$&#x20;

$$
K_s(m | K_a^-(H(m))) | K_B^+(K_s)
$$

The final message Alice sends will **use 3 keys**: her private key, Bob's public key, and the newly created symmetric key $$K_s$$&#x20;

### 8.5.2: PGP (Pretty Good Privacy)

1. GnuPG (GNU Privacy Guard): Free software that implements PGP
2. Thunderbird Software: for reading & writing emails.

## 8.6: Securing TCP Connections using SSL

### 8.6.1: Big Picture

### 8.6.2: More Complete Picture

## Works Cited

| Resource                                  | Caption                      |
| ----------------------------------------- | ---------------------------- |
| Dr. Yao CPS 570 Lecture                   |                              |
| Computer Netyworking: A Top Down Approach | Powerpoint slides & visuals. |
