def is_palindrome(s):
    length = len(s)
    for i in range(length/2):
        if s[i] != s[length-i-1]:
            return False
    return True
