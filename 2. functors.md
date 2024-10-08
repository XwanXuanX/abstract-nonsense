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

* Any two terminal objects are isomorphic! Terminal objects in the category of $Set$ are any set that contains only one element. For terminal objects $A$ and $B$, there exists two one-to-one mapping $f$ and $g$ that maps one element to the other, and vice versa. Thus any two terminal objects are isomorphic by definition.

### Functor

* A function goes from a set to another, whereas a functor goes from one category to another, and it preserves the structure of the category.

* Imagine having two categories, $\mathfrak{C}$ and $\mathfrak{D}$. $F$ is a functor goes from $\mathfrak{C}$ to $\mathfrak{D}$ such that:
  
  * For each object $A$ in $\mathfrak{C}$, we have $F(A)$ in $\mathfrak{D}$
  * For each arrow $f: A \mapsto B$ in $\mathfrak{C}$, we have $F(f): F(A) \mapsto F(B)$ in $\mathfrak{D}$
  * $F(g) \circ F(f) = F(g \circ f)$
  * $F(id_A) = id_{F(A)}$

## More categories of structured sets (categories)

### $Mon$

Objects in $Mon$ are monoids (which themselves are categories), arrows between objects are functors (a.k.a. monoidmorphism).

### $Pre$

Objects in $Pre$ are preordered sets (which themselves are categories), and arrows as functors. When $a \leq b$, then $F(a) \leq F(b)$ (where $a \leq b$ means there is an arrow going from $b$ to $a$).

## Other types of functors

### Covariant functor

* Normal functor, preserves the structure.

* If $F$ is a covariant functor, then for all $f: A \mapsto B$, $F(f): F(A) \mapsto F(B)$ and $F(g \circ f) = F(g) \circ F(f)$.

### Contravariant functor

* Reverse the arrow directions, including functions and function compositions.

* If $F$ is a contravariant functor, then for all $f: A \mapsto B$, $F(f): F(B) \mapsto F(A)$ and $F(g \circ f) = F(f) \circ F(g)$.
