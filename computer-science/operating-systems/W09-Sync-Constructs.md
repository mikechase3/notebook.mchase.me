# W08 & 09 Synchronization Constructs  
  
## Atomic Instructions  
  
Progress: 50%  
  
### Examples of Atomic Instructions  
  
Progress: 50%  
  
* Compare & Swap  
* Read & Increment  
* Test & Set  
    * Different architectures perform this more efficiently & some don't support it at all.  
    * The `test_and_set()` returns 0 for the first thread that acquires the lock.  
  
### Guarantees:  
  
* Atomicity  
* Mutual Exclusion  
* Queue all concurrent instructions but one.  
  
### Hardware helps this happen atomically.  
  
### Sometimes problematic when on different CPUs and can overlap  
  
## Shared Memory Multiprocessors (SMPs)  
  
### Bus-Based  
  
* Common in current systems  
* One memory reference  
* Uses a single memory model  
  
### Caches  
  
* **Cache Coherence** is the discipline ensuring that changes in the values of shared operands are propagated throughout the system in a timely fashion. The programmer doesn't get to choose between cache invalidate or update because that's a property of the hardware architecture.  
    * Inconsistencies in data values across different CPUs is bad.  
    * On cache-coherent platforms, hardware will take care of everything and make life easy  
    * When you change something in one cache of a CPU, propagate that to RAM & the other CPU caches.  
    * **Write Invalidate** occurs when we try to call something from cache, but it was already invalidated and updated elsewhere so it has to retreive it from RAM  
        * "Amortized Cost"  
        * Lower bandwidth requirements on the interconnect  
        * We don't have to send the full value of x, just it's address so it can be invalidated in other caches  
    * **Write Update** Corrects the caches in all CPUs so we get more cache hits.  
        * Data is available immediately on other CPUs needing to access it.  
        * No cost to perform another memory access in order to retrieve the latest value of 'x'  
* Caches speed up & reduce latency  
* Latency is even more of an issue in shared memory systems because of contention on the memory module  
* **Non-Cache-Coherence**  
    * Solve inconsistencies by implementing **non-cache-coherent architectures** for platforms that don't support it (in hardware?)  
* What happens to caches & memory when we write to it?  
    * **Write-Back**  
        * First writes to cache  
        * Then, writes to memory location when that cache line is evicted (or some later time)  
    * **Write-through**  
        * Both... writes to memory &  
        * Writes to cache  
    * You might not allow a write to happen to the cache. It'll write directly to memory and any cached copy of that particular memory location will be invalidated.  
  
### Interconnected (IC) Based  
  
* Could have multiple memory references or one memory reference for each memory module  
* Older systems  
  
### The bus is shared across all modules  
  
## Sync Mechanisms  
  
### Barriers  
  
* "like a reverse of semaphores"  
* Allows multiple threads to wait for each other at a particular point in the execution of a program  
* Ensures no thread proceeds until **n** threads have reached the barrier point  
    * After which, it's lifted & threads proceed  
    * Note: rendezvous points are when **all** threads arrive.  
  
### Monitors  
  
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
  
### Path Expressions  
  
* As opposed to locks, the programmer would specify 'many reads' or 'single write'  
* Require programmers specify a regular expression capturing the right synchornization behavior  
* The runtime ensures that the way the operations access the shared resource match what's in the **regular expression**  
  
### Reader/Writer Lock Mechanism  
  
Also referred to as shared and exclusive locks.  
  
* Operations  
    * **upgrade()** lets an owner of a shared lock convert it from reader -> writer  
        * Better than releasing & trying to re-acquire it and contend with other threads.  
    * Usage on Linux:  
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
  
### Rendezvous Points  
  
* A sync construct that waits for multiple threads to meet that particular point in execution.  
* Unlike barriers, rendezvous points wait for **all threads** to arrive before allowing any thread to proceed.  
  
### Semaphores  
  
* Used to protect shared resources from concurrent ccess by multiple threads  
    * Often used to protect critical sections of a code.  
    * Oftentimes used to signal between threads  
* Uses a counter used to control access to shared resources  
    * Allows `n` threads to proceed before it blocks other threads via a barrier.  
  
### Serializes  
  
* Hides explicit use of condition variables from the programmers  
* Hides the need for explicit signaling  
* Makes it easier to define priorities  
  
### Spinlocks (Primitive)  
  
* Polls constantly & wastes CPU cycles checking if the lock get unlocked.  
* Simple, Basic  
    * Used to make more complex synchronization mechanisms.  
* Uses mutual exclusion with lock/unlock mechanisms  
  
### Wait-Free Synchronization  
  
* Makes programs more scalable & efficient at the cost of potential conflicts due to concurrent writes.  
* Read-Copy-Update (RCU) Lock  
    * Part of the linux kernel.  
    * Underlying hardware supports to make  
