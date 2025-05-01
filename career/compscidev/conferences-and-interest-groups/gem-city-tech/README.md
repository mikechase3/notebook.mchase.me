# Gem City Tech

## Resources

Website:

{% embed url="https://gemcity.tech" %}

Meetup:

{% embed url="https://www.meetup.com/gem-city-tech/?eventOrigin=event_home_page" %}

### Upcoming Technology Events

* **Technology First**
* **CodeMash Conference** in Sandusky, OH
* **Stir Trek** - Columbus, OH pre-screening? [stirtrek.com](https://stirtrek.com)
* **Momentum Developer Conference**
* **Gdex** - [thegdex](https://thegdex.com)
* Code for Dayton - house demolishing?

### Conferences in Dayton

* **Con with games?**
* The game developer group started one at D20 in October.
* [thecogg.org](https://thecogg.org)

{% embed url="https://code.golf" %}

{% embed url="https://thecogg.com" %}

## Attributes of Clean Code

### No Magic Numbers

* All code shouldn't have any "numbers" that are just defined.
* They should all be attached to a constant.
* Never just have `moveForward(10)`, but put that in as a constant.

### Meaningful Descriptive Identifiers

* For variables.

### Self-Documenting Code

* Functions should be clear.
* .

### DRY Code (Don’t Repeat Yourself)

* Don't repeat yourself when possible.
* .

### Consistent Code Style

.

### Reduced Nesting

.

### Game Delays

* Developers here are saying "double however much time it'll take."
* Consider quadrupling your estimates while starting.
* Incrementally address forces that encourage change/growth. Allow opportunities for growth to be exploited locally as they occur.
* Refactor unrelentingly.

The site has explanations for:

* **BIG BALL OF MUD**
* **THROWAWAY CODE**
* **PIECEMEAL GROWTH**
* **KEEP IT WORKING**
* **SHEARING LAYERS**
* **SWEEPING IT UNDER THE RUG**
* **RECONSTRUCTION**
  * Used when you can't comprehend your code.
  * Throw it away & start over.

## Additional Concepts

* It's an **iterative project** like a scientific method. Hypothesize, try it, test it, revise your hypothesis.
* It's _inherently creative_.
* The most important testing in games is player testing.

## Big Ball of Mud & Architectures

[http://www.laputan.org/mud/](http://www.laputan.org/mud/)

Typical Software Architectures:

* **N-Tier Software Architecture**
* **MVC**: Model View Controller
* Essentially, every game might start off with structured diagrams but turns into a _big ball of mud_ (unstructured).
  * Spaghetti code example graphic.
  * Shantytowns: common, inexpensive materials. Anyone who can code might create spaghetti code.
