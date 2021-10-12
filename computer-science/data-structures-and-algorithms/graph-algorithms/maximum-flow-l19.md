# Maximum Flow (L19)

## Flow Network Terminology

![](<../../../.gitbook/assets/image (91).png>)

### Definition

**Notation: **Flow/Capacity

| Term                | Definition                                                                                                                                                                                                                                                                                          |
| ------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| G                   | Graph $$G=(V,E)$$ is directed.                                                                                                                                                                                                                                                                      |
| Edge                | <ol><li>Each <em><strong>edge </strong></em><span class="math">(u,v)</span> has a <em><strong>capacity</strong></em><strong> </strong><span class="math">c(u,v)  \geq 0 </span> </li><li>If <em>edge<strong> </strong></em><span class="math">(u,v) \notin E \implies c(u,v) = 0</span>  </li></ol> |
| Reverse Edges       | If _edge_ $$(u,v) \in E \implies \texttt{the reverse edge } (v,u) \notin E$$                                                                                                                                                                                                                        |
| Source Vertex _(s)_ | Where the flow comes from.                                                                                                                                                                                                                                                                          |
| Sink Vertex _(t)_   | Where all the flow points to; no outgoing edges.                                                                                                                                                                                                                                                    |
| Vertex _(v)_        | Each vertex lies on a path from the source to the sink.                                                                                                                                                                                                                                             |
| Capacity Constraint | $$\forall (u,v) \in V \implies 0 \leq f(u,v) \leq c(u,v)$$                                                                                                                                                                                                                                          |
| Flow Conservation   | <p><span class="math">\forall (u\in V) - \{s, t\} \implies \sum_{v \in V}^{} f(u,v) = \sum_{v \in V} f(u,v) </span> </p><p>The flow going into all the edges is the same going out of all the edges.</p>                                                                                            |
| Flow                | <p>The total amount currently going out of the source node - flow going into the source node (usually none).</p><p><span class="math">\sum_{v \in V} f(s,v) - \sum f(v,s)</span> </p>                                                                                                               |
|                     |                                                                                                                                                                                                                                                                                                     |

## Ford-Fulkerson Method

* Applications: Maximize data flowing through a network, utilizing all possible paths from source to destination.
* _Augmenting Path_: We're increasing flow in the network.
* _Residual Network: _The leftovers.

```
Iniialize flow f to all 0's:
while (there is an augmenting path p in residual network Gf):
    augment flow f along p
return f
```

## Residual Networks

#### What is a residual network?

It's an entirely new graph, but we're defining all the nodes and edges by how much free-space they have at each edge. More formally:

$$G_f = (V, E_f)$$ describes a residual network. The edges with residual capacities, $$E_f$$ describe how we can change the _flow_ on edges of $$G=(V,E)$$ 

If an edge _(u, v)_ in _G_ can admit additional flow, we place the edge into $$G_f$$ with a _residual capacity _$$c_f (u,v) = c(u, v) - f(u, v)$$ . Edges where$$c_f (u, v) = 0 \implies c_f(u, v) \notin G_f$$ 

