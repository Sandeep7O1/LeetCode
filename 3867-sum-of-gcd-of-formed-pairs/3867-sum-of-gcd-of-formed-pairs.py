class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        n = len(nums)
        pregcd = [0]*n
        maxi = nums[0]

        for i in range(0,n,1):
            maxi = max(nums[i], maxi)
            pregcd[i] = gcd(maxi, nums[i])

        pregcd.sort()
        ans = 0
        i =0
        j = n-1

        while i<j:
            ans += gcd(pregcd[i], pregcd[j])
            i +=1
            j -=1
        
        return  ans

