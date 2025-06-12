import Proofs.TutorialWorld
import Proofs.AdditionWorld

namespace MultiplicationWorld

open TutorialWorld
open AdditionWorld

theorem mul_zero (m : ℕ) : m * 0 = 0 := by rfl

theorem mul_succ (a b : ℕ) : a * succ b = a * b + a := by rfl

theorem mul_one (m : ℕ) : m * 1 = m := by rw [one_eq_succ_zero, mul_succ, mul_zero, zero_add]

theorem zero_mul (m : ℕ) : 0 * m = 0 := by
  induction m with
  | zero => rw [mul_zero]
  | succ d hd => rw [← succ_eq_add_one, mul_succ, hd, zero_add]

theorem succ_mul (a b : ℕ) : succ a * b = a * b + b := by
  induction b with
  | zero => repeat rw [mul_zero]
  | succ d hd => rw [← succ_eq_add_one, mul_succ, mul_succ, hd]
                 rw [add_succ, add_succ, add_right_comm]

theorem mul_comm (a b : ℕ) : a * b = b * a := by
  induction b with
  | zero => rw [mul_zero, zero_mul]
  | succ d hd => rw [← succ_eq_add_one, mul_succ, succ_mul, hd]

theorem one_mul (m : ℕ): 1 * m = m := by rw [mul_comm, mul_one]

theorem two_mul (m : ℕ): 2 * m = m + m := by rw [two_eq_succ_one, succ_mul, one_mul]

theorem mul_add (a b c : ℕ) : a * (b + c) = a * b + a * c := by
  induction c with
  | zero => rw [← add_zero, mul_zero, ← add_zero]
  | succ d hd => rw [← succ_eq_add_one, add_succ, mul_succ, hd, mul_succ, add_assoc]

theorem add_mul (a b c : ℕ) : (a + b) * c = a * c + b * c := by
  rw [mul_comm, mul_add, mul_comm c, mul_comm c]

theorem mul_assoc (a b c : ℕ) : (a * b) * c = a * (b * c) := by
  induction c with
  | zero => repeat rw [mul_zero]
  | succ d hd => rw [← succ_eq_add_one, mul_succ, hd, mul_succ, mul_add]

end MultiplicationWorld
