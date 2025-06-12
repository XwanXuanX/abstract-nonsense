import Proofs.TutorialWorld
import Mathlib.Data.Nat.Basic

namespace AdditionWorld

open TutorialWorld

theorem zero_add (n : ℕ) : 0 + n = n := by
  induction n with
  | zero => rw [add_zero 0]
  | succ d hd => rw[← succ_eq_add_one, add_succ, hd]

theorem succ_add (a b : ℕ) : succ a + b = succ (a + b) := by
  induction b with
  | zero => rw [← add_zero, ← add_zero]
  | succ d hd => repeat rw [← succ_eq_add_one]; repeat rw [add_succ]
                 rw [hd]

theorem add_comm (a b : ℕ) : a + b = b + a := by
  induction b with
  | zero => rw [add_zero a, zero_add]
  | succ d hd => repeat rw [← succ_eq_add_one]; rw [add_succ, succ_add, hd]

theorem add_assoc (a b c : ℕ) : a + b + c = a + (b + c) := by
  induction a with
  | zero => repeat rw [zero_add]
  | succ d hd => repeat rw [← succ_eq_add_one]; repeat rw [succ_add]
                 rw [hd]

theorem add_right_comm (a b c : ℕ) : a + b + c = a + c + b := by
  induction b with
  | zero => rw [← add_zero, ← add_zero]
  | succ d hd => repeat rw [← succ_eq_add_one]
                 rw [add_succ, succ_add, add_succ, hd]

end AdditionWorld
