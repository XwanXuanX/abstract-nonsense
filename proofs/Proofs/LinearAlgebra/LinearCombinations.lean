import Mathlib.Algebra.Module.Prod
import Mathlib.Data.Real.Basic
import Mathlib.Tactic.Ring

namespace Proofs.LinearAlgebra

/-- Construct the two coefficients that generate an arbitrary point of the plane. -/
theorem diagonal_vectors_generate_plane (x y : ℝ) :
    ∃ a b : ℝ, a • ((1, 1) : ℝ × ℝ) + b • ((1, -1) : ℝ × ℝ) = (x, y) := by
  refine ⟨(x + y) / 2, (x - y) / 2, Prod.ext ?_ ?_⟩
  · change (x + y) / 2 * 1 + (x - y) / 2 * 1 = x
    ring
  · change (x + y) / 2 * 1 + (x - y) / 2 * (-1) = y
    ring

/-- Comparing both coordinates would give different values for the same scalar. -/
theorem collinear_vectors_cannot_generate_unit_x :
    ¬ ∃ a b : ℝ, a • ((1, 1) : ℝ × ℝ) + b • ((2, 2) : ℝ × ℝ) = (1, 0) := by
  intro h
  obtain ⟨a, b, h⟩ := h
  have hx := congrArg Prod.fst h
  have hy := congrArg Prod.snd h
  change a * 1 + b * 2 = 1 at hx
  change a * 1 + b * 2 = 0 at hy
  exact one_ne_zero (hx.symm.trans hy)

end Proofs.LinearAlgebra
