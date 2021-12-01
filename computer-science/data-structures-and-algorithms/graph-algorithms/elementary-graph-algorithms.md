# Graph Fundamentals (L12)

## Graph Fundamentals

All these notes are from the video from Back to Back SWE. Some of this is copied and pasted. Nothing in this section is my own. (Well, that's not true some is paraphrased... but this isn't my work).

By the way - you should check out his videos because they're awesome. Even though they're not free, I couldn't learn this stuff without him.

### Mathematical Representation

* &#x20;A [graph](https://en.wikipedia.org/wiki/Graph\_\(abstract\_data\_type\)) is a mathematical object that consists of a [set](https://en.wikipedia.org/wiki/Set\_\(mathematics\)) of vertices (or "nodes") and a set of edges connecting those nodes together.
* We stress that you see a graph as a mathematical object that takes the form `G = (V, E)`. A graph consists of a set of vertices and a set of edges.
* We say this because many get confused by the many ways a graph can be _represented_ and get stuck on details. In the problem-solving process, it is of great help to "see the larger picture" and understand that a graph just consists of **2 sets** (`V` & `E`).

```
     1
   /   \
  2  -  3

V = {1, 2, 3}
E = {(1,2), (1,3), (2,3)}
|V| = 3
|E| = 3
```

$$
G = (V, E)
$$

| Title     | Definition                                                                     |
| --------- | ------------------------------------------------------------------------------ |
| Edges     | Connects the verticies                                                         |
| Verticies | The 'nodes,' or circles you're connecting to.                                  |
| V         | V is the set of all vertices, like `V = {1, 2, 3, 4, 5}`                       |
| E         | E contains all the **sets of edges**, like `E = { {1,2}, {1, 3}, {2, 3} }`     |
| \|V\|     | The **cardinality**, or size of the vertices, or how many vertices their are.  |
| \|E\|     | The **cardinality**, or size, or how many total edges there are.               |

### Vertices (V)

![](<../../../.gitbook/assets/image (61).png>)

* Vertices is the set of all the vertices.&#x20;
* These are connected by edges.&#x20;
* Here, the vertices are `V = {1, 2, 3, 4, 5}`.
* The _cardinality_ (or size) __ of the vertices is 5.

### Edges

![](<../../../.gitbook/assets/image (57).png>)

* Edges connect the vertices together.&#x20;
* The order in which you write out the edges doesn't matter
* The _cardinality_ of the edges is 6.

Terminology of edges, using the example `{u,v}`

| Term        | Meaning                                                                                                    |
| ----------- | ---------------------------------------------------------------------------------------------------------- |
| Directed    | Here, u points to v. The tail points to the head.                                                          |
| `u`         | `u` is called the **tail** of this edge.                                                                   |
| `v`         | `v` is called the **head** of this edge.                                                                   |
| `indeg(v)`  | The number of edges where `v` is the head, going into `v`.                                                 |
| `outdeg(v)` | The out-degree of v.                                                                                       |
| `deg(v)`    | The sum of all edges _incident_ (touching) the vertex. It's the sum of the in-degrees and the out-degrees. |

### Degrees

#### Digraphs

Digraphs mean that edges are directed edges. It's short for _directed graph_.

![](<../../../.gitbook/assets/image (50).png>)

* The in-degree of vertex `v` is 2 because v is the head of two incoming tails.
* The out-degree of vertex `v` is 3 because v is the tail of three outgoing heads.
* The degree of vertex v is 5 because the sum of 2 (in) and 3 (out) = 5 total edges.

### Summations for Undirected Graphs

$$
\sum_{v \in V}^{}deg(v) = 2m
$$

#### Translation

* The sum for every single vertex (v) that is an element of the vertices (V) we saw
  * Summing all of the degrees of each vertex `V`.
  * `v` describes one vertex. `V` describes the set of all vertexes.
* `m` is the amount of true edges.
* `2` means we're double counting every edge because they can go back and forth.
  * We count each edge twice
  * We double count the number of true edges.&#x20;

### Summations for Directed Graphs

$$
\sum_{v \in V}^{}indeg(v) = m = \sum_{v \in V}^{}outdeg(v)
$$

#### Translation

If I loop over every single edge and take the sum of indeg for every single vertex, then that is going to be the same as the true amount of edges. And if I take the sum of out degrees for all the vertices, that is the same as the true amount of edges.

