# Comparing Angular, Vue, React, Vanilla

## General Comparison

* Angular: is good all across the board. "Insanely stable"
* Vue: poor release cycles, solid community, everything else is okay.
* React: Solid documentation, community, build tools, and tooling. Okay with others.
* Javascript: Solid documentation, community, and release cycles. Okay testing. No installation or build tools.&#x20;

## Implementation Comparison

* **Enterprise**: great for Angular. React is ok.
* **Mid-Size**: Angular is solid. Vue/React are ok.&#x20;
* **Small Team**: Angular is ok. Vue/React are solid. Javascript is 'ok'.
* **Hackathon**: JavaScript is your solid choice.
* **Individual**: any are ok.&#x20;

## Why Frameworks

* Javascript came out to display video
  * The initial demo of javascript came out in 10 days.
  * There wasn't much in the way of interactivity.
  * Original web was built by displaying a page.
* When Javascript came out, you could attach elements, change your DOM.
* Javascript neeeds a little more, and a little more.&#x20;
  * Hey - I want to grab the table itself. And when you find this button, attach it.
  * Code is really awkward to work with.
  * React came after angular & JS were horriffic.&#x20;
  * We're binding javasccript code & need binding from the DOM back to the javascript.
  * **Data-Binding** goes two directions & Angular JS by default uses 2-way data binding.
* React came out and had this concept of **virtual DOM** that ti could work with really fast. It would look at the virtual DOM & say what's the minimal DOM you can make to make it happen.
  * Completely different model mentally.
  * Instead of the whole page reload.
  * You have to account for HTML, JS, and CSS.
  * Angular said "hey - I go thhthis component & there's a backend class"
  * Separation of concerns. Angular wasn't as fast.



## React

| Area           | Notes                                                                                                                                                   |
| -------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Documentation  | Solid                                                                                                                                                   |
| Community      | Strong corporate support (Facebook). Translated into bootcamp use and lots of developer experience.                                                     |
| Installation   | <p>Next.JS, Remix, Gatsby, Expo, (Next.js App Router); legacy: Create React App.<br><br>Many options for installation; each is a different opinion.</p> |
| Build Tools    | React "let's you focus on code, not build tools"                                                                                                        |
| Tooling        | Web component platforms                                                                                                                                 |
| Release Cycles | <ul><li>No sest timeframe</li><li>Strong plan for stable releases</li><li>Breaking changes</li><li>Latest, Canary, and Experimental</li></ul><p></p>    |
| Testing        | Recommended tools: Jest & React Testing Library.                                                                                                        |

Having a scaffolded out component that he doesn't have to mess with is really cool. Going back & tweaking stuff back/forth is awkward.

## Javascript

There's a lot of talk going around where "are there times when pure JavaScript is good." 90% of what we need are websites w/ a little bit of functionality and Javascript is fine when it's just Java.

| Area           | Notes                                                                                                                                                     |
| -------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Documentation  |                                                                                                                                                           |
| Tooling        | Web omponents are foundational. Everything is built in Javascfript.                                                                                       |
| Release Cycles | Language specification (ECMAScript) and browser implementation & adoption. ECMAScript annual while browsers are independent & release on a rolling basis. |
| Testing        | Can use Jest, Jasmine, or others.                                                                                                                         |

.

## Title

1. **Build Size**:
   * **What it Means**: This refers to the size of the final code that is delivered to users when you create your application. A smaller build size usually means faster loading times.
   * **Summary**: Angular has a reasonable build size, while Vue, React, and JavaScript (JS) have good build sizes.
2. **Lighthouse Score**:
   * **What it Means**: Lighthouse is a tool from Google that measures the performance of web pages. It provides scores on various aspects like speed, accessibility, and SEO (how well your page will show up in search results).
   * **Summary**: All the frameworks (Angular, Vue, React, and JS) receive good scores, meaning they're optimized and perform well.
3. **Developer Tooling**:
   * **What it Means**: This refers to the tools and features available to help developers write, test, and debug their code effectively.
   * **Summary**: All frameworks have strong tools for developers, but the tools for JavaScript itself are only okay, which means they could be better.
4. **Full Stack**:
   * **What it Means**: Full stack development involves working on both the front end (what users see) and the back end (the server and database). A strong full stack means there's a good framework or technology for handling both parts.
   * **Summary**: Most frameworks are solid for full stack development, but JavaScript does not perform as well as the others.

In summary: Angular is decent, Vue and React are great, and JavaScript has some room for improvement in both build size and developer tooling. All of them perform well in terms of user experience and have good support for building web applications.



