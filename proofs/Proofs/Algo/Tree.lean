import Mathlib.Data.List.Basic
import Mathlib.Data.Nat.Basic
import Mathlib.Data.Finset.Basic
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

-- Obtain the left subtree of a binary tree.
def BinaryTree.getLeft : BinaryTree α → BinaryTree α
  | leaf => leaf -- The left subtree of a leaf is a leaf.
  | node left _ _ => left -- The left subtree of a node is its left child

-- Obtain the right subtree of a binary tree.
def BinaryTree.getRight : BinaryTree α → BinaryTree α
  | leaf => leaf -- The right subtree of a leaf is a leaf.
  | node _ _ right => right -- The right subtree of a node is its right child

-- Obtain the value of a binary tree node.
def BinaryTree.getVal : BinaryTree α → Option α
  | leaf => none -- A leaf has no value.
  | node _ val _ => some val -- A node has a value.

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

-- 7. If two binary trees are equal, then their left subtrees, values, and right subtrees must also be equal.
theorem BinaryTree.eq_of_eq [DecidableEq α] {t1 t2 : BinaryTree α} :
  t1 = t2 ↔ (getLeft t1 = getLeft t2) ∧ (getRight t1 = getRight t2) ∧ (getVal t1 = getVal t2) := by
  constructor
  · -- Prove if trees are equal, their components are equal.
    intro h; rw [h]
    constructor; rfl; constructor; rfl; rfl
  · -- Prove if components are equal, trees are equal.
    intro h
    obtain ⟨h_left, h_right, h_val⟩ := h
    -- Enumerate the cases for t1 and t2.
    cases t1 <;> cases t2
    case leaf.leaf => rfl
    case leaf.node | node.leaf => contradiction
    case node.node =>
      simp [getLeft, getRight, getVal] at h_left h_right h_val
      rw [h_left, h_right, h_val]

-- 8. A tree made of only one node has depth 1 and size 1.
theorem BinaryTree.single_node_depth_size [DecidableEq α] (val : α) :
  depth (node leaf val leaf) = 1 ∧ size (node leaf val leaf) = 1 := by
  simp [depth, size]

-- 9. A leaf is not a node.
theorem BinaryTree.leaf_not_node [DecidableEq α] (t : BinaryTree α) (h : t = leaf) :
  ¬ ∃left val right, t = node left val right := by
  by_contra h1
  obtain ⟨left, val, right, h_node⟩ := h1
  rw [h] at h_node
  contradiction

-- 10. If a tree has depth 0, it must be a leaf.
theorem BinaryTree.depth_zero_is_leaf [DecidableEq α] (t : BinaryTree α) (h : depth t = 0) : t = leaf := by
  induction t with
  | leaf => rfl
  | node l v r ih_l ih_r => simp [depth] at h

-- 11. The size of a swapped tree is the same as the original.
theorem BinaryTree.swapped_size [DecidableEq α] (t : BinaryTree α) : size (swap t) = size t := by
  induction t with
  | leaf => simp [swap, size]
  | node l v r ih_l ih_r =>
    simp [swap, size, ih_l, ih_r]
    rw [Nat.add_assoc, Nat.add_assoc, Nat.add_comm (size l) (size r)]

-- 13. There exists a tree of size n for every natural number n.
theorem BinaryTree.exists_tree_of_size_n [DecidableEq α] {val : α} : ∀ n : Nat, ∃ t : BinaryTree α, size t = n := by
  intro n
  induction n with
  | zero => use leaf; simp [size]
  | succ d ih =>
    obtain ⟨t, h_size⟩ := ih
    use node t val leaf
    simp [size, h_size, Nat.add_comm]

-- Define the mirroring operation for a binary tree.
def BinaryTree.mirror : BinaryTree α → BinaryTree α
  | leaf => leaf -- Mirroring a leaf results in a leaf.
  | node left val right => node (mirror right) val (mirror left) -- Swap the left and right subtrees recursively.

-- Define the symmetric property for a binary tree.
def BinaryTree.symmetric (t : BinaryTree α) : Prop :=
  t = mirror t -- A tree is symmetric if it is equal to its mirrored version.

-- Function to check if a binary tree is symmetric.
def BinaryTree.is_symmetric [DecidableEq (BinaryTree α)] (t : BinaryTree α) : Bool :=
  if t = mirror t then true else false

-- 16. A tree with only leafs as children of the root has depth 1.
theorem BinaryTree.leafs_as_children_depth [DecidableEq α] (val : α) :
  depth (node leaf val leaf) = 1 := by
  simp [depth]

