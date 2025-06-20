import Mathlib.Data.List.Basic
import Mathlib.Data.Nat.Basic
import Mathlib.Tactic

namespace BinTree

variable {α : Type*}

inductive BinaryTree (α : Type*) where
  | leaf : BinaryTree α
  | node : BinaryTree α → α → BinaryTree α → BinaryTree α

variable {btree : BinaryTree α} {val : α} {left right : BinaryTree α}

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

-- Compute the size of a binary tree.
def BinaryTree.size : BinaryTree α → Nat
  | BinaryTree.leaf => 0 -- By definition, leaves have size zero.
  | BinaryTree.node left _ right => 1 + BinaryTree.size left + BinaryTree.size right -- Size is one plus the size of left and right subtrees.

-- Compute the depth of a binary tree.
def BinaryTree.depth : BinaryTree α → Nat
  | BinaryTree.leaf => 0 -- Depth of a leaf is zero.
  | BinaryTree.node left _ right => 1 + max (BinaryTree.depth left) (BinaryTree.depth right) -- Depth is one plus the maximum depth of left and right subtrees.

-- 1. The size of a leaf is zero.
theorem BinaryTree.leaf_size [DecidableEq α] : size (leaf : BinaryTree α) = 0 := by rfl

-- 2. The size of a node is one plus the size of its left and right subtrees.
theorem BinaryTree.node_size [DecidableEq α] (left : BinaryTree α) (val : α) (right: BinaryTree α) :
  size (node left val right) = 1 + size left + size right := by rfl

-- 3. All leaf values are structurally equal — there’s only one leaf.
theorem BinaryTree.leaf_unique [DecidableEq α] (t1 t2 : BinaryTree α) (h1 : t1 = leaf) (h2 : t2 = leaf) : t1 = t2 := by
  rw [h1, h2]

-- Swap the subtrees of a binary tree.
def BinaryTree.swap : BinaryTree α → BinaryTree α
  | leaf => leaf -- Swapping a leaf results in a leaf.
  | node left val right => node right val left -- Swap the left and right subtrees.

-- 4. Swapping the left and right subtrees of a node twice gives back the original tree.
theorem BinaryTree.double_swap [DecidableEq α] (t : BinaryTree α) : swap (swap t) = t := by
  induction t with
  | leaf => rfl
  | node left val right ih_left ih_right => rw [← ih_left, ← ih_right, swap, swap]

-- 5. The depth of any tree is always greater than or equal to zero.
theorem BinaryTree.depth_nonneg [DecidableEq α] (t : BinaryTree α) : depth t ≥ 0 := by
  induction t with
  | leaf => rfl
  | node left val right ih_left ih_right => simp

end BinTreeFacts

end BinTree
