# Graph Representations (L12)

## Adjacency Matrix

* **Disadvantages**: Space is proportional to `n^2`.
  * Two representations of each edge.
* **Advantages**: checking if `(u,v)` is an edge takes O(1) time.&#x20;

<figure><img src="../../../../.gitbook/assets/image (647).png" alt="" width="375"><figcaption><p>From MTSU.edu</p></figcaption></figure>

## Adjacency List

* Node indexed array of list
* There are two representations of each edge.
* **Space** is proportional to `m` + `n`.&#x20;
  * `m` is the node.
  * `n` is an edge.
  * There are `m` total nodes.
* **Disadvantage**: lookups are more expensive & not constant time.
* We'll say there's a connection between `node u` and `node v`.&#x20;

<figure><img src="../../../../.gitbook/assets/image (650).png" alt=""><figcaption><p>From MTSU</p></figcaption></figure>

## Paths and Connectivity

<figure><img src="../../../../.gitbook/assets/image (651).png" alt="" width="375"><figcaption></figcaption></figure>

Not listed:

* **Cycles**: blah

## Trees

* **Trees**: an undirected graph is a tree if it's connected & doesn't contain a cycle.
  * **Theorem**: let `G` b an undirected graph on `n` nodes. Any two of the following statements imply the third.
  * 1\) G is connected
  * 2\) G does not contain a cycle
  * 3\) G has n-1 edges

### Rooted Trees

* They have a root node at the top level & there are parent/children relationships within the nodes.

#### Example: Phylogeny Trees

<figure><img src="../../../../.gitbook/assets/image (656).png" alt="" width="375"><figcaption></figcaption></figure>

#### GUI Containment Hierarchy

GUIs contain roots, frames, and objects within those frames. The components like `ComboBox` or `JFrame` are contained within trees.



