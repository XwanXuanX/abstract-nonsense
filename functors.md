## Functor

### Homomorphism

* A graph homomorphism $f$ is a function from one graph to another graph such that if vertex $u$ is linked to vertex $v$, then $f(u)$ is linked to $f(v)$.

* Morphism = arrow

### Monoid

* A category with only one object $A$, the identity arrow $id_A$, and many other self-loop arrows.

* A monoid is a structured set, such as $\{+, \{..., -1, 0, 1, ...\}\}$

* Formal definition later!

### Isomorphism

* Imagine two sets $A$ and $B$. There exists a one-to-one mapping $f$ such that $f: A \mapsto B$. There exists another one-to-one mapping $g$ such that $g: B \mapsto A$, and $g$ is the inverse of $f$.

* If compose $f$ and $g$, we get the identity arrows for $A$ and $B$: $$g \circ f: A \mapsto A$$ $$f \circ g: B \mapsto B$$

* **Formal definition**: An arrow $f: A \mapsto B$ is an isomorphism if there exists $g: B \mapsto A$ such that $g \circ f = id_A$ and $f \circ g = id_B$.
