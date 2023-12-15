# CPS 536 Mindmap

CPS 536\
Progress: 83%

* W01 Processes & Process Management
* W02 Threads
  * W02 Threads and Concurrency
  * W03 Thread Design Considerations
  * W04 Thread Performance Considerations
* W05 Scheduling
* W06 Memory Management
* W07 Inter-Process Communication
* W08 & 09 & Part of 10 Synchronization Constructs\
  Progress: 50%
  * Hardware Techniques\
    Progress: 100%
    * **Cache Coherence** is the discipline ensuring that changes in the values of shared operands are propagated throughout the system in a timely fashion. The programmer doesn't get to choose between cache invalidate or update because that's a property of the hardware architecture.
      * Caches
        * Caches speed up & reduce latency
        * Latency is even more of an issue in shared memory systems because of contention on the memory module
      * Inconsistencies in data values across different CPUs is bad.
      * Invalidation-Based Protocols
        * **Read Invalidate** is same as write invalidate, but with read protocols
        * **Write Invalidate** When one processor writes to a memory location, all other caches holding copies of that data are invalidated. This means that the next time another processor accesses that data, it must fetch the updated value from memory.
          * "Amortized Cost"
          * When a processor writes to the cache line, it'll send an invalidate command to all the other caches that have a copy of the same cache line.
            * Lower bandwidth requirements on the interconnect
            * We don't have to send the full values, just the adddress to invalidate
        * **Write-Back**
          * Efficient & reduces number of writes to main memory.
          * Requires additional logic to ensure that all copies of a cache line are updated when one copy is modified.
          * Writes to **cache** only, at least, initially.
            * Then, writes to memory location when that cache line is evicted (or some later time)
      * **Non-Cache-Coherence**
        * Solve inconsistencies by implementing **non-cache-coherent architectures** for platforms that don't support it (in hardware?)
      * On cache-coherent platforms, hardware will take care of everything and make life easy
      * Update-Based Protocols
        * **Write Update** Corrects the caches in all CPUs so we get more cache hits.
          * Data is available immediately on other CPUs needing to access it.
          * No cost to perform another memory access in order to retrieve the latest value of 'x'
        * **Write-through** protocol
          * Ensures the data in the main memory is always up-to-date
          * Slow due to the overhead of writing to main memory on every write operation.
          * Writes directly to memory. Every write operation to a cache line is immediately propagated to main memory
            * Writes to cache too
      * When you change something in one cache of a CPU, propagate that to RAM & the other CPU caches.
      * WRITE: what happens when CPUs perform a write?
        * You might not allow a write to happen to the cache. It'll write directly to memory and any cached copy of that particular memory location will be invalidated.
    * For Shared Memory Multiprocessors (SMPs)
      * Benefits of using SMPs
        * Data sharing is easier
        * Ease of programming.
        * Reduced latency because CPUs can access memory directly without having to send messages to other CPUs.
      * Bus-Based
        * Common in current systems
        * One memory reference
        * The bus is shared across all modules
        * Uses a single memory model
      * Drawbacks of using SMPs
        * Contention: shared memory is susceptible to contention
        * Not as scalable as other types of multiprocessor architectures.
      * Interconnected (IC) Based
        * Could have multiple memory references or one memory reference for each memory module
        * Older systems
  * Software Techniques\
    Progress: 0%
    * **Atomic Instructions** are special instructions guaranteed to execute "atomically," meaning they can't be interrupted by another CPU. It's usually **implemented** using hardware support, but can also be implemented using software techniques
      * Examples of Atomic Instructions
        * Compare & Swap
        * Read & Increment
        * Spinlock Improvements
          * Analysis
            * • Static delay alternatives: These spinlock implementations are a good compromise between latency and overhead under high loads. However, they can lead to wasted cycles under light loads if the two processors that have the smallest and largest delays are the only ones contending for the lock.\
              • Dynamic delay alternatives: These spinlock implementations have low overhead under high loads because they avoid collisions between processors. However, they have medium latency because they require a random delay to be generated before acquiring the lock.
            * Heavy=High & Low=Light loads meaning there’s little contention for the lock.
            * Queuing locks are fair & scalable, but has high latency as it requires an atomic read & increment operation to acquire the lock. It’s a good choice for high loads when fairness/scalability are more important than latency.
            * Test & set has high overhead under high loads because it causes a lot of cache invalidation.
          * Delays in Spinlocks
            * Dynamic Delay
              * Anderson’s Queueing Lock
                * **Problem**: a common problem in spin locks is that everyone is trying to acquire the lock at the same time once it’s freed leading to lots of delays
                * **Process:** When a thread wants to acquire a lock, what does it do?
                  * 1: get a ticket by atomically incrementing the queue-last pointer.
                  *
                    2. Thread will then spin on its flag in the queue.
                    3. As long the flag still must-wait, the thread keeps spinning.
                  *
                    3. If a flag becomes has-lock, it means that the thread has acquired the lock & can enter the critical section.
                  *
                    4. When a thread releases the lock, it sets its flag in the queue to “must-wait” & sets the flag of the next element in the queue to has-lock, signaling to the next thread in the queue to acquire the lock.
                  * Atomic read & increment w/ a thumbs down next to it?
                    * Arriving tickets will be assigned the next position in the array & automatically incremented since multiple threads may arrive a the same time
                * Implementation
                  * **Advantages**: what are the advantages of this spin lock implementation compared to other implementations?
                    * Efficient when there is lots of contention for the lock
                      * Because the atomic read-and-increment operation is only performed once, when the thread first acquires the lock.
                    * Fair
                    * Scalable to a large number of processes
                  * **Data Structures:** What data structures does Anderson’s queueing lock require?
                    * **Array of Flags** is required where each flag represents a processor in one of two states:
                      * `n` is the number of cores or processors to split tasks. Each element will be set to
                        * `HL` if it has a lock
                        * `MW` if it must wait.
                      * Has Lock
                      * Must Wait
                    * Pointers
                      * One pointer points to the current lock holder.
                      * One pointer points to the last element in the queue.
                  * **Disadvantages**: what’s wrong with this?
                    * **Higher latency** occurs because the thread has to perform an atomic read & increment operation and then spin on its flag before it can acquire the lock.
                    * **Requires more memory** than other spin lock implementations because it needs. To store an array of flags for each processor in the system.
                  * • The queueing lock is implemented using an array of flags, two pointers, and an atomic read and increment operation.\
                    • The first element of the array is initially set to has-lock and all other elements are set to must-wait.\
                    • To acquire the lock, a thread first performs an atomic read and increment operation on the queue-last pointer. This returns the thread's ticket number.\
                    • The thread then spins on its flag in the queue. As long as the flag is must-wait, the thread keeps spinning.\
                    • When the thread's flag becomes has-lock, the thread has acquired the lock and can enter the critical section.\
                    • To release the lock, a thread sets its flag in the queue to must-wait and then sets the flag of the next element in the queue to has-lock.
                    * Q: “How does the thread **acquire a lock?**”
                    * Start
                      * Upon start, the first element of the array is initially set to has-lock and all other elements are set to must-wait
              * Backoff Algorithms
                * Reduces contention for the lock.
                * These are techniques that'll increase the amount of time a thread spins before trying to acquire a lock.
                  * Increased delay is proportional to # of failed test & set operations.
              * Fair Spinlock
                * Helps prevent priority inversion.
                * This type of spinlock gives all threads an equal chance to acquire the lock.
              * The delay each processes "picks" is based upon the load of contention on the system.
            * Inside the Loop Delays
              * Reduces the amount of contention.
              * Reduces the number of threads that check the lock at the same time.
              * The delay is incurred **before checking the lock again**
            * Outside the Loop Delays
              * Delay increases, but contention in the system is significantly improved compared to the test-and-set function
              * Delay is incurred **after a thread releases the lock** so other threads have a chance to acquire before the current thread rechecks the value of the lock.
                * Every thread/processor doesn't try to acquire the lock because they don't all see it's free because of the **delay function**
                * Gives other threads a chance to acquire the lock before the current thread re-checks the value of the lock.
                * Increased fairness
            * Static Delay
              * Benefits
                * No continous spinning
                * Simple Approach
                * Under high loads, this static delay will spread out all the atomic references so that there's no contention.
                * Works on non-cache coherent architectures.
              * Determining the Delay
                * Len(critical\_section) is also used.
                * Process is delayed 1\*critical\_section and another process is delayed 2\*critical\_section and so forth...
                * Use some fixed information to determine a delay that'll be used for any single process that ends up running on that CPU.
                  * CPU
                  * ID
              * Drawbacks
                * Clearly hurts the delay much more because we're building up the delay even when there is no contention on the network.
                * Unnecessary delay under low contention.
          * Test & Set Spinlock Instruction
            * Background
              * A low-level instruction that atomically sets a memory location to 1 and returns the old value.
              * The `test_and_set()` returns 0 for the first thread that acquires the lock.
                * Returns 1 and its previous value if used/taken
              * Therefore, the instruction cannot be interrupted by another CPU and the memory location will always be in a consistent state.
              * We'll always assume that the lock initialization is set to free upon lock creation.
            * Cons
              * "The real problem with this implementation is that it continuously spins _on the atomic instruction_
                * Even with coherent caches, those'll be bypassed because we're using an atomic instructions?
                  * Warning: this statement, as phrased, makes it seem like all atomic instructions bypass the cache, but that's not true according to a google search by AI?
                * Without cache coherence, it's especially bad because we have to go into memory to check the value of the lock
              * As long as their spinning, every single processor will repeatedly go on the shared interconnect
              * Creates contention & delay on the processing that's carried out on other CPUs.
              * Delays the time that the lock actually beocmes free.
              * Different architectures perform this more efficiently & some don't support it at all.
            * Pros
              * **Atomic**: the test-and-set instruction is guaranteed to execute atomically meaning it can't be interrupted by another CPU.
              * **Efficient**: efficiently implemented on CPUs; we're just spinning on the atomic instruction
              * **Simple**: the test-and-set instruction is a simple instruction to understand & implement.
              * Regarding delay, it could perform well because we're continously just spinning on the atomic instruction
          * **Test-and-test-and-set spinlock** solution or spin-and-read spinlock. There's a separate test which is checking from the atomic parts by using caches & testing the caches copy of the lock. Only perform atomic if cache indicates it's cleaned/changed.
            * A little more latency/delay because of the extra check whether the lock is busy/not that hits the cache.
            * Comparison
              * Worse performace on multicore/multiprocessors because everyone will see the lock has changed its state & try to acquire the lock at the same time.
            * Contention
      * Guarantees no interference from other threads
        * Atomicity
        * Mutual Exclusion
        * Queue all concurrent instructions but one.
      * Slow because
        * Always directly access the memory controller directly where they'll be ordered/synchorinzed
          * Makes race conditions impossible
        * Generates **coherence traffic**
        * Require memory barriers or other synchronization primitives to ensure atomic instructions are executed correctly
        * Require synchronization between threads
        * Requires more hardware support
    * Locking Mechanisms
      * Barriers
        * "like a reverse of semaphores"
        * Allows multiple threads to wait for each other at a particular point in the execution of a program
        * Ensures no thread proceeds until **n** threads have reached the barrier point
          * After which, it's lifted & threads proceed
          * Note: rendezvous points are when **all** threads arrive.
      * Monitors
        * Accessing
          * Easier for programmers
          * On exit, the library does all the unlocks, checking, and signaling necessary for the condition variables.
          * Upon access, lock/check takes place.
        * History
          * Developed by Xerox in the MESA Language Runtime
          * High-Level synchronization construct
        * Java uses
          * In its synchronization methods
          * notify() must still be done explicitely
        * What do monitors specify?
          * Entry procedure
          * Possible condition variable
          * Shared resources
      * Path Expressions
        * As opposed to locks, the programmer would specify 'many reads' or 'single write'
        * Require programmers specify a regular expression capturing the right synchornization behavior
        * The runtime ensures that the way the operations access the shared resource match what's in the **regular expression**
      * Reader/Writer Lock Mechanism\
        Also referred to as shared and exclusive locks.
        * Operations
          * **upgrade()** lets an owner of a shared lock convert it from reader -> writer
            * Better than releasing & trying to re-acquire it and contend with other threads.
          *   Usage on Linux:

              ```
              include <linux/spinlock.h>  
              read_lock(m);  
                // critical section  
              read_unlock(m);  
                
              write_lock(m)  
                // crit  
              write_unlock(m);  
              ```
        * Priority
          * Different OS's implement locks differently.
          * Sometimes there's sync issues because of these different implementations.
        * Readers have different rules than writers
          * **Readers** that never modify files can **share** access without any synchronization issues
          * **Writers** by contrast get exclusive access since they modify files
      * Rendezvous Points
        * A sync construct that waits for multiple threads to meet that particular point in execution.
        * Unlike barriers, rendezvous points wait for **all threads** to arrive before allowing any thread to proceed.
      * Semaphores
        * Used to protect shared resources from concurrent ccess by multiple threads
          * Often used to protect critical sections of a code.
          * Oftentimes used to signal between threads
        * Uses a counter used to control access to shared resources
          * Allows `n` threads to proceed before it blocks other threads via a barrier.
      * Serializes
        * Hides explicit use of condition variables from the programmers
        * Hides the need for explicit signaling
        * Makes it easier to define priorities
      * Spinlocks (Primitive)
        * Atomic instructions are used to implement spin locks
        * Polls constantly & wastes CPU cycles checking if the lock get unlocked.
        * Simple, Basic
          * Used to make more complex synchronization mechanisms.
        * Spinlock Performance Metrics. _What are the three spinlock performance metrics we discussed_?
          * Conflicting Metrics
            * Latency conflicts with contention
              * A lock that's designed to reduce latency means we want to execute the atomic operation as soon as possible. Locking/Unlocking it quicker potentially creates additional contention on the network
            * Reducing **waiting time** conflicts with **contention** like bus/network requests.
              * Detect ASAP when the lock is freed so we can try & acquire it.
              * To reduce the waiting time to delay, we have to continously spin the lock as long as it is not available.
          * Low Delay or Low Waiting Time
            * Reduce the time it takes from the thread to stop spinning & acquire that lock that has just been freed.
            * Spinlocks shouldn't introduce a significant amount of overhead to the system.
          * Low Latency
            * How fast is it to acquire/release the lock?
            * The ideal case is that we can execute a single atomic instruction & be done.
          * No Contention
            * Could delay the unlock operation for the spin lock which will impact the performance even more.
            * Delays the owner of the spin lock
            * It'll delay other CPUs in the systems trying to access that location on the Mutex
            * Where it often occurs
              * On the shared bus
              * Or on the network interconect
        * Uses mutual exclusion with lock/unlock mechanisms
      * Wait-Free Synchronization
        * Makes programs more scalable & efficient at the cost of potential conflicts due to concurrent writes.
        * Read-Copy-Update (RCU) Lock
          * Part of the linux kernel.
          * Underlying hardware supports to make
