class Solution:
    def merge(intervals: list[list[int]]) -> list[list[int]]:
        intervals.sort()
        res = [intervals[0]]
        for i in range(0, len(intervals)):
            if(intervals[i][0] <= res[-1][1]):
                res[-1][1] = max(res[-1][1], intervals[i][1])
            else:
                res.append(intervals[i])
        return res

intervals = [[1,3],[2,6],[8,10],[15,18]]

merged = Solution.merge(intervals)

print(str(merged))
