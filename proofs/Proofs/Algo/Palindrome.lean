import Mathlib.Data.Nat.Basic
import Mathlib.Data.List.Basic
import Mathlib.Tactic

variable {α : Type} {a : α} {as : List α}

inductive Palindrome : List α → Prop where
  | nil      : Palindrome []
  | single   : ∀ a, Palindrome [a]
  | sandwich : ∀ a as, Palindrome as → Palindrome ([a] ++ as ++ [a])

-- Proves that ([a] ++ as ++ [a]).reverse = [a] ++ as.reverse ++ [a]
lemma rev_eq (a : α) : ([a] ++ as ++ [a]).reverse = [a] ++ as.reverse ++ [a] := by
  simp [List.reverse_append]

-- Proves that the reverse of a palindrome is also a palindrome
theorem palindrome_reverse (h : Palindrome as) : Palindrome as.reverse := by
  induction h with
  | nil => exact Palindrome.nil
  | single a => exact Palindrome.single a
  | sandwich a as h ih => rw [rev_eq]; exact Palindrome.sandwich a as.reverse ih

-- Proves that the reverse of a palindrome is itself, which is very intuitive
theorem reverse_eq_of_palindrome (h : Palindrome as) : as.reverse = as := by
  induction h with
  | nil => rfl
  | single a => rfl
  | sandwich a as h ih => simp [ih]

-- Now the theorem `palindrome_reverse` can be proved must easier
example (h : Palindrome as) : Palindrome as.reverse := by
  simp [reverse_eq_of_palindrome h, h]

-- Proves that a list with 2 elements is not empty (duh)
example (x y : α) : [x, y] ≠ [] := by
  intro h; contradiction

-- Proves that a general non-empty list is not empty (duh)
example (as : List α) (h : as.length > 0) : as ≠ [] := by
  intro h'; rw [h'] at h; simp at h

section PalindromeFacts

