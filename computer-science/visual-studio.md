# Visual Studio

{% embed url="https://learning.oreilly.com/library/view/visual-studio-code/9781119588184/f01.xhtml" %}



## Layout

### Activity Bar

The activity bar is on the left. From top to bottom, here’s how it’s laid out: 

* File explorer
* Search \(for files?\)
* Version Control
* Debugger
* Extensions
* Settings \(At the very bottom\)

### Settings Bar

* Split into user settings and workspace setting.
  * User: across VS
  * Workspasce: Just this ’project’.

### Status Bar

On the left side:

* Current git branch
  * A `*` will appear if there are any changes that are uncommitted/synced.
  * Clicking on this lets you change branches.
* Circular arrows help you sync changes.
* Errors/Warnings and the number tells you how many there are.
* `Go`: What language. 
* `1.13.4`: Version number.

On the right side:

* Line and colum of the cursor .You can use `CTRL+G/CMD+G` to go to a certain line.
* The `Tab Size: 4` gives you information about indentation and whether it’s tabs or spaces. It might say `spaces` if it’s using spaces.
* `UTF-8` is the encoding of the text file.
* `LF` lets you specify the end of line sequence
  * Can be a return carrage.
  * Or some line terminator.

## Windows

### Command Pallette

* Mike Chase: double click ’shift’.
* Also CMD+SHIFT+P for non-jetbrains people. Also `F1`
* Also view -&gt; command pallette for weird people.

### Opening Temrinal in VS Code

* Type in ``CMD+```
* Use the `+` button to create a new terminal.
* Type `shell` in the command pallette to change to git bash or another terminal interface.
* Use the 2x windows button to put two terminals side by side.
* ’trash’ kills the terminal.

### Output Window

* Displays the output. The dropdown tells you where the output is coming from.
* _Clear_: is the weird x and ciouple lines. Clears your output.
* _Lock_: Freezes your scroll point.
* `^` isn’t available for everything, but clicking it will take you to a physical logfile. 

### Debug Console

* You can filter using _globs_ which are like regular expressions, but slightly different. 
  * Click the _gear_ to change what will be shown/excluded
  * For example, you’ll probably want to exclude git results.
  * Changing the debug console happens across a project, not file.
* Search ’globs’ or lookup table 2.1 in the book to see wildcard descriptions.



| WILDCARD | DESCRIPTION |
| :--- | :--- |
| \* | Matches zero or more of any character. |
| ? | Matches any single character. |
| \[abc\] | Matches any one of the characters specified in the brackets. In this example, it would match either ‘a’, ‘b’, or ‘c’. |
| \[a–z\] | Matches any one of the range of characters specified in the brackets. |
| \[0–9\] | Matches any one of the numeric characters specified in the brackets. |
| \*\* | Matches zero or more path segments. |



