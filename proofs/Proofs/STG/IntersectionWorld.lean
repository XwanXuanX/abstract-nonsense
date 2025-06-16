import Mathlib.Data.Set.Basic
import Mathlib.Tactic

namespace IntersectionWorld

open Set

-- Declare U as a placeholder for Type
variable {U : Type}

theorem inter_subset_swap (A B : Set U) : A ∩ B ⊆ B ∩ A := by
  intro x h
  rw [mem_inter_iff]
  rw [mem_inter_iff] at h
  obtain ⟨ha, hb⟩ := h
  constructor
  exact hb
  exact ha

theorem inter_comm (A B : Set U) : A ∩ B = B ∩ A := by
  apply Subset.antisymm
  exact inter_subset_swap _ _
  exact inter_subset_swap _ _

theorem inter_assoc (A B C : Set U) : (A ∩ B) ∩ C = A ∩ (B ∩ C) := by
  ext x
  constructor
  -- l → r
  show x ∈ A ∩ B ∩ C → x ∈ A ∩ (B ∩ C)
  repeat rw [mem_inter_iff]
  intro h
  constructor
  exact h.left.left
  constructor
  exact h.left.right
  exact h.right
  -- r → l
  show x ∈ A ∩ (B ∩ C) → x ∈ A ∩ B ∩ C
  repeat rw [mem_inter_iff]
  intro h
  constructor
  constructor
  exact h.left
  exact h.right.left
  exact h.right.right

section Toys
  example (x : U) (A B : Set U) (h : x ∈ A ∧ x ∈ B) : x ∈ A := by
    obtain ⟨h1, h2⟩ := h
    exact h1

  example (x : U) (A B : Set U) (h : x ∈ A ∩ B) : x ∈ B := by
    rw [mem_inter_iff] at h
    exact h.right

  example (A B : Set U) : A ∩ B ⊆ A := by
    intro x h
    rw [mem_inter_iff] at h
    exact h.left

  example (x : U) (A B : Set U) (h1 : x ∈ A) (h2 : x ∈ B) : x ∈ A ∩ B := by
    rw [mem_inter_iff]
    constructor
    exact h1
    exact h2

  example (A B C : Set U) (h1 : A ⊆ B) (h2 : A ⊆ C) : A ⊆ B ∩ C := by
    intro x h
    rw [mem_inter_iff]
    constructor
    exact h1 h
    exact h2 h

end Toys

end IntersectionWorld
