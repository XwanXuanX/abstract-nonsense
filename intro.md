## Definition of a category

### What is a category

A category is a collection of objects, with arrows between objects.

### What is function composition

If $f: A \mapsto B$ and $g: B \mapsto C$, then $g \circ f: A \mapsto C$.

### Identity arrows

* Every object must have an arrow going from itself to itself. For every object $B$, we have an identity arrow $id_B: B \mapsto B$ such that $id_B \circ f = f$ and $g \circ id_B = g$.

* If we compose identity arrows with other arrows, we just get the other arrow back, like a do nothing operation.

### Associtivity

* $h \circ (g \circ f) = (h \circ g) \circ f = h \circ g \circ f$

* The order that you compose arrows does not matter.


## Set

* $Set$ is a category (not to confuse with set) that, has objects as sets and arrows as functions.

* Imagine having 3 sets, $A$, $B$, and $C$. They are objects in the category of $Set$. There are functions, say $f$ and $g$, such that $f: A \mapsto B$ and $g: B \mapsto C$. The composition of $f$ and $g$, $g \circ f: A \mapsto C$.

### Final object

A final object $F$ is an object such that for any object $A$ there is a unique arrow $$g: A \mapsto F$$

#### What is the final object in the category of $Set$?

* A set with only one element, $1$, or the singleton set.

* This is because it's obvious that for any set, $A$, we can define a mapping function $f$, such that $f: A \mapsto 1$. $f$ will simply map each element in $A$ to that single element in $1$.