* W10 & W11.1 I/O Management\
  Progress: 88%
  * \_Overview\
    Progress: 100%
    * Definition & Tasks
      * Buffering
      * Caching
      * Data Transfer
      * Device Discovery
      * Device Scheduling
      * Error Handling
      * I/O Management is the process of controlling and managing input and output devices in an OS
        * **devices** include peripherals like microphones, keyboards, and displays.
    * Internals (Hardware)
      * Memory (DRAM or SRAM or both)
      * Micro-controller (a CPU)
      * Other hardware-specific chips
  * CPU Device Interconnect. Components:\
    Progress: 100%
    * **PCI-E Bus** Has more bandwidth, is faster, lower access latency, and supports more devices than older PCI-X and PCI devices.
    * **SCSI Controller**: small computer system interface is a parallel interface standard for connecting peripherals to a computer.
      * Advantages
        * Daisy chaining
        * High speed & transfer capability
          * Disclaimer/Note: At the time it was fast. Superseded now by SATA and NVMe which are significantly faster
        * Supports multiple devices connected to a single bus
      * Disadvantages
        * Complex to manage/configure
        * Expensive
      * Originally for hard disk drives & a variety of things like optical drives, tape drives, scanners, and optical drives.
      * SCSI Interconnect
        * A bridge handles different types of physical hardware ports
      * Types of SCSI Busses
        * Parallel SCSI (SPI); the O.G. controller supporting 8 devices & 5MB/s documents.
        * This has been replaced by SATA and NVMe
        * Ultra SCSI (320MB/s)
        * Wide Parallel (16 bit; 16 devices; 320MB/s)
  * I/O Management Tasks\
    Progress: 75%
    * **Bufferring**
      * Stores data temporarily in memory before being transferred to the I/O device.
    * **Bufferring and Caching** techniques can be used to improve the performance of I/O operations. Caching stores the frequently accessed data in memory-ish. Bufferring stores it temporarily in memory before being transferred to the I/O device.
    * Data Transfer
      * The process of moving data between the CPU and I/O Devices
    * **Device Drivers:**
      * **Device Drivers Independence**
        * Manufacturers/designers are the ones responsible for making sure device drivers are available.
        * OS Systems turn standardize their interfaces to a device drivers'. Typically, manufacturers are given a framework so manufacturers can develop the specific device drivers within that framework, given specific interfaces that OS supports.
      * Functions
        * Provides **device access, management, and control**
        * They provide the OS with a uniform interface to the I/O devices regardless of their specific characteristics.
      * Intermediaries between the OS & I/O devices.
    * **Error Handling**: techniques.
      * Notify/Log Error.
      * Retry I/O
      * Techniques to handle errors that occur during I/O Operations
    * **I/O Scheduling**: I/O scheduling algorithms decide which I/O requests to service and in what order. This can be a complex task, as the scheduler must consider a number of factors, such as the priority of the I/O requests, the type of I/O devices involved, and the current state of the system.
      * Considers factors such as:
        * Device type
        * Request Priority
        * System state
      * The process of deciding which I/O requests to service & in what order
  * Mechanisms for Interacting with Devices\
    Progress: 90%
    * **Block Device Stack**
      * Benefits of block devices
        * **Abstraction:** The block device stack hides the details of the underlying block device from applications and the kernel file system. This makes it easier to develop applications and to support different types of block devices.
        * **Flexibility:** The block device stack is flexible and can be easily extended to support new types of block devices. This is because the generic block layer provides a standard interface for accessing block devices.
        * **Performance:** The block device stack can improve the performance of applications by caching data in memory and by performing read-ahead operations.
      * Consists of **layers**
        * File Systems
          * Creates & deletes files.
          * Formats the device
          * Responsible for managing the data on the block device.
        * Generic Block Layer
          * Provides a standard interface for accessing block devices, regardless of their specific type.
            * All the features are still available through the device driver.
            * Hides the details of the underlying device driver
          * Provides common set of operations like read/write
        * Kernel File System
          * Manages files & directories & provides a way for applications to access files without having to know about the undlerlying block device.
          * Provides a file system abstraction for accessing block devices
            * Defined in POSIX
      * The block device stack works as follows:
        * The device driver performs the read or write operation on the block device and returns the results to the generic block layer.
        * The generic block layer passes the operation to the appropriate device driver.
        * The generic block layer returns the results to the kernel file system.
        * The kernel file system determines which block device the file is stored on and invokes the appropriate read or write operation on the generic block layer.
        * The kernel file system returns the results to the application.
        * When an application wants to access a file, it calls the kernel file system.
    * **Canonical Device**: a hypothetical interface used to illustrate the concepts of device interaction & I/O Management.
    * **Control registers** allow the CPU to control the operation of the device. _example: select the mode of operation of the device or start a specific operation_
      * Registers are accessed by the CPU quickly/often. I'd guess interacting with the registers on that device is efficient/quick way to communicate on microcontrollers.
    * **Data Transfer Registers** are used to store data being transferred between the External device & the CPU. Examples:
      * A status register might indicate whether or not the device is ready to receive data.
      * Error register for errors is another exmaple.
    * Direct Memory Access
      * **Advantages**:
        * DMA controller handles the movement freeing up the CPU to do other work.
        * Faster than PIO because CPU isn't involved.
      * A technique that uses special hardware to move data between the CPU & devices.
      * Example: to send a network packet using DMA, the CPU would:
        *
          1. Write a command to the network card's command register to start a transmission.
        *
          2. Configure the DMA controller with the information about the memory address and size of the buffer that holds the packet data.
          3. Drawback - many more cycles than a _memory store_
        *
          3. The DMA controller will then move the packet data from the CPU memory to the network card without further intervention from the CPU.
        * All information must be written/present in physical memory until the transfer completes.
    * **I/O Port Access** Uses a special instruction to specify the target device (the I/O port) and the value to be written/read.
    * Interrupts
      * **Benefits**: generated as soon as the device has data ready to be processed which can improve performance.
    * **Memory Mapped I/O** is similar to memory access.
      * Dedicates a portion of computer's physical memory on the system for device interactions.
        * CPU writes/reads from these locations
        * Memory controller then routes the accesses to the appropriate devices.
      * The device registers appear to the device as memory locations
    * OS Bypass
      * **Challenges** introduced by OS bypass
        * OS must still be able to control the device
          * Arbitrate access to the device between multiple user processes
          * Blocking, adding, and removing permissions.
          * Enabling/Disabling of the device
      * **Drawbacks**: increased complexity, reduced security.
      * **Purpose**: allows user-level processes to access devices directly, without going through the operating system.
        * Improves performance performance of I/O Operations
        * Reduces overhead.
        * Useful for performance critical applications like network drivers & graphics drivers.
      * **Technique**: allow user level processes to access the devices directly without going through the OS
        * Map the device's memory registers into the user process's address space.
        * OS must configure the device to be directly accessible from the user level.
      * Demultiplexing
        * Implement demultiplexing using **protocols** like how TCP/IP has network packets with port numbers.
        * When multiple devices access the same device, that device is responsible for demultiplexing the data that is receives.
    * PIO (Programmable Input/Output)
      * **Example: sending network packet using PIO**. To do this:
        *
          1. Write a command to the network card's command register to start a transmission.
        *
          2. Copy the packet data into the network card's data registers
        *
          3. Repeat until the entire packet has been sent.
      * CPU controls the device by writing to command registers on the foreign device.
      * CPU then moves data to/from the device's data registers.
    * Polling
      * **Benefits: reduces overhead** (b/c OS can choose when to poll the device); also avoids cache pollution.
      * **Drawbacks**: can introduce delays in handling events; consumes CPU resources which reduces performance for other tasks.
    * Schronized versus Asynchronous Access
      * **Asynchronous I/O**: the processor/thread is allowed to continue executing while the I/O operation is in progress. The process/thread can then be notified when the I/O operation is complete & results are available.
        * Improved responsiveness because the thread isn't blocked while the I/O operation is in progress
        * Improved throughput because multiple I/O operations can be in progress at the same time
        * Less predictable performance because the process/thread doesn't know exactly when the I/O operation will complete
        * More complex to implement
      * **Example**:\
        Imagine a process that needs to read a file from disk. If the process is using synchronous I/O, the process will be blocked until the file has been completely read from disk. This means that the process cannot do anything else until the file has been read.\
        If the process is using asynchronous I/O, the process will not be blocked when it makes the I/O call to read the file from disk. The process can continue executing while the file is being read. The process will then be notified when the file has been completely read from disk and the results are available.
      * **Synchronous I/O**: the process/thread is blocked until the I/O is complete.
        * Predictable Performance
        * Reduced responsiveness
        * Simple to implement
    * Typical Device Access
      * When a process needs to access a hardware device, it makes a system call to the operating system. The operating system then invokes the appropriate device driver, which configures the device to perform the requested operation. The device driver then uses programmed I/O or DMA to issue commands to the device. Once the device is configured, it performs the request and sends any results back to the device driver. The device driver then returns the results to the process.
  * Types of IO Devices\
    Progress: 75%
    * Block (Disks)
      * Direct access to arbitrary blocks
      * Read/Write in "blocks"
    * Character Devices: work with a serial sequence of characters
      * Operations
        * Get a char
        * Put a char
    * Network Devices
      * The granularity of the data chunks vary.
  * Virtual File System\
    Progress: 90%
    * Abstractions
      * **Dentries**: data structures representing dictionary entries. Keeps track of the location of files/directories in the file system hierarchy.
        * **Dentry Cache**
          * Maintains a cache of all directory entries that've been visited.
        * Each dentry object corresponds to a single path component being traversed as we are trying to reach a particular file
        * In the process, the virtual file system will create a dentry element for every path component /users
      * **File Descriptors**: represent open files & provides a number of operations that can be performed like reading/writing/closing.
      * **Files**: read/write
      * **Superblocks**: contain information about the overall structure of a file system like the number of blocks & location of the free block list. The VFS uses it to determine how to access file on a particular file system.
    * Benefits
      * Abstraction
      * Flexibility
      * Performance
    * Example: Ex2 on Linux
    * How the VFS works
      * Applications call the VFS & the VFS calls/invokes the operations provided by the local file system driver.
      * Caches the directory too
      * Enforces file permissions.
    * Inodes
      * Benefits
        * Easy to manage large files
        * Fast & efficient access to file data
        * Flexible & extensible.
      * Disk Access Optimizations
        * **Buffering:** Buffering allows the operating system to group together multiple disk accesses into a single larger access. This reduces the overhead of disk access.
        * **Caching:** Caching allows the operating system to store frequently accessed data in memory. This reduces the number of disk accesses that are required.
        * **I/O scheduling:** I/O scheduling allows the operating system to optimize the order of disk accesses. This can reduce the time that it takes to access data.
        * **Journaling:** Journaling allows the operating system to track pending disk writes. This can improve the reliability of the file system in the event of a power failure or other system crash.
        * **Prefetching:** Prefetching allows the operating system to read data from disk before it is needed. This can improve the performance of applications that access data in a predictable pattern.
      * Drawbacks
        * Can add overhead to disk operations.
        * Limits the size of files to the number of indexable blocks
      * I-Nodes with indirect pointers
        * **Direct Pointers**: pointers to data blocks
        * **Indirect Pointers** pointers to blocks of pointers.
        * Supports larger files
        * Used to address larger files than possible with direct pointers alone.
      * I-Nodes with Pointers
      * Information Contained
        * File name
        * File permissions
        * File size
        * Location of file's data blocks
        * Ownership of information
    * Purpose/Overview
      * Abstract details of underlying file system from applications.
      * Easier to access storage on different mediums like network drives
      * Provides a unified interface for applications to access files, regardless of the specific file system that the files are stored on. This makes it possible to change the underlying file system without having to modify applications.
