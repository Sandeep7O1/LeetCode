class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key= lambda x: (x[0], -x[1]))

        m = len(intervals)
        ans = 0
        maxi = intervals[0][1]

        for i in range(1,m,1):
                if maxi >= intervals[i][1]:
                    ans  = ans+1
                else: 
                    maxi = intervals[i][1]

        return m -ans
        