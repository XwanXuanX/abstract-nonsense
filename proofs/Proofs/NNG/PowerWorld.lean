import Proofs.NNG.MultiplicationWorld

namespace PowerWorld

open TutorialWorld
open AdditionWorld
open MultiplicationWorld
open MyNat

axiom pow_zero (m : MyNat) : m ^ (0 : MyNat) = 1
axiom pow_succ (m n : MyNat) : m ^ succ n = m ^ n * m

theorem zero_pow_zero : (0 : MyNat) ^  (0 : MyNat) = 1 := by
  rw [pow_zero]

theorem zero_pow_succ (m : MyNat) : (0 : MyNat) ^ (succ m) = 0 := by
  rw [pow_succ, mul_zero]

theorem pow_one (a : MyNat) : a ^ (1 : MyNat) = a := by
  rw [one_eq_succ_zero, pow_succ, pow_zero, one_mul]

theorem one_pow (m : MyNat) : (1 : MyNat) ^ m = 1 := by
  induction m with
  | zero =>
    change 1 ^ 0 = 1
    rw [pow_zero]
  | succ d hd =>
    rw [pow_succ, hd, one_mul]

theorem pow_two (a : MyNat) : a ^ (2 : MyNat) = a * a := by
  rw [two_eq_succ_one, pow_succ, pow_one]

theorem pow_add (a m n : MyNat) : a ^ (m + n) = a ^ m * a ^ n := by
  induction n with
  | zero =>
    change a ^ (m + 0) = a ^ m * a ^ 0
    rw [← add_zero, pow_zero, mul_one]
  | succ d hd =>
    rw [add_succ, pow_succ, hd, pow_succ, mul_assoc]

theorem mul_pow (a b n : MyNat) : (a * b) ^ n = a ^ n * b ^ n := by
  induction n with
  | zero =>
    change (a * b) ^ 0 = a ^ 0 * b ^ 0
    repeat rw [pow_zero]
    rw [mul_one]
  | succ d hd =>
    repeat rw [pow_succ]
    rw [hd]
    repeat rw [mul_assoc]
    rw [mul_comm (b ^ d), mul_comm (b ^ d), mul_assoc]

theorem pow_pow (a m n : MyNat) : (a ^ m) ^ n = a ^ (m * n) := by
  induction n with
  | zero =>
    change (a ^ m) ^ 0 = a ^ (m * 0)
    rw [pow_zero, mul_zero, pow_zero]
  | succ d hd =>
    rw [pow_succ, hd, mul_succ, pow_add]

theorem add_sq (a b : MyNat) : (a + b) ^ (2 : MyNat) = a ^ (2 : MyNat) + b ^ (2 : MyNat) + (2 : MyNat) * a * b := by
  repeat rw [pow_two]
  rw [mul_add, add_mul, two_mul, add_mul, add_mul]
  rw [mul_comm b]
  repeat rw [add_assoc]
  rw [add_comm (a * b), add_comm (a * b)]
  rw [add_assoc (b * b)]

end PowerWorld
