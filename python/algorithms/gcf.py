num1 = input("First number: ")
num2 = input("Second number: ")

while (num1 != num2):
	if num1 > num2: num1  = num1 - num2
	else: num2 = num2 - num1
print(num1)
