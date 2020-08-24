# Introduction

## Interruptions

Common functions of interruptions:

* Interrupt transfers control of the interrupt service routine generally, through the **interrupt vector**, which contains the address of all the service routines
* Interrupt architecture must save the address of the interrupted instruction
* A **trap** or **exception** is a software-generate interrupt caused either by an error or a user request.
* An operating system is **interrupt driven**.

## Storage Structure

### Main Memory

* CPU accesses directly.
* Good for random access
* Typically **volatile**.

### Secondary Storage

* **Nonvolatile**: it's stored permanently.
* Examples: hard disks, magnetic recording material.
* Disk surface is logically divided into **tracks**. 
  * Tracks are divided into **sectors**.

### Caching

Copying information into faster storage system; main memory can be viewed as a cache for secondary storage.



