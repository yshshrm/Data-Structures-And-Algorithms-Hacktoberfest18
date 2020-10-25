s = input()
si = 0
l = 1
max_len = 1
start_si = si
while si+l < len(s):
    if s[si+l] in s[si:si+l]:
        # Element found then start from index of that
        ind = s[si:si+l].index(s[si+l])+1
        si = si + ind
        l = l - ind + 1
    else:
        l+=1
        if max_len < l:
            max_len = l
            start_si = si
print(s[start_si:start_si+max_len])