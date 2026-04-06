import Mathlib.Data.Set.Basic
import Mathlib.Tactic

namespace CombinationWorld

open Set

-- Declare U as a placeholder for Type
variable {U : Type}

theorem compl_union (A B : Set U) : (A ∪ B)ᶜ = Aᶜ ∩ Bᶜ := by
  ext x
  repeat rw [mem_compl_iff]
  rw [mem_union]
  constructor
  · intro h
    push_neg at h
    exact h
  · intro h
    push_neg
    exact h

theorem compl_inter (A B : Set U) : (A ∩ B)ᶜ = Aᶜ ∪ Bᶜ := by
  rw [← compl_compl (Aᶜ ∪ Bᶜ)]
  rw [compl_union _, compl_compl, compl_compl]

theorem inter_distrib_left (A B C : Set U) : A ∩ (B ∪ C) = (A ∩ B) ∪ (A ∩ C) := by
  ext x
  constructor
  show x ∈ A ∩ (B ∪ C) → x ∈ A ∩ B ∪ A ∩ C
  · repeat rw [mem_inter_iff, mem_union]
    intro h
    obtain ⟨hl, hr⟩ := h
    rcases hr with hrl | hrr
    · left
      constructor
      · exact hl
      · exact hrl
    · right
      constructor
      · exact hl
      · exact hrr
  show x ∈ A ∩ B ∪ A ∩ C → x ∈ A ∩ (B ∪ C)
  · rw [mem_inter_iff, mem_union, mem_union, mem_inter_iff, mem_inter_iff]
    intro h
    rcases h with hl | hr
    · constructor
      · exact hl.left
      · left; exact hl.right
    · constructor
      · exact hr.left
      · right; exact hr.right

theorem union_distrib_left (A B C : Set U) : A ∪ (B ∩ C) = (A ∪ B) ∩ (A ∪ C) := by
  rw [← compl_compl (A ∪ (B ∩ C))]
  rw [compl_union, compl_inter B C]
  rw [inter_distrib_left]
  rw [compl_union]
  repeat rw [compl_inter]
  repeat rw [compl_compl]

section Toys
  example (A B C : Set U) (h1 : A ∪ C ⊆ B ∪ C) (h2 : A ∩ C ⊆ B ∩ C) : A ⊆ B := by
    intro x h
    have hAC : (x ∈ A ∪ C) := by
      rw [mem_union]
      left
      exact h
    have h3 : (x ∈ B ∪ C) := h1 hAC
    rw [mem_union] at hAC
    rw [mem_union] at h3
    rcases h3 with h3l | h3r
    · exact h3l
    · have h4 := And.intro h h3r
      rw [← mem_inter_iff] at h4
      have h5 : (x ∈ B ∩ C) := h2 h4
      rw [mem_inter_iff] at h5
      exact h5.left

end Toys

end CombinationWorld
