arr = [3,8,4,2,10,45,4]
item = 7
count = 0
for i in arr
    if i == item
        print("Item found")
        return
    else
        count += 1
    end
  end
if count == length(arr)
    print("Item not found")
    end
