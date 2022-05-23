# Chapter 03: User Authentication

## 3.1: NIST Authentication Model

* Any authentication function is going to have these sub-routines in some manner or fashion.
* There are 3 on the registration side, and 3 on the authentication side.

![](<../../../.gitbook/assets/image (637).png>)

### Means of Authentication

1. Something the individual **owns**: pins/passwords
2. Something the individual **possesses**
   1. Smartcards/Keycards/Physical Key
3. Something the individual **is**: fingerprint/retina/face
4. Something the individual **does**: voice pattern, handwriting, typing rhythm.

### Risk Assessment

#### Assurance Level

This describes an organization's degree of certainty that a user has presented a credential that refers to his identity.

![](<../../../.gitbook/assets/image (638).png>)

#### Potential Impact

There are three levels of potential impact on an organizations or individuals should there be a breach: low, moderate, or high.

#### Areas of Impact

This is self-explanatory.

## 3.2: Password Authentication

### Password Vulnerabilities

* **Offline Dictionary Attack**: try to match/compare hashed passwords on the system.
* **Specific account attack**: is where you're trying to get into a particular account by trying random passwords.
* **Popular password attack:** trying weak passwords.
* **Password guessing against a single user**
* **Workstation hijacking**: Someone is logged in and then they walk away, but leave their terminal/workstation open and you go and use it.
* **Exploiting user mistakes**: like should surfing and watch them type in their password. Or use a camera. Or they put their password under their mouse/keyboard.
* **Exploiting multiple password use**: they use the same password across multiple accounts.
* **Electronic monitoring**: keylogger/network.

### Unix Password Scheme

* Back in the day, unix passwords were limited to 8 characters.



![](<../../../.gitbook/assets/image (639).png>)

* Salt is stored in plain-text in the password file and is prepended/appended to the user's file.

### UNIX Implementation

#### Original Scheme

* Up to 8 printable characters in length.
* 12-bit salt used to modify DES encryption into a one-way hash function
* Zero-value repeatedly encrypted 25 times.
* The output was translated into an 11-char sequence.
* It's now regarded as inadequate - but is still required with existing account management software or multivender environments.

#### Improved Implementations

* Much stronger hash/salt schemes.
* Use MD5 hashing with 1000 iterations to achieve slowdown.
* OpenBSD uses a blowfish block cipher. It is the most secure version of Unix/hash/salt scheme.

### Password Cracking of User-Chosen Passwords

#### Traditional Approaches

1. Dictionary Attacks
2. Rainbow table attacks
3. Exploit that people choose easily guessable passwords.
4. John the ripper: brute force/dictionary techniques.

#### Modern Approaches to Improved Implementations

* Password policies
* Password file access control. Restrict it.
  * Store the actual cryptographic value in a restricted file.
  * A 'shadow password' file still exists for compatibility reasons, but it's got a changed/removed hash.

### Password Selection Strategies

* User education
* Computer generated passwords:&#x20;
  * Users had trouble remembering them.
  * And wrote them down.
* Reactivate password checking
* Complex password policy
  * User is allowed, but system checks it to see if it's allowable and rejects it.

### Bloom Filter

![](<../../../.gitbook/assets/image (640).png>)

* Used to built a table based on dictionary using hashes.
* Check desired passwords against this table.
* You basically build common passwords and submit it to these bloom filters. You can check quickly to see whether or not they meet criterial.
* We use simple/stupid hash functions.

## 3.3: Token-Based Authentication

### Memory Cards

![Embossed cards were read literally.](<../../../.gitbook/assets/image (641).png>)

* Magnetic stripes.
* Electronic memory inside.
* NFC/Contactless

### Smart Cards

These are mini-computers with entire microprocessors inside.