-- 17. The maximum depth of a tree with n nodes is n.
-- Notice that this formalization states that: *depth of the tree is bounded by its size*
-- Which is equivalent to the fact that we want to prove.
theorem BinaryTree.max_depth_n_nodes [DecidableEq α] : ∀ t : BinaryTree α, depth t ≤ size t := by
  intro t
  induction t with
  | leaf => rfl
  | node l v r ih_l ih_r =>
    simp [depth, size, Nat.add_assoc]
    constructor
    show l.depth ≤ l.size + r.size
    · have claim1 : l.size ≤ l.size + r.size := by
        exact Nat.le_add_right l.size r.size
      exact Nat.le_trans ih_l claim1
    show r.depth ≤ l.size + r.size
    · have claim1 : r.size ≤ l.size + r.size := by
        rw [Nat.add_comm]
        exact Nat.le_add_right r.size l.size
      exact Nat.le_trans ih_r claim1

-- Definition of the `Full` predicate
inductive BinaryTree.Full : BinaryTree α → Prop where
  | nil : Full leaf
  | cons : ∀ (l r : BinaryTree α) (x : α),
    Full l → Full r → (l = leaf ↔ r = leaf) → Full (node l x r)

-- Function to check if the binary tree is full.
-- A full binary tree is one where every node has either 0 or 2 children.
def BinaryTree.isFull : BinaryTree α → Bool
  | leaf => true
  | node left _ right =>
    match left, right with
    | leaf, leaf => true
    | leaf, _ => false
    | _, leaf => false
    | _, _ => isFull left && isFull right

-- Function to compute the number of leaves in the binary tree
def BinaryTree.numLeaves : BinaryTree α → Nat
  | leaf => 1
  | node left _ right => numLeaves left + numLeaves right

-- Prove that BinaryTree.isFull is correct
theorem BinaryTree.is_full_correct [DecidableEq α] {t : BinaryTree α} : isFull t = true ↔ Full t := by
  constructor
  -- Prove .mp
  show t.isFull = true → t.Full
  · intro h
    induction t with
    | leaf => exact Full.nil
    | node ltree x rtree ihl ihr =>
      cases ltree <;> cases rtree
      case leaf.leaf =>
        have : (leaf : BinaryTree α) = leaf ↔ (leaf : BinaryTree α) = leaf := by simp
        exact Full.cons leaf leaf x Full.nil Full.nil this
      case leaf.node | node.leaf =>
        simp [isFull] at h
      case node.node =>
        rename_i l1 v1 r1 ll vv rr
        -- Need Full (node l1 v1 r1) and Full (node ll vv rr)
        -- and node l1 v1 r1 = leaf ↔ node ll vv rr (this is easy to prove)
        have claim1 : Full (node l1 v1 r1) := by simp_all [isFull]
        have claim2 : Full (node ll vv rr) := by simp_all [isFull]
        have claim3 : node l1 v1 r1 = leaf ↔ node ll vv rr = leaf := by simp
        exact Full.cons (l1.node v1 r1) (ll.node vv rr) x claim1 claim2 claim3

  -- Prove .mpr
  show t.Full → t.isFull = true
  · intro h
    induction h with
    | nil => simp [isFull]
    | cons ltree rtree x hl hr ih_leaf ih_l ih_r =>
      simp [isFull, ih_l, ih_r]
      cases ltree <;> cases rtree
      case leaf.leaf => simp
      case leaf.node | node.leaf => simp at ih_leaf ih_l
      case node.node => simp

-- Prove that if Full (node ltree x rtree) then Full ltree AND Full rtree
lemma BinaryTree.full_node_imp_full_lr [DecidableEq α] {ltree rtree : BinaryTree α} {x : α}
  (h : Full (node ltree x rtree)) : Full ltree ∧ Full rtree := by
  constructor
  show ltree.Full
  · cases h with
    | cons ltree rtree x ihl ihr ih_leaf => exact ihl
  show rtree.Full
  · cases h with
    | cons ltree rtree x ihl ihr ih_leaf => exact ihr

-- 20. The number of leaves in a full binary tree is one more than the number of internal nodes.
theorem BinaryTree.num_leaf_in_full_tree [DecidableEq α] (t : BinaryTree α)
  (h : isFull t = true) : numLeaves t = size t + 1 := by
  rw [is_full_correct] at h
  induction t with
  | leaf => rfl
  | node ltree x rtree ihl ihr =>
    rw [numLeaves, size]
    -- Need Full ltree and Full rtree
    -- Intuitively this is true, since Full (node ltree x rtree), this implies claim
    have claim : Full ltree ∧ Full rtree := by exact full_node_imp_full_lr h
    obtain ihl := ihl claim.left
    obtain ihr := ihr claim.right
    rw [ihl, ihr, Nat.add_comm ltree.size, ← Nat.add_assoc]

