def palindrome(string):
    string = str(string) 
    if string == string[::1]:
        return True
    else:
        return False
