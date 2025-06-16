import Mathlib.Data.Set.Basic
import Mathlib.Tactic

namespace UnionWorld

open Set

-- Declare U as a placeholder for Type
variable {U : Type}

theorem union_subset_swap (A B : Set U) : A ∪ B ⊆ B ∪ A := by
  intro x
  repeat rw [mem_union]
  intro h
  rcases h with hA | hB
  right; exact hA
  left; exact hB

theorem union_comm (A B : Set U) : A ∪ B = B ∪ A := by
  apply Subset.antisymm
  exact union_subset_swap _ _
  exact union_subset_swap _ _

theorem union_assoc (A B C : Set U) : (A ∪ B) ∪ C = A ∪ (B ∪ C) := by
  ext x
  constructor
  -- sep --
  show x ∈ A ∪ B ∪ C → x ∈ A ∪ (B ∪ C)
  repeat rw [mem_union]
  intro h
  rcases h with hL | hR
  rcases hL with hLa | hLb
  left; exact hLa
  right; left; exact hLb
  right; right; exact hR
  -- sep --
  show x ∈ A ∪ (B ∪ C) → x ∈ A ∪ B ∪ C
  repeat rw [mem_union]
  intro h
  rcases h with hL | hR
  left; left; exact hL
  rcases hR with hRa | hRb
  left; right; exact hRa
  right; exact hRb

section Toys
  example (x : U) (A B : Set U) (h : x ∈ A) : x ∈ A ∨ x ∈ B := by
    left
    exact h

  example (A B : Set U) : B ⊆ A ∪ B := by
    intro x h
    rw [mem_union]
    right
    exact h

  example (A B C : Set U) (h1 : A ⊆ C) (h2 : B ⊆ C) : A ∪ B ⊆ C := by
    intro x h3
    rw [mem_union] at h3
    rcases h3 with h3A | h3B
    exact h1 h3A
    exact h2 h3B

end Toys

end UnionWorld
