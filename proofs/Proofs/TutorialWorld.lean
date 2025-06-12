import Mathlib.Data.Nat.Basic
import Mathlib.Tactic.NthRewrite

namespace TutorialWorld

inductive MyNat where
  | zero : MyNat
  | succ : MyNat → MyNat

open MyNat

def add : MyNat → MyNat → MyNat
  | a, zero => a                  -- add_zero := a + 0 = a
  | a, succ b => succ (add a b)   -- add_succ := a + succ b = succ (a + b)

set_option linter.unusedVariables false
def mul : MyNat → MyNat → MyNat
  | a, zero => zero               -- mul_zero := a * 0 = 0
  | a, succ b => add (mul a b) a  -- mul_succ := a * succ b = (a * b) + a

instance : OfNat MyNat (nat_lit 0) := ⟨zero⟩
instance (n : Nat) [OfNat MyNat n]: OfNat MyNat (n + 1) := ⟨succ (OfNat.ofNat n)⟩
instance : HAdd MyNat MyNat MyNat where hAdd := add
instance : HMul MyNat MyNat MyNat where hMul := mul

theorem one_eq_succ_zero : 1 = succ 0 := by rfl
theorem two_eq_succ_one : 2 = succ 1 := by rfl
theorem three_eq_succ_two : 3 = succ 2 := by rfl
theorem four_eq_succ_three : 4 = succ 3 := by rfl
theorem add_zero (a : MyNat) : a = a + 0 := by rfl
theorem add_succ (a d : MyNat) : a + succ d = succ (a + d) := by rfl
theorem succ_eq_add_one (n : MyNat) : succ n = n + 1 := by
  rw [one_eq_succ_zero, add_succ, ← add_zero]

section Toys
  -- Multiplication not defined yet...
  example (x q : ℕ) : 37 * x + q = 37 * x + q := by
    rfl

  -- Multiplication not defined yet...
  example (x y : ℕ) (h : y = x + 7) : 2 * y = 2 * (x + 7) := by
    rw [h]

  example : 2 = succ (succ 0) := by
    rw [two_eq_succ_one, one_eq_succ_zero]

  example (a b c : MyNat) : a + (b + 0) + (c + 0) = a + b + c := by
    rw [← add_zero b, ← add_zero c]

  example : (2 : MyNat) + 2 = 4 := by
    nth_rewrite 2 [two_eq_succ_one]
    rw [add_succ, one_eq_succ_zero, add_succ, ← add_zero]
    rw [← three_eq_succ_two, ← four_eq_succ_three]

end Toys

end TutorialWorld
