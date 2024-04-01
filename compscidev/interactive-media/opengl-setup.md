# OpenGL Setup

## Mac (XCODE)

First, launch xcode and make a command line tool.

<figure><img src="../../.gitbook/assets/CleanShot 2024-03-07 at 12.53.11@2x.png" alt=""><figcaption></figcaption></figure>

Link the following files:

<figure><img src="../../.gitbook/assets/CleanShot 2024-03-07 at 12.53.48@2x.png" alt=""><figcaption></figcaption></figure>

## Mac (Clion)

### Installing & Checking XQuartz

{% hint style="warning" %}
Currently doesn't work, I'm throwing darts at solutions until it does or going back to Xcode.
{% endhint %}

After doing some `brew install`s from various services, I ended up with OpenGL sorta being installed through a free open gl. You'll use `pgrep XQuartz` to see if it's running, and if it returns nothing install `brew install XQuartz`.  Since mine returned nothing, I ran the command and think it's installed. Where?&#x20;

<div>

<figure><img src="../../.gitbook/assets/CleanShot 2024-03-17 at 22.05.27.png" alt=""><figcaption></figcaption></figure>

 

<figure><img src="../../.gitbook/assets/CleanShot 2024-03-17 at 22.05.47@2x.png" alt=""><figcaption></figcaption></figure>

</div>

I found it in `/applications/utilities/XQuartz.app`. Not sure if I'll reference it here because I was expecting some cpp headers, but I'll cross my fingers & come back to that if it doesn't work.&#x20;

<figure><img src="../../.gitbook/assets/CleanShot 2024-03-17 at 22.07.54@2x.png" alt=""><figcaption></figcaption></figure>

Now, despite putting environmental vars in my `.zshrc` file and sourcing them, Clion complained that there weren't any display environmental variables when testing it with this script:

```cpp
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib> // for getenv


int main(int argc, char** argv)
{
    const char* display_env = std::getenv("DISPLAY");
    if (display_env) {
        std::cout << "DISPLAY: " << display_env << std::endl;
    } else {
        std::cout << "DISPLAY environment variable not set" << std::endl;
    }

    // Initialize GLUT
    glutInit(&argc, argv);

    // Create a window
    glutCreateWindow("Library Check");

    // Initialize GLEW
    GLenum glewStatus = glewInit();
    if (glewStatus != GLEW_OK)
    {
        std::cerr << "Error initializing GLEW: " << glewGetErrorString(glewStatus) << std::endl;
        return 1;
    }

    // Check if GLEW is working
    if (!GLEW_VERSION_2_1)  // Check for GLEW 2.1 or higher
    {
        std::cerr << "Your GLEW version is too old. GLEW 2.1 or higher is required." << std::endl;
        return 1;
    }

    // Check if freeglut is working
    if (!glutGet(GLUT_ELAPSED_TIME))
    {
        std::cerr << "freeglut is not working correctly." << std::endl;
        return 1;
    }

    std::cout << "GLEW and freeglut are installed and working correctly." << std::endl;

    return 0;
}
```

So I went back and fixed it!

<figure><img src="../../.gitbook/assets/CleanShot 2024-03-17 at 22.24.51@2x.png" alt=""><figcaption></figcaption></figure>

But then I got this `failed to open display 0` error again.&#x20;

<figure><img src="../../.gitbook/assets/CleanShot 2024-03-17 at 22.45.01.png" alt=""><figcaption></figcaption></figure>

### XQuartz Permissions

I ran `xhost +` in my terminal and found that there was no access control issues; however, when running it in Clion, I got that permissions error again.

<figure><img src="../../.gitbook/assets/CleanShot 2024-03-17 at 22.49.53.png" alt=""><figcaption></figcaption></figure>

