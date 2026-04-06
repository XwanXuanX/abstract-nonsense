import Proofs.NNG.AdvancedAdditionWorld
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
  induction y with
  | zero =>
    change x ≤ 0 ∨ 0 ≤ x
    right
    use x
    rw [zero_add]
  | succ d hd =>
    cases hd with
    | inl h1 =>
      left
      have ⟨e, he⟩ := h1
      use (e + 1)
      rw [he, succ_eq_add_one, add_assoc]
    | inr h2 =>
      have ⟨e, he⟩ := h2
      cases e with
      | zero =>
        change x = d + 0 at he
        left
        rw [he, ← add_zero]
        exact le_succ_self d
      | succ e =>
        right
        rw [he, add_succ, ← succ_add]
        use e

theorem succ_le_succ (x y : MyNat) (hx : succ x ≤ succ y) : x ≤ y := by
  have ⟨c, hc⟩ := hx
  use c
  rw [succ_add] at hc
  exact succ_inj _ _ hc

theorem le_one (x : MyNat) (hx : x ≤ 1) : x = 0 ∨ x = 1 := by
  cases x with
  | zero =>
    left
    change 0 = 0
    rfl
  | succ x =>
    rw [one_eq_succ_zero] at hx
    have hx := le_zero _ (succ_le_succ _ _ hx)
    rw [hx]
    right
    rw [one_eq_succ_zero]

theorem le_two (x : MyNat) (hx : x ≤ 2) : x = 0 ∨ x = 1 ∨ x = 2 := by
  cases x with
  | zero =>
    left
    change 0 = 0
    rfl
  | succ x =>
    rw [two_eq_succ_one] at hx
    have hx := le_one _ (succ_le_succ _ _ hx)
    cases hx with
    | inl h1 =>
      right
      left
      rw [h1, one_eq_succ_zero]
    | inr h2 =>
      right
      right
      rw [h2, two_eq_succ_one]

end LessOrEqualWorld
