#linear search program in python
items = [5, 7, 10, 12, 15]
 
print("list of items is", items)
 
x = int(input("enter item to search:"))
 
i = flag = 0
 
while i < len(items):
    if items[i] == x:
        flag = 1
        break
 
    i = i + 1
 
if flag == 1:
    print("item found at position:", i + 1)
else:
    print("item not found")
