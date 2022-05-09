from audioop import reverse

def reverseNum(num):
    rmder = 0
    rev_num = 0
    while(num > 0):
        rmder = num % 10
        rev_num = (rev_num)*10 + rmder
        num %= 10
    return rev_num

n = int(input("Enter number to be reversed: "))
n = reverseNum(n)
print("Reversed num: " + str(n))