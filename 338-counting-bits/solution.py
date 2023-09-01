class Solution:
    def countBits(self, n: int) -> List[int]:
        out = [0 for i in range(n+1)]
        for i in range(1, n+1):
            if i%2==1:
                out[i]=out[i-1]+1
            else:
                out[i]=out[i//2]
        return out