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

| Name | Description |
| :--- | :--- |
| s-t path | Is there a path between `s` and `t`? |
| Shortest s-t path | What is the shortest path between `s` and `t`? |
| Cycle | Is there a cycle in the graph? |
| Euler Cycle | Is there a cycle that uses each edge exactly once? |
| Hamilton Cycle | Is there a cycle that uses each vertex exactly once? |
| Connected Components | Find connected components |
| Bioconnectivity | Is there a vertex whose removal disconnects the graph? |
| Plalanarity | Can the graph be drawn in the plane with no crossing edges? |
| Graph isomorphism | Are two graphs isomorphic? \(They are equivalent even though they look differently? |

Words



## Breadth First Search

## Depth First Search

## 

