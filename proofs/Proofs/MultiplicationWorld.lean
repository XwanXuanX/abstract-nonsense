import Proofs.TutorialWorld
import Proofs.AdditionWorld

namespace MultiplicationWorld

open TutorialWorld
open AdditionWorld
open MyNat

theorem mul_zero (m : MyNat) : m * 0 = 0 := by
  rfl

theorem mul_succ (a b : MyNat) : a * succ b = a * b + a := by
  rfl

theorem mul_one (m : MyNat) : m * 1 = m := by
  rw [one_eq_succ_zero, mul_succ, mul_zero, zero_add]

theorem zero_mul (m : MyNat) : 0 * m = 0 := by
  induction m with
  | zero =>
      change 0 * 0 = 0
      rw [mul_zero]
  | succ d hd =>
      rw [mul_succ, hd, zero_add]

theorem succ_mul (a b : MyNat) : succ a * b = a * b + b := by
  induction b with
  | zero =>
      change succ a * 0 = a * 0 + 0
      repeat rw [mul_zero]
      rfl
  | succ d hd =>
      rw [mul_succ, mul_succ, hd, add_succ, add_succ, add_right_comm]

theorem mul_comm (a b : MyNat) : a * b = b * a := by
  induction b with
  | zero =>
      change a * 0 = 0 * a
      rw [mul_zero, zero_mul]
  | succ d hd =>
      rw [mul_succ, succ_mul, hd]

theorem one_mul (m : MyNat): 1 * m = m := by
  rw [mul_comm, mul_one]

theorem two_mul (m : MyNat): 2 * m = m + m := by
  rw [two_eq_succ_one, succ_mul, one_mul]

theorem mul_add (a b c : MyNat) : a * (b + c) = a * b + a * c := by
  induction c with
  | zero =>
      change a * (b + 0) = a * b + a * 0
      rw [← add_zero, mul_zero, ← add_zero]
  | succ d hd =>
      rw [add_succ, mul_succ, hd, mul_succ, add_assoc]

theorem add_mul (a b c : MyNat) : (a + b) * c = a * c + b * c := by
  rw [mul_comm, mul_add, mul_comm c, mul_comm c]

theorem mul_assoc (a b c : MyNat) : (a * b) * c = a * (b * c) := by
  induction c with
  | zero =>
      change a * b * 0 = a * (b * 0)
      repeat rw [mul_zero]
  | succ d hd =>
      rw [mul_succ, hd, mul_succ, mul_add]

end MultiplicationWorld