/-
Let's remind you that a palindrome is defined as follows:
```
inductive Palindrome : List α → Prop where
  | nil      : Palindrome []
  | single   : ∀a, Palindrome [a]
  | sandwich : ∀a as, Palindrome as → Palindrome ([a] ++ as ++ [a])
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

Have fun proving :)
-/

-- 1. The empty list is a palindrome.
example (as : List α) (h : as = []) : Palindrome as := by
  simp_all [Palindrome.nil]

-- 2. A singleton list (a list with one element) is a palindrome.
example (a : α) (as : List α) (h : as = [a]) : Palindrome as := by
  simp_all [Palindrome.single]

-- 3. If as is a palindrome, then so is [a] ++ as ++ [a] for any element a.
example (h : Palindrome as) : Palindrome ([a] ++ as ++ [a]) := by
  exact Palindrome.sandwich a as h

-- 4. The reverse of a palindrome is a palindrome.
example (h : Palindrome as) : Palindrome (as.reverse) := by
  induction h with
  | nil => exact Palindrome.nil;
  | single a => exact Palindrome.single a;
  | sandwich a as h ih =>
    rw [rev_eq];
    exact Palindrome.sandwich a as.reverse ih;

-- This is a hard one:
-- 5. Every prefix of a palindrome that is also a suffix of the same length is itself a palindrome.
-- To formalize this statement, we need to first formally define what's a prefix and suffix

inductive Prefix : List α → List α → Prop where
  | nil   : ∀ l, Prefix [] l
  | cons  : ∀ a l₁ l₂, Prefix l₁ l₂ → Prefix (a :: l₁) (a :: l₂)

inductive Suffix : List α → List α → Prop where
  | nil   : ∀ l, Suffix [] l
  | cons  : ∀ a l₁ l₂, Suffix l₁ l₂ → Suffix (l₁ ++ [a]) (l₂ ++ [a])

def isPrefix [DecidableEq α] (as ab: List α) : Bool :=
  match as, ab with
  | [], _ => true -- empty list is always prefix of any list
  | _::__, [] => false -- non-empty list cannot be prefix of empty list
  | a::asc, b::abc => if a = b then isPrefix asc abc else false

-- Proves that the function `isPrefix` is always correct
theorem is_prefix_correct [DecidableEq α] (as ab : List α) : isPrefix as ab ↔ Prefix as ab := by
  constructor
  show isPrefix as ab = true → Prefix as ab
  · intro h
    cases as with
    | nil => exact Prefix.nil ab
    | cons a as' =>
      cases ab with
      | nil => contradiction
      | cons b ab' =>
        by_cases hab : a = b
        · -- Case a = b
          have : isPrefix as' ab' = true := by
            rw [isPrefix, hab] at h
            simp at h
            exact h
          -- Now we have the inductive hypothesis
          rw [← hab]
          exact Prefix.cons a as' ab' ((is_prefix_correct as' ab').mp this)
        · -- Case a ≠ b
          rw [isPrefix, if_neg hab] at h
          contradiction
  show Prefix as ab → isPrefix as ab = true
  · intro h
    induction h with
    | nil ab => rw [isPrefix]
    | cons a as' ab' h' ih =>
      rw [isPrefix, if_pos (by rfl)]
      exact ih

-- Notice that we now can define isSuffix from isPrefix!
-- ... but we should still prove it's correctness (that the suffix = prefix of the reverse)
def isSuffix [DecidableEq α] (as : List α) (ab : List α) : Bool :=
  isPrefix as.reverse ab.reverse

-- Prove that the suffix of as = the prefix of as.reverse
theorem suffix_eq_prefix_rev [DecidableEq α] (as ab : List α) : Suffix as ab ↔ Prefix as.reverse ab.reverse := by
  constructor
  show Suffix as ab → Prefix as.reverse ab.reverse
  · intro h
    induction h with
    | nil ab => exact Prefix.nil (ab.reverse)
    | cons a as' ab' h' ih => simp; exact Prefix.cons a (as'.reverse) (ab'.reverse) ih
  show Prefix as.reverse ab.reverse → Suffix as ab
  · intro h
    have (xs ys : List α) : Prefix xs ys → Suffix xs.reverse ys.reverse := by
      intro h
      induction h with
      | nil ys => exact Suffix.nil (ys.reverse)
      | cons a xs' ys' h' ih => simp; exact Suffix.cons a (xs'.reverse) (ys'.reverse) ih
    obtain h := this as.reverse ab.reverse h
    simp at h; exact h

-- Proves that the function `isSuffix` is always correct
theorem is_suffix_correct [DecidableEq α] (as ab : List α) : isSuffix as ab ↔ Suffix as ab := by
  constructor
  show isSuffix as ab = true → Suffix as ab
  · intro h
    rw [isSuffix] at h; rw [suffix_eq_prefix_rev]
    exact (is_prefix_correct as.reverse ab.reverse).mp h
  show Suffix as ab → isSuffix as ab = true
  · intro h
    rw [isSuffix]; rw [suffix_eq_prefix_rev] at h
    exact (is_prefix_correct as.reverse ab.reverse).mpr h

theorem Prefix.eq_take [DecidableEq α] (xs ys : List α) (h : Prefix xs ys) : xs = ys.take xs.length := by
  induction h with
  | nil ys => rfl
  | cons a l1 l2 h ih => simp; exact ih

theorem Suffix.eq_drop [DecidableEq α] (xs ys : List α) (h : Suffix xs ys) : xs = ys.drop (ys.length - xs.length) := by
  induction h with
  | nil ys => simp
  | cons a l1 l2 h ih =>
    have h1 : (l1 ++ [a]).length = l1.length + 1 := by simp
    have h2 : (l2 ++ [a]).length = l2.length + 1 := by simp
    simp [h1, h2]; nth_rewrite 1 [ih]
    have (l1 l2 : List α) (n : ℕ) (h : n ≤ l1.length) :
      List.drop n (l1 ++ l2) = (List.drop n l1) ++ l2 := by
      induction n generalizing l1 l2 with
      | zero => simp
      | succ n' ih =>
        cases l1 with
          | nil => contradiction -- contradiction: succ n' ≤ 0 is false
          | cons x xs => simp at h; simp; exact ih xs l2 h
    simp [this]

-- Prove the other direction of `reverse_eq_of_palindrome`
theorem Palindrome.of_eq_reverse [DecidableEq α] (xs : List α) (h : xs = xs.reverse) : Palindrome xs := by
  match xs with
  | [] => exact Palindrome.nil
  | [a] => exact Palindrome.single a
  | a :: b :: xs' => sorry

-- Now we can finally formally define fun fact 5!
-- . 5. Every prefix of a palindrome that is also a suffix of the same length is itself a palindrome.
-- . What chatgpt means, is that, given a prefix of length n of a palindrome, and get the suffix of the
-- . same length. If they are equal, that that prefix is also a palindrome! Very interesting fact!
-- . Prefix [1, 2, 1, 2, 1] [1, 2, 1, 2, 1, 2, 1]
theorem prefix_eq_suffix_palindrome [DecidableEq α] (as pas : List α)
    (h₁ : Palindrome as) (h₂ : Prefix pas as) (h₃ : Suffix pas as) : Palindrome pas := by
  sorry

-- 6. If a list is a palindrome, then its length is even or odd according to whether the list is made by the sandwich or single constructor.
theorem len_even_or_odd [DecidableEq α] (h : Palindrome as) : Even as.length ∨ Odd as.length := by
  induction h with
  | nil => left; simp
  | single a => right; simp
  | sandwich a as' h' ih =>
    rcases ih with ihl | ihr
    · left; simp [ihl]
    · right; simp [ihr]

-- 10. The concatenation of a list and its reverse is always a palindrome.
theorem concat_rev_palindrome [DecidableEq α] (as : List α) : Palindrome (as ++ as.reverse) := by
  induction as with
  | nil => exact Palindrome.nil
  | cons a as' ih =>
    -- Need to show that (a :: as').reverse = as'.reverse ++ [a]
    have h : (a :: as').reverse = as'.reverse ++ [a] := by simp
    rw [h] -- now adjust the goal to Palindrome ([a] ++ (as' ++ as'.reverse) ++ [a])
    -- Then we can use the `sandwich` constructor easily
    have h1 : a :: as' = [a] ++ as' := by simp
    have h2 (a : α) (xs xy : List α) : xs ++ (xy ++ [a]) = (xs ++ xy) ++ [a] := by simp
    rw [h1, List.append_assoc, h2]
    exact Palindrome.sandwich a (as' ++ as'.reverse) ih

-- 11. A list is a palindrome if and only if it is equal to its reverse.
theorem Palindrome.iff_eq_reverse [DecidableEq α] : Palindrome as ↔ as = as.reverse := by
  constructor
  · intro h; exact Eq.symm (reverse_eq_of_palindrome h)
  · intro h; exact Palindrome.of_eq_reverse _ h

-- 12. If a palindrome has even length, it can be written as xs ++ xs.reverse for some list xs.
theorem even_palindrome_eq_concat_rev [DecidableEq α] (h : Palindrome as) :
  Even as.length → ∃ xs, as = xs ++ xs.reverse := by
  intro h1
  use List.take (as.length / 2) as
  induction h with
  | nil => simp
  | single a => -- we need to show that this is a contradiction, can't happen
    obtain ⟨k, hk⟩ := h1;
    have (h : 1 = k + k) : False := by
      cases k with
      | zero => linarith
      | succ k' => linarith
    simp_all [this];
  | sandwich a as' h' ih =>
    obtain ⟨k, hk⟩ := h1
    -- Fill in this blank
    sorry

end PalindromeFacts
