import Proofs.AdvancedAdditionWorld
import Mathlib.Tactic.Use

namespace LessOrEqualWorld

open TutorialWorld
open AdditionWorld
open ImplicationWorld
open AdvancedAdditionWorld
open MyNat

def le (a b : MyNat) : Prop := ∃c : MyNat, b = a + c
instance : LE MyNat where le := le

theorem le_refl (x : MyNat) : x ≤ x := by
  use 0
  rw [← add_zero]

theorem zero_le (x : MyNat) : 0 ≤ x := by
  use x
  rw [zero_add]

theorem le_succ_self (x : MyNat) : x ≤ succ x := by
  use 1
  rw [succ_eq_add_one]

theorem le_trans (x y z : MyNat) (hxy : x ≤ y) (hyz : y ≤ z) : x ≤ z := by
  have ⟨a, ha⟩ := hxy
  have ⟨b, hb⟩ := hyz
  rw [ha, add_assoc] at hb
  use (a + b)

theorem le_zero (x : MyNat) (hx : x ≤ 0) : x = 0 := by
  have ⟨a, hx⟩ := hx
  symm at hx
  exact add_right_eq_zero _ _ hx

theorem le_antisymm (x y : MyNat) (hxy : x ≤ y) (hyx : y ≤ x) : x = y := by
  have ⟨a, ha⟩ := hxy
  have ⟨b, hb⟩ := hyx
  rw [ha] at hb
  rw [add_assoc] at hb
  symm at hb
  have hb := add_right_eq_self _ _ hb
  have hb := add_right_eq_zero _ _ hb
  rw [hb, add_zero y] at ha
  have hb := add_right_cancel _ _ _ ha
  symm at hb
  exact hb

example (x y : MyNat) (h : x = 37 ∨ y = 42) : y = 42 ∨ x = 37 := by
  cases h with
  | inl hx =>
      right
      exact hx
  | inr hy =>
      left
      exact hy

theorem le_total (x y : MyNat) : x ≤ y ∨ y ≤ x := by
  sorry




end LessOrEqualWorld
