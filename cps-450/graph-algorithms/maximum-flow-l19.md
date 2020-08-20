# Maximum Flow \(L19\)

## Flow Network Terminology

![](../../.gitbook/assets/image%20%2891%29.png)

### Definition

**Notation:** Flow/Capacity

<table>
  <thead>
    <tr>
      <th style="text-align:left">Term</th>
      <th style="text-align:left">Definition</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align:left">G</td>
      <td style="text-align:left">Graph is directed.</td>
    </tr>
    <tr>
      <td style="text-align:left">Edge</td>
      <td style="text-align:left">
        <ol>
          <li>Each <em><b>edge </b></em> has a <em><b>capacity</b></em><b> </b> 
          </li>
          <li>If <em>edge<b> </b></em> 
          </li>
        </ol>
      </td>
    </tr>
    <tr>
      <td style="text-align:left">Reverse Edges</td>
      <td style="text-align:left">If <em>edge</em> 
      </td>
    </tr>
    <tr>
      <td style="text-align:left">Source Vertex <em>(s)</em>
      </td>
      <td style="text-align:left">Where the flow comes from.</td>
    </tr>
    <tr>
      <td style="text-align:left">Sink Vertex <em>(t)</em>
      </td>
      <td style="text-align:left">Where all the flow points to; no outgoing edges.</td>
    </tr>
    <tr>
      <td style="text-align:left">Vertex <em>(v)</em>
      </td>
      <td style="text-align:left">Each vertex lies on a path from the source to the sink.</td>
    </tr>
    <tr>
      <td style="text-align:left">Capacity Constraint</td>
      <td style="text-align:left"></td>
    </tr>
    <tr>
      <td style="text-align:left">Flow Conservation</td>
      <td style="text-align:left">
        <p></p>
        <p>The flow going into all the edges is the same going out of all the edges.</p>
      </td>
    </tr>
    <tr>
      <td style="text-align:left">Flow</td>
      <td style="text-align:left">
        <p>The total amount currently going out of the source node - flow going into
          the source node (usually none).</p>
        <p></p>
      </td>
    </tr>
    <tr>
      <td style="text-align:left"></td>
      <td style="text-align:left"></td>
    </tr>
  </tbody>
</table>

## Ford-Fulkerson Method

* Applications: Maximize data flowing through a network, utilizing all possible paths from source to destination.
* _Augmenting Path_: We're increasing flow in the network.
* _Residual Network:_ The leftovers.

```text
Iniialize flow f to all 0's:
while (there is an augmenting path p in residual network Gf):
    augment flow f along p
return f
```

## Residual Networks

#### What is a residual network?

It's an entirely new graph, but we're defining all the nodes and edges by how much free-space they have at each edge. More formally:

$$G_f = (V, E_f)$$ describes a residual network. The edges with residual capacities, $$E_f$$ describe how we can change the _flow_ on edges of $$G=(V,E)$$ 

If an edge _\(u, v\)_ in _G_ can admit additional flow, we place the edge into $$G_f$$ with a _residual capacity_ $$c_f (u,v) = c(u, v) - f(u, v)$$ . Edges where$$c_f (u, v) = 0 \implies c_f(u, v) \notin G_f$$ 



