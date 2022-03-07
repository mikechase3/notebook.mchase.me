# Installing Applications

## Debian Files

If you're on a ubuntu-based system, you can install it super easily by opening the file in the application center. If you don't have one of those, you'll have to use install it manually, but for debian based systems, it's easy.

{% embed url="https://help.ubuntu.com/kubuntu/desktopguide/C/manual-install.html" %}

> Alternatively, you can also install a .deb file by opening a terminal and typing:
>
> ```
> sudo dpkg -i package_file.deb
> ```

### Locating Installation Directory

#### Given a Debian Package

To see where the binaries are going to be installed before you install it (something important when linking it up to your desktop environment), you can type `dpkg --contents <packageName>.deb` and it'll list out what is going to be placed where.

#### From apt

```
~$ dpkg -L libpcsclite1

Output:
/.
/usr
/usr/lib
/usr/lib/x86_64-linux-gnu
/usr/lib/x86_64-linux-gnu/libpcsclite.so.1.0.0
...
```

## Building from source (.tar.xz)

1. First, unpack the archive with a command like `tar -xzf archive.tar.gz`.&#x20;
2.  The software must be compiled before it is installed. Typically, what you do is\


    ```
    tar -xzf archive-name.tar.gz
    cd archive-name
    ./configure
    make
    sudo make install
    ```



## Make a desktop shortcut

Once you have something that is executable, make it searchable in natillius by adding a desktop shortcut (a text file) at `/usr/share/applications/<AppName>.desktop`.&#x20;

Inside this text file, enter the following information:

{% code title="/usr/share/applications/AppName.desktop" %}
```
[Desktop Entry]
Name=<appname>
Comment=<any app comment>
Exec=/opt/bin/<appname>.AppImage %U
Icon=<app icon name copied in step 1 without full path. remove this line if step 1 was skipped>
Terminal=false
Type=Application
Encoding=UTF-8
Categories=Network;Application;
Name[en_US]=<App Name in English>/
```
{% endcode %}



