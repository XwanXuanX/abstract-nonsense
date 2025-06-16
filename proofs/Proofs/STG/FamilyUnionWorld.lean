import Mathlib.Data.Set.Basic
import Mathlib.Tactic

namespace FamilyUnionWorld

open Set

-- Declare U as a placeholder for Type
variable {U : Type}

axiom mem_pair {U : Type} (t A B : U) : t ∈ ({A, B} : Set U) ↔ t = A ∨ t = B

section Toys
  example (A : Set U) : ∃ s, s ⊆ A := by
    use A

  example (A : Set U) (F : Set (Set U)) (h1 : A ∈ F) : A ⊆ ⋃₀ F := by
    intro x h2
    rw [mem_sUnion]
    use A

  example (F G : Set (Set U)) (h1 : F ⊆ G) : ⋃₀ F ⊆ ⋃₀ G := by
    intro x h2
    rw [mem_sUnion] at h2
    rw [mem_sUnion]
    obtain ⟨s, hs⟩ := h2
    obtain ⟨h2, h3⟩ := hs
    use s
    constructor
    · exact h1 h2
    · exact h3

  example (A B : Set U) : A ∪ B = ⋃₀ {A, B} := by
    ext x
    constructor
    · intro h1
      rw [mem_sUnion]
      rw [mem_union] at h1
      rcases h1 with h1l | h1r
      · use A
        rw [mem_pair]
        constructor
        · left; rfl
        · exact h1l
      · use B
        rw [mem_pair]
        constructor
        · right; rfl
        · exact h1r
    · intro h
      rw [mem_union]
      rw [mem_sUnion] at h
      obtain ⟨w, hw⟩ := h
      rw [mem_pair] at hw
      obtain ⟨h1, h2⟩ := hw
      rcases h1 with h1l | h1r
      · rw [h1l] at h2
        left; exact h2
      · rw [h1r] at h2
        right; exact h2

  example (F G : Set (Set U)) : ⋃₀ (F ∪ G) = (⋃₀ F) ∪ (⋃₀ G) := by
    ext x
    constructor
    · intro h
      rw [mem_sUnion] at h
      repeat rw [mem_union]
      obtain ⟨w, hw⟩ := h
      obtain ⟨h1, h2⟩ := hw
      rw [mem_union] at h1
      rcases h1 with h1l | h1r
      · left
        constructor; constructor
        exact h1l; exact h2
      · right
        constructor; constructor
        exact h1r; exact h2
    · intro h
      rw [mem_sUnion]
      repeat rw [mem_union] at h
      rcases h with h1 | h2
      · obtain ⟨w, hw⟩ := h1
        use w
        constructor
        · rw [mem_union]
          left; exact hw.left
        · exact hw.right
      · obtain ⟨w, hw⟩ := h2
        use w
        constructor
        · rw [mem_union]
          right; exact hw.left
        · exact hw.right

  example (A : Set U) (F : Set (Set U)) : ⋃₀ F ⊆ A ↔ ∀ s ∈ F, s ⊆ A := by
    constructor
    · intro h1 s h2 x h3
      apply h1
      rw [mem_sUnion]
      apply Exists.intro s
      constructor
      · exact h2
      · exact h3
    · intro h1 x h2
      rw [mem_sUnion] at h2
      obtain ⟨w, hw⟩ := h2
      apply h1 w
      · exact hw.left
      · exact hw.right

  example (A : Set U) (F : Set (Set U)) : A ∩ (⋃₀ F) = ⋃₀ {s | ∃ u ∈ F, s = A ∩ u} := by
    ext x
    constructor
    · intro h1
      rw [mem_inter_iff] at h1
      obtain ⟨h1, h2⟩ := h1
      rw [mem_sUnion] at h2
      obtain ⟨w, h2⟩ := h2
      obtain ⟨h2, h3⟩ := h2
      rw [mem_sUnion]
      use (A ∩ w)
      rw [mem_setOf]
      constructor
      · use w
      · rw [mem_inter_iff]
        constructor
        · exact h1
        · exact h3
    · intro h1
      rw [mem_sUnion] at h1
      obtain ⟨w, hw⟩ := h1
      obtain ⟨h1, h2⟩ := hw
      rw [mem_setOf] at h1
      obtain ⟨u, h1⟩ := h1
      obtain ⟨h1, h3⟩ := h1
      rw [h3] at h2
      rw [mem_inter_iff] at h2
      obtain ⟨h4, h2⟩ := h2
      rw [mem_inter_iff]
      constructor
      · exact h4
      · rw [mem_sUnion]
        use u

end Toys

end FamilyUnionWorld
