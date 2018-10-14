import random
 
chars = "a1b2c3d4e5f6g7h8i9j0k2l4m6n8o10p12qr14s16t18u20v22x24w26y28z30" 
password = "".join(random.choice(chars) for x in
range(0, 8))
 
print(password)