```cpp
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib> // for getenv


int main(int argc, char** argv)
{
    // Disable access control for the X11 server
    int result = system("/opt/X11/bin/xhost +");
    if (result != 0)
    {
        std::cerr << "Failed to disable access control for the X11 server" << std::endl;
        return 1;
    }

    // Check if the DISPLAY environment variable is set
    const char* display_env = std::getenv("DISPLAY");
    if (display_env) {
        std::cout << "DISPLAY: " << display_env << std::endl;
    } else {
        std::cout << "DISPLAY environment variable not set" << std::endl;
    }

    // Initialize GLUT
    glutInit(&argc, argv);

    // Create a window
    glutCreateWindow("Library Check");

    // Initialize GLEW
    GLenum glewStatus = glewInit();
    if (glewStatus != GLEW_OK)
    {
        std::cerr << "Error initializing GLEW: " << glewGetErrorString(glewStatus) << std::endl;
        return 1;
    }

    // Check if GLEW is working
    if (!GLEW_VERSION_2_1)  // Check for GLEW 2.1 or higher
    {
        std::cerr << "Your GLEW version is too old. GLEW 2.1 or higher is required." << std::endl;
        return 1;
    }

    // Check if freeglut is working
    if (!glutGet(GLUT_ELAPSED_TIME))
    {
        std::cerr << "freeglut is not working correctly." << std::endl;
        return 1;
    }

    std::cout << "GLEW and freeglut are installed and working correctly." << std::endl;

    return 0;
}
```

This is where I give up for today.&#x20;

## Windows & Visual Studio

{% hint style="info" %}
Lots of classmates had issues/errors using this.&#x20;
{% endhint %}

You can get the community studio of visual studio for free:

<figure><img src="../../.gitbook/assets/CleanShot 2024-03-07 at 13.02.07@2x.png" alt=""><figcaption></figcaption></figure>

Then, download these files from Isidore:

<figure><img src="../../.gitbook/assets/CleanShot 2024-03-07 at 12.56.56@2x.png" alt=""><figcaption></figcaption></figure>



<figure><img src="../../.gitbook/assets/CleanShot 2024-03-07 at 13.04.30@2x.png" alt=""><figcaption></figcaption></figure>

## Linux

Linux seems to work extremely well whenever I have development issues. I love the terminal & it lets me stay focused on my work instead of complaints [about why I'm not using Edge](https://arstechnica.com/gadgets/2024/01/microsoft-edge-is-apparently-seamlessly-usurping-chrome-on-peoples-pcs/).&#x20;

And GOSH DARN IT I DIDNT EVEN GET THAT FAR!:

### Debugging HyperV

<figure><img src="../../.gitbook/assets/CleanShot 2024-04-01 at 10.11.25@2x (1).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/CleanShot 2024-04-01 at 10.29.14@2x.png" alt=""><figcaption></figcaption></figure>

To install OpenCV and OpenGL on Ubuntu 22.04 LTS, you can follow the steps below:

**1. Install OpenCV:**\
OpenCV can be installed using the package manager or built from source. Here's the recommended method of installation using the package manager:

```
sudo apt updatesudo apt install libopencv-dev
```

This command will install the pre-compiled OpenCV package and its dependencies.

**2. Install OpenGL:**\
OpenGL is usually installed on Linux systems by default. However, you may need to install the development libraries and utilities to compile and link OpenGL applications. Use the following command:

```
sudo apt install mesa-common-dev libgl1-mesa-dev libglu1-mesa-dev
```

This will install the necessary packages for OpenGL development.

**3. Verify the installations:**\
To make sure the installations were successful, you can check the versions of OpenCV and OpenGL installed on your system:

For OpenCV, use the following command:

```
pkg-config --modversion opencv
```

This should display the version number of OpenCV.

For OpenGL, you can check the version by running:

```
glxinfo | grep "OpenGL version"
```

This will display the OpenGL version information.

These steps should help you install OpenCV and OpenGL on Ubuntu 22.04 LTS. Remember to consult official documentation or resources from the respective projects if you encounter any issues during the installation process.
