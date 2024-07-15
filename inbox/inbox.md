---
description: A place to put scrap ideas before I destroy or perfect them.
---

# Inbox
Updated 20240714
Evaluating [python web frameworks](/compscidev/web-apps/onPythoNWebFrameworks.md)

## Google Cloud Platform
* I evaled Azure & it was alright. Free plan only had 0.5gb ram
  * Turns out remote IDE for PyCharm requires 4GB.
  * It really didn't like 0.5gb of ram & 1 vCPU core.
  * Now I have $300 for three months and spend $1/day on 8gb RAM & 2 vCPUS.
* I'm playing the [arcade](inbox.md#google-cloud-platform) if I can (which is locked but I'm a student!!)

## On "The Art of Gathering"? (Title might not be right)

* I listened to a _No Stupid Questions_ podcast regarding group gatherings & what makes good groups.
* The topic was a _book club_\* & they used that as an example. Good book clubs have:
  1. An authoritative figure w/ house rules.
  2. Exclusivity (creates a sense of belonging & feeling special/important).
  3. Rules against new members because they don't have prior knowledge nor shared experiences/friends.
* Should I look at [Docusaurus](https://docusaurus.io/docs)?\*

## Stock/Bond Analysis
Moved [here](/finance/investments/README.md) temporarily.
Will put in it's own page when I continue this research.

## Front End w/ HTML, CSS, JS fundamentals
My girlfriend Annie is learning front-end development. 
We've been brushing up on HTML/CSS/JS stuff
Next, we're going to learn node.js and the react framework
I'll switch to other research after making a docker image and deploying.


TODO: move below to web-apps under front-end probably. 
Also refresh my syntax knowledge with CodeCademy and
then make a website or putty/neal.fun article.

### Developer Console

Our first little project is to randmly change colors.

```js
const htmlBody = document.querySelector('body')

const randomClickFunction = function(){
    const colors = ["#002942", "#0CA7DB", "red", "green", "blue", "yellow", "purple"];
    const randomIndex = Math.floor(Math.random() * colors.length);

    randomClickFunction()

    htmlBody.onclick = randomClickFunction;
```

Well - that didn't work. Check this out later: https://gemini.google.com/app/b54581554ee330ce
