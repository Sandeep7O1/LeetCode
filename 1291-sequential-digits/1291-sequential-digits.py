class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        num = "123456789"
        res = []
        low_digit = int(log10(low))+1
        high_digit = int(log10(high))+1
        
        for length in range(low_digit, high_digit + 1):
            for start in range(10 - length):

                end = start+ length
                target = int(num[start:end])
                
                if low <= target <= high:
                    res.append(target)



        return res

