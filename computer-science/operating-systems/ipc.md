# Inter Process Communication
* From week 7
* 7-1 is on flash cards only for now. It discusses:
  * Pipes (1-way, POSIX, easiest)
  * Messaging (requires more sys calls)
  * Shared RAM (fast for large amounts of data)
  * Sockets (good for networking)

----
7.2 is below:
* **Message passing** requires the CPU to copy so it's slow for large amounts.

## On Shared Memory
Each stage is slightly different.

### On Create
* When it's created, the OS allocates the required amount of physical memory
and assigns it a unique key.
* The process that creates it is given that memory key.
* Other processes can refer to that segment using the key, but it must be passed by the creating process
  * Oftentimes a command line argument
  * Sometimes passed through a file or other options.

### On Attach
* Multiple processes can **attach** to the same shared memory segment.
* Eachprocess ends up sharing access to the same physical pages.
* Reads/writes are visible across the process like when threads share access to memory in the same space.
* Shared memory can be mapped to different virtual addresses in different processes.

### On Detach
* This means invalidating the address mappings for the virtual address region
    that corresponded to that segment within the process.
* Table entries for those v irtual addresses won't be valid.
* The segment isn't destroyed once detatched.
* Segments can be attached, detached, and re-attached again multipe. times by different processes during its lifetime.

### On Destroy
* There must be an explicit request for memory to be destroyed.
* ShAlso happens during reboot.


### Shared Memory API Calls
* `shmget(shmid, size, flag)` creates/opens memory. OS assigns a unique key.
* `ftok(pathname, prg-id)` attaches and maps virtual to physical.
  * This is how different processes can agree upon how they'll obtain a unique key for the shared mem segment they'll use to communicate
* `Shmat(shmid, addr, flags)` detaches/invalidates an address mapping
  * To attach the shared memory segments into the virtual address space of the process:
  * The programmer passes a specific virtual address where the segment to be mapped or NULL where OS chooses some arbitrary addr for the process.
* `Shmdt` or `shmdt(shmid, cmd, buf)` destroys with `IPC_RMID`
  * wITHOUT args, this detaches the sgement so the virtual -> physical mapping is no longer valid.
  * With the `cmd` and `buf` args, we can remove a particular segment?
  * HELP: What's the difference

## POSIX Shared Memory API
There's some commands here. Go view/record them. 