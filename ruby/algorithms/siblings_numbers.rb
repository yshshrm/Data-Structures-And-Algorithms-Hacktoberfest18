
# Two non-negatives integers are called siblings if they can be obtained from each other
# by rearranging the digits of their decimal representations. For example, 123 and 213 are siblings
# 535 and 355 are also siblings.

# A set consisting of a non-negative integer N and all of its siblings is called the
#  of N. For example, the family of 553 comprises three numbers: 355, 535 and 553.

# Write a function:
# def solution(n)

# that, given a non-negative integer N, returns the largest number in the family of N.
# For example, given N = 213 the function should return 321. Given N = 553 the function should return 553.
# Assume that:
# N is an integer within the range [0..10,000].
# In your solution, focus on correctness, . The performance of your solution will not be the focus of the assessment.

# Wellington Avelino

def solution(n)
  siblings = n.to_s.chars.each_slice(1).to_a
  siblings.sort {|x,y| -(x <=> y)}.join.to_i
end
