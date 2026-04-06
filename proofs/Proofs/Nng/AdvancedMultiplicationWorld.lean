import Proofs.NNG.MultiplicationWorld
import Proofs.NNG.LessOrEqualWorld
import Proofs.NNG.AlgorithmWorld
import Mathlib.Tactic.Tauto

namespace AdvancedMultiplicationWorld

open TutorialWorld
open AdditionWorld
open ImplicationWorld
open AdvancedAdditionWorld
open MultiplicationWorld
open LessOrEqualWorld
open AlgorithmWorld
open MyNat

theorem mul_le_mul_right (a b t : MyNat) (h : a ≤ b) : a * t ≤ b * t := by
  have ⟨e, he⟩ := h
  use (e * t)
  rw [he, add_mul]

theorem mul_left_ne_zero (a b : MyNat) (h : a * b ≠ 0) : b ≠ 0 := by
  intro hb
  apply h
  rw [hb, mul_zero]

theorem eq_succ_of_ne_zero (a : MyNat) (ha : a ≠ 0) : ∃ n, a = succ n := by
  cases a with
  | zero =>
    change 0 ≠ 0 at ha
    contradiction
  | succ a =>
    use a

theorem one_le_of_ne_zero (a : MyNat) (ha : a ≠ 0) : 1 ≤ a := by
  have ha := eq_succ_of_ne_zero _ ha
  have ⟨c, hc⟩ := ha
  rw [hc]
  cases c with
  | zero =>
    change 1 ≤ succ 0
    rw [one_eq_succ_zero]
    use 0
    rw [← add_zero]
  | succ c =>
    use (succ c)
    rw [succ_eq_add_one, add_comm]

theorem le_mul_right (a b : MyNat) (h : a * b ≠ 0) : a ≤ a * b := by
  have h1 := mul_left_ne_zero _ _ h
  have h1 := one_le_of_ne_zero _ h1
  have h1 := mul_le_mul_right 1 b a h1
  rw [one_mul, mul_comm] at h1
  exact h1

theorem mul_right_eq_one (x y : MyNat) (h : x * y = 1) : x = 1 := by
  have h2 : x * y ≠ 0 := by
    rw [h, one_eq_succ_zero]
    exact succ_ne_zero 0
  have h2 := le_mul_right _ _ h2
  rw [h] at h2
  have h2 := le_one _ h2
  cases h2 with
  | inl hl =>
    rw [hl, zero_mul] at h
    rw [hl]
    exact h
  | inr hr =>
    exact hr

theorem mul_ne_zero (a b : MyNat) (ha : a ≠ 0) (hb : b ≠ 0) : a * b ≠ 0 := by
  have ha := eq_succ_of_ne_zero _ ha
  have hb := eq_succ_of_ne_zero _ hb
  have ⟨c, hc⟩ := ha
  have ⟨d, hd⟩ := hb
  rw [hc, hd, succ_mul, add_succ]
  exact succ_ne_zero (c * succ d + d)

theorem mul_eq_zero (a b : MyNat) (h : a * b = 0) : a = 0 ∨ b = 0 := by
  contrapose! h
  have ⟨h1, h2⟩ := h
  exact mul_ne_zero _ _ h1 h2

theorem mul_left_cancel (a b c : MyNat) (ha : a ≠ 0) (h : a * b = a * c) : b = c := by
  induction b generalizing c with
  | zero =>
    change a * 0 = a * c at h
    change 0 = c
    rw [mul_zero] at h
    symm at h
    have hb := mul_eq_zero _ _ h
    tauto
  | succ d hd =>
    cases c with
    | zero =>
      change a * succ d = a * 0 at h
      change succ d = 0
      rw [mul_zero] at h
      have hb := mul_eq_zero _ _ h
      tauto
    | succ c =>
      rw [mul_succ, mul_succ] at h
      have hb := hd _ (add_right_cancel _ _ _ h)
      rw [hb]

theorem mul_right_eq_self (a b : MyNat) (ha : a ≠ 0) (h : a * b = a) : b = 1 := by
  nth_rewrite 2 [← mul_one a] at h
  exact mul_left_cancel _ _ _ ha h

end AdvancedMultiplicationWorld
