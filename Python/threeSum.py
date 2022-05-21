def threeSum(nums: list[int]) -> list[list[int]]:
    res = []
    nums.sort()

    for i, a in enumerate(nums):
        if(i > 0 and a == nums[i - 1]): continue
        l = i + 1
        r = len(nums) - 1

        while(l < r):
            sum = a + nums[l] + nums[r]
            if(sum > 0): r -= 1
            elif(sum < 0): l += 1
            else:
                res.append([a, nums[l], nums[r]])
                l += 1
                while(l < r and nums[l] == nums[l - 1]): l += 1

    return res

nums = [-1,0,1,2,-1,-4]
print(str(threeSum(nums)))