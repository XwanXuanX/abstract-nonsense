import Mathlib.Data.Nat.Basic
import Mathlib.Data.List.Basic
import Mathlib.Tactic

namespace Onions

variable {α : Type*}

-- Data structure that can easily *peel off* head and last
inductive Onion (α : Type*) where
  | zero : Onion α
  | one  : α → Onion α
  | ends : α → Onion α → α → Onion α
deriving Repr, DecidableEq

def Onion.reverse [DecidableEq α] : Onion α → Onion α
  | Onion.zero => Onion.zero
  | Onion.one a => Onion.one a
  | Onion.ends a on b => Onion.ends b (Onion.reverse on) a

def Onion.length : Onion α → Nat
  | Onion.zero => 0
  | Onion.one _ => 1
  | Onion.ends _ on _ => 2 + on.length

def Onion.toList : Onion α → List α
  | Onion.zero => []
  | Onion.one a => [a]
  | Onion.ends a on b => a :: on.toList ++ [b]

end Onions

namespace Palindromes

open Onions

variable {α : Type*} {a : α} {on : Onion α}

inductive Palindrome : Onion α → Prop where
  | nil : Palindrome Onion.zero
  | single (a : α) : Palindrome (Onion.one a)
  | sandwich (a : α) (on : Onion α) : Palindrome on → Palindrome (Onion.ends a on a)

-- Proves that the reverse of a palindrome is also a palindrome
theorem Palindrome.reverse [DecidableEq α] (h : Palindrome on) : Palindrome on.reverse := by
  induction h with
  | nil => constructor
  | single a => constructor
  | sandwich a on h ih =>
    simp [Onion.reverse];
    exact Palindrome.sandwich a on.reverse ih

-- Proves that the reverse of a palindrome is itself, which is very intuitive
theorem Palindrome.reverse_eq [DecidableEq α] (h : Palindrome on) : on.reverse = on := by
  induction h with
  | nil => rfl
  | single a => rfl
  | sandwich a on h ih => simp [ih, Onion.reverse]

section PalindromesFacts

/-
Let's remind you that a palindrome is defined as follows:
```
inductive Palindrome : Onion α → Prop where
  | nil : Palindrome Onion.zero
  | single (a : α) : Palindrome (Onion.one a)
  | sandwich (a : α) (on : Onion α) : Palindrome on → Palindrome (Onion.ends a on a)
```

# Facts suggested by Chatgpt:
1. The empty list is a palindrome.
2. A singleton list (a list with one element) is a palindrome.
3. If as is a palindrome, then so is [a] ++ as ++ [a] for any element a.
4. The reverse of a palindrome is a palindrome.
5. Every prefix of a palindrome that is also a suffix of the same length is itself a palindrome.
6. If a list is a palindrome, then its length is even or odd according to whether the list is made by the sandwich or single constructor.
7. Any list of length 2 is a palindrome if and only if its first and second elements are equal.
8. Concatenating two palindromes does not necessarily yield a palindrome.
9. If a list is a palindrome, then every element at position i equals the element at position length - i - 1.
10. The concatenation of a list and its reverse is always a palindrome.
11. A list is a palindrome if and only if it is equal to its reverse.
12. If a palindrome has even length, it can be written as xs ++ xs.reverse for some list xs.
13. The set of palindromic lists over a finite alphabet is infinite.
14. If as and bs are palindromes, then [a] ++ as ++ [a] and [b] ++ bs ++ [b] are palindromes.
15. Every sublist of a palindrome is not necessarily a palindrome.

Have fun proving :3
-/

-- 1. The empty onion is a palindrome.
example (h : on = Onion.zero) : Palindrome on := by
  simp_all [Palindrome.nil]

-- 2. A singleton onion (an onion with one element) is a palindrome.
example (a : α) (h : on = Onion.one a) : Palindrome on := by
  simp_all [Palindrome.single]

-- 3. If on is a palindrome, then so is Onion.ends a on a for any element a.
example (h : Palindrome on) : Palindrome (Onion.ends a on a) := by
  exact Palindrome.sandwich a on h

-- Prove the other direction of `Palindrome.reverse_eq`
theorem Palindrome.eq_reverse [DecidableEq α] (h : on = on.reverse) : Palindrome on := by
  induction on with
  | zero => constructor
  | one a => constructor
  | ends a on' b ih =>
    -- Need to show a = b and Palindrome on' from h and ih
    have claim1 : a = b ∧ on' = on'.reverse:= by
      simp [Onion.reverse] at h
      exact And.intro h.left h.right.left
    have claim2 : Palindrome on' := by exact ih claim1.right
    rw [claim1.left]
    constructor
    exact claim2

-- 6. If a list is a palindrome, then its length is even or odd according to whether the list is made by the sandwich or single constructor.
theorem Palindrome.len_even_or_odd [DecidableEq α]
  (h : Palindrome on) : Even on.length ∨ Odd on.length := by
  induction h with
  | nil => left; simp [Onion.length]
  | single a => right; simp [Onion.length]
  | sandwich a on' h' ih =>
    rcases ih with ihl | ihr
    · left; simp [Onion.length]
      have claim1 (n : Nat) (hc : Even n) : Even (2 + n) := by
        cases hc with
        | intro k hk =>
          use k + 1; rw [hk]; ring
      exact claim1 on'.length ihl
    · right; simp [Onion.length]
      have claim2 (n : Nat) (hc : Odd n) : Odd (2 + n) := by
        cases hc with
        | intro k hk =>
          use k + 1; rw [hk]; ring
      exact claim2 on'.length ihr

-- 11. A list is a palindrome if and only if it is equal to its reverse.
theorem Palindrome.eq_reverse_iff [DecidableEq α] : Palindrome on ↔ on = on.reverse := by
  constructor
  · intro h; exact (Palindrome.reverse_eq h).symm
  · intro h; exact Palindrome.eq_reverse h

end PalindromesFacts

end Palindromes

namespace PalindromeList

variable {α : Type*}

-- This is an alternative definition of a palindrome using lists
-- Concatenation of Onions is painful, thus we use lists default concatenation
inductive Palindrome : List α → Prop where
  | nil      : Palindrome []
  | single   : ∀ a, Palindrome [a]
  | sandwich : ∀ a as, Palindrome as → Palindrome ([a] ++ as ++ [a])

-- 10. The concatenation of a list and its reverse is always a palindrome.
theorem Palindrome.concat_rev_palindrome [DecidableEq α] (as : List α) :
  Palindrome (as ++ as.reverse) := by
  induction as with
  | nil => constructor
  | cons a as' ih =>
    -- Need to show that (a :: as').reverse = as'.reverse ++ [a]
    have h : (a :: as').reverse = as'.reverse ++ [a] := by simp
    rw [h] -- now adjust the goal to Palindrome ([a] ++ (as' ++ as'.reverse) ++ [a])
    -- Then we can use the `sandwich` constructor easily
    have h1 : a :: as' = [a] ++ as' := by simp
    have h2 (a : α) (xs xy : List α) : xs ++ (xy ++ [a]) = (xs ++ xy) ++ [a] := by simp
    rw [h1, List.append_assoc, h2]
    exact Palindrome.sandwich a (as' ++ as'.reverse) ih

end PalindromeList
