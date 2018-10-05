#this is a simple panagram checking program 

s = input().lower()

a = 'abcdefghijklmnopqrstuvwxyz'

for i in range(26):
    if s.find(a[i]) == -1:
        print ('not pangram')
        sys.exit()

print ('pangram')
