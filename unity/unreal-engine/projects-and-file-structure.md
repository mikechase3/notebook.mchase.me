# Projects and File Structure

## Launcher

* You can hide games by selecting the gear opton and hiding the game tabs.
* Community: See what's new.
  * Answer hub: asking other developers for help.
  * Forumn: see what's going on with the community
  * Road Map: What do you want later? What might happen?
  * Blog: thigns Epic Games finds interesting
* **Learn**: Tutorials and resources
  * Sample projects
  * VR Demos
  * Specific concepts: user interface and full games.
* **Marketplace:** buy content and free items you can use from Epic Games
* **Library**: What engine versions and crap did you install?
* **Modding**: Helps you learn crap and make mods.

## Projects and Templates

### Managing Your Projects

* You can convert in place or convert all your assets and stuff to a newer version.
* Projects Tab is where you go to start new projects.

### Starting a New Project

* Templates: accelerate your development.
* Blueprint: Visual scripting language
* C++: Your traditional coding system.
* **Starter Content**: Some stuff to help you begin development.

#### In The Editor

* A Map is included and it will show you a map.

#### Feature Packs

* Templates that can be added after creation.
* In the contentbrowser, click `Add New` and `Add Feature or Content Pack`
* Our content packs are the starter content.
  * The mobile device thing takes up 1/5th of the memory and is better optimized for mobile devices.

### Project Settings Overview

* `Edit -> Project Settings` contains the project settings.
* `Project -> Target Hardware` lets you optimize stuff for a specific platform.
* `Project -> Maps & Modes` lets you control starting templates and default maps.
* `Project -> Supported Packages` lets you define where your game will run.

## Important Files and Folders

* Features editing
* Basic structure
* Disposable
* Cached downloadds
* DDC folders and managing the files.

### The uProject File

* The uProject file contains the settings needed to run a project.
* Files are forward compatible not backward compatible.
* You can half-ass backwards compatibility by opening up the text file and changing the version; however, anything created with a newer version won't show up.

{% hint style="warning" %}
If you ever need to work backwards, check out the video "Understanding the .uproject File." It's not safe. But it might \(probably will\) work.
{% endhint %}

### Project Structure

#### Config

* Contains project specific settings.

#### Content

* Contains all the geometry and stuff
* If you delete this you delete all your content
* Intermediate: Just holding temp files. It will be regenerated but take longer
* Logs: running log of your game. Crashes and stuff.
* .vs: The visual studio file.
* Binaries: Contains the binaries of your project.

### Vault

* You only download things when you wish to install to the engine.
* It's not alwayd downloaded.
* You can select `Edit Vault Cache Location` and find a different drive or folder to change your cache location to change it.
* The same content might be in 3 different versions that are pre-downloaded.
  * It'll take a good chunk of space that you might not even need anymore.
  * Delete anything that isn't in installed engines.
* You can also remove the project from within Unreal Engine.

### Derived Data Cache \(DDC\)

It stores your assets in a specific format compatable for the Unreal Engine. It speeds things up for when you're working with unreal Engine like caches do obviously.

* You can delete the old files from the drive data cache.
* You can lookup how to move the DDC so that it's shared in public folders.
  * This can make things faster in saved drives.

## 

