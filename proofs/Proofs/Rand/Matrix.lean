import Mathlib.Data.Matrix.Basic
import Mathlib.Algebra.Module.Basic

variable {m n : Type*} {α : Type*} [AddCommMonoid α]

theorem matrix_add_zero (A : Matrix m n α) : A + 0 = A := by
  ext i j
  simp

theorem matrix_add_comm (A B : Matrix m n α) : A + B = B + A := by
  sorry