* W11 Virtualization\
  Progress: 71%
  * Abstract & Terminology\
    Progress: 100%
    * **Guest Machines** are virtual machines that run on a host machine.
    * **Host Machines** are e physical computers upon which virtual machines run.
    * **Hypervisors** describe the software layer that manages the resources of the physical hardware & creates/runs virtual machines.
    * **Virtual Machine** is a software representation of a physical computer system that operates as an independent, isolated environment.
    * **Virtual Resources** are where each OS thinks that it owns hardware resources.
    * **Virtualization** is the process of creating virtual version of something like servers, storage devices, network resources, and even an operating system.
  * Benefits of Virtualization\
    Progress: 100%
    * **Consolidation**: reduces number of physical machines & leads to improved cost efficiency.
    * **Debugging**
      * Malicious behavior apps can be ran/studied.
      * The main PC doesn't shut down after a critical error.
    * **Migration**
      * Or move apps/drives from one physical machine to another (e.g. drives)
      * You can copy OS's.
    * **Supports Legacy OS's**
  * Protection Levels\
    Progress: 100%
    * **Modes**: {root, non-root} modes?
      * Non-Root
        * Contains its own set of protection rings.
      * Root
        * Contains its own set of protection rings too!
    * **Rings** control access to hardware resources & prevent unauthorized access.
      * x86 has four protection rings where 0 is the most privileged & 3 is the least
    * **Traps, VMExits & ReEntry** occur when a guest OS attempts to perform a priveleged operation causing a switch to root mode & hands control to the hypervisor.
      * Once the hypervisor completes its task, it passes control back to the virtual machine through a VMEntry, switching the mode back to non-root mode for continued execution.
  * Types of Virtualization\
    Progress: 55%
    * **Type 1 aka Bare Metal Virtualization** is where the hypervisor runs directly on the physical hardware w/ full control over the hardware resources to provide better performance & security than hosted virtualization.\
      Progress: 100%
      * Examples of Bare Metal Hypervisors\
        Link: [en.wikipedia.org/wiki/Hypervisor#External\_links](https://en.wikipedia.org/wiki/Hypervisor#External\_links)
        * **Xen** (Open source or Citrix XenServer)
          * VMs are referred to as **domains**. There are two types:
            * **Dom0** is a privileged domain.
              * Drivers live here.
            * **DomUs** contains the user domains.
          * Xen is opensource
        * ESX (VMware)
          * Drivers are located in the VMM
          * It originally used a linux control core but now uses remote APIs.
          * Provides many open APIs.
          * This holds the largest market share for virtualized server cores.
      * Key Features
        * A privileged service VM handles devices, configuration, and management tasks.
        * The hypervisor is responsible for managing the physical resources & supporting the execution of virtual machines.
    * Type 2 or "hosted" runs over an existing OS.\
      Progress: 10%
      * **KVM** (Kernel-based Virtual Machine) is free & opensource within th ekernel that allows it to function as a hypervisor.
        * **Drivers** are software programs allowing the guest VM to interact with hardware devices such as network adapters & graphics cards.
        * **File System & block devices** are virtual storage devices that the guest VM uses to store data. They can be mapped to physical storage devices on the host system or completely virtualized.
        * **Hardware Emulation (QEMU)** is the software that provides the guest VM with access to hardware devices.
          * **gemu\_mutex** is a sync mechanism that prevents multiple threads at the same time.
          * Ensures only one thread can execute QEMU code at any time.
          * It translates the guest VM's request into instructions that the host system's hardware can understand.
        * **KVM Guest** represents the virtual machine that's running on the host system. It has it's own OS, applications, data, and is isolated from the other VMs & the host system.
          * **Applications**: are the programs that run on the guest VM.
          * **KVM Guest's Kernel** is the guest VM's operating system. It manages the VM's resources like memory/CPU time and provides basic services that applications need to run.
        * **lothread**: is a thread responsible for handling low-priority tasks like garbage collection.
        * Component that **Generates I/O Requests to the host on guest's behalf and handles events**
          * Handles events generated by the host system.
          * Responsible for communicating with the host system on behalf of the guest VM. It'll send I/O requests to the host system when the guest VM needs access to hardware devices.
        * KVM.KO is the kernel module that implements the core functionality of KVM. It provides the hypervisor with the ability to create/manage virtual machines.
        * vCPU 0...N: are virtual CPUs assigned to a guest VM. Each executes instructions independently of the others.
      * The **VMM** or virtual machine monitor is like the building manager providing each virtual machine with its own space. It'll also take advantage of services/features offered by the host OS making it easier to manage virtual machines.
      * The host operating system is like the landlord owning all the resources still.
  * Virtualization Mechanisms\
    Progress: 0%
    * Device Virtualization
      * **Challenging** because there's greater variety of devices & no standard specification for device interfaces.
      * Allows the guest OS to use devices as if it were attached to the system physically.
      * Models of Device Virtualization
        * **Emulation Model:** In this model, the hypervisor emulates the behavior of the physical device. This model is more flexible than the passthrough model, but it can also be less efficient.
          * **Hypervisor Direct** allows hypervisor to intercept every single possible device access that is performed by a guest VM.
            * **Complexity** hypervisor needs to support all the drivers for the devices it wants to virtualize.
            * **Decoupling** is good & guest VMs are decoupled from physical drive.
            * **Flexibility**: hypervisor can translate device accesses to a generic representation of an I/O operation, making it easy to support a wide variety of devices.
            * **Latency**: emulation step
          * Not discussed? In wrong place?
        * **Para-virtualization Model:** In this model, the guest operating system is modified to cooperate with the hypervisor to manage the device. This model can be as efficient as the passthrough model, but it requires more work from the vendor of the guest operating system.
          * Not discussed? In wrong place?
        * **Passthrough Model:** In this model, the guest operating system has direct access to the physical device. This is the most efficient model, but it also makes it difficult to share devices between guest operating systems.
        * **Split Device Driver Model** is good for virtualizing devices by splitting the device access control between a front-end driver & back-end driver in a service VM.
          * **Centralization**: the back-end driver can be centralized making it easier to manage shared devices accesses.
          * **Complexity:** The front-end driver must be modified to work with the back-end driver.
          * **Paravirtualization:** This model is only applicable to paravirtualized guests.
          * **Performance** goes up & eliminates overheads associated with device simulation
    * Dynamic Binary Translation Technique
      * _History_: the guy who made it commercialized the technology as VMware.
      * Advantages over Static Binary Translation
        * Input Dependency
          * **Efficiency**: dynamic binary translation can be more efficient than static binary translation
            * Doesn't need to translate all the code up-front. Only the code that's actually executed is translated
          * The exact sequence of the code may depend on the parameter available at runtime, so it's not always possible to translate the code statically upfront
      * Goal
        * A technique for virtualizing processors that **addresses the limitations of trap & emulate techniques** by rewriting the VM's binary code to never issue privilege instructions that cannot be trapped & emulated.
          * Binary translator intercepts the execution of the original code, analyzes it, and generates a new version of the code without problematic instructions. The new code is executed instead of the original code.
        * Achieve full virtualization.
        * Allows the virtual machine to run w/o modifications to the guest OS.
      * Steps
        *
          1. Inspect Code Blocks
          2. As code is executed, the binary translator inspects each code block to determine whether it contains any of the problematic privileged instructions
        *
          2. Mark safe blocks
          3. If code doesn't contain problematic instructions, mark it as safe.
          4. Safe blocks can execute natively at hardware speeds.
        *
          3. Translate problematic blocks
          4. Translate into something that doesn't trigger a trap.
        *
          4. Cache Translated blocks for performance
    * Hardware Virtualization
      * **Adding root/non-root modes:** Providing two modes of operation, one for the hypervisor and one for the guest VMs.
      * **Adding VM control structures:** Providing hardware support for managing virtual processors (VCPUs).
      * **Closing holes in the ISA:** Fixing instructions that could not be trapped by the hypervisor.
      * **Enhancing memory management:** Adding features like extended page tables and tagged TLBs to improve memory virtualization.
      * **Improving I/O virtualization:** Adding support for multi-queue devices and interrupt routing.
      * **Strengthening security:** Providing hardware-based security features to protect VMs from each other and from the hypervisor.
    * Memory Virtualization (Full)
      * Page Tables
        * Guest Page Tables
          * Maintained by the guest OS
          * Maps virtual to physical addresses
        * Hypervisor Page Table
          * Maintained by hypervisor.
          * Maps physical to machine addresses.
      * Paravirtualied Memory Virtualization
        * In paravirtualized memory virtualization, the guest operating system does not need to use contiguous physical memory that starts at 0. The guest operating system can also explicitly register its page tables with the hypervisor, so there is no need for maintaining dual page tables.
        * Paravirtualized memory virtualization takes advantage of the fact that the guest operating system is aware that it is running in a virtualized environment. This allows the guest operating system to cooperate with the hypervisor to manage memory more efficiently.
      * Provides the guest OS with the illusion it has full control over the physical memory of the system.
      * Shadow Page Tables
        * Hardware MMU uses the shadow page table to translate virtual addresses to machine addresses.
        * Hypervisor maintains consitency between guest OS's page table & shadow page table.
          * Can be invalidated.
        * More efficient, but requires more work from hypervisor to maintain consistency between two page tables.
        * The hypervisor maintains a copy of the guest OS's page table.
      * Two-Stage Translation Implementation: every memory access goes through two separate translations:
        * First is done by software in the guest OS using its own page tables.
        * Second is done in hardware by the MMU using the hypervisor's page table.
        * Slow because every memory access requires two accesses.
      * Types of addresses
        * Machine Addresses (MA)
          * Actual address of the physical memory on the underlying hardware.
        * Physical Addresses
          * The address the guest OS thinks it is using to access physical memory.
        * Virtual Addresses
          * What apps see in the guest OS.
    * **Paravirtualization** is a type of virtualization that requires the guest operating system to be modified to work with the hypervisor.
      * Approach
        * Make explicit calls to the hypervisor to request desired behavior instead of directly perform operations which it knows will fail.
        * Use **hypercalls**
          * Allows the guest OS to perform privileged operations without having to trap to the hypervisor for every instruction.
          * Hypercalls are software traps that allow the guest OS to make requests to the hypervisor.
          * Package Context Info
            * When the guest OS makes a hypercall, it must package all relevant context information the hypervisor needs to process the request.
      * Goal
        * Doesn't require binary translation or other techniques to modify the guest operating system.
        * Performance
    * **Trap & Emulate Technique**
      * Execution of **Guest Instructions**
        * A guest instruction gets executed directly by hardware for efficiency.
        * Hypervisor doesn't interfere with every single instruction issued by the guest OS or its applications.
      * Handling of **privileged operations**
        * The hypervisor takes control & determines whether the operation is legal or illegal.
          * Illegal -> terminate VM.
          * Legal -> emulate behavior guest OS is expecting from the hardware.
      * If a privileged operation occurs, **trap** to hypervisor & either terminate the VM or if it's illegal or emulate expected behavior the guest OS expects
      * Problems on pre-2005 x86 Architectures
        * Had four protection rings, but no root/non-root modes.
        * Hypervisor ran in ring 0 & guest OS ran in ring 1.
        * There were still 17 privilege instructions that did not trap to the hypervisor & so it was unaware/unable to emulate them.
          * POPF/PUSHF modifies the interrupt enable/disable bit in a privileged register & would fail silently. This could lead to problems if the guest OS attempted to perform operations that could be interrupted.
      * What is it & How it works
        * The hypervisor controls the hardware & ensures the virtual machines are isolated from each other.
        * The technique traps privilege instructions and emulates them in software.
* W12 Remote Procedure Calls\
  Progress: 94%
  * Benefits\
    Progress: 100%
    * **Abstraction** of RPC hides network/communication complexities from programmers who can call it as if it were a local procedure.
    * **Efficiency**: can be implemented efficiently compared to bigger/other networking tasks.
    * **Transparency** makes it appear as if remote procedures are being called locally. The programmer doesn’t need to worry about the details of how the procedure is actually called on the remote computer.
  * Client/Server IPC Interactions\
    Progress: 100%
    * Call
      *
        1. Bind
        2. **Binding** is a mechanism used by the client to know which name & server to connect to. It’ll check the service name & version too.
           * Binding is normally done through IP addresses & network packets, but it can be anything.
        3. **Pointers**: must not be allowed or must be used _only_ in the RPC run-time
        4. **Registry** is abstract in this case, but holds information about how clients can find information about the service they need, which IP addresses to use, etc.
           * Simple: clients must specify exact name & number of the required service.
           * Sophisticated Naming: consider the facts & words like summation, sum, and addition are likely equivalent to the use of the word _add_.
        5. Examples
           * Compression servers.
           * Image processing.
        6. SUN RPC Binding
           * The binding process is the process by which a client establishes a connection with a server.
           * The clnt\_create() function returns a client handle, which is used to make RPC calls to the server.
           * To bind to a server, the client uses the clnt\_create() function. This function takes a number of parameters, including the host name of the server, the name of the RPC service, the protocol that the client wants to use, and the version number of the RPC service.
      *
        2. Call
      *
        3. Marshall
        4. **Marshalling** is the process of converting data into a format that’ll be transmitted over a network.
        5. **Serializing** means converting the data into a format that can be transmitted over a network.
           * Converts data
        6. Modifies the buffer which gets generated by the marshaling code.
        7. RPC system linker will link the executable code?
        8. Serializes arguments of the procedure into contiguous memory locations
        9. Uses `rpc.add()`
      *
        4. Send
        5. Send the **”marshalled”** procedure parameters to the server.
    * Execute
      * 5\. Receive
        * Receive marshaled procedure parameters from client.
      *
        6. Unmarshal
        7. Convert buffer from network protocol => parse out the byte stream => Rebuild appropriate data structures
        8. Unmarshals parameters back to their original format
      *
        7. Execute & Return results to the client.
    * Return
      * 8\. Unmashall
        * Client program “unmarshals” the results of the remote procedure.
      *
        9. Return
        10. Client program returns result of the remote procedure to the caller.
  * Interface Definition Languages\
    Progress: 100%
    * **Interfaces** describe what a server **exports**. Exports include:
      * Result type
      * The name of the procedure
      * Type of arguments
      * Version Number
    * Language-Agnostic
      * Developers use IDLs or IDL-Lists to know what the server does, what arguments are required for the various arguments, etc.
  * _Overview_\
    Progress: 100%
    * **Example**: Arithmetic Multiply/Add Example
      * Client doesn’t have the implementation of the addition process. Only the server knows how to do it.
      * Program could call a remote procedure on another server computer to perform the mutiplication.
      * The client program would send the two numbers to the server & the server returns the result.
      * When the RPC call is added, the execution of the program will also jump to another location in address space. (It won’t be where the real implementation, just a **sub implementation**.
    * **Remote Procedure Calls (RPCs)** are a way for programs to call subroutines/functions on another computer on a network without having to know the details of the network or remote computer. It makes **distributed applications** easier.
  * Requirements\
    Progress: 100%
    * Client & Server Interactions
    * Cross Machine Conversion
    * Higher Level Mechanisms
    * Procedure Call iInterface
    * Type checking mechanisms that Optimize RPC?
      * Better errors
  * RPCGEN Mechamisms\
    Progress: 66%
    * Flags\
      Progress: 100%
      * \-C flag generates code that's not thread safe.
        * Output results in a function that will need to be called y=squareproc\_1\`
        * This leads to race conditions when multiple threads are trying to make RPC calls to this routine.
      * \-M generates thread safe code.
        * Avoids issues that can occur with the non-thread safe implementation.
        * Creates a wrapper funciton for each RPC routine that's thread safe.
        * The wrapper function will dynamically allocate memory for the results ofthe operation
      * `./usr/sbin/rpcinfo-p`
        * Squrae Operation Example
          * Once the client has bound to the server, it can make RPC calls to the server by calling the appropriate client stub functions.
          * The following example shows how to use the rpcinfo-p command to find the port number of the square RPC service and then use the clnt\_create() function to bind to the server:
        * This will output a list of all of the RPC services that are registered with the portmapper, along with their program ID, version number, protocol, socket port number, and service name.
        * Used to query the portmapper for information about RPC services running on the network
    * Generates & Compiles output files\
      Progress: 0%
      * Compiles source code written in the RPC language which is very similar to the syntax/structure of C.
      * Developer Provides...
        * All `.h` headers, particularly the auto-generated ones from the RPCGEN comiler.
        * Dev must use the stub object to link the client & server code.
        * For client-side
          * Dev must make client application & whenever necessary, call the wrapper function
        * For the server side application
          * Implementation of the actual service procedure
      * How to generate RPC interface modules using RPCGEN?
        *
          1. Create a `.x` file that contains the RPC program specification. This file is written int he RPC language & describes the procedures available to clients as well as the data types that are used in the RPC calls.
        *
          2. Run RPCGEN compiler on the `.x` file. It'll generate the 4 output files described
        *
          3. Compile the client stub & server stubs using a C compiler.
        *
          4. Link the client stub & server stub programs with the RPC runtime library
        *
          5. Stat the RPC server program
        *
          6. Run the RPC client program.
      * Output Files Created
        * Client Stub
          * **Client stub:** The client stub program is responsible for marshalling and unmarshalling arguments, and sending and receiving RPC requests and responses. It does this by calling the appropriate RPC runtime functions. The client stub program also provides a wrapper function for each RPC procedure. This wrapper function makes the RPC call to the server and returns the results to the client.
          * Responsible for mashalling & unmarshalling arguments & sending/receiving RPC requests/responses.
        * Header file (containing definitions common to server/client)
          * **Header file:** The header file contains definitions for all of the data types and function prototypes that are used in the RPC program. This file is included by both the client stub and server stub programs.
        * Server Stub is responsible for:
          * **Server stub:** The server stub program is responsible for receiving RPC requests, unmarshalling arguments, calling the appropriate server procedure, and marshalling the results. It does this by calling the appropriate RPC runtime functions. The server stub program also provides a skeleton for the server procedure. The developer must fill in the skeleton with the implementation of the server procedure.
          * Calling appropriate server procedure
          * Re-Marshaling the results of whatever was ran.
          * Receiving the RPC requests
          * Unmarshalling args
        * XDR Compilation Routines
          * Data Types
            * Additional XDR Types (const, hyper, quadruple, opaque)
            * Default Types (in C: char, byte, int, float)
            * Fixed-Length Arrays
              * Represented in XDR by their length & the elements of the array.
              * RPC runtime will allocate the corresponding amount of memeory when arguments of this data type are sent/received
            * Variable Length Arrays in XDR are represented by a data struct with the fields:
              * `len` corresponds to the actual size of the array
              * `val` is a pointer to the memory location where the data in the array is stored.
          * Encoding
            * Rules
              * **Big Indian** is the transmission standard.
              * All data types are encoded in multiples of 4 bytes.
              * IEEE format is used for floating point.
              * Two's complement is used for integers.
            * Steps
              *
                1. The RPC header is encoded. This includes the service procedure ID, version number, and request ID.
              *
                2. The arguments to the RPC procedure are encoded.
              *
                3. The results of the RPC procedure are encoded (if any).
              *
                4. The encoded data is placed in a packet, which is then preceded with the transport header.
              *
                5. The packet is transmitted to the server.
          * Purpose
            * **XDR routines:** The XDR routines are responsible for marshalling and unmarshalling data types from the host platform representation into XDR format, and vice versa.
            * XDR is a **standard format** for representing data in a way that is independent of the underlying platform. This allows RPC programs to be portable across different platforms.
      * RPC Functoinality
        * Creating Sockets
        * Interactions with the OS
        * Managing Connections
    * Portmapper\
      Progress: 100%
      * ./sbin/portmap (needs pseudo privileges)
      * The portmapper can be started with the following command:
      * The portmapper is a process that runs on every machine in a Sun RPC network. It is responsible for maintaining a registry of all of the RPC services that are running on the network.
      * When a client wants to call an RPC procedure, it first contacts the portmapper to find out the port number that the server is listening on.
* W13 Distributed File Systems DFSs\
  Progress: 100%
  * Abstractions\
    Progress: 100%
    * Definition
      * File system
      * Spans multiple servers or storage nodes.
    * Enables:
      * Users can access files from any device on the network as if it were stored locally.
    * Requirements
      * Availability
      * Reliability
      * Scalability
  * Mechanisms\
    Progress: 100%
    * Caching State
      * Caching is a common optimization technique in distributed systems.
      * Clients can perform some operations on the cached state locally (e.g. open, read, write)
      * Requires coherence mechanisms to ensure consistency across clients.
    * Coherence Mechanims\
      Progress: 0%
      * Communication costs & latencies in distributed systems make real-time coherence challenging.\
        Progress: 0%
      * File sharing semantics options\
        Progress: 0%
        * ...
          * • Immutable files: Files are never modified; new files are created.
          * • Periodic updates: Clients write back periodically or the server invalidates periodically.
          * • Session semantics: Writes are visible within a session (between open and close).
          * • Transactions: The file system provides APIs to treat a collection of files/operations as a transaction, guaranteeing atomic changes.
          * • UNIX semantics: Every write is visible immediately.
          * Single node
      * Triggers for Coherence Mechanisms\
        Progress: 0%
        * Client/Server Driven
        * On Open\
          Progress: 0%
        * On-Demand
        * Periodic
      * Write Update & Write Invalidate
        * Problem: clients 1 & 2 both cache a portion of file F & client 2 modifies F’ and updates the server such that client 1 needs to be notified by the change.
    * DFS Extreme Models
      * Ideally a mix:
        * **Cons**: requires additional consistency management.
        * How it works
          * Clients store portions of files locally for faster access.
        * **Pros:** reduced latency & server load.
      * True Remote File Access
        * **Advantages**: centralized control & knowledge of the file access and modification
        * **Disadvantages**: results in network latency & limit server scalability. Also latency for repeated read operations.
        * How it works
          * Every file operation is performed on the server
          * Maintains centralized control & consistency
      * Upload & Download
        * **Advantages:** fast local reads/writes
        * **Disadvantages**: the entire file transfers for small operations & server relinquishes control over file operations. Can lead to inefficient network traffic & server load
        * **Examples:** FTP and SVN
        * The entire file is transferred between the client & server for each operation
    * Partitioning
      * Benefits
        * Data Locality
          * By keeping related data partitions on the same node, partitioning can minimize data movement & improve performance for applications that access specific data subsets frequency.
        * Parallel Processing
          * Parallel processing tasks can be executed on different nodes, improving overall processing efficiency.
        * Scalability
          * You can handle increased traffic by adding more nodes & distributing data across them.
      * Divides a large dataset into smaller manageable chunks and distributing them across multiple nodes.
    * Replication
      * Benefits
        * Geographic Distribution
          * Reduces latency for users in different regions
        * High Availability
          * If one node fails, other replicas remain available
          * Uninterrupted data access
        * Load Balancing
          * By spreading data across multiple nodes, replication can distribute read/write requests
          * Reduces the load on individual nodes & improves overall system performance.
      * Involves maintaining multiple copies of the same data across multiple storage nodes in the DFS.
    * Stateful & Stateless Servers
      * Qualities of **Stateful** Servers
        * **Advantages:** allows caching and consistency management. Also supports locking & incremental operations.
        * **Disadvantages**: complex state recovery mechanisms on failure. Also runtime overheads due to caching & consistency requirements.
        * **Examples:** NFS, AFS
        * This server maintains information about clients and file access, enabling caching and consistency management. However, it requires more complex state management and can be more susceptible to failures.
      * Qualities of **Stateless** Servers
        * **Advantages**: suitable for upload/download and true remote file access models. Simpler implementation. Resource-efficient on the server side.
        * **Disadvantages:** prevents caching & increases request size.
        * Doesn’t maintain information about clients or their file access patterns
        * **Examples**: FTP & HTTP
        * Requires self-contained requests with all necessary parameters
        * This server does not maintain any client or file access information, making it suitable for the upload/download and true remote file access models. However, it cannot support caching and consistency management.
    * Virtual File System (VFS)
  * Models\
    Progress: 100%
    * Client-Server
      * 1+ clients access files
      * 1+ servers store files
    * Peer to Peer
      * All machines can store & serve files
  * Networking File System (NFS)\
    Progress: 100%
    * Caching Semantics
    * Client/Server DFS Model
    * Locking Semantics
    * Nfs file handler
    * Uses TCP/IP Protocol
  * Sprtie Distributed File System\
    Progress: 100%
    * File operations
* W15 Distributed Shared Memory\
  Progress: 100%
  * Design\
    Progress: 100%
    * ABSTRACT
      * DSM owns memory state & provides memory read/writes from any node.
      * Manages memory across multiple memory nodes to create the illusion of running on a shared memory machine.
      * Requires consistency protocols to hide access differences & provide low latency.
    * Access Algorithm
      * **Access Latency Concerns** are reduced with migration and replication (caching) to achieve low latency.
      * Multiple Readers / Multiple Writers
      * Single Reader / Single Writer (SRSW)
    * Consistency Management
      * How do you manage synchronization in shared memory multiprocessors?
        * Pull Invalidations
        * Push Invalidations
        * Terminology
          * Eager
          * Lazy
          * Optimistic
          * Proactive
        * Write-Invalidate Mechanism
        * Write-Update Mechanism
      * What is false sharing?
        * False sharing occurs when two write accesses to the same page trigger unnecessary coherence operations.
    * Consistency Models
      * Consistency Modes: Casual Consistency
        * ...
          * Forcing all processes to see the exact same order on all updates may be an overkillUpdates can be independent and causally relatedCausal consistency models guarantee correct ordering of causally related updates
      * Consistency Modes: Sequential Consistency
        * ...
          * Memory updates from different processors may be arbitrarily interleavedAll processes will see the same interleavingOperations from same process always appear in the order they were issued
      * Consistency Modes: Strict Consistency
        * Every single update must be immediately everywhere visibleOrdering of updates needs to be preservedIn SMP, no guarantees on order without extra locking and synchronizationIn DSM, latency and message reorder/loss make this even harder → impossible to guarantee
      * Consistency Modes: Weak Consistency
        * ...
          * Updates can have synchronization pointsNo guarantee of order between synchronization pointsVariations: single sync operation, separate sync per subset of state, separate "entry/acquire" vs "exit/release" operations
      * Mechanisms for consistency models.
        * Access ordering
        * Memory (state) guarantees to behave correctly if software follows specific rules & access ordering.
        * Propagation & Visibility of Updates
      * Our Notation
        * ...
          * R\_m1(x) == x was read from memory location m1W\_m1(y) == y was written to memory location m1Initially all memory is set to zeroValue y was written to m1Value z was written to memory location m3
    * Paged-Based Architecture
      * Explicit replicas can be used for load balancing, performance, or reliability.
      * Home Node keeps track of page ownership & manages access and caching
      * Nodes with their own family contribute to the DSM Service
  * Implementations\
    Progress: 100%
    * Common Tasks
      * Address translation
      * Sharing granularity can be:
        1. Cache-Line
        2. Object
        3. Page
        4. Variable
        5. Cache-Line is divided into small chunks & each process can only access a specific cache line. (Pages are larger)
        6. Granularity is the detail at which a resources is divided or allocated.
    * Hardware
      * Relies on advanced interconnect technology & larger physical memory managed by the OS
    * Issues
      * ...
    * Metadata
      * Manager Maps
        * Available on every node.
        * Per-page metadata is distributed across managers.
      * Manager Types???
        * Fixed Manager
      * Pages have an address. Its consists of:
        * Node ID
        * Page Frame Number
      * What does the **global map** contain?
        * Object (page) ID -> Manager Node ID
    * Software
      * Can be implemented in OS level or programming language & runtime libraries.
      * Message passing & memory operations.
  * Peer Distributed Applications
* W16 Datacenter Techs
  * Ain’t nobody got time for that