-- Prove that the maximum number of nodes at depth d in any binary tree is 2^d (where d = 0 is root).
-- Restate the definition as: size of a binary tree is bounded by 2^(depth t) - 1
theorem BinaryTree.max_nodes_at_depth [DecidableEq α] (t : BinaryTree α) : size t < 2 ^ (depth t) := by
  induction t with
  | leaf => simp [size, depth]
  | node ltree x rtree ihl ihr =>
    simp [size, depth]
    have claim1 : ∀ n : Nat, 2 ^ (1 + n) = 2 * 2 ^ n := by
      intro n; simp [Nat.add_comm, ← Nat.succ_eq_add_one, Nat.pow_succ, Nat.mul_comm]
    rw [claim1 (max ltree.depth rtree.depth)]
    have claim2 : ∀ n m : Nat, 2 ^ (max n m) = max (2 ^ n) (2 ^ m) := by
      intro n m;
      by_cases hcase1 : n ≤ m
      · simp [Nat.max_def, hcase1]
        intro hcase2;
        have hcase3 : m < n := by
          exact (Nat.pow_lt_pow_iff_right (by decide)).mp hcase2
        linarith
      · push_neg at hcase1
        simp [Nat.max_def, hcase1, if_neg]
        intro hcase2;
        exfalso
        have hcase3 : n ≤ m := by
          exact (Nat.pow_le_pow_iff_right (by decide : 1 < 2)).mp hcase2
        linarith
    rw [claim2 ltree.depth rtree.depth, Nat.max_def]
    -- Finally, we isolated the 2 ^ (depth t) term
    by_cases hcase1 : 2 ^ ltree.depth ≤ 2 ^ rtree.depth
    · simp [hcase1]; linarith [ihr, ihl]
    · simp [hcase1]; linarith [ihr, ihl]

end BinTreeFacts

section BinTreeAlgos

-- Typical inorder traversal algorithm for binary trees.
def BinaryTree.inorder [DecidableEq α] : BinaryTree α → Finset α
  | leaf => ∅
  | node left val right => inorder left ∪ {val} ∪ inorder right

-- Typical preorder traversal algorithm for binary trees.
def BinaryTree.preorder [DecidableEq α] : BinaryTree α → Finset α
  | leaf => ∅
  | node left val right => {val} ∪ preorder left ∪ preorder right

-- Typical postorder traversal algorithm for binary trees.
def BinaryTree.postorder [DecidableEq α] : BinaryTree α → Finset α
  | leaf => ∅
  | node left val right => postorder left ∪ postorder right ∪ {val}

-- Define membership for a node in a binary tree.
def BinaryTree.contains [DecidableEq α] : α → BinaryTree α → Prop
  | _, leaf => false -- A leaf cannot contain any value.
  | x, node l v r => x = v ∨ contains x l ∨ contains x r

-- This version of `contains` is decidable.
def BinaryTree.contains' [DecidableEq α] : α → BinaryTree α → Bool
  | _, leaf => false
  | x, node l v r => if x = v then true else contains' x l || contains' x r

