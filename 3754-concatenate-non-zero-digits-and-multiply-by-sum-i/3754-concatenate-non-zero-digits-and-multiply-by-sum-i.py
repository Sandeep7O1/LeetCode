class Solution:
    def sumAndMultiply(self, n: int) -> int:
        ans = 0
        add = 0
        num = n

        while num > 0:
            if num % 10 != 0:
                ans = ans * 10 + num % 10
                add = add + num % 10
            num = num // 10

        rev = int(str(ans)[::-1])

        return rev * add