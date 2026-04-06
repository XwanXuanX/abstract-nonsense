import Mathlib.Data.Set.Basic
import Mathlib.Tactic

namespace SubsetWorld

open Set

-- Declare U as a placeholder for Type
variable {U : Type}

theorem Subset.refl (A : Set U) : A ⊆ A := by
  intro x h
  exact h

theorem Subset.trans {A B C : Set U} (h1 : A ⊆ B) (h2 : B ⊆ C) : A ⊆ C := by
  intro x h
  exact h2 (h1 h)

section Toys
  example (x : U) (A : Set U) (h : x ∈ A) : x ∈ A := by
    exact h

  example (x : U) (A B : Set U) (h1 : A ⊆ B) (h2 : x ∈ A) : x ∈ B := by
    exact h1 h2

  example (x : U) (A B C : Set U) (h1 : A ⊆ B) (h2 : B ⊆ C) (h3 : x ∈ A) : x ∈ C := by
    have h4 : x ∈ B := h1 h3
    exact h2 h4

  example {x : U} {A B C : Set U} (h1 : A ⊆ B) (h2 : x ∈ B → x ∈ C) : x ∈ A → x ∈ C := by
    intro h3
    have h4 : x ∈ B := h1 h3
    exact h2 h4

end Toys

end SubsetWorld
