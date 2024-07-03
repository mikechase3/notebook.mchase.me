# 01 OS Welcome

## Operating System Tasks

The operating system is the interface between the software & hardware.

1. Direct operational resources. (Control the CPU memory, peripheral devices)
2. Enforce working policies (fair resource use/access, impose limits for processes/apps)
3. Mitigate difficulty of complex tasks (abstract hardware details w/ system calls)
4. Hides hardware complexity: from developers & applications.
5. Resource management
6. Provide isolation & protection: for multiple apps co-running on the same hardware.
7. Also device drivers.

## OS Elements

### Abstractions

* Process & threads correspond to the applications that the OS executes.
* To operate on abstractions, the OS may incorporate **mechanisms.**

### Policies

* Controls the maximum number of sockets that a process can have access to.

## OS Design Principles

1. Separation between mechanisms and policies.
   1. Incorporate into the OS number of flexible mechanisms supporting a range of policies.
   2. Mechanism used to track frequency or the time when memory locations have been accessed.
2. Optimize for the common case:
   1. Where will the OS be used?
   2. What will the user want to execute on that machine?
   3. What are the workload requirements?

## OS Protection Boundary

Computers have at least a user & kernel mode. Operating systems access at the kernel level while applications operate in user mode.

### Privileged Mode

1. When in the kernel mode, a special bit is set in the CPU and if the bit is set, any instructions that directly manipulate hardware is permitted to execute.
2. When in user mode, the bit isn't set so privileged operations are forbidden.
3. Such attempts to perform privileged an operation when in user mode will cause a **trap**.

### System Call Interface

* Rather than applications interfacing with hardware, it'll invoke a system call
* On a system call, control is passed to the operating system, in priveledged mode, and the OS will perform the operation and return the result to the process.
* To make a system call, an application must:
  * Write arguments
  * Save all relevant data at a well-defined location
  * Make the actual sys call using this specific system call number & make the call.

### Crossing the OS Boundary

1. Making system calls is expensive. You use more memory locations & must pass arguments back/forth which is expensive for memory.
2. If you want to build an optimization, try and reduce the number of system calls.

## Types of OS

### Monolithic OS

A **monolithic kernel** is a single large process running entirely in a single address space. Unix & Linux were the first ones introduced. It's a single static binary file.

* **Benefits**: everything is packaged at the same time. There are compile-time optimizations.
* **Downsides**: too much state & code that's hard to maintain, debug, and upgrade.
* Since the device drivers reside in the kernel space, it makes monlothic kernels less secure/stable.
* **Examples**: early Linux.

### Microkernel OS

* The kernel is broken down into separate processes known as servers.
* **Pros**: if something goes down, your whole PC doesn't go down, also more secure.
* **Examples**: Mac OS and Windows NT & most systems these days.

### Modular Operating System

Now, the operating system isn't this one piece of software but rather it's a bunch of modules. Once you boot it up, different applicatoins require different modules. If there's another module thta is needed, it's going to bring it in & serve the application.

**Pros**:

* You can easily customize which particular file system or schedule the OS uses. Just bring up the corresponding module.
* Allows the administrator to add functionality only when it's required.
* Decreases boot itme because you don't have to load everything at once.
* Faster development time because the components operate independently.

**Cons**:

* Less security/reliability compared to a microkernel becuase components change.

## Linux Architectures

**Layers of abstraction**: Hardware => Linux OS (process management, memory management, file system) => Standard Library (read/close/open/write/fork) => Standard Utility Programs (shell, editors, compilers) => User Applications.

## Mac OS Architecture

* Core is a microkernel, it's a type 2 operating system.
* Kernel level is like Linux.
* Driver's modules and kernel modules can be dynamically loaded into the kernel.

## Scrap Quiz

<figure><img src="../../../.gitbook/assets/image (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/image (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

More
