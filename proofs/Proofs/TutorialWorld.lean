import Mathlib.Data.Nat.Basic
import Mathlib.Tactic.NthRewrite

namespace TutorialWorld

/- the successor function used to build any natual numbers from 0 -/
def succ (a : ℕ) : ℕ := a + 1

theorem one_eq_succ_zero : 1 = succ 0 := by rfl
theorem two_eq_succ_one : 2 = succ 1 := by rfl
theorem three_eq_succ_two : 3 = succ 2 := by rfl
theorem four_eq_succ_three : 4 = succ 3 := by rfl
theorem add_zero (a : ℕ) : a = a + 0 := by rfl
theorem add_succ (a d : ℕ) : a + succ d = succ (a + d) := by rfl
theorem succ_eq_add_one (n : ℕ) : succ n = n + 1 := by
  rw [one_eq_succ_zero, add_succ, add_zero n]

section Toys
  example (x q : ℕ) : 37 * x + q = 37 * x + q := by
    rfl

  example (x y : ℕ) (h : y = x + 7) : 2 * y = 2 * (x + 7) := by
    rw [h]

  example : 2 = succ (succ 0) := by
    rw [two_eq_succ_one, one_eq_succ_zero]

  example (a b c : ℕ) : a + (b + 0) + (c + 0) = a + b + c := by
    rw [add_zero b, add_zero c]

  example : (2 : ℕ) + 2 = 4 := by
    nth_rewrite 2 [two_eq_succ_one]
    rw [add_succ, one_eq_succ_zero, add_succ, add_zero 2]
    rw [← three_eq_succ_two, ← four_eq_succ_three]

end Toys

end TutorialWorld
