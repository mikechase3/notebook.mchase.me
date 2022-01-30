---
description: >-
  Lecture 25: Input validation, final project tutorial 3, and more security
  topics.
---

# L25: Input Validation and Regular Expressions

## Agenda

* Review login system with user registration for the mini-facebook project.
* Input validation
* Final project 3 tutorial.
  * Database Design Suggestion
  * Displaying data from the database
* More Topics
  * Type checking
  * Common DBMS Vulnerabilities
  * Programming Flaws
  * Integer Errors
  * Static Analysis

## CPS475 Final Project Information

### Current Login System

| Item                     | What it Does                                                                                                                                                                                                  |
| ------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| form.php                 | Users provide their username/password to login.                                                                                                                                                               |
| `index.php`              | Gets the username and password from `from.php` and connects to the database to check the account. (Set the session as 'logged-in' and display the home page. Otherwise, alert and redirect back to `form.php` |
| `session_auth.php`       | Checks to ensure that the session is logged-in, otherwise, redirect to `form.php`                                                                                                                             |
| `database.php`           | Connect to the database and provide more database functions.                                                                                                                                                  |
| `changepasswordform.php` | Logged-in users can request to change the password                                                                                                                                                            |
| `changepassword.php`     | Gets the new password from the logged session to change the password of the current user                                                                                                                      |
| `registrationform.php`   | A form for usser registration. When we click on the sign-up button, the form will be submitted to `addnewuser.php`                                                                                            |
| `addnewuser.php`         | Gets the user registration data and inserts it to the database. (Call the `addnewuser` function defined in `database.php`)                                                                                    |
| `database.php` (updated) | Added a new function `addnewuser` (copied from the `changepassword`). Revise the SQL to include new fields depending on your database design.                                                                 |

### Registration Form

* You can deploy your form for your team project direclty onto `/var/www/html` in your SEED VM. You don't need to change the root directory for HTTPS.
* The page should be accessible from the mini-server with a specific domain name.
* CSS is optional.

### Security Features of Current System

| Action                                         | What This Means                                                |
| ---------------------------------------------- | -------------------------------------------------------------- |
| Deploy on HTTPS                                | All transaction data is encrypted and protected.               |
| Sanitized HTML Outputs                         | Prevents cross-site scripting attacks.                         |
| Implemented Prepared Statements                | Prevents SQL Injection attacks.                                |
| Protect system from session hijacking          | Secure cookies for a session; check browser information.       |
| Implemented Session Authentication             | Protected pages can only be accessible by the logged-in users. |
| Access Control                                 | A user cannot change the password of another user.             |
| Implemented Secret Token Generation/Validation | Cross-site request forgery (CSRF) attacks will be prevented.   |

{% hint style="info" %}
At this point, we ended the review and switched to implementing new features.
{% endhint %}

### Registration Form User Validation

{% embed url="https://cheatsheetseries.owasp.org/cheatsheets/Input_Validation_Cheat_Sheet.html" %}

#### Types of Syntax Validation

**Syntactic** enforces correct syntax such as a SSN, email, phone, or other things using a regular expression.

**Semantics** check to see that the values make logical sense. For example, the start date must be before the end-date.

## Client-Side Input Validation with HTML and Regex

Input validation must be implemented in both the client-side and server side.

### HTML5 Form Validation

![Example HTML5 Form Validation](<../../../.gitbook/assets/image (241).png>)

### HTML5 Placeholders

A placeholder attribute is used to guide the user to the expected input:

![](<../../../.gitbook/assets/image (217).png>)

```markup
<input type="text" class="text_field" name="username" 
    placeholder="Your Email Address"/>
```

### HTML5 Titles

The `title` attribute is used to browsers to display a message in case of a mismatch.

![](<../../../.gitbook/assets/image (195).png>)

```markup
<input type="text" name="username" required pattern="\w+"
title="Please enter a valid username"
onchange="this.setCustomValidity(this.validity.patternMismatch ? this.title : ' '); "/>
```

### Adding Validation Code

Here is the code we should add to the `registrationform.php` file and upload to the server.  This code validates usernames, only if they accept a valid email.

```markup
<!-- Must be an email address as username -->
<input type="text" class="text_field" name="username" required
pattern=" ^[\w.-]+@[\w-]+(.[\w-]+)*$"
title="Please enter a valid email as username"
placeholder="Your email address"
onchange="this.setCustomValidity(this.validity.patternMismatch?this.title: '');"/>

<!--Rule: at least one special character !@#$%^& one number, one lowercase and one uppercase letter with
at least 8 characters -->
<input type="password" name="password" required
pattern="^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#$%^&])[\w!@#$%^&]{8,}$"
placeholder="Your password"
title="Password must have at least 8 characters with 1 special symbol !@#$%^& 1 number, 1 lowercase, and 1
UPPERCASE"
onchange="this.setCustomValidity(this.validity.patternMismatch?this.title: ''); form.repassword.pattern =
this.value;"/>
Retype Password: <input type="password" class="text_field" name="repassword"
placeholder="Retype your password" required
title="Password does not match"
onchange="this.setCustomValidity(this.validity.patternMismatch?this.title: '');"/> <br>
```

### Validation Demonstration

![](<../../../.gitbook/assets/image (297).png>)

{% embed url="https://www.aspsnippets.com/Articles/HTML5-Validations-example-Required-Email-Password-Strength-and-Compare-Password-validations-in-HTML5.aspx" %}

## Server-Side PHP Validation

### Guiding Principles

{% embed url="https://www.w3schools.com/php/php_form_validation.asp" %}

* Check if the input is empty.
* Trim and sanitize the input.

```php
// Trimps and sanitizes input.
function sanitize_input($input) {
    $input = trim($input);
    $input = stripslashes($input);
    $input = htmlspecialchars($input);
    return $input;
}
```

* Check the input length.
* Check the input against a regular expression.
* Sanitize input using a function.

### For Our Project

See slides 22-23

* Implement input validation functions in `database.php`
  * Sanitize input.
  * Username/password should match the same regex rules as in the client.
* Change some functionality in `addnewuser()` to have secure input validation.

## Captcha

### Issues with Automated User Registration

* The registration process can be automated by a program.
* System can be abused via non-human bot users.

### Captcha

Defends against Denial of Service attacks, automatic registration/posting, and scraping of web contents.

{% embed url="https://www.youtube.com/watch?v=GC26qylV8IU" %}

## Common Programming Flaws

### General Implementation

* Buffer overflows.
* String formatting
* Data Races
* Integer Overflows
* Failure to handle errors correctly.
* Too much privilege
* Failure to protect stored data.

### Cryptography and Network Security

* Use of weak password-based systems
* Weak random number generators.
* Using cryptography incorrectly
* Failing to protect network traffic
* Improper use of PKI, especially SSL
* Trusting network name resolution.

### Web Applications

* SQL Injection
* Cross-Site Scripting
* Session-hijacking
* Cross-site request forgery.
