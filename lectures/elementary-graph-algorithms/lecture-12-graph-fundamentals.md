# Lecture 12: Graph Representations

## Common Graph Operations

{% tabs %}
{% tab title="Undirected Graphs" %}
Defining Undirected Graphs

* Let `V` be a finite set and `E` be a subset of $$\{e | e \subseteq V, |e|=2\}$$ . Then, the pair `G=(V, E)` is called an undirected graph.
* Self-loops are not allowed.
  * `e != {u, u} = {u}`
{% endtab %}

{% tab title="Directed Graphs" %}
**Definition**: Let `V` be a finite set and `E` be a binary relation on V, that is,  $$E \subseteq V \cdot V$$ . Then, the pair `G=(V, E)` is called an directed graph.

**Self Loops** are allowed. `E` may contain `(v, v)`.
{% endtab %}
{% endtabs %}

### Common Algorithms

{% hint style="warning" %}
I have no idea how to implement the first three or what arguments they would take
{% endhint %}

| Name | Description |
| :--- | :--- |
| `exists(e)` | Check if the element is present in the graph |
| traverse\(\) | Traverse the graph |
| `add(vertex, edges)` | Add elements to the graph |
| s-t path | Is there a path between `s` and `t`? |
| Shortest s-t path | What is the shortest path between `s` and `t`? |
| Cycle | Is there a cycle in the graph? |
| Euler Cycle | Is there a cycle that uses each edge exactly once? |
| Hamilton Cycle | Is there a cycle that uses each vertex exactly once? |
| Connected Components | Find connected components |
| Bioconnectivity | Is there a vertex whose removal disconnects the graph? |
| Plalanarity | Can the graph be drawn in the plane with no crossing edges? |
| Graph isomorphism | Are two graphs isomorphic? \(They are equivalent even though they look differently? |

### Text File Representations

We can sort the values using spaces or a CSV or tab spaced.

1. The first line describes how many nodes and how many edges there are.
2. Lines 2-6 contain information about the nodes.
3. Lines 7-11 contain information about the edges.

```java
graph.txt:
4 5 // 4 nodes, 5 edges.
0 10 10 // Node 0 has an x-value of 10 and a y-value of 10.
1 90 40 // Node 1 has an x-value of 90 and a y-value of 40.
2 30 10
3 90 10
0 2 1 //Node #0 is connected to node #2. The weight is 1.
1 2 5 //Node #1 is connected to node #2. The weight is 5.
2 3 3 //Node #2 is connected to node #3. The weight is 3.
1 3 2
0 3 10
```

{% hint style="warning" %}
She describes the text-file as having an x and a y axis. Why? How? Why do node have 3 parameters?
{% endhint %}

#### Reading Data into the text file.

![](../../.gitbook/assets/image%20%2869%29.png)

| Function | Description |
| :--- | :--- |
| `BufferedReader in = new BR(new FR(args[0]));` | Opens the text file. |
| `StringTokenizer(oneLine);` | Gets one line? |
| `int V` | Number of vertices. |
| `int E` | Number of edges. |
| `G` | Pointer to a graph object |
| `G = new EdgeWeightedDiagraph(V);` | Create a new graph with `V` objects. |
| `for (int i = 0; i < V; i++){`  | For all the vertexes... |
| `oneLine = in.readLine()` | Grab the line. It's stored in a weird type. |
| `str = new StringTokenizer(oneLine);` | Convert it from a weird type to a string. |
| `v = Integer.parseInt(str.nextToken());` | Takes that string |
| `x = Double.parseInt(str.nextToken());` | Take the string and find x. |
| `y = Double.parseInt(str.nextToken());` | Take the string and find y. |
| `for(int i = 0; i < E; i++){` | For loop for reading edge information |
| `v = Integer.parseInt(str.nextToken());` | Get first node connection. |
| `w = Integer.parseInt(str.nextToken());` | Get the second node. |
| `weight = Double.parseDouble(str.nextToken());` | Get the weight. |
| `e = new DirectedEdge(v, w, weight);` | Make an edge object. |
| `G.addEdge(e);` | Adds a directed edge to the graph. |

{% hint style="warning" %}
What is the x and y value for the nodes? What does that mean?
{% endhint %}

## Adjacency Matrices

{% hint style="info" %}
Don't worry about the adjacency list representation just yet.
{% endhint %}

For unweighted graphs, especially small ones, we use adjacency matrices because they only take up 1 bit. We can define a graph by vertices and edges. Formally, we define a _\|V\| x \|V\| matrix A =_ $$a_{ij}$$ where

$$
|V| \cdot |V| \text{ Matrix }A = a_{ij} = \begin{cases}
 &1 \text{ if } (i,j)\in E\\ 
 &0 \text{ if } (i,j)\notin E
\end{cases}
$$

![](../../.gitbook/assets/image%20%2873%29.png)

![](../../.gitbook/assets/image%20%2872%29.png)

#### Adjacency Matrix Analysis

| Representation | Space | Add Edge | Find if Edge Exists | Iterate over Adj. Vertices |
| :--- | :--- | :--- | :--- | :--- |
| Adjacency matrix | $$V^2$$  | 1 | 1 | V |
| Adjacency Lists | E+V | 1 | `degree(v)` | `degree(v)` |

* The space requirement is $$\Theta(|V|^2)$$ 
* The time complexity for listing all vertices adjacent to node `u` is $$\Theta(|V|)$$, which is how long it takes to check one row of the adjacency matrix. _This is asking "what is adjacent to this node, not all nodes\)._
* The running time to determine if two nodes are directly connected is $$\Theta(1).$$ You can just check the adjacency list.

#### Real-World Differences

* In the real world, we use sparse graphs or adjacency lists. There are a huge number of vertices, but small average vertex degrees. They save you lots of space.
* For a given situation, your implementation will likely depend on how your program uses the graph and the programming language.

## Adjacency Lists

![An Adjacency List Representation of the Graph](../../.gitbook/assets/image%20%2875%29.png)

Adjacency lists maintain a vertex-indexed array of lists. 

## Undirected Graph API

| Method | Description |
| :--- | :--- |
| `Graph(int V)` | Constructs an empty graph with `V` nodes on the graph. |
| `void addEdge(int v, int w)` | Creates two edges: `v` to `w` and `w` to `v`. We specify two nodes. |
| `Iterable adj(int v)` | Returns v's neighbors: a list of nodes adjacent to the specified nodes.  |
| `int V()` | Return the number of vertices |
| `int E()` | Return the number of edges. |



### Adjacency List Implementation

```java
public class Graph{
    private final int V; //We don't want to change the number of nodes.
    private ArrayList<Integer>[] adj; //holds the list.
    
    //Create the Array of lists.
    public Graph(int V){
        this.V = V;adj = V;
        adj = new ArrayList[V]; //Array of array lists.
        for (int v = 0; v < V; v++)
            adj[v] = new ArrayList<Integer>(); //Give each node an empty list.
    }
    
    //Fill in the array lists.
    public void addEdge(int v, int w){ // v points to w. w points to v.
        adj[v].add(w); //Add w to v's adjacency list (neighbor set)
        adj[w].add(v); //Add v to w's neighbor set.
    }
    
    public Iterable adj(int v){ 
        return adj[v]; //Return iterator for v's neighbor set.
    }
    
    public int V(){
        return V;
    }
}
```

{% hint style="warning" %}
What is the iterator? Line 20?  What is it iterating through? is v's neighbor set the 
{% endhint %}

## Directed Graphs

### Directed Graphs API

![](../../.gitbook/assets/image%20%2877%29.png)

### Directed Graphs Implementation

![](../../.gitbook/assets/image%20%2876%29.png)

## Importing From a File

{% hint style="info" %}
Go through this later to see if I understand it.
{% endhint %}

![](../../.gitbook/assets/image%20%2878%29.png)

## Summary

> Q: Can you find all nodes/edges in an unknown network? ● Q: Find a shortest path \(\# of hops\) from u to v? ● Q: Topological sort: Given a directed acyclic graph \(DAG\), can you find a linear ordering of the vertices such that if \(u, v\) is an edge then u precedes v? − DAG indicates precedence among events: Vertices are events, edge uv means u has precedence over v − Tasks that have to be done before one eats breakfast: ● Get glass, pour juice, get bowl, pour cereal/milk, get spoon, eat ● Brute force searching in a graph for all applications above 18
>
> Breadth-first search: Go level by level in the graph − Applications of BFS: ● Crawling a network \(finding all nodes/edges on a graph\) ● Finding the shortest path \(\# of hops\) from a source to a destination ● Depth-first search: Go as deep as you can, then backtrack − Applications of DFS: ● Topological sort ● Finding strongly connected components of a graph ● Both take Θ\(\|V\|+\|E\|\) time − where \|V\| is the number of vertices and \|E\| is the number of edges

| Title | Content Used | Author |
| :--- | :--- | :--- |
| CPS 450 Class | Structure | [Dr. Zhongmei Yao](https://udayton.edu/directory/artssciences/computerscience/yao_zhongmei.php) |
| [Graphs Fundamentals](https://backtobackswe.com/platform/content/graphs-fundamentals) | Fundamentals Section | [Back to Back SWE](https://backtobackswe.com/platform/content/graphs-fundamentals) |
| Introduction to Algorithms | Adjacency Matrix | Thomas e.t. al. |
| Graph | None, but see quizzes. | Visualgo |

