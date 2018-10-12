use std::cmp::PartialEq;
use std::iter::DoubleEndedIterator;

// Create a trait that requires its implementors also implement DoubleEndedIterator
// This allows us to call DoubleEndedIterator methods (self.next() and self.next_back()) in any method implementations
pub trait IsPalindrome: DoubleEndedIterator {
    fn is_palindrome(mut self) -> bool
            where Self: Sized,
                  Self::Item: PartialEq
    {
        // Try to pull an item from both ends at once
        // - If there are no items left, we'll get (None, None) and break
        // - If there's one item left, we'll get (Some(_), None) and break
        // - If there are two or more items left, we'll get (Some(_), Some(_)) and continue
        while let (Some(left), Some(right)) = (self.next(), self.next_back()) {
            if left != right {
                return false;
            }
        }
        // At this point, we consumed the entire iterator and found nowhere where the front and back of the iterator were
        // unequal, so this must be a palindrome.
        true
    }
}

// By implementing IsPalindrome for every type that implements DoubleEndedIterator, users can simply bring IsPalindrome
// into scope with `use` declarations, and every double-ended iterator whose items implement PartialEq
// (i.e. Vec<i32>.iter(), String.chars(), and more) will automatically have an is_palindrome method.
impl<T> IsPalindrome for T where T: DoubleEndedIterator {}

fn main() {
    // Test vecs that are palindromes, of odd and even length
    assert!(vec![1, 2, 1].iter().is_palindrome());
    assert!(vec![1, 2, 3, 3, 2, 1].iter().is_palindrome());

    // Test strings that are palindromes, of odd and even length
    assert!("racecar".chars().is_palindrome());
    assert!("abccba".chars().is_palindrome());

    // Test vecs that aren't palindromes, of odd and even length
    assert!(!vec![1, 2, 3].iter().is_palindrome());
    assert!(!vec![1, 2, 3, 4].iter().is_palindrome());

    // Test strings that aren't palindromes, of odd and even length
    assert!(!"rusty".chars().is_palindrome());
    assert!(!"palindrome".chars().is_palindrome());
}
