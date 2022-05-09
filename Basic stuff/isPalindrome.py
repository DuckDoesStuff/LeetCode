def isPalindrome(x: int) -> bool:
    if (x < 0): return False
    num = x
    sign = 1 if x >= 0 else -1
    reversedNum = 0
    x = abs(x)
    
    while(x > 0):
        reversedNum = reversedNum * 10 + x % 10
        x = x // 10
    
    if(num == reversedNum*sign): return True
    else: return False

number = -11
print(isPalindrome(number))