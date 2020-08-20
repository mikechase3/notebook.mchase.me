# Editor basics

## Editor Basics

| Object | Caption |
| :--- | :--- |
| Viewport | The layout of the game. |
| World Outliner | Overview of all the items |
| Details Panel | Details shows you everything in the level. |
| Modes Panel | Add items. Landscape, geometry. |
| Content Browser | File explorer |
| Main Toolbar | Play, blueprints, save, etc. |
| _**HELP**_ | _**CTRL+ALT+HOVER**_ |

## Viewport

| Options |  |
| :--- | :--- |
| Options Drop Down | Bookmark jumping using 1, 2, 3. Layouts for viewpoints.  |
| Perspective | Obvious |
| View Mode | Wireframe, lit, unlit |
| Show | Changes the way the editor shows different parts. Show grid. |
| Editor Mode | Quick way of showing what your project looks like. |
| Translate  | \[W\] |
| Rotate | \[E\] |
| Scale | \[R\] |
|  |  |

### Camera

| Snapping Options | Configures snapping. In top right of viewport. |
| :--- | :--- |
| Right button | Rotate, sort-of. |
| WASD | Moves the camera |
| Up and Down | \[q\] and \[E\] |
| Focus | \[F\] after clicking the item. |
|  |  |

## World Outliner

* You can nest things parent/child and they'll be _grouped_.
* Click _view options_ to see a bit more.

### Grouping

* When you group a bunch of items, when you click one of them, it selects all of them.
* You can unlock individual items to move one specifically, then re-lock it to the group.

## Details Panel

The details panel shows us the properties of whatever you selected.

| Topic | Caption |
| :--- | :--- |
| Name of Object | Usually in underlines. Linear\_stair\_staticMesh |
| Blueprint | Makes an object comprised of many things. If you want to easily create one, select a few objects and click add edit blueprint. \(maybe\). |
| Edit Blueprints | Click it, in the details click edit blueprint. |
| Eyeball | Lets you set defaults . There are debugging tools here too unique to when we are playing. Lets you see hidden properties too. |
| Property Matrix | Next to the eyeball, it shows you common properties to all things. If you want to compare two differnet items,  click `window -> details 2` to see the second detail panel.  Click the lock to lock the current panel \(on the top right\) to lock the properties on the object. |

## Modes Panel

Gives you access to operations such as place for adding common objects to your scene, paint, landscape, foliage, and mesh editing. Being in a particular mode affects the available option in other panels in the Modes tab.

| Mode | Caption |
| :--- | :--- |
| Basic | Cubes, characters, boxes. |
| Geometry | More complex shapes |
| All Classes | Everything. |
| Landscape | Where you paint the landscape. |
| Foliage | \[Shift+4\] |
| \[Shift+1\] | Place shortcut. |

## Content Browser

* Keeps track of everything in your project; not particularily in that level.
* Color click by right clicking folders and hitting color. Nice for organization.
* **Filters**: You can change what type of thing you want to filter by.
* _**Toggle Lock**_: Protects your directory from changing when you're navigating the file tree.
* When importing files, go to `File -> Import`. Don't just put it in the asset directory.
* _**Developer:**_ A scratch folder. Enable it by right clicking in the browser and hitting show developer.
* _**Collections**_: They're like tags. You can drag and drop things that you want to tag as rocks.
  * It's a static collection.
  * Use filters instead if you want things to dynamically update.

## Main Toolbar

|  |  |
| :--- | :--- |
| Save | Saves stuff |
| Source Control | Git, checkout files, quick shortcuts |
| Marketplace | Get more assets |
| Sttings | World and project settings. Setting translucent items to be selectable. Scalability in the editor \(not the project\). Material quality for GPUs. Preview rendering. Audio. Snapping. |
| Blueprints | Open the level blueprints.  |
| Cinematics | Shortcuts to matinee, sequencers |
| Build | Builds everything by default. Dropdown for more options |
| Play | Testing. See advanced settings to launch it in its own window. How detailed do you want to be? |
| Launch | Weird frameworks and other miscellaneous stuff I won't get into for a while. |
| Advanced Settings | Under the play setting. Want to launch your game in a new window? Go here. |



