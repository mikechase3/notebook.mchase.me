---
description: A place to put scrap ideas before I destroy or perfect them.
---

# Inbox

## Google Cloud Platform

* I evaled Azure & it was alright. Free plan only had 0.5gb ram
  * Turns out remote IDE for PyCharm requires 4GB.
  * It really didn't like 0.5gb of ram & 1 vCPU core.
* I'm playing the [arcade](inbox.md#google-cloud-platform) if I can (which is locked but I'm a student!!)

## On "The Art of Gathering"? (Title might not be right)

* I listened to a _No Stupid Questions_ podcast regarding group gatherings & what makes good groups.
* The topic was a _book club_\* & they used that as an example. Good book clubs have:
  1. An authoritative figure w/ house rules.
  2. Exclusivity (creates a sense of belonging & feeling special/important).
  3. Rules against new members because they don't have prior knowledge nor shared experiences/friends.
* Should I look at [Docusaurus](https://docusaurus.io/docs)?\*

## Stocks and Bonds

* Currently, I buy index funds.
* But I'm in tech & tech is booming.
  * I've got tons of my portfolio in tech
  * Which goes against my "just index it" philosophy
  * Is that risky? AI is changing the world & has been over last ten years.
  * But now chat gippity came out and it's... oversaturated?
* Anyways - how do I know when to sell $MSFT, $AMZN, if we're innnnnnnnn a bubble?
  * And when do I get out?

Let's examine [the o-chem teacher](https://www.youtube.com/watch?v=7IBzTZqeyo0\&list=PL0o\_zxa4K1BVJoep\_XshasfnwHfCV\_JMf\&index=1)

### 01 Percent Changes

The first question is a math question of who made more money?

* 1 -> 2 = 100% return on investment because it doubles
* 1 -> 4 = not 400, but a 300% return on investment. (100 doubles, +100 triples, +100 quadruples)

Second question - what if stocks go down? If price starts at $10 -> $20 -> $5?

* Initial investment for John, Kelly, and Bruce buy 1000 shares at $10 = 10K.
* Different people do different things, but see the video.

The strategy is to take some money out and "trim the fat"

* Aka: Take some profit when the price goes up.
* Buy low, sell high as they say.

### 02 ROI Calculations

If Jon purchases a house for $250K and sells for $325K find ROI.

* **ROI** = Profit/COI \* 100%
* (325K-250K)/250K \* 100% = 30%
* The _Annual ROI_ is 30%/5yrs = 6%/year.

## Front End w/ HTML, CSS, JS fundamentals

Annie is doing this.

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
