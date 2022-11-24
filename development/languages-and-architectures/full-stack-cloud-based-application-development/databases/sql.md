# SQL

## Introduction

* It's a comprehensive database language.
* Access control
* **Integrity constraints**: you define what the database is going to look like.
* Update language lets you insert/delete/modify tuples.

## SQL Syntax Basics

### CREATE TABLE \<NAME>

Syntax:

```sql
CREATE TABLE student
    (sid VARCHAR2(5),
    sname VARCHAR2(16),
    yog CHAR(4),
    gpa DECIMAL(3,2),
    sex CHAR(1),
    major VARCHAR2(16)
    PRIMARY KEY (sid));
```

### Drop Table

* `DROP ABLE DEPENDENT` will drop a table.

### Alter Table

Use this to keep track of employees in the company database:

```sql
ALTER TABLE EMPLOYEE ADD COLUMN JOB VARCHAR(12);
```

### SQL Data Types

* Integer, SMALLINT&#x20;
* Float, real, double precision, decimal(i,j)&#x20;
* Character(n), VARCHAR(n)&#x20;
* Bit(n), bit varying(n)&#x20;
* Date, time, time with time zone, timestamp
