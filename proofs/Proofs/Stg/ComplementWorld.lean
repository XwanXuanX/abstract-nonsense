import Mathlib.Data.Set.Basic
import Mathlib.Tactic

namespace ComplementWorld

open Set

-- Declare U as a placeholder for Type
variable {U : Type}

theorem mem_compl_iff (A : Set U) (x : U) : x ∈ Aᶜ ↔ x ∉ A := by
  rfl

theorem compl_subset_compl_of_subset {A B : Set U} (h1 : A ⊆ B) : Bᶜ ⊆ Aᶜ := by
  intro x h2
  rw [mem_compl_iff]
  rw [mem_compl_iff] at h2
  by_contra h3
  have h4 : (x ∈ B) := h1 h3
  exact h2 h4

theorem compl_compl (A : Set U) : Aᶜᶜ = A := by
  apply Subset.antisymm
  intro x h1
  repeat rw [mem_compl_iff] at h1
  push_neg at h1
  exact h1
  intro x h1
  rw [mem_compl_iff, mem_compl_iff]
  push_neg
  exact h1

section Toys
  example {A B : Set U} {x : U} (h1 : x ∈ A) (h2 : x ∉ B) : ¬A ⊆ B := by
    by_contra h3
    exact h2 (h3 h1)

  example (A B : Set U) : A ⊆ B ↔ Bᶜ ⊆ Aᶜ := by
    constructor
    intro h1
    apply compl_subset_compl_of_subset at h1
    exact h1
    intro h1
    apply compl_subset_compl_of_subset at h1
    rw [compl_compl, compl_compl] at h1
    exact h1

end Toys

end ComplementWorld
