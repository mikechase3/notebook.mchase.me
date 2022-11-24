# Manim Math Animation Package

## What is Manim

![](<../../../.gitbook/assets/image (459).png>)

* Precise animations.
* Designed for creating explanatory math videos.

```
pip install manim
```

## Installation

`pip install manim` would ideally just work, but it doesn't.

### Mac OSX Debugging

On MacOS, If you get these errors:

```bash
Failed to build pycairo
ERROR: Could not build wheels for pycairo which use PEP 517 and cannot be installed directly
```

Then open a terminal outside of your virtual environment and run the following command. You'll need to install Homebrew if you don't have it installed already.

```bash
brew install cairo pkg-config pygobject3 gtk+3
brew install ffmpeg mactex
```

If this doesn't work, check for an updated command in this ReadMe file. This is for an unrelated program, but it worked for me:

{% embed url="https://github.com/azeam/camset" %}

### Other Platforms

I used MacOSX, but other platforms have documentation. Checkout the official ReadMe.

{% embed url="https://github.com/3b1b/manim" %}

### Video Installation

There are also several video installation instructions here:

{% embed url="https://youtube.com/c/TheoremofBeethoven/search?query=manim%20install" %}

## Getting Started



## References and Further Reading

This all started when I watched 3Blue1Brown's animations for understanding calculus far better than my math teachers and professors ever explained any concept whatsoever. I wish they all had to learn this program.

I used the article above to start my search.

{% embed url="https://towardsdatascience.com/how-to-create-mathematical-animations-like-3blue1brown-using-python-f571fb9da3d1" %}

Next, I watched the following video to further help me get started.

{% embed url="https://www.youtube.com/watch?v=d9nbtyO2YcU" %}

Second, I found an excellent youtube video that shows an overview of what i could create with this.
