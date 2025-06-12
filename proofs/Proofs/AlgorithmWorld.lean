import Proofs.TutorialWorld
import Proofs.AdditionWorld
import Proofs.ImplicationWorld

namespace AlgorithmWorld

open TutorialWorld
open AdditionWorld
open ImplicationWorld
open MyNat

def pred : MyNat → MyNat
  | 0 => 37
  | succ n => n

set_option linter.unusedVariables false
def is_zero : MyNat → Bool
  | 0 => True
  | succ n => False

axiom pred_succ (n : MyNat) : pred (succ n) = n
axiom is_zero_succ (n : MyNat) : is_zero (succ n) = False
axiom is_zero_zero : is_zero 0 = True

theorem add_left_comm (a b c : MyNat) : a + (b + c) = b + (a + c) := by
  rw [add_comm a (b + c), add_assoc, add_comm c a]

theorem succ_ne_zero (a : MyNat) : succ a ≠ 0 := by
  intro h
  rw [← is_zero_succ a, h, is_zero_zero]
  trivial

theorem succ_ne_succ (m n : MyNat) (h : m ≠ n) : succ m ≠ succ n := by
  contrapose! h
  rw [← pred_succ m, h, pred_succ]

-- This algorithm solves if a == b or a != b type of goal
instance instDecidableEq : DecidableEq MyNat
  | 0, 0 => isTrue <| by
      show 0 = 0
      rfl
  | succ m, 0 => isFalse <| by
      show succ m ≠ 0
      exact succ_ne_zero m
  | 0, succ n => isFalse <| by
      show 0 ≠ succ n
      exact zero_ne_succ n
  | succ m, succ n =>
      match instDecidableEq m n with
      | isTrue (h : m = n) => isTrue <| by
          show succ m = succ n
          rw [h]
      | isFalse (h : m ≠ n) => isFalse <| by
          show succ m ≠ succ n
          exact succ_ne_succ m n h

section Toys
  example (a b c d : MyNat) : a + b + (c + d) = a + c + d + b := by
    repeat rw [add_assoc]
    rw [add_left_comm b c, add_comm b d]

  example (a b c d e f g h : MyNat) : (d + f) + (h + (a + c)) + (g + e + b) = a + b + c + d + e + f + g + h := by
    simp only [add_assoc, add_left_comm, add_comm]

  -- define our own tactic to automate things!
  macro "simp_add" : tactic => `(tactic|(simp only [add_assoc, add_left_comm, add_comm]))

  example (a b c d e f g h : MyNat) : (d + f) + (h + (a + c)) + (g + e + b) = a + b + c + d + e + f + g + h := by
    simp_add

  example (a b : MyNat) (h : succ a = succ b) : a = b := by
    rw [← pred_succ a, h, pred_succ]

  example : (20 : MyNat) + 20 = 40 := by
    decide

  example : (2 : MyNat) + 2 ≠ 5 := by
    decide

end Toys

end AlgorithmWorld
