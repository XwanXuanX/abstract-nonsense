import Mathlib.Algebra.Module.Prod
import Mathlib.Data.Real.Basic
import Mathlib.LinearAlgebra.Span.Defs
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

/-- A scalar multiple of the first vector adds nothing to the span of the pair. -/
theorem span_pair_eq_span_singleton_of_smul
    (u v : ℝ × ℝ) (k : ℝ) (hv : v = k • u) :
    Submodule.span ℝ ({u, v} : Set (ℝ × ℝ)) =
      Submodule.span ℝ ({u} : Set (ℝ × ℝ)) := by
  apply le_antisymm
  · intro w hw
    obtain ⟨a, b, hab⟩ := Submodule.mem_span_pair.mp hw
    refine Submodule.mem_span_singleton.mpr ⟨a + k * b, ?_⟩
    calc
      (a + k * b) • u = a • u + (k * b) • u := by rw [add_smul]
      _ = a • u + b • v := by rw [hv, smul_smul, mul_comm b k]
      _ = w := hab
  · intro w hw
    obtain ⟨c, hc⟩ := Submodule.mem_span_singleton.mp hw
    refine Submodule.mem_span_pair.mpr ⟨c, 0, ?_⟩
    simpa only [zero_smul, add_zero] using hc

end Proofs.LinearAlgebra
