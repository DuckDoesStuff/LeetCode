class Solution:
    def fourSum(self, nums: list[int], target: int) -> list[list[int]]:
        nums.sort()
        res = []
        for i in range(0, len(nums)):
            if(i > 0 and nums[i] == nums[i - 1]): continue
            for j in range (i + 1, len(nums)):
                if(j > i + 1 and nums[j] == nums[j - 1]): continue
                threeTarget = target - nums[i]
                l, r = j + 1, len(nums) - 1
                
                while(l < r):
                    threeSum = nums[j] + nums[l] + nums[r]
                    if(threeSum == threeTarget):
                        res.append([nums[i], nums[j], nums[l], nums[r]])
                        l += 1
                        while (l < r and nums[l] == nums[l - 1]): l += 1
                    elif(threeSum > threeTarget): r -= 1
                    else: l += 1
        return res