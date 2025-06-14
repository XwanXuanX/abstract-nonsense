import Proofs.NNG.TutorialWorld
import Mathlib.Data.Nat.Basic

namespace AdditionWorld

open TutorialWorld
open MyNat

theorem zero_add (n : MyNat) : 0 + n = n := by
  induction n with
  | zero =>
      rfl
  | succ d hd =>
      rw[add_succ, hd]

theorem succ_add (a b : MyNat) : succ a + b = succ (a + b) := by
  induction b with
  | zero =>
      rfl
  | succ d hd =>
      repeat rw [add_succ]
      rw [hd]

theorem add_comm (a b : MyNat) : a + b = b + a := by
  induction b with
  | zero =>
      change a + 0 = 0 + a
      rw [← add_zero, zero_add]
  | succ d hd =>
      rw [add_succ, succ_add, hd]

theorem add_assoc (a b c : MyNat) : a + b + c = a + (b + c) := by
  induction a with
  | zero =>
      change 0 + b + c = 0 + (b + c)
      repeat rw [zero_add]
  | succ d hd =>
      repeat rw [succ_add]
      rw [hd]

theorem add_right_comm (a b c : MyNat) : a + b + c = a + c + b := by
  induction b with
  | zero =>
      change a + 0 + c = a + c + 0
      rw [← add_zero, ← add_zero]
  | succ d hd =>
      rw [add_succ, succ_add, add_succ, hd]

end AdditionWorld
