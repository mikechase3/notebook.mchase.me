# Controlling your IoT Projects with Terminal

{% @github-files/github-code-block url="https://github.com/codemash-conference/session-slides/blob/main/2025/slides/Command_Your_IoT_Projects_from_the_Terminal.pdf" %}



{% @github-files/github-code-block url="https://github.com/codemash-conference/session-slides/blob/main/2025/slides/Command_Your_IoT_Projects_from_the_Terminal_TEXT.txt" %}



## My Notes

### Questions for End

* How do you setup netwoork booting. Is it on a servr? Need a specific IP address? Any challenges like that? Is it an ISO that gets copied & boots from it? Do you need an SD card even?&#x20;
* What's the psf.gz file? Is that something you download and then you set it with the set-font command in that filepath earlier?

### Terminals & Terminal Emulators

What is a terminal? You can still buy. SERIAL terminal and connect it to your Raspberry Pi.&#x20;

* Ghostty, iTerm, Mac OS Default.
* OGB Cable & the SSH

### Shells

Ben Thompson is the person who created the shell

* Any shell can run over any serial connection.
* Bash is POSIX compliant.
* ZSH is a little less.
* FISH is even less
* REPL is a terminal, the one built into Python, which runs python and is less like a terminal but can do terminal-like things.

### RasPy Imager

* `rpilocator.com` is a nice tool and lets you set stuff up.&#x20;

### RasPi Config

* Raspberry Pi Imager lets you configure SSH and other things that get flashed on the boot to the SD card.&#x20;
* Raspbian.
* NETWOORK BOOTing is now supported by Raspberry Pi.

### RasPi Connect

You can have it phone home, register itself, adn through a browser, you can gain remote access to a raspberry pi at home. This is `sudo apt install rpi-connect`. There's also `rpi-connect-lite`. Then you do `systemctl --user start rpi-connect` and `rpi-connect signin`. It'll prompt you to complete your singn in ny visiting `https://connect.raspberrypi.com/verify/XXXX-XXXX` and through  you can do a ton.

### RasPi USB Gadget

Terminal client on your iPad can let you SSH into the raspberry Pi. The Pi is running the gadget and tells the iPad it wants a network connection & has the ability to ssh into the raspberry Pi. You'll set it up wityh `arp` commands I think.

### Video Capture Cards

If you don't have an extra monitor, you can run QuickTime to do a video capture with a capture card. `QuickTime -> New Movie Recording -> USB Video`. OBS works too. Unfortunately, your mac doesn't act as a keyboard, so you'd need to have a second keyboard.

### RS232 Output

To connect to any terminal, you'll configure it. Take WYSE -> 9-pin to 25pin adapter , null modem, USB to Serial thing.

### Connecting via SSH&#x20;

You can ssh into the raspberry pi via SSH. It is aware of the full filesystem and can be aaware if you have a git repo & status on the thing. Connecting to it via SSH.

It's aware of the status of the files to the git repo which si really, really nice. Command for VS code is `select Remote-SSSH:  Connect to Host` in there.&#x20;

### Fonts and Colors

You can change the fonts on the terminal.&#x20;

```bash
grep -n FONTFACE /etc/default/console-setup
echo $TERM; sudo showconsolefront -Vvi
sudo dpkg-reconfigure console-setup
ls /usr/share/consolefonts/*.psf.gz
setFont /usr/share/consolefonts/*.psf.gz

```

