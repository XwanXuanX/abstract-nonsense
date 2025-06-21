import Mathlib.Data.List.Basic
import Mathlib.Data.Nat.Basic
import Mathlib.Tactic

namespace PrefixSuffix

variable {α : Type*}

inductive Prefix : List α → List α → Prop where
  | nil   : ∀ l, Prefix [] l
  | cons  : ∀ a l₁ l₂, Prefix l₁ l₂ → Prefix (a :: l₁) (a :: l₂)

inductive Suffix : List α → List α → Prop where
  | nil   : ∀ l, Suffix [] l
  | cons  : ∀ a l₁ l₂, Suffix l₁ l₂ → Suffix (l₁ ++ [a]) (l₂ ++ [a])

def Prefix.isPrefix [DecidableEq α] (as ab: List α) : Bool :=
  match as, ab with
  | [], _ => true -- empty list is always prefix of any list
  | _::__, [] => false -- non-empty list cannot be prefix of empty list
  | a::asc, b::abc => if a = b then isPrefix asc abc else false

def Suffix.isSuffix [DecidableEq α] (as : List α) (ab : List α) : Bool :=
  Prefix.isPrefix as.reverse ab.reverse

-- Proves that the function `isPrefix` is correct
theorem Prefix.is_prefix_correct [DecidableEq α] (as ab : List α) :
  isPrefix as ab ↔ Prefix as ab := by
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
        · have : isPrefix as' ab' = true := by
            rw [isPrefix, hab] at h; simp at h; exact h
          rw [← hab]
          exact Prefix.cons a as' ab' ((is_prefix_correct as' ab').mp this)
        · rw [isPrefix, if_neg hab] at h
          contradiction
  show Prefix as ab → isPrefix as ab = true
  · intro h
    induction h with
    | nil ab => rw [isPrefix]
    | cons a as' ab' h' ih =>
      rw [isPrefix, if_pos (by rfl)]
      exact ih

-- Prove that the suffix of as = the prefix of as.reverse
lemma suffix_eq_prefix_rev [DecidableEq α] (as ab : List α) :
  Suffix as ab ↔ Prefix as.reverse ab.reverse := by
  constructor
  show Suffix as ab → Prefix as.reverse ab.reverse
  · intro h
    induction h with
    | nil ab =>
      exact Prefix.nil (ab.reverse)
    | cons a as' ab' h' ih =>
      simp; exact Prefix.cons a (as'.reverse) (ab'.reverse) ih
  show Prefix as.reverse ab.reverse → Suffix as ab
  · intro h
    have (xs ys : List α) : Prefix xs ys → Suffix xs.reverse ys.reverse := by
      intro h
      induction h with
      | nil ys =>
        exact Suffix.nil (ys.reverse)
      | cons a xs' ys' h' ih =>
        simp; exact Suffix.cons a (xs'.reverse) (ys'.reverse) ih
    obtain h := this as.reverse ab.reverse h
    simp at h;
    exact h

-- Proves that the function `isSuffix` is always correct
theorem Suffix.is_suffix_correct [DecidableEq α] (as ab : List α) :
  isSuffix as ab ↔ Suffix as ab := by
  constructor
  show isSuffix as ab = true → Suffix as ab
  · intro h
    rw [isSuffix] at h
    rw [suffix_eq_prefix_rev]
    exact (Prefix.is_prefix_correct as.reverse ab.reverse).mp h
  show Suffix as ab → isSuffix as ab = true
  · intro h
    rw [isSuffix]
    rw [suffix_eq_prefix_rev] at h
    exact (Prefix.is_prefix_correct as.reverse ab.reverse).mpr h

-- Proves that the prefix is equal to take the length of the prefix from the list
theorem Prefix.eq_take [DecidableEq α] (xs ys : List α)
  (h : Prefix xs ys) : xs = ys.take xs.length := by
  induction h with
  | nil ys => rfl
  | cons a l1 l2 h ih => simp; exact ih

-- Proves that the suffix is equal to drop the total minus the length of the suffix from the list
theorem Suffix.eq_drop [DecidableEq α] (xs ys : List α) (h : Suffix xs ys) :
  xs = ys.drop (ys.length - xs.length) := by
  induction h with
  | nil ys => simp
  | cons a l1 l2 h ih =>
    have h1 : (l1 ++ [a]).length = l1.length + 1 := by simp
    have h2 : (l2 ++ [a]).length = l2.length + 1 := by simp
    simp [h1, h2];
    nth_rewrite 1 [ih]
    have (l1 l2 : List α) (n : ℕ) (h : n ≤ l1.length) :
      List.drop n (l1 ++ l2) = (List.drop n l1) ++ l2 := by
      induction n generalizing l1 l2 with
      | zero => simp
      | succ n' ih =>
        cases l1 with
        | nil =>
          -- contradiction: succ n' ≤ 0 is false
          contradiction
        | cons x xs =>
          simp at h; simp;
          exact ih xs l2 h
    simp [this]

end PrefixSuffix
