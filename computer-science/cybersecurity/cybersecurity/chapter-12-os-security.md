# Chapter 12: OS Security

## 12.1: Introduction

* The **SMM** stands for the System Management Module. Before the operating system takes over and gets booted up, you can put an intel chip into a different configuration and have extremely low-level access to the chip before the operating system boots up.

![](<../../../.gitbook/assets/image (622).png>)

* The **TPM** makes sure that the firmware of BIOS/SMM doesn't change.&#x20;
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

![Source: Dr. Baldwin's slides.](<../../../.gitbook/assets/image (621).png>)

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
   3. Intrusion detection systems (IDS)
4. Test the security of the basic OS to ensure that the steps are taken adequately address its security needs.

{% hint style="info" %}
We'll be doing #2 in the project. Remove unnecessary services/apps/ports/groups/users/permissions/resource controls.
{% endhint %}

### OS Installation: Initial setup and patching.

![](<../../../.gitbook/assets/image (620).png>)

1. Be disconnected from the network.
2. Install minimum necessary for the desired system.
3. Password protect the overall boot process (like secure your bios)
   1. Don't boot from DVD/USB
4. Secure integrity/source of device drivers.
5. Keep the system up to date
   1. There are tools you can use to make sure patches are up-to-date.
   2. Test patches to make sure it doesn't create a security flaw before deploying them in production.

### Remove Unnecessary Services/Apps/Protocols

| Action                               | Why?                                                                                                 |
| ------------------------------------ | ---------------------------------------------------------------------------------------------------- |
| Don't use defaults                   | Default configurations maximize ease of use rather than security.                                    |
| Restrict Privileges                  | Only give elevated privileges to those when they are needed to perform the task.                     |
| Remove Default Accounts              | Windows/Linux has a guest account. Don't use default usernames/passwords and disable those accounts. |
| Configure Resource Controls          | Set permissions so randos can't access things they shouldn't be able to.                             |
| Install Additional Security Controls | Anti-virus software. Host-based firewalls.                                                           |
| Test the system security             | There are specific programs that do this automatically. It'll probe your system in known ways        |

* Default configurations are intended to maximize ease of use than security.

### Configure Users/Groups/Authentication

### Application Configuration

### Encryption Technology

![Dr. Baldwin's Slides](<../../../.gitbook/assets/image (619).png>)

* Encrypt your file system.
* Encrypt SSH keys.

## Interlude

* Shodan.io: resource for finding open things on the internet.

## 12.5: Security Maintenance

### On Logging

1. Logs can only inform you about bad things that already happened.
2. Logs help system administrators figure out what happened more quickly.
3. Range of data acquired: you can/should tailor which information you want logged.
4. **Automated analysis** is preferred.&#x20;
5. Logs generate a large amount of information, so it's important space is allocated to them.

### Data Backup and Archive

* There are legal and operational requirements for the retention of data.
* **Backup**: making copies at regular intervals
* **Archives**: kept for regulatory/legal purposes.

{% embed url="https://en.wikipedia.org/wiki/9_track_tape" %}
Mediums are out of date.
{% endembed %}

## 12.6: Linux/Unix Security

### Patch Management

* Make sure everything is updated.
* If they can subvert patch servers like Microsoft/Apple servers that push out patches, then they can subvert the entire universe.

### Application and Service Configuration

* Most commonly implemented using separate text files for each application/service.
* Most of the configs are stored in readable text files located in the `/etc` directory.
* Disable services and remove applications that are not required because it reduces the attack surface available for hackers to subvert.

{% hint style="info" %}
**Project**: Disable which are essential for Unix to run and what can I remove. First, disable the FTP service and disable the port it uses too.
{% endhint %}

### Users, Groups, and Permissions

* Checkout the users list. It'll probably have a bunch of users that don't need to be there.
* Guides recommend changing the access permissions for critical files and directories.
* **Local exploit:** a software vulnerability that can be exploited by an attacker to gain elevated privileges.
* **Remote exploit**: software vulnerability in a network server that could be triggered by a remote attacker.

### Remote Access Controls

* Most systems provide an administrative utility to select which services will be permitted to access the system.

### Logging and Log Rotation

* It's almost invariably true that the default configuration for the logging on the system is not appropriate for what you needed.

### Chroot Jail

* This is an operating system utility that forces a particular view into the directory hierarchy.
* `chroot` makes something else look like a root directory. There's a pseudo root directory, and so if a hacker tries to subvert your software, when it references root.
* It gives an app a fake root. It's the process by mapping the root of the file directory to somewhere else.
* Disadvantage: added complexity.

## 12.7: Windows Security

### Patch Management

* Various DNS attacks try and redirect you to a different server then you're expecting.
* 3rd party applications use the _Windows Update_ service but other times, they use their own.

### Users, Groups, and Permissions

#### Integrity

* **Mandatory Integrity Controls**:&#x20;
* **Integrity Levels**: the windows system will not let it write any information to higher levels.
* **Biba Integrity Model**: Biba was a researcher. It basically makes sure that objects with low integrity levels aren't messing with things of high integrity levels.

![Integrity Controls](<../../../.gitbook/assets/image (626).png>)

#### Low Privilege Service Accounts

* Used for long-lived service processes such as file, print, and DNS services.

### Application and Service Configuration

* Much of the configuration information is centralized in the registry.
* **Registry**: forms a database of keys/values that may be queried and interpreted by applications.
* Registry keys can be directly modified using the registry editor.

### Other Security Controls

* Anti-virus
* Anti-spyware
* Personal firewall
* Cryptographic functions
  * AES using BitLocker
  * Encrypting files/directories using the EFS (Encrypting File System) service.
* Microsoft Security Compliance Toolkit
  * Free tool checking for compliance with Microsoft's security recommendations.

## 12.8: Virtualization Security

* Virtualization provides an abstraction fo the resources used by some software running on a virtual machine.
* Benefits include better efficiency int he use of physical system resources.
* Provides support for multiple, distinct operating systems.

### Virtualization Alternatives

![](<../../../.gitbook/assets/image (628).png>)

### Native Virtualization

Native virtualization&#x20;

![](<../../../.gitbook/assets/image (625).png>)

### Host Virtualization

Whatever you install it on,&#x20;



![](<../../../.gitbook/assets/image (627).png>)

### Virtualization Security Issues

* **Guest OS Isolation**: the host can only access/use the resources allocated to it (and nothing more).
* Guest OS monitoring by the hypervisor: this has privileged access to the programs/data in each guest OS.
* Virtualized environment security: particularly image and snapshot management which attackers may attempt to view/modify.

### Securing Virtualization Systems

* It's an operating system, so all of these things&#x20;

## Works Cited

* Baldwin, Rusy. _Cyber Security Fundamentals._ Operating System Security. Fall 2021.
* Stallings, William, and Lawrie Brown. _Computer Security_. Available from: VitalSource Bookshelf, (3rd Edition). Pearson Education (US), 2014.
