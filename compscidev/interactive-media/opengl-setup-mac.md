# OpenGL Setup Mac

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

You can get the community studio of visual studio for free:

<figure><img src="../../.gitbook/assets/CleanShot 2024-03-07 at 13.02.07@2x.png" alt=""><figcaption></figcaption></figure>

Then, download these files from Isidore:

<figure><img src="../../.gitbook/assets/CleanShot 2024-03-07 at 12.56.56@2x.png" alt=""><figcaption></figcaption></figure>



<figure><img src="../../.gitbook/assets/CleanShot 2024-03-07 at 13.04.30@2x.png" alt=""><figcaption></figcaption></figure>
