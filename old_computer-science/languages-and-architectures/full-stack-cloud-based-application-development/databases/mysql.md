# MySQL

## Creating a Database

* Download and install MySQL.

## SQL Monitor Basics

* Login: `mysql -u root -p` is how you login from a terminal.

| Action                  | Command                                                                                                                     |
| ----------------------- | --------------------------------------------------------------------------------------------------------------------------- |
| Show databases          | `show databases;`                                                                                                           |
| Switch to a specific db | `use database_name;`                                                                                                        |
| Create a new database   | `create database database_name;`                                                                                            |
| Create a table          | `create table users(username varchar(50) PRIMARY KEY, password varchar(100) NOT NULL);` That's a username/password example. |
|                         |                                                                                                                             |

## Inserting Data

* The syntax generally goes: `INSERT INTO <table_name> [fields] VALUES (...);`
* For example: `INSERT INTO users VALUES ('admin', 'password');`

## Updating Data

The syntax is easy: `UPDATE tablename SET assignmentlist [WHERE condition]`

For example, if we want to update the admin user's password with a hashed password, type this in: `UPDATE users SET password=SHA2('usersPassword', 256) WHERE username='admin';`

* Note: the PASSWORD function hashes the user's password, but it is not secure nowadays. Instead, use SHA2 to hash or something more secure. `256` is the bit depth, but you can choose `512` or some other values.

{% embed url="https://dev.mysql.com/doc/refman/8.0/en/encryption-functions.html#function_sha2" %}



## Viewing Data

You can view all data from a table using `SELECT * FROM <table_name>;`. For example, `SELECT * FROM users;`

### Where Clause

The where clause is used to filter records. 

{% embed url="https://www.w3schools.com/sql/sql_where.asp" %}