-- Prove that the `contains` function is correct.
theorem BinaryTree.contains'_iff_contains [DecidableEq α] (x : α) (t : BinaryTree α) :
  contains' x t = true ↔ contains x t := by
  constructor
  all_goals
  · intro h
    induction t with
    | leaf => contradiction
    | node l v r ihl ihr =>
      simp_all [contains', contains]
      rcases h with ha | hb | hc
      ·  -- x = v
        left;
        exact ha
      · -- x ∈ left subtree
        right; left;
        exact ihl hb
      · -- x ∈ right subtree
        right; right;
        exact ihr hc

-- Define the number of operations needed to traverse a binary tree with inorder.
def BinaryTree.inorder_time [DecidableEq α] : BinaryTree α → Nat
  | leaf => 0 -- Traversing a leaf takes no time.
  | node left _ right => 1 + inorder_time left + inorder_time right

-- Prove that inorder traversal of a binary tree contains all its values.
-- that is, if traverse from the root, then it's guaranteed to visit all nodes.
theorem BinaryTree.inorder_visits_all_nodes [DecidableEq α] (x : α)
  (t : BinaryTree α) : contains x t ↔ x ∈ inorder t := by
  constructor
  -- Prove the forward direction
  show contains x t → x ∈ inorder t
  · intro h
    induction t with
    | leaf => contradiction
    | node ltree v rtree ihl ihr =>
      simp_all [contains, inorder]
      rcases h with ha | hb | hc
      · right; left
        exact ha
      · left
        exact ihl hb
      · right; right
        exact ihr hc

  -- Prove the reverse direction
  show x ∈ inorder t → contains x t
  · intro h
    induction t with
    | leaf => contradiction
    | node ltree v rtree ihl ihr =>
      simp_all [contains, inorder]
      rcases h with ha | hb | hc
      · right; left
        exact ihl ha
      · left
        exact hb
      · right; right
        exact ihr hc

-- Prove that inorder traversal has a tight bound of O(n)
theorem BinaryTree.inorder_time_bound [DecidableEq α] (t : BinaryTree α) :
  ∃ (C₁ C₂ D₁ D₂ : ℕ), C₁ * size t + D₁ ≤ inorder_time t ∧ inorder_time t ≤ C₂ * size t + D₂ := by
  use 1, 1, 0, 0 -- Constants for the big-O bound
  have claim1 (a b c d : Nat) (h1 : a ≤ b) (h2 : c ≤ d) : a + c ≤ b + d := by
    exact Nat.add_le_add h1 h2
  constructor
  · -- Prove the lower bound
    simp [inorder_time, size]
    induction t with
    | leaf => simp [inorder_time, size]
    | node ltree v rtree ihl ihr =>
      simp [inorder_time, size, Nat.add_assoc]
      exact claim1 ltree.size ltree.inorder_time rtree.size rtree.inorder_time ihl ihr
  · -- Prove the upper bound
    simp [inorder_time, size]
    induction t with
    | leaf => simp [inorder_time, size]
    | node ltree v rtree ihl ihr =>
      simp [inorder_time, size, Nat.add_assoc]
      exact claim1 ltree.inorder_time ltree.size rtree.inorder_time rtree.size ihl ihr

-- In a binary tree, there is a unique path between the root and any given node.

-- Represent a path from root to a node as a sequence of left and right turns.
inductive BinaryTree.Dir : Type
  | left | right
  deriving DecidableEq, Repr

abbrev BinaryTree.Path := List BinaryTree.Dir

-- Define a function to find the node given a path from the root.
def BinaryTree.follow_path [DecidableEq α] (t : BinaryTree α) (path : Path) : Option α :=
  match t, path with
  | leaf, _ => none
  | node _ v _, [] => some v
  | node l _ _, Dir.left :: rest => follow_path l rest
  | node _ _ r, Dir.right :: rest => follow_path r rest

-- Define a function to produce a path from the root to a node.
def BinaryTree.search_path [DecidableEq α] (t : BinaryTree α) (v : α) : Option Path :=
  if contains' v t then
    let rec search (cur : BinaryTree α) (v : α) (p : Path) : Option Path :=
      match cur with
      | leaf => none
      | node ltree val rtree =>
        if val = v then some p
        else if contains' v ltree then search ltree v (p ++ [Dir.left])
        else search rtree v (p ++ [Dir.right])
    search t v [] -- Start searching from the root with an empty path.
  else
    none -- If the value is not in the tree, return none.

-- Define a function to collect all node values from a binary tree.
def BinaryTree.collect_values [DecidableEq α] : BinaryTree α → List α
  | leaf => []
  | node l v r => v :: (l.collect_values ++ r.collect_values)

-- Define the proposition that all nodes in the tree have unique values.
def BinaryTree.all_unique [DecidableEq α] (t : BinaryTree α) : Prop :=
  t.collect_values.Nodup

section Testcases

open BinaryTree
open BinaryTree.Dir

/-
`exampleTree` looks like this:

        4
      /   \
     2     5
    / \     \
   1   3     6

-/

def exampleTree : BinaryTree Nat :=
  node
    (node
      (node leaf 1 leaf)
      2
      (node leaf 3 leaf))
    4
    (node
      leaf
      5
      (node leaf 6 leaf))

-- Check correctness of `search_path`
#eval search_path exampleTree 1 = some [left, left]
#eval search_path exampleTree 2 = some [left]
#eval search_path exampleTree 3 = some [left, right]
#eval search_path exampleTree 4 = some []
#eval search_path exampleTree 5 = some [right]
#eval search_path exampleTree 6 = some [right, right]
#eval search_path exampleTree 7 = none

-- Check correctness of `follow_path` as an inverse to `search_path`
#eval follow_path exampleTree (search_path exampleTree 1).get! = some 1
#eval follow_path exampleTree (search_path exampleTree 2).get! = some 2
#eval follow_path exampleTree (search_path exampleTree 3).get! = some 3
#eval follow_path exampleTree (search_path exampleTree 4).get! = some 4
#eval follow_path exampleTree (search_path exampleTree 5).get! = some 5
#eval follow_path exampleTree (search_path exampleTree 6).get! = some 6

-- By inspection, `search_path` and `follow_path` seems to be correct
-- Thus, we should keep searching for ways to prove them

end Testcases

-- Prove the correctness of the `search_path` function.
theorem BinaryTree.search_path_correct
  [DecidableEq α] (t : BinaryTree α) (v : α) (p₀ p : Path)
  (h1 : search_path.search t v p₀ = some p) (h2 : contains' v t = true)
  : ∃ q, p = p₀ ++ q ∧ follow_path t q = some v :=
by
  induction t generalizing p p₀ with
  | leaf => contradiction
  | node ltree val rtree ihl ihr =>
    unfold contains' at h2; simp at h2

    have claim1 (h : v = val)
      : ∃ q, p = p₀ ++ q ∧ (ltree.node val rtree).follow_path q = some v :=
    by
      unfold search_path.search at h1
      unfold follow_path;
      simp_all [h]

    have claim2 (hc1 : v ≠ val) (hc2 : contains' v ltree = true)
      : ∃ q, p = p₀ ++ q ∧ (ltree.node val rtree).follow_path q = some v :=
    by
      unfold search_path.search at h1
      simp [hc1.symm, hc2] at h1
      obtain ihl := ihl (p₀ ++ [Dir.left]) p h1 hc2
      obtain ⟨q, ihlq⟩ := ihl
      rcases ihlq with ⟨ihlq1, ihl12⟩
      use ([Dir.left] ++ q)
      constructor
      · simp_all
      · simp; unfold follow_path
        exact ihl12

    rcases h2 with ha | hb | hc
    · -- Case when v = val
      exact claim1 ha

    · -- Case when v ∈ left subtree
      unfold search_path.search at h1
      simp [hb] at h1
      by_cases hcase : val = v
      · exact claim1 hcase.symm
      · -- If v ≠ val, then we need to search in the left subtree
        exact claim2 (fun a ↦ hcase (id (Eq.symm a))) hb

    · -- Case when v ∈ right subtree
      unfold search_path.search at h1
      by_cases hcase : val = v
      · exact claim1 hcase.symm
      · simp [hcase] at h1
        by_cases hcase1 : contains' v ltree = true
        · exact claim2 (fun a ↦ hcase (id (Eq.symm a))) hcase1
        · simp [hcase1] at h1
          obtain ihr := ihr (p₀ ++ [Dir.right]) p h1 hc
          obtain ⟨q, ihrq⟩ := ihr
          rcases ihrq with ⟨ihrq1, ihr12⟩
          use ([Dir.right] ++ q)
          constructor
          · simp_all
          · simp; unfold follow_path
            exact ihr12

-- Prove that if a value is contained in the tree, then search_path returns a valid path.
lemma BinaryTree.path_valid [DecidableEq α] (t : BinaryTree α) (v : α) (h : contains v t)
  : (search_path.search t v []).isSome := by
  induction t with
  | leaf => simp [contains] at h
  | node ltree val rtree ihl ihr =>
    unfold contains at h

    have search_append_monotonic [DecidableEq α] (t : BinaryTree α) (v : α) (p q : Path)
      : (search_path.search t v p).isSome = true → (search_path.search t v (q ++ p)).isSome = true :=
    by
      intro h1
      induction t generalizing p with
      | leaf => contradiction
      | node ltree val rtree ihl ihr =>
        unfold search_path.search at h1
        unfold search_path.search
        by_cases hcase1 : v = val
        · simp_all [hcase1]
        · push_neg at hcase1
          by_cases hcase2 : contains' v ltree = true
          · simp_all [hcase1.symm, hcase2]
          · simp_all [hcase1.symm, hcase2]

    rcases h with ha | hb | hc
    · unfold search_path.search; simp [ha]
    · obtain ihl := ihl hb
      unfold search_path.search
      by_cases hcase1 : val = v
      · simp [hcase1]
      · simp [hcase1, hb, contains'_iff_contains]
        exact search_append_monotonic ltree v [] [Dir.left] ihl
    · obtain ihr := ihr hc
      unfold search_path.search
      by_cases hcase1 : val = v
      · simp [hcase1]
      · simp [hcase1]
        by_cases hcase2 : contains' v ltree = true
        · simp [hcase2]
          obtain ihl := ihl ((contains'_iff_contains _ _).mp hcase2)
          exact search_append_monotonic ltree v [] [Dir.left] ihl
        · simp [hcase2]
          exact search_append_monotonic rtree v [] [Dir.right] ihr

lemma BinaryTree.contains_iff_mem_collect_values [DecidableEq α] (v : α) (t : BinaryTree α) :
  contains v t ↔ v ∈ t.collect_values := by
  constructor
  all_goals
  · intro h
    induction t with
    | leaf => contradiction
    | node ltree val rtree ihl ihr =>
      simp_all [contains, collect_values]
      rcases h with ha | hb | hc
      · left;
        exact ha;
      · right; left;
        exact ihl hb;
      · right; right;
        exact ihr hc

lemma BinaryTree.v_notin_unq_lrtree [DecidableEq α] (ltree rtree : BinaryTree α) (v : α)
  (h : (node ltree v rtree).all_unique)
  : ¬ contains v ltree ∧ ¬ contains v rtree :=
by
  constructor
  show ¬ contains v ltree
  · by_contra! hcon
    unfold all_unique at h; unfold collect_values at h; unfold List.Nodup at h
    cases h with
    | cons ih1 ih2 =>
      -- Now use hcon to show that v is in the left subtree
      -- Thus, v is definitely in ltree.collect_values ++ rtree.collect_values
      -- ih1 wold be come v ≠ v, which is a contradiction
      have h_v_in_ltree : v ∈ ltree.collect_values := by
        exact (contains_iff_mem_collect_values v ltree).mp hcon
      have h_v_in_all : v ∈ ltree.collect_values ++ rtree.collect_values := by
        exact List.mem_append_left rtree.collect_values h_v_in_ltree
      have claim := ih1 v h_v_in_all
      contradiction

  show ¬ contains v rtree
  · by_contra! hcon
    unfold all_unique at h; unfold collect_values at h; unfold List.Nodup at h
    cases h with
    | cons ih1 ih2 =>
      -- Now use hcon to show that v is in the left subtree
      -- Thus, v is definitely in rtree.collect_values ++ rtree.collect_values
      -- ih1 wold be come v ≠ v, which is a contradiction
      have h_v_in_rtree : v ∈ rtree.collect_values := by
        exact (contains_iff_mem_collect_values v rtree).mp hcon
      have h_v_in_all : v ∈ ltree.collect_values ++ rtree.collect_values := by
        exact List.mem_append_right ltree.collect_values h_v_in_rtree
      have claim := ih1 v h_v_in_all
      contradiction

lemma BinaryTree.follow_path_means_contains [DecidableEq α] (t : BinaryTree α) (v : α) (path : Path)
  : follow_path t path = some v → contains v t :=
by
  intro h
  induction t generalizing path with
  | leaf => contradiction
  | node l val r ihl ihr =>
    unfold follow_path at h
    unfold contains
    match path with
    | [] =>
      simp at h
      left; exact h.symm
    | Dir.left :: rest =>
      simp at h
      obtain ihl := ihl rest h
      right; left; exact ihl
    | Dir.right :: rest =>
      simp at h
      obtain ihr := ihr rest h
      right; right; exact ihr

-- Prove that for all non-empty paths, (ltree.node v rtree).follow_path path = some v is impossible.
lemma BinaryTree.follow_nonempty_path_false [DecidableEq α] (ltree rtree : BinaryTree α) (v : α) (path : Path)
  (h1 : path ≠ [])                        -- For all non-empty paths
  (h2 : (node ltree v rtree).all_unique)  -- Need a condition that all values in the tree are unique
  : (node ltree v rtree).follow_path path = some v → False :=
by
  intro h3
  -- Prove that the left subtree cannot contain v
  have h_v_notin_subtrees : ¬ contains v ltree ∧ ¬ contains v rtree := by
    exact v_notin_unq_lrtree ltree rtree v h2
  rcases h_v_notin_subtrees with ⟨h_v_notin_ltree, h_v_notin_rtree⟩

  match path with
  | [] => contradiction
  | Dir.left :: rest =>
    unfold follow_path at h3
    have h_v_in_ltree : contains v ltree := by
      exact follow_path_means_contains ltree v rest h3
    contradiction
  | Dir.right :: rest =>
    unfold follow_path at h3
    have h_v_in_rtree : contains v rtree := by
      exact follow_path_means_contains rtree v rest h3
    contradiction

lemma BinaryTree.whole_tree_unique_imp_subtree_unique [DecidableEq α] (ltree rtree : BinaryTree α) (v : α)
  (h : (node ltree v rtree).all_unique) : ltree.all_unique ∧ rtree.all_unique :=
by
  constructor
  show ltree.all_unique
  · -- Prove that the left subtree is unique
    cases h with
    | cons ih1 ih2 =>
      have ⟨ltree_unique, rtree_unique, _⟩ := List.pairwise_append.mp ih2
      unfold all_unique; unfold List.Nodup
      exact ltree_unique
  show rtree.all_unique
  . -- Prove that the right subtree is unique
    cases h with
    | cons ih1 ih2 =>
      have ⟨ltree_unique, rtree_unique, _⟩ := List.pairwise_append.mp ih2
      unfold all_unique; unfold List.Nodup
      exact rtree_unique

lemma BinaryTree.search_path_search_cons [DecidableEq α]
  {t : BinaryTree α} {v : α} {p p' : Path} (d : Dir)
  : search_path.search t v (d :: p) = some (d :: p') ↔ search_path.search t v p = some p' :=
by
  constructor
  -- Can remove common prefix and can add common prefix
  all_goals
  · intro h
    induction t generalizing p p' with
    | leaf => contradiction
    | node lt vt rt ihl ihr =>
      by_cases hcase1 : v = vt
      · simp_all [search_path.search, hcase1]
      · push_neg at hcase1
        by_cases hcase2 : contains' v lt = true
        · simp_all [search_path.search, hcase1.symm, hcase2]
        · simp_all [search_path.search, hcase1.symm, hcase2]

/-
It's not easy to see that `d` can only be `left` for all three hypothesis to hold.
* `hpath` guarentees that one valid path is found
* `hunq` guarantees that all values in the tree are unique
* `hb` guarantees that the value is contained in the tree
There are two cases:
1. `d = left` - agrees with all hypothesis
2. `d = right` - we start from empty accumulator, and we explore the right subtree.
                 However, by `hunq` and `hb`, `v` cannot be in the right subtree,
                 thus, we cannot find a valid path - contradicts to `hpath`.
-/
lemma BinaryTree.search_go_left [DecidableEq α] {ltree rtree : BinaryTree α} {val v : α} {p : Path} {d : Dir}
  (hpath : search_path.search (node ltree val rtree) v [] = some (d :: p))
  (hunq : (ltree.node val rtree).all_unique)
  (hb : contains v ltree)
  : search_path.search ltree v [] = some p :=
by
  cases d with
  | left =>
    simp [search_path.search] at hpath
    -- Need to prove that val ≠ v from `hb`
    by_cases hcase : val = v
    · have h_val_notin_ltree := (v_notin_unq_lrtree ltree rtree val hunq).left
      rw [hcase] at h_val_notin_ltree
      contradiction
    · simp [hcase, contains'_iff_contains, hb] at hpath
      exact (search_path_search_cons Dir.left).mp hpath

  | right =>
    simp [search_path.search] at hpath
    by_cases hcase : val = v
    · simp [hcase] at hpath
    · simp [hcase, contains'_iff_contains, hb] at hpath
      -- Prove that ∃ q : Path, s.t. search ltree v [] = some q, and by .mpr of search_path_search_cons
      -- We can can prove that search ltree v [Dir.left] = some (Dir.left :: q)
      have h_exists_path : ∃ q : Path, search_path.search ltree v [] = some q := by
        have claim := path_valid ltree v hb
        exact Option.isSome_iff_exists.mp claim

      obtain ⟨q, hq⟩ := h_exists_path
      obtain hq' := (search_path_search_cons Dir.left).mpr hq

      -- Now we have everything to prove a contradiction
      by_cases hcase : p = q
      · simp [hq'] at hpath
      · simp [hq'] at hpath


/- --------------------------------------------------------------------------------------------- -/
/-                                    WORK UNDER CONSTRUCTION                                    -/
/- --------------------------------------------------------------------------------------------- -/


lemma BinaryTree.search_go_right [DecidableEq α] {ltree rtree : BinaryTree α} {val v : α} {p : Path} {d : Dir}
  (hpath : search_path.search (node ltree val rtree) v [] = some (d :: p))
  (hunq : (ltree.node val rtree).all_unique)
  (hb : contains v rtree)
  : search_path.search rtree v [] = some p :=
by
  sorry
  -- cases d with
  -- | left =>
  --   simp [search_path.search] at hpath
  --   by_cases hcase : val = v
  --   · simp [hcase] at hpath
  --   · simp [hcase, contains'_iff_contains, hb] at hpath




  --     -- Prove that ∃ q : Path, s.t. search rtree v [] = some q, and by .mpr of search_path_search_cons
  --     -- We can can prove that search rtree v [Dir.left] = some (Dir.left :: q)
  --     have h_exists_path : ∃ q : Path, search_path.search rtree v [] = some q := by
  --       have claim := path_valid rtree v hb
  --       exact Option.isSome_iff_exists.mp claim

  --     obtain ⟨q, hq⟩ := h_exists_path
  --     obtain hq' := (search_path_search_cons Dir.right).mpr hq

  --     -- Now we have everything to prove a contradiction
  --     by_cases hcase : p = q
  --     · simp [hq'] at hpath
  --     · simp [hq'] at hpath




  -- | right =>
  --   simp [search_path.search] at hpath
  --   -- Need to prove that val ≠ v from `hb`
  --   by_cases hcase : val = v
  --   · have h_val_notin_ltree := (v_notin_unq_lrtree ltree rtree val hunq).left
  --     rw [hcase] at h_val_notin_ltree
  --     contradiction
  --   · simp [hcase, contains'_iff_contains, hb] at hpath
  --     exact (search_path_search_cons Dir.left).mp hpath










lemma BinaryTree.subtree_disjoint_left [DecidableEq α] {ltree rtree : BinaryTree α} {val v : α}
  (hunq : (node ltree val rtree).all_unique) (h : contains v ltree)
  : val ≠ v ∧ ¬ rtree.contains v :=
by
  constructor
  show val ≠ v
  · by_contra! hcon
    rw [hcon] at hunq
    have claim := (v_notin_unq_lrtree ltree rtree v hunq).left
    contradiction

  show ¬ rtree.contains v
  · by_contra! hcon
    sorry


lemma BinaryTree.subtree_disjoint_right [DecidableEq α] {ltree rtree : BinaryTree α} {val v : α}
  (hunq : (node ltree val rtree).all_unique) (h : contains v rtree)
  : val ≠ v ∧ ¬ ltree.contains v :=
by
  sorry







-- Formalize the statement: there **exists** a **unique** path betwen the root and any given node.
theorem BinaryTree.exists_unique_path [DecidableEq α] (t : BinaryTree α) (v : α) (hunq : t.all_unique) :
  contains v t → ∃! p : Path, follow_path t p = some v :=
by
  intro h
  rw [ExistsUnique]

  let ppath : Option Path := search_path.search t v []
  have option_isSome_iff_exists (o : Option Path) : o.isSome ↔ ∃ x, o = some x := by
    cases o <;> simp
  obtain ⟨path, hpath⟩ := (option_isSome_iff_exists ppath).mp (path_valid _ _ h)
  use path

  have hx : t.follow_path path = some v := by
    unfold ppath at hpath
    have claim1 := search_path_correct t v [] path hpath ((contains'_iff_contains v t).mpr h)
    obtain ⟨path, claim1, claim2⟩ := claim1
    simp_all [claim1]

  constructor
  show t.follow_path path = some v
  · -- Prove that the path exists
    exact hx

  show ∀ (y : Path), t.follow_path y = some v → y = path
  · -- Prove that the path is unique
    /-
      Note that when proving uniquenss, we need to use the fact that all values
      in the tree are distinct - like having a unique id for each node.
      Counterexamle:
          1
         / \
        2   2    Clearly, the paths to 2 are not unique.
    -/
    intro y hy
    induction t generalizing path y with
    | leaf => contradiction
    | node ltree val rtree ihl ihr =>
      simp [contains] at h

      /- ------------------------------------------------------------------- -/
      -- General facts about both subtrees
      /- ------------------------------------------------------------------- -/
      obtain h_subtree_unique := whole_tree_unique_imp_subtree_unique ltree rtree val hunq
      obtain h_val_notin_subtree := v_notin_unq_lrtree ltree rtree val hunq

      rcases h with ha | hb | hc
      /- ------------------------------------------------------------------- -/
      · -- Case when v = val
      /- ------------------------------------------------------------------- -/
        simp [← ha] at hx hy

        -- Prove contradiction when path = nil and y ≠ nil or vice versa
        have hclaim (p : Path) (hp : p ≠ [])
          (h : (ltree.node val rtree).follow_path p = some val) : False :=
        by
          rw [ha] at hx hy
          have hz := follow_nonempty_path_false ltree rtree val p hp hunq h
          contradiction

        -- Analyze the structure of the input paths
        cases path <;> cases y
        case nil.nil => rfl
        case nil.cons | cons.nil | cons.cons => simp_all [ha, hclaim]

      /- ------------------------------------------------------------------- -/
      · -- Case when v ∈ left subtree
      /- ------------------------------------------------------------------- -/
        unfold ppath at hpath
        obtain ihl := ihl h_subtree_unique.left hb

        have claim1 (p : Path) (hp : p = []) (h : (ltree.node val rtree).follow_path p = some v)
          : False := by simp_all [follow_path, hp]

        have claim2 {p : Path} (h : (ltree.node val rtree).follow_path (Dir.left :: p) = some v)
          : ltree.follow_path p = some v := by simp_all [follow_path]

        have claim3 {p : Path} (h : (ltree.node val rtree).follow_path (Dir.right :: p) = some v) : False := by
          simp [follow_path] at h
          have hy := follow_path_means_contains _ _ _ h
          have claim := (subtree_disjoint_left hunq hb).right
          contradiction

        cases path <;> cases y
        case nil.nil | nil.cons | cons.nil => simp_all [claim1]
        case cons.cons =>
          rename_i d path' d' y'
          obtain ihl := ihl path' (search_go_left hpath hunq hb)
          cases d <;> cases d'
          case left.left =>
            obtain ihl := ihl (claim2 hx) y' (claim2 hy)
            simp [ihl]
          case left.right =>
            have hclaim := claim3 hy; contradiction
          case right.left | right.right =>
            have hclaim := claim3 hx; contradiction

      /- ------------------------------------------------------------------- -/
      · -- Case when v ∈ right subtree
      /- ------------------------------------------------------------------- -/
        unfold ppath at hpath
        obtain ihr := ihr h_subtree_unique.right hc

        have claim1 (p : Path) (hp : p = []) (h : (ltree.node val rtree).follow_path p = some v)
          : False := by simp_all [follow_path, hp]

        have claim2 {p : Path} (h : (ltree.node val rtree).follow_path (Dir.right :: p) = some v)
          : rtree.follow_path p = some v := by simp_all [follow_path]

        have claim3 {p : Path} (h : (ltree.node val rtree).follow_path (Dir.left :: p) = some v) : False := by
          simp [follow_path] at h
          have hy := follow_path_means_contains _ _ _ h
          have claim := (subtree_disjoint_right hunq hc).right
          contradiction

        cases path <;> cases y
        case nil.nil | nil.cons | cons.nil => simp_all [claim1]
        case cons.cons =>
          rename_i d path' d' y'
          obtain ihr := ihr path' (search_go_right hpath hunq hc)
          cases d <;> cases d'
          case left.left | left.right =>
            have hclaim := claim3 hx; contradiction
          case right.left =>
            have hclaim := claim3 hy; contradiction
          case right.right =>
            obtain ihr := ihr (claim2 hx) y' (claim2 hy)
            simp [ihr]

-- In any tree with n nodes, there are n − 1 edges.
-- TODO: Prove this fact

-- The number of distinct binary trees with n nodes is the ( n )th Catalan number.
-- TODO: Prove this fact

-- The sum of the depths of all leaves in a perfect binary tree of height h is (h + 1) ⋅ 2h.
-- TODO: Prove this fact

end BinTreeAlgos

end BinTree
