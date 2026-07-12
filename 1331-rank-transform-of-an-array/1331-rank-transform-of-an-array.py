class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        num = arr[:]
        n =  len(arr)
        num.sort()

        res = [0] * n

        lst= defaultdict(int)
        cnt=1
        for item in num:
            if lst[item] == 0:
                lst[item] = cnt
                cnt +=1

        for i in range(0, n, 1):
            res[i] = lst.get(arr[i])


        return res