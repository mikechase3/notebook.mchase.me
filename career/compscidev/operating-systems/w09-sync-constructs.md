# W09 Sync Constructs

## Hardware Techniques

### **Cache Coherence** is the discipline ensuring that changes in the values of shared operands are propagated throughout the system in a timely fashion. The programmer doesn't get to choose between cache invalidate or update because that's a property of the hardware architecture.

* **Non-Cache-Coherence**
  * Solve inconsistencies by implementing **non-cache-coherent architectures** for platforms that don't support it (in hardware?)
* Caches
  * Caches speed up & reduce latency
  * Latency is even more of an issue in shared memory systems because of contention on the memory module
* Inconsistencies in data values across different CPUs is bad.
* On cache-coherent platforms, hardware will take care of everything and make life easy
* When you change something in one cache of a CPU, propagate that to RAM & the other CPU caches.
* WRITE: what happens when CPUs perform a write?
  * **Write Invalidate** occurs when we try to call something from cache, but it was already invalidated and updated elsewhere so it has to retrieve it from RAM
    * "Amortized Cost"
    * When a processor writes to the cache line, it'll send an invalidate command to all the other caches that have a copy of the same cache line.
      * Lower bandwidth requirements on the interconnect
      * We don't have to send the full values, just the adddress to invalidate
  * **Write Update** Corrects the caches in all CPUs so we get more cache hits.
    * Data is available immediately on other CPUs needing to access it.
    * No cost to perform another memory access in order to retrieve the latest value of 'x'
  * **Write-Back**
    * Efficient & reduces number of writes to main memory.
    * Requires additional logic to ensure that all copies of a cache line are updated when one copy is modified.
    * Writes to **cache** only, at least, initially.
      * Then, writes to memory location when that cache line is evicted (or some later time)
  * **Write-through** protocol
    * Ensures the data in the main memory is always up-to-date
    * Slow due to the overhead of writing to main memory on every write operation.
    * Writes directly to memory. Every write operation to a cache line is immediately propagated to main memory
      * Writes to cache too
  * You might not allow a write to happen to the cache. It'll write directly to memory and any cached copy of that particular memory location will be invalidated.

### For Shared Memory Multiprocessors (SMPs)

* Bus-Based
  * Common in current systems
  * One memory reference
  * The bus is shared across all modules
  * Uses a single memory model
* Interconnected (IC) Based
  * Could have multiple memory references or one memory reference for each memory module
  * Older systems

## Software Techniques

### **Atomic Instructions** are special instructions guaranteed to execute "atomically," meaning they can't be interrupted by another CPU. It's usually **implemented** using hardware support, but can also be implemented using software techniques

* Examples of Atomic Instructions
  * Compare & Swap
  * Read & Increment
  * Spinlock Improvements
    * **Test-and-test-and-set spinlock** solution or spin-and-read spinlock. There's a separate test which is checking from the atomic parts by using caches & testing the caches copy of the lock. Only perform atomic if cache indicates it's cleaned/changed.
      * A little more latency/delay because of the extra check whether the lock is busy/not that hits the cache.
      * Comparison
        * Worse performace on multicore/multiprocessors because everyone will see the lock has changed its state & try to acquire the lock at the same time.
      * Contention
    * Analysis
      * Heavy=High & Low=Light loads meaning there’s little contention for the lock.
      * Queuing locks are fair & scalable, but has high latency as it requires an atomic read & increment operation to acquire the lock. It’s a good choice for high loads when fairness/scalability are more important than latency.
      * Test & set has high overhead under high loads because it causes a lot of cache invalidation.
      * • Static delay alternatives: These spinlock implementations are a good compromise between latency and overhead under high loads. However, they can lead to wasted cycles under light loads if the two processors that have the smallest and largest delays are the only ones contending for the lock.\
        • Dynamic delay alternatives: These spinlock implementations have low overhead under high loads because they avoid collisions between processors. However, they have medium latency because they require a random delay to be generated before acquiring the lock.
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

### Locking Mechanisms

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
*   Reader/Writer Lock Mechanism

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
