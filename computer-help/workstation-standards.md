# Workstation Standards

When configuring Mac, it's important to prepare it for maximum productivity, which includes the time it takes to scan for whatever setting/menu item you are trying to find. If you are consistent across terminals, it will save people time.

Computers at {redacted} use the [FOG](https://wiki.fogproject.org/wiki/index.php?title=Introduction#What\_is\_FOG) server so they can be recovered; however, for new images, you should configure it with the following setup (last revised 2022-05-21):

## Connections

* [ ] VPNs
  * [ ] Work
  * [ ] Home
  * [ ] {Redacted} Other
* [ ] Network Drives
  * [ ] AWS Production Environment
  * [ ] AWS Testing Environment
  * [ ] Home Servers
  * [ ] Work Servers
* [ ] Cloud Drives
  * [ ] Dropbox: pin `/Collections/Applications/Mac` for later.&#x20;
  * [ ] ~~Google Cloud Drive~~
  * [ ] ~~iCloud Drive: exclude contacts.~~

## Core Applications

* [ ] **Install Brave:** sync code is in lastpass or Dropbox vault.
* [ ] **Install TeamViewer**: and sign-in. [Grant unattended/easy-access](https://community.teamviewer.com/English/kb/articles/109267-easy-access).



## App Store

{% tabs %}
{% tab title="00 Imperative" %}
#### Creative

1. Logic Pro
2. iMovie

#### Develop

1. Code Recipes Pro
2. Xcode

#### GUI Behavior

1. Magnet _(allows for window snapping as you'd expect in MS/Gnome)_
2. Helium

#### Productivity

1. Microsoft Remote Desktop
2. Microsoft Office Suite (make sure OneNote is included)
3. Notability
4. Todoist
{% endtab %}

{% tab title="01 Advisable" %}
#### Create

1. DaVinci Resolve
2. Ulysses
3. Swift Playgrounds
4. Forscore

#### Develop

1.

#### Design

1.

#### Manage

1.
{% endtab %}

{% tab title="02 Experimental" %}
#### Create

1. FL Studio Mobile

#### Develop

1. [BBEdit](https://www.barebones.com/products/bbedit/): text editor mac peeps love. (\$$ perpetual license)
2. Sequel Ace (Free)

#### Design

#### Manage (Productivity & OS Optimizations)

1. Timepage


{% endtab %}

{% tab title="Untitled" %}

{% endtab %}
{% endtabs %}





## Setapp

{% tabs %}
{% tab title="00 Imperative" %}

{% endtab %}

{% tab title="01 Advisable" %}

{% endtab %}

{% tab title="02 Experimental" %}

{% endtab %}
{% endtabs %}

### Bartender (Setapp)

Menubar should be setup like this. Everything to the left of "new items here" is unstandardized, so you can leave it alone or use your best judgement:

![Standard Bartender Configuration](<../.gitbook/assets/CleanShot 2022-05-21 at 19.38.10@2x.jpg>)

## External

### Create

*

### Develop

### Design

### Project Management

### Task Management

### Tweakers

* [Alfred](https://www.alfredapp.com/) (Mac OSX)
*

{% tabs %}
{% tab title="Imperative" %}


* **Alfred**, prefs, and key are in: `./Mac/Utilities.` Verify snippets in-place.
  * [ ] Check snippets are in-place.
* **Better Touch Tool**
* **Install Setapp:** Get the favorited apps. (Warning: heavily decreases security?)

#### Create

1.

#### Develop

1.

#### Design

1.

#### Project Management

#### Task Management

#### Tweak
{% endtab %}

{% tab title="Noteworthy" %}


* ****
* **Better Touch Tool**
* **Install Setapp:** Get the favorited apps. (Warning: heavily decreases security?)

#### Create

1.

#### Develop

1.

#### Design

1.

#### Project Management

*

#### Task Management

*

#### Tweak

* [ ] **Alfred:** prefs, and key are in: `./Mac/Utilities.` Verify snippets in-place.
* [ ] Check snippets are in-place.
{% endtab %}

{% tab title="Experimental" %}
#### Create

1.

#### Develop

1.

#### Design

1.

#### Manage

1.
{% endtab %}
{% endtabs %}

1.





## Backup

* [ ] Configure time machine.
* [ ] Ensure time-machine server has recent backups to backblaze.