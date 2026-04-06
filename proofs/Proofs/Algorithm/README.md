# What to Prove Next?

### 1. Relationship Between Leaves and Internal Nodes

For a finite rooted $n$-ary tree with $i$ internal nodes (nodes with at least one child), the number of leaves $l$ satisfies:

$$
l = 1 + (n-1)i - \sum_{v} (n - \deg(v))
$$

where the sum is over all internal nodes $v$, and $\deg(v)$ is the number of children of $v$.

In a **full** $n$-ary tree (every internal node has exactly $n$ children):

$$
l = 1 + (n-1)i
$$

---

### 2. Vertex and Edge Count

For any finite tree (not necessarily binary or full):

$$
|V| = |E| + 1
$$

where $|V|$ is the number of vertices and $|E|$ is the number of edges.

---

### 3. Prüfer Sequence and $n$-ary Trees

For labeled trees, the Prüfer code gives a bijection between labeled trees on $n$ vertices and sequences of length $n-2$.

For $n$-ary trees, the set of sequences corresponding to valid $n$-ary trees is much smaller, and their enumeration is related to generalized Catalan numbers.

---

### 4. Enumeration: Generalized Catalan Numbers

The number of rooted, unlabeled, ordered $n$-ary trees with $k$ internal nodes is given by:

$$
C_k = \frac{1}{(n-1)k+1} \binom{nk}{k}
$$

---

### 5. Height Distribution in Random $n$-ary Trees

The expected height of a random $n$-ary tree with $k$ nodes grows as $O(\sqrt{k})$, not linearly.

---

### 6. Uniqueness from Leaf-to-Root Paths

Every finite rooted $n$-ary tree is uniquely determined by its set of leaf-to-root paths.

---

### 7. Perfect $n$-ary Tree Node Count

If all leaves are at the same depth (a "perfect" $n$-ary tree) and the height is $h$, then the total number of nodes is:

$$
\frac{n^{h+1} - 1}{n - 1}
$$

---

### 8. Expected Number of Leaves in Random Labeled $n$-ary Trees

For a random labeled $n$-ary tree on $n$ vertices, the expected number of leaves approaches $n/e$ as $n \to \infty$.

---

### 9. Counting Unlabeled $n$-ary Tree Shapes

The number of different shapes of unlabeled rooted $n$-ary trees with $k$ nodes can be much less than the number of labeled trees. Counting these shapes exactly is a hard combinatorial problem.

---

### 10. Unique Shortest Path Characterization

A tree is characterized by the property that the shortest path between any two nodes is unique. This property is equivalent to being connected and acyclic.
