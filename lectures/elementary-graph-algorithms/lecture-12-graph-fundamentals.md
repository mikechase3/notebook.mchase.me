# Lecture 12: Graph Fundamentals

## Graph Representations

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

## Gathering Nodes and Edges From Files



#### The Text File

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

{% hint style="warning" %}
What is the x and y value for the nodes?
{% endhint %}

## Breadth First Search

## Depth First Search

## 

