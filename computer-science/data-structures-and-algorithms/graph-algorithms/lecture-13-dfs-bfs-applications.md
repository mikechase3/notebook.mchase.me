# Weighted Graphs \(L13\)

## Weighted Digraphs

* In [lecture 12](lecture-12-graph-fundamentals.md), we used directed graphs and showed that we store all the node objects as integers.
* Adjacency lists store outgoing nodes we point to in the Adjacency list. 

![](../../../.gitbook/assets/image%20%2882%29.png)

When it comes to directed **weighted** graphs; however, we also have to specify the weight. In the example below, we'll store the **weights** as doubles as a new parameter in our adjacency list.

![](../../../.gitbook/assets/image%20%2883%29.png)

### Weighted Digraph Implementation

```java
public class DirectedEdge{ //Define a class for the edge.

    //Class Variables. Edges are only declared once.
    private final int v, w;
    private final double weight;
    
    //Constructor to make the directed edge.
    public DirectedEdge(int v, int w, double weight){
        this.v = v;
        this.w = w;
        this.weight = weight;
    }
    
    // Member Methods; (v is source, w is destination).
    
    //Find the source node.
    public int from(){ //endpoint v of edge v->w
        return v;
    }
    
    //Find the destination node.
    public int to(){ //Endpoint v -> w
        return w;
    }
    
    public double weight(){
        return weight;
    }
}
```

### Importing Graph Nodes & Edges

```java
Google how to import graphs nodes and edges from a text file.
```

{% hint style="info" %}
Breadth First Search is covered just a bit in lecture 13, but is primarily discussed in lecture 14 so I put it there. 
{% endhint %}

## Works Cited

| Title | Content Used | Author |
| :--- | :--- | :--- |
| CPS 450 Class | Structure | [Dr. Zhongmei Yao](https://udayton.edu/directory/artssciences/computerscience/yao_zhongmei.php) |
| [Graphs Fundamentals](https://backtobackswe.com/platform/content/graphs-fundamentals) | Fundamentals Section | [Back to Back SWE](https://backtobackswe.com/platform/content/graphs-fundamentals) |
| Visualization | Visualization Screenshots | Visualgo |



