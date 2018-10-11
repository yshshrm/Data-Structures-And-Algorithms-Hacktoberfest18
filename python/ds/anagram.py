def anagram(string):
    if type(string) != type('a'):
        return False

    n = len(string)
    for i in range(n):
        if string[i] != string[n - i - 1]:
            return False

    return True

inp = input()
if (anagram(inp)):
    print("Anagram")
else:
    print("Not Anagram")
