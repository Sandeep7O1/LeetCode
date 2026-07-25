class Solution:
    def maxProduct(self, n: int) -> int:
        num = list( str(n))
        num.sort()
        return int(num[-1]) * int(num[-2])
        