def lengthOfLongestSubstring(s: str) -> int:
    seen = set() #a type of array that can not have duplicated value
    l = result = 0
    for r in range(len(s)):
        while(s[r] in seen):#remove characters until the current character is no longer in our set
            seen.remove(s[l])
            l += 1
        seen.add(s[r])#add current character to the set
        result = max(result, r - l + 1)
    return result


s = "pwwkew"
print(str(lengthOfLongestSubstring(s)))