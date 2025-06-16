import Mathlib.Data.List.Basic
import Mathlib.Tactic

variable {α : Type}
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

end PalindromeFacts