See also [Nerdfonts](https://www.nerdfonts.com/). Draws boxes. Fun little characters. Improved ASCII art. Emojis that are font-sized? Rounded corners, double-wide lines. Lets you do all that kind-of stuff.&#x20;

### Bashrc

```bash
ecolor_test.sh
```

You can take control of the terminal on the pi? \`if \["$TERM" = "linux" ]; then (He changed the slide).



### What's an IoT Project

* This is when you want to install stuff on a microcontroller that deals with sensors, actuators, motors, lights, etc.
* I2C.
* Chip
* Pins/boards
* Platforms
* Connectors
* Protocols
* Board Pins
* Chips

### Platforms

1. Micropython (pyboard)
2. Circuitpython
3. Arduino (arduino-cli)
4. Pico SDK (C/C++ - very specific. cmake/make)
5. ESP-IDF (C/C++ **idf.py**)

The arduino command line interface is in C/C++

### Runtimes

The runtimes require you to specifically comile for a sepeciifc board for the Arduino, Pico SDK, and ESP-IDF. You must do it for the exact board you want to do.&#x20;

For MicroPython (pyboard) and CircuitPython, there is a **runtime** and you can run any python code that you want. This is more flexible, given that they made a runtime for that board.

### Boards

Unexpected Maker PrS3, Raspberry Pi Pico W, Arduino Nano Every, Adafruit M0 Express, ESP32-S3-DevKitC-1, Pimoroni Tiny2350, SparkFun Things Plus, seeed??.

### Sensors

BMP280, ADXL345, MPU6050, VCNL4040, LIS3MDL, ASDT7410, TSL2591, VL553L4CX, BH1745, BH1750, ICM20948, BME688 (Pimoroni). These are some sensors. Sometimes, these will not work with all the runtimes/platforms so be awware of that and research that it works.

### Command Workflows

* Libraries:&#x20;
* Deploy: ther's some commands that'll help you deploy.
* App (deploy/copy/upload)
* Monitor

He separates the platform from the working code. in two directory structures.&#x20;

For the circuitPython platform, when you do that, it'll come up as a drive and that drive has a directory structure. For Circuit python, it wants to run `./code.py` but Micropython wants to run at `./boot.py` and they both are monitored by the PyBoard.py.



### Arduino IDE

You have to install the full IDE development environment.  You have to setup some dependencies.&#x20;

```sh
cd $IOT; mkdir $IOT/arduino; cd ./arduino

curl -fsSL https://raw.githubusercontent....whatever that is...
```

#### CHecking Status of your installation

```sh
arduino-cli version
arduino-cli config dump
arduino-cli core list
arduino-cli lib list
arduino-cli outdatd
```

#### Arduino Update

* You can update everything within the arduino CLI, except for the CLI itself.&#x20;
* You want to update the core index and referencing.
* It'll download all the cpp headers & abstraction layers that makes your thing available to the ease of use API. You want to update those frequency.
* If I have a library that's talking to my BMP280 sensor, you can keep it updated in case that thing changes.&#x20;

```sh
arduino-cli core update # CHECK SLIDE
arduino-cli core upgrade # Check Slides, this might not be accurate.
```

### Arduino - Board Support

```sh
arduino-cli config add
board_manager.additional_urls https://adafruit.github.io/arduino-board-index/package_adafruit_index.json

arduino-cli core update-index
arduino-cli board search adafruit | grep samd
...
```

When you find the board, you want to do the install for it with `arduino-cli core install adafruit:samd` and `listall samd` and `details -b`. That helps you download the headers & support for it so you're ready to compile.

### Creating a Project

```sh
cd $WORK/Arduino
arduino-cli sketch new trinkey_neopixel_blink
```

And that creates the file I think. Then you go in and edit the code.

### Arduino - Compiling and UPloading

arduion-cli compile -vu -b

monitoring:

```sh
arduino-cli mionitor -p /dev/ttyAMC0
minicom -D /dev/ttyACM0
```

Once it's on the board and running, you can?

Checkout MINICOM. He uses that a lot.



### Arduino Libraries

```sh
arduino-cli lib list
lib search {SEARCH}
download name
install NAME

lib update-index
upgrade
```

The above isn't real code, but it's in the slides and you can use that to do stuff..



***

We're now piviting to ESP-IDF. It's similar.&#x20;

### ESP-IDF Instaling

* You'll install tfrom Github.
* Then there's an ./install.sh script. This is the commpiler and compils your code.
* There's also a `python -m pip install --upgrade esptool`. The tool lets you interface/control the board.&#x20;

### ESP-IDF Check Status

You'll do `cd $IOT/esp-idf; . ./export.sh` which you run every time you start the env?



He's going way faster so I have to just bullet points:

* For the updating, you'll go see the commands, isntall submotoddules, fetch stuff, upgrade stuff. See ESP-IDF - Update. This is just to basically update the stuff from the git repo. It's generally easier to just delete and reinstlal the thing, except the python tool. You can just update with Pip.
* Board Support - if you have esptool you can talk to it and you pass the chip\_id to see a bunch of information about th chip.&#x20;
  * IDF.py isis when you do the -list-targets, it tell=s you which versions of ESP is supported.
  * IDF.PY set-target esp32s3. When&#x20;
  * When you go to the IDF.PY, it only wants to know the main main controller chip. The compiler is going to know about the ESP32S3 chip so you have to write something to get to all the little gadtets.
  * menuconfig sets some defaults for the compiler.
* Create Project
  * Not much tool support. Create a directory. Go to the directory.
* How to Cpimle
  * You'll list your target and set your target.
  * Do a menuconfig to config stuff for it.\
    You'll do `build`
  * And then flash does the install.&#x20;
  * ESP-IDF is similar to the console.
* Libraries for ESP-IDF
  * Using AI to generate code.&#x20;
  * When you use Pico SDK and the IDF and the code generators don't look for the libraries to use.
  * It just directly in-line brings the library into your code so it works & it's happy I suppose.
  * **UncleRus** maintains a lot of libraries for Github.
* ESP-IDF demo is now shown.&#x20;