If the whole graph is just `u -> v`, then:

* The set of all vertices is `V = {u, v}`
* The set of all edges is `{(u,v)}`.
* Clearly, the sum of all in-degrees is equal to the sum of all outgoing degrees.&#x20;

### Sub-Graphs

A **subgraph** of a graph is a **new graph** which is a non-strict **subset** of the original graph, where non-strict means the vertices do not have to be contiguous. What this means is that `V'` is a subset of `V` and `E'` is a subset of `E`.

$$
G' = (V', E') \in G=(V,E)
$$

As long as the sub-graph contains the same unique elements in the graph, a sub-graphs as well as the edges are a subset of the original mathematical representation of the graph.

### Connectivity And Components

When we talk about connectedness, it depends on what type of graph we're looking at:

* When it's an undirected graph, we have connectedness.
* When it's a digraph, we have simple connectedness and strong connectedness because directionally introduces another thing we need to enforce.

{% tabs %}
{% tab title="Undirected Graphs" %}
A component is a subgraph is a graph that has all the properties of u and v in that subgraph, `u` can reach `v` and `v` can reach `u`.

The components are where we can find a path from every single pair of `u` and `v`'s.

![](<../../../.gitbook/assets/image (56).png>)

In this example:

1. The connected components of `v(1)` is the entire red arrow.
2. The connected components of `v(5)` is the entire set the yellow arrow points to.

#### Why are we concerned?

DFS and BFS are guaranteed to search their connected component, but they are not going to search the whole graph like looping over all the vertices and finding each edge between them in the representation versus just doing a search off of a node (which will only hit the whole component).
{% endtab %}

{% tab title="Directed Graphs" %}

{% endtab %}
{% endtabs %}

#### Strongly Connected

{% hint style="danger" %}
Is this actually what a strong connection means?
{% endhint %}

Strong connections between two nodes means there is a connection to each other. Given two vertices: `u` and `v`, a _strong connection_ implies`v` can get to `u` and `u` can get to `v`.&#x20;

![Strong Connection](<../../../.gitbook/assets/image (64).png>)

![No strong connection between u and v.](<../../../.gitbook/assets/image (65).png>)

### Tree Terminology

A forest is a graph with no cycles, and a tree is a connected forest. That makes a tree a directed, acyclic graph. (Directed, has no cycles because it's a forest, and is a graph).

| Term    | Definition                                                                 |
| ------- | -------------------------------------------------------------------------- |
| Forest  | A graph with no cycles.                                                    |
| Tree    | A connected forest. (A directed, acyclic graph).                           |
| Leaf    | Any child of any parent. We can choose anything but the root to be a leaf. |
| Root    | Whatever vertex we choose to be the root.                                  |
| Parent  | One of the node's neighbors that is closest to the root.                   |
| Acyclic | It means there are no cycles.                                              |

## Algorithms

| Algorithm     | Use/Goal                                                            | Comment                                        |
| ------------- | ------------------------------------------------------------------- | ---------------------------------------------- |
| BFS           | Graph Traversal                                                     | Used for others.                               |
| DFS           | Graph Traversal                                                     | Used for others.                               |
| Prim's        |                                                                     |                                                |
| Kruskal's     | Finds minimum spanning tree (cheapest roads to connect all cities). | No starting node.                              |
| Floyd         |                                                                     |                                                |
| Bellmond-Ford | Find shortest path from source to all others.                       | Handles for negative weights. O(V\*E)          |
| Dikstra's     | Find shortest path.                                                 | Faster if there's not negative weights. O(V+E) |

Shortest path: You start at a source node.

Minimum spanning:&#x20;

## Works Cited

| Title                                                                                 | Content Used         | Author                                                                                           |
| ------------------------------------------------------------------------------------- | -------------------- | ------------------------------------------------------------------------------------------------ |
| CPS 450 Class                                                                         | Structure            | [Dr. Zhongmei Yao](https://udayton.edu/directory/artssciences/computerscience/yao\_zhongmei.php) |
| [Graphs Fundamentals](https://backtobackswe.com/platform/content/graphs-fundamentals) | Fundamentals Section | [Back to Back SWE](https://backtobackswe.com/platform/content/graphs-fundamentals)               |
|                                                                                       |                      |                                                                                                  |
