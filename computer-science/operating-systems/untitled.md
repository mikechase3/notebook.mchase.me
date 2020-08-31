# Processes

## Processes in Memory

![](../../.gitbook/assets/image%20%28174%29.png)

* An operating system executes a variety of programs
  * Batch systems: **jobs**.
  * Timer-shared systems: **user programs** or **tasks**. 
* The textbook uses the terms job and process almost interchangeably.
* **Process**: a program in its execution.
  * Current activity, including the _program counter_, processor registers.
    * A program counter is like a line-by-line examination.
    * A pointer to the current line of execution.
    * Processor registers: temporary holding spaces for data. Smallest, but fastest.
  * Stack: contains temporary data.
    * Function parameters, return addresses, local variables.
    * In operating systems, it specifies a region in the hardware.
  * Data Ssection: contains global regions?

## Process States

![](../../.gitbook/assets/image%20%28175%29.png)

| Process | Comment |
| :--- | :--- |
| new | The process is being created. |
| running | Instructions are being executed. The CPU scheduler takes a process from the head of the ready queue to execute. Sometimes, there may be multiple ready queues. |
| Waiting | The process is waiting for another event to occur. |
| Ready | The process is waiting to be assigned to a processor |
| Terminated | The process has finished execution. |

## Process Control Block PCB

![](../../.gitbook/assets/image%20%28173%29.png)

### Process Scheduling

* Process Scheduling
* Job Queues







