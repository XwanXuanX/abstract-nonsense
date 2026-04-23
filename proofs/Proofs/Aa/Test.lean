import Mathlib

open Equiv Equiv.Perm

variable {α : Type*} [Fintype α] [DecidableEq α]

/-- The product of two even permutations is even. -/
theorem sign_mul_of_even
    (σ τ : Perm α) (hσ : sign σ = 1) (hτ : sign τ = 1) :
    sign (σ * τ) = 1 := by
  rw [Perm.sign_mul, hσ, hτ, one_mul]
