def reverse(x: int) -> int:
        sign = 1 if x >= 0 else -1
        reversedNum = 0
        if(sign == 1): max_value = 2**31 -1
        else: max_value = 2**31
        x = abs(x)
        
        while(x > 0):

            if (reversedNum > (max_value - x % 10)//10): return 0
            reversedNum = reversedNum * 10 + x % 10
            x = x // 10
            
        return reversedNum*sign

number = -2147483412
print(str(reverse(number)))