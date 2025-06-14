import Proofs.NNG.ImplicationWorld

namespace AdvancedAdditionWorld

open TutorialWorld
open AdditionWorld
open ImplicationWorld
open MyNat

theorem add_right_cancel (a b n : MyNat) : a + n = b + n → a = b := by
  induction n with
  | zero =>
      change a + 0 = b + 0 → a = b
      repeat rw [← add_zero]
      simp
  | succ d hd =>
      repeat rw [add_succ]
      intro h
      have h := succ_inj _ _ h
      exact hd h

theorem add_left_cancel (a b n : MyNat) : n + a = n + b → a = b := by
  repeat rw [add_comm n]
  exact add_right_cancel a b n

theorem add_left_eq_self (x y : MyNat) : x + y = y → x = 0 := by
  nth_rewrite 2 [← zero_add y]
  exact add_right_cancel x 0 y

theorem add_right_eq_self (x y : MyNat) : x + y = x → y = 0 := by
  nth_rewrite 2 [add_zero x]
  exact add_left_cancel y 0 x

theorem add_right_eq_zero (a b : MyNat) : a + b = 0 → a = 0 := by
  cases b with
  | zero =>
      change a + 0 = 0 → a = 0
      rw [← add_zero]
      simp
  | succ d =>
      intro h
      rw [add_succ] at h
      symm at h
      have h := zero_ne_succ _ h
      cases h

theorem add_left_eq_zero (a b : MyNat) : a + b = 0 → b = 0 := by
  intro h
  rw [add_comm] at h
  exact add_right_eq_zero b a h

end AdvancedAdditionWorld
