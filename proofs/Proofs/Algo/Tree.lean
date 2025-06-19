import Mathlib.Data.List.Basic
import Mathlib.Data.Nat.Basic
import Mathlib.Tactic

namespace BinTree

variable {α : Type*}

inductive BinaryTree (α : Type*) where
  | leaf : BinaryTree α
  | node : BinaryTree α → α → BinaryTree α → BinaryTree α

section BinTreeFacts

/-
Let's remind you that the definition of a binary tree is as follows:
```
inductive BinaryTree (α : Type*) where
  | leaf : BinaryTree α
  | node : BinaryTree α → α → BinaryTree α → BinaryTree α
```

# Facts about Binary Trees (suggested by ChatGPT)
1. The size of a leaf is zero.
2. The size of a node is one plus the size of its left and right subtrees.
3. All leaf values are structurally equal — there’s only one leaf.
4. Swapping the left and right subtrees of a node twice gives back the original tree.
5. The depth of any tree is always greater than or equal to zero.
6. The number of values (of type α) stored in a tree equals the number of node constructors.
7. If two binary trees are equal, then their left subtrees, values, and right subtrees must also be equal.
8. A tree made of only one node has depth 1 and size 1.
9. A leaf is not a node.
10. If a tree has depth 0, it must be a leaf.
11. The size of a swapped tree is the same as the original.
12. If two trees have the same structure and the same values in the same positions, they are equal.
13. There exists a tree of size n for every natural number n.
14. Any tree can be mirrored (swapping left and right subtrees recursively) to get another valid tree.
15. If two mirrored trees are equal, then the tree must be symmetric.
16. A tree with only leafs as children of the root has depth 1.
17. The maximum depth of a tree with n nodes is n.
18. The minimum depth of a tree with n nodes is ⌈log₂(n + 1)⌉. (more mathematical — optional for Lean)
19. If all leaves are at the same depth and every node has two children, the tree is full.
20. The number of leaves in a full binary tree is one more than the number of internal nodes.

**Have fun proving :3**
-/

end BinTreeFacts

end BinTree
