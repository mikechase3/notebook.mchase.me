# CAC Configuration

I decided to spend 2hrs of my time figuring out how to login to my government email instead of studying for my Geology test. i thought it'd be simple, but I was wrong; however, the process wasn't too bad.

Here's the general process:



## General Process

1.  Install packages:&#x20;

    ```
    sudo apt-get install libpcsclite1 pcscd pcsc-tools
    ```


2.  Check to see if your CAC works:&#x20;

    ```
    pcsc_scan
    ```


3. Get the DOD Certificates. Where? Idk, but I have a copy at `Active\ Documents/17th\ Grade/Work/Air\ Force/CAs`
4. Locate and download `cackey`. There's a `.deb` file you can get. Google around.
5. Go to Firefox => Settings => \<search> Certificates
   1. Load the certificates in, one by one.
   2. Load the driver. Use `dpkg --contents <cackey_package_location.deb`> which will reveal the location of where it got installed.
   3. Hit Load and navigate to the driver. My linux installation dropped it in `/usr/lib64/libcackey.so` but yours might be different.

![Loading Certificates into Firefox](<../../../.gitbook/assets/Screenshot from 2022-02-28 13-41-52.png>)

## Resources

* Ubuntu CAC docs has these instructions in more detail; however, many of the links wouldn't load for me.&#x20;
