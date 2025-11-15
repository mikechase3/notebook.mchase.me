# Gymnasium Environment Setup

## What is Gemnasium?

Gemnasium is a way to practice & hone in on my AI skills. It's meant for visual learners.

{% embed url="https://gymnasium.farama.org/environments/classic_control/" %}

Here are some examples:

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-04 at 21.09.34.gif" alt=""><figcaption></figcaption></figure>

## Setup with PyCharm

Their website says that they're now "gemnasium" not "gym", but in my searching I think we're still supposed to use gym at the time I'm writing this. So ignore this part of the website:

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-04 at 22.55.27@2x.png" alt=""><figcaption></figcaption></figure>

I found out the hard way by trying to get sub-packages. I'm not 100% sure why the

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-04 at 22.57.52@2x.png" alt=""><figcaption></figcaption></figure>

### Weird Imports

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-04 at 23.00.32@2x.png" alt=""><figcaption></figcaption></figure>

### Quotes Matter

Apparently this is an open issue.

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-04 at 23.12.38@2x (1).png" alt=""><figcaption></figcaption></figure>

### Dealing with Swig Issues

I had to uninstall swig `pip3 uninstall swig`, then install it through homebrew `brew install swig`.

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-04 at 23.16.19@2x.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-04 at 23.18.24@2x.png" alt=""><figcaption></figcaption></figure>

### Now What?

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-04 at 23.22.09@2x.png" alt=""><figcaption></figcaption></figure>

```
pip install 'gym[box2d]'
```

### Reinstall Python Apparently

> The error message indicates that the pygame package failed to install because it couldn't find the longintrepr.h file. This file is part of the Python development headers, which are needed to compile some Python packages from source. You can install the Python development headers by installing the python-dev package. However, on macOS, these headers should be included with the Python installation from Homebrew. If you installed Python from another source, you might need to reinstall it using Homebrew:

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-04 at 23.25.03@2x.png" alt=""><figcaption></figcaption></figure>

{% hint style="info" %}
Abandoned this technique.
{% endhint %}

### Conda

Next download this thing

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-04 at 23.28.45@2x.png" alt="" width="366"><figcaption></figcaption></figure>

And install it of course. It takes more than a minute.

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-04 at 23.29.51@2x (1).png" alt=""><figcaption></figcaption></figure>

I couldn't get it activated:

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-04 at 23.34.59@2x.png" alt=""><figcaption></figcaption></figure>
