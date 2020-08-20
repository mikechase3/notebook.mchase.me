# BFS & DFS Basics \(L14\)

## Introduction

_Depth First Search_ and _Breadth First Search_ both:

1. Pull a node
2. Do work
3. Visit adjacent nodes.
4. Queue or push unseen adjacent nodes. 

The difference is that they have different ways of traversing through that graph. Check out this [visualization](https://visualgo.net/en/dfsbfs) while you're using these notes.

## Breadth First Search

![](../../.gitbook/assets/image%20%2886%29.png)

_Breadth First Search_ uses a queue. It's a _first-in-first-out_ structure. 

1. Visit a node
2. Add all the items to the queue. 
3. The first item to come out is the first one that came in.

We're to **process layer by layer**. We're not going deep into a path.

### Example Walkthrough

![](../../.gitbook/assets/image%20%2885%29.png)

### Memoization

1. **Queue:** Tells us which nodes we'll examine next.
2. **"Seen" Hash-Set**: Ensures we don't add nodes to the queue we've already added and processed.
3. **Output Nodes**: Shows us the output of the nodes.

So the basic form of DFS uses an array **status\[u\]** of size **V** vertices to decide between binary conditions: Whether vertex **u** has been visited or unvisited. Only if vertex **u** is still unvisited, then DFS can visit vertex **u**.

#### Memorizing the path

DFS uses another array **p\[u\]** of size **V** vertices to remember the **parent/predecessor/previous** of each vertex **u** along the DFS traversal path.  




## Depth First Search

![Basics of Depth First Search](../../.gitbook/assets/image%20%2890%29.png)

### Does a Path Exist from Node S to T? `hasPath(s,t)`

_Depth-First Search_ uses a stack, which is LIFO.

#### Story

So mom is like _"I wonder if Shelby is related to Hal"_. So we have this initial node that we're going to call `S` for Shelby.

So we say _"Hey Shelby" `S`, are you related to Hal?"_ And of course, Shelby doesn't even know who Hal is so she says "I don't know. Let me ask my children."

So now `S` goes to Gregg and asks "Hey Greg, do you have a path to Hal? And then Hal is like "I don't know, let me go ask my children: `R`ob and `B`ob. And then they ask their children, and their children, and so on until one of them knows Tim. Or if everyone asks their children.

 

## Comparison

| Breadth First Search | Depth First Search |
| :--- | :--- |
| Good for shortest path. | Bad for shortest path. |
| Level by level approaches: Areas, region, matrixes |  |

## Works Cited

| Title | Author | Content |
| :--- | :--- | :--- |
| [DFS & BFS](https://www.youtube.com/watch?v=TIbUeeksXcI) | [Back to Back SWE](https://backtobackswe.com/platform/content/depth-first-search-and-breadth-first-search) | Structure, Pictures, Explanations... I watched his videos and took notes. |
| [Algorithms: Graph Search, DFS, and BFS](https://www.youtube.com/watch?v=zaBhtODEL0w&t=209s) | ![](../../.gitbook/assets/image%20%2889%29.png) | Screenshots,  |
| [Lecture 13: BFS](https://www.youtube.com/watch?v=s-CYnVz-uh4&t=2s) | Erik Demaine; MIT Open Courseware | None \(But really good resource\). |



