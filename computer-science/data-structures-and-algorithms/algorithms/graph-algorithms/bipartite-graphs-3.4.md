# Bipartite Graphs (3.4)

## Introduction

* Bipartite grpahs can be colored red & blue.
* If you can represent a problem using bipartite graphs, you can find smart solutions.
* Stable marriage: men = red & women = blue. (Not stable marriage problem, but compatibility)
* Scheduling: machines = red & jobs = blue.

## Testing Barpititeness

* Tractable if the underlying graph is bipartite. (And independent set)
* To see if graph `G` is **bipartite**, we'll {idk}

### Obstruction to Bipartiteness

* **Lemma**: If a graph G is bipartite, it cannot contain an odd length cycle.
* **Contrapositive**: if a graph G contains an odd length cycle, then it can't be bipartite.
  * Use breadth first search to see if it has a cycle.
* **PF**: it's not possible to 2-color the odd cycle, let alone G.
* If there's any connections between a _red/red_ or _blue/blue_, it's not bipartite.

## Bipartite Graphs

![](../../../../.gitbook/assets/image.png)
