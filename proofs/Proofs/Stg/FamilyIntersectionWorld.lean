import Mathlib.Data.Set.Basic
import Mathlib.Tactic

namespace FamilyIntersectionWorld

open Set

-- Declare U as a placeholder for Type
variable {U : Type}

axiom mem_pair {U : Type} (t A B : U) : t ∈ ({A, B} : Set U) ↔ t = A ∨ t = B

section Toys
  example (A : Set U) (F : Set (Set U)) (h1 : A ∈ F) : ⋂₀ F ⊆ A := by
    intro x h
    rw [mem_sInter] at h
    exact h A h1

  example (F G : Set (Set U)) (h1 : F ⊆ G) : ⋂₀ G ⊆ ⋂₀ F := by
    intro x
    repeat rw [mem_sInter]
    intro h t h2
    have h3 : (t ∈ G) := h1 h2
    apply h at h3
    exact h3

  example (A B : Set U) : A ∩ B = ⋂₀ {A, B} := by
    ext t
    constructor
    show t ∈ A ∩ B → t ∈ ⋂₀ {A, B}
    · intro h
      rw [mem_inter_iff] at h
      rw [mem_sInter]
      intro a
      rw [mem_pair]
      intro h1
      rcases h1 with h1l | h1r
      · rw [h1l]; exact h.left
      · rw [h1r]; exact h.right
    show t ∈ ⋂₀ {A, B} → t ∈ A ∩ B
    · intro h
      rw [mem_inter_iff]
      rw [mem_sInter] at h
      have h2 : (A ∈ {A, B} → t ∈ A) := h A
      have h3 : (B ∈ {A, B} → t ∈ B) := h B
      rw [mem_pair] at h2
      rw [mem_pair] at h3
      have hA : (t ∈ A) := h2 (Or.inl rfl)
      have hB : (t ∈ B) := h3 (Or.inr rfl)
      exact And.intro hA hB

  example (F G : Set (Set U)) : ⋂₀ (F ∪ G) = (⋂₀ F) ∩ (⋂₀ G) := by
    ext x
    constructor
    show x ∈ ⋂₀ (F ∪ G) → x ∈ ⋂₀ F ∩ ⋂₀ G
    · rw [mem_inter_iff]
      repeat rw [mem_sInter]
      intro h
      constructor
      · intro t h1
        apply h
        rw [mem_union]
        left; exact h1
      · intro t h1
        apply h
        rw [mem_union]
        right; exact h1
    show x ∈ ⋂₀ F ∩ ⋂₀ G → x ∈ ⋂₀ (F ∪ G)
    · intro h
      rw [mem_sInter]
      intro t h1
      rw [mem_inter_iff, mem_sInter, mem_sInter] at h
      obtain ⟨ha, hb⟩ := h
      rw [mem_union] at h1
      rcases h1 with h1l | h1r
      · apply ha; exact h1l
      · apply hb; exact h1r

  example (A : Set U) (F : Set (Set U)) : A ⊆ ⋂₀ F ↔ ∀ s ∈ F, A ⊆ s := by
    constructor
    show A ⊆ ⋂₀ F → ∀ s ∈ F, A ⊆ s
    · intro h s h1 x h2
      have h3 : (x ∈ ⋂₀ F) := h h2
      rw [mem_sInter] at h3
      apply h3 s
      exact h1
    show (∀ s ∈ F, A ⊆ s) → A ⊆ ⋂₀ F
    · intro h x h1
      rw [mem_sInter]
      intro t h2
      have h3 : (A ⊆ t) := h t h2
      exact h3 h1

  example (A : Set U) (F G : Set (Set U)) (h1 : ∀ s ∈ F, A ∪ s ∈ G) : ⋂₀ G ⊆ A ∪ (⋂₀ F) := by
    intro x h
    rw [mem_union]
    by_cases hA : x ∈ A
    · left; exact hA
    · right
      rw [mem_sInter];
      rw [mem_sInter] at h
      intro t h2
      have h3 : (A ∪ t ∈ G) := h1 t h2
      have h4 : (x ∈ A ∪ t) := h (A ∪ t) h3
      rw [mem_union] at h4
      rcases h4 with h4l | h4r
      · by_contra
        exact hA h4l
      · exact h4r

end Toys

end FamilyIntersectionWorld
