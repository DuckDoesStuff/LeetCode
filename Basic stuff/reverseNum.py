def recur_reverse(num):#recursive method
    global rev_num
    if(num > 0):
        remain = num % 10
        rev_num = (rev_num) * 10 + remain
        recur_reverse(num // 10)
    return rev_num

# num = int(input("Enter a number: "))
# rev_num = 0
# rmder = 0
# while(num > 0):
#     rmder = num % 10
#     rev_num = rev_num*10 + rmder
#     num = num // 10
# print(str(rev_num))

num = int(input("Enter a number: "))
rev_num = 0
rev_num = recur_reverse(num)
print(str(rev_num))