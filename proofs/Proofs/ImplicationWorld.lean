import Proofs.TutorialWorld
import Proofs.AdditionWorld
import Mathlib.Data.Nat.Basic

namespace ImplicationWorld

open TutorialWorld
open AdditionWorld
open MyNat

-- two functionally correct (same) axioms
axiom succ_inj (a b : MyNat) (h: succ a = succ b) : a = b
axiom succ_inj2 (a b : MyNat) : succ a = succ b → a = b
axiom zero_ne_succ (a : MyNat) : 0 ≠ succ a

theorem zero_ne_one : (0 : MyNat) ≠ 1 := by
  intro h
  rw [one_eq_succ_zero] at h
  exact zero_ne_succ _ h

theorem one_ne_zero : (1 : MyNat) ≠ 0 := by
  symm
  exact zero_ne_one

section Toys
  set_option linter.unusedVariables false
  example (x y z : ℕ) (h1 : x + y = 37) (h2 : 3 * x + z = 42) : x + y = 37 := by
    exact h1

  example (x y : MyNat) (h : 0 + x = 0 + y + 2) : x = y + 2 := by
    repeat rw [zero_add] at h
    exact h

  example (x y : MyNat) (h1 : x = 37) (h2 : x = 37 → y = 42) : y = 42 := by
    exact h2 h1

  example (x : MyNat) (h : x + 1 = 4) : x = 3 := by
    rw [four_eq_succ_three] at h
    rw [← succ_eq_add_one] at h
    exact succ_inj _ _ h

  example (x : MyNat) : x = 37 → x = 37 := by
    intro h
    exact h

  example (x y : MyNat) : x + 1 = y + 1 → x = y := by
    intro h
    repeat rw [← succ_eq_add_one] at h
    exact succ_inj _ _ h

  example (x y : MyNat) (h1 : x = y) (h2 : x ≠ y) : False := by
    exact h2 h1

  example : succ (succ 0) + succ (succ 0) ≠ succ (succ (succ (succ (succ 0)))) := by
    intro h
    repeat rw [add_succ] at h
    rw [← add_zero] at h
    repeat have h := succ_inj _ _ h
    exact zero_ne_succ _ h

end Toys

end ImplicationWorld
