import Mathlib.Data.List.Basic
import Mathlib.Tactic

variable {α : Type}
variable {a : α}
variable {as : List α}

inductive Palindrome : List α → Prop where
  | nil      : Palindrome []
  | single   : ∀a, Palindrome [a]
  | sandwich : ∀a as, Palindrome as → Palindrome ([a] ++ as ++ [a])

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
example (as : List α) (h : as = []) : Palindrome as := by {
  simp_all [Palindrome.nil]
}

-- 2. A singleton list (a list with one element) is a palindrome.
example (a : α) (as : List α) (h : as = [a]) : Palindrome as := by {
  simp_all [Palindrome.single]
}

-- 3. If as is a palindrome, then so is [a] ++ as ++ [a] for any element a.
example (h : Palindrome as) : Palindrome ([a] ++ as ++ [a]) := by {
  exact Palindrome.sandwich a as h
}

-- 4. The reverse of a palindrome is a palindrome.
example (h : Palindrome as) : Palindrome (as.reverse) := by {
  induction h with
  | nil => exact Palindrome.nil;
  | single a => exact Palindrome.single a;
  | sandwich a as h ih => {
    rw [rev_eq];
    exact Palindrome.sandwich a as.reverse ih;
  }
}

-- This is a hard one:
-- 5. Every prefix of a palindrome that is also a suffix of the same length is itself a palindrome.
-- To formalize this statement, we need to first formally define what's a prefix and suffix

inductive Prefix : List α → List α → Prop where
  | nil   : ∀ l, Prefix [] l
  | cons  : ∀ a l₁ l₂, Prefix l₁ l₂ → Prefix (a :: l₁) (a :: l₂)

inductive Suffix : List α → List α → Prop where
  | nil   : ∀ l, Suffix l []
  | cons  : ∀ a l₁ l₂, Suffix l₁ l₂ → Suffix (l₁ ++ [a]) (l₂ ++ [a])

def isPrefix [DecidableEq α] (as ab: List α) : Bool :=
  match as, ab with
  | [], _ => true -- empty list is always prefix of any list
  | _::__, [] => false -- non-empty list cannot be prefix of empty list
  | a::asc, b::abc => if a = b then isPrefix asc abc else false

-- Proves that the function `isPrefix` is always correct
theorem is_prefix_correct [DecidableEq α] (as ab : List α) : isPrefix as ab  ↔ Prefix as ab := by {
  constructor
  show isPrefix as ab = true → Prefix as ab; {
    intro h
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
  }
  show Prefix as ab → isPrefix as ab = true; {
    intro h
    induction h with
    | nil ab => rw [isPrefix]
    | cons a as' ab' h' ih =>
      rw [isPrefix, if_pos (by rfl)]
      exact ih
  }
}





-- def isSuffix [DecidableEq α] (as : List α) (ab : List α) : Bool :=
--   match as, ab with
--   | [], _ => true



section check

variable {α : Type}
#eval isPrefix [] [1]
#eval isPrefix [1] []
#eval isPrefix [1, 2, 3] [1, 2, 3, 4, 5]
#eval isPrefix [1, 2, 3] [1, 3, 5, 7, 9]

end check







end PalindromeFacts
