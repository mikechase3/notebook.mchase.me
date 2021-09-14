# Chapter 12: OS Security

## 12.1: Introduction

* The **SMM** stands for the System Management Module. Before the operating system takes over and gets booted up, you can put an intel chip into a different configuration and have extremely low-level access to the chip before the operating system boots up.

![](../../.gitbook/assets/image%20%28622%29.png)

* The **TPM** makes sure that the firmware of BIOS/SMM doesn't change. 
* **Physical hardware:** has a series of gates that you can re-configure the hardware on-the-fly. An `FPGA` has an array of gates with no particular configuration, but you can reconfigure them on-the-fly and corrupt the physical hardware.
  * Also... who is building these circuits?
  * Can China build it in a way that compromises US systems?
  * Can they have back-doors and listen to US communications?

### General Guidelines

1. White-list approved applications.
2. Patch third-part applications and operating system vulnerabilities
3. Restrict administrative privileges.
4. Create a defense-in-depth system.

### OS Install: Initial Setup and Patching

* It's possible to get compromised during the installation process.
* When building/deploying a system, you should be disconnected from the internet.

## 12.2: System Security Planning Process

* _**The first step in deploying a new system is planning.**_
* Where should we include a wide security assessment?
* Maximize security & minimize costs.
* Who is going to be responsible for the responsibility of this system?
* Identify all appropriate personnel and training to install/manage the system.

![Source: Dr. Baldwin&apos;s slides.](../../.gitbook/assets/image%20%28621%29.png)

## 12.3: Operating System Hardening

### How to Secure the Base System

1. Install/patch the OS.
2. Harden/configure the OS to adequately address the identified security needs of the system:
   1. Remove unnecessary services/apps/ports
   2. Configure users/groups/permissions
   3. Configuring resource controls.
3. Install and configure security controls
   1. Anti-virus
   2. Host-based firewalls
   3. Intrusion detection systems \(IDS\)
4. Test the security of the basic OS to ensure that the steps are taken adequately address its security needs.

{% hint style="info" %}
We'll be doing \#2 in the project. Remove unnecessary services/apps/ports/groups/users/permissions/resource controls.
{% endhint %}

### OS Installation: Initial setup and patching.

![](../../.gitbook/assets/image%20%28620%29.png)

1. Be disconnected from the network.
2. Install minimum necessary for the desired system.
3. Password protect the overall boot process \(like secure your bios\)
   1. Don't boot from DVD/USB
4. Secure integrity/source of device drivers.
5. Keep the system up to date
   1. There are tools you can use to make sure patches are up-to-date.
   2. Test patches to make sure it doesn't create a security flaw before deploying them in production.

### Remove Unnecessary Services/Apps/Protocols

| Action | Why? |
| :--- | :--- |
| Don't use defaults | Default configurations maximize ease of use rather than security. |
| Restrict Privileges | Only give elevated privileges to those when they are needed to perform the task. |
| Remove Default Accounts | Windows/Linux has a guest account. Don't use default usernames/passwords and disable those accounts. |
| Configure Resource Controls | Set permissions so randos can't access things they shouldn't be able to. |
| Install Additional Security Controls | Anti-virus software. Host-based firewalls. |
| Test the system security | There are specific programs that do this automatically. It'll probe your system in known ways |

* Default configurations are intended to maximize ease of use than security.

### Configure Users/Groups/Authentication

### Application Configuration

### Encryption Technology

![Dr. Baldwin&apos;s Slides](../../.gitbook/assets/image%20%28619%29.png)

* Encrypt your file system.
* Encrypt SSH keys.

## 12.5: Security Maintenance



## Works Cited

* Baldwin, Rusy. _Cyber Security Fundamentals._ Operating System Security. Fall 2021.
* Stallings, William, and Lawrie Brown. _Computer Security_. Available from: VitalSource Bookshelf, \(3rd Edition\). Pearson Education \(US\), 2014.

