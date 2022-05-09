def twoSum(nums, target):
    for i in range(0, len(nums)):
        for j in range(i + 1, len(nums)):
            if(target == nums[i] + nums[j]):
                return [nums[i], nums[j]]

nums = [2, 3, 4, 5, 9]
target = 11
pair = twoSum(nums, target)
print(pair)