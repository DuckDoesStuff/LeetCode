num = int(input("Enter a number: "))
rev_num = 0
rmder = 0
while(num > 0):
    rmder = num % 10
    rev_num = rev_num*10 + rmder
    num = num // 10
print(str(rev_num))
