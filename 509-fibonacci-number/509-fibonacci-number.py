class Solution:
    def fib(self, n: int) -> int:
        if n==0: return 0
        li = [0,1]
        i = 2
        while i-1 < n:
            li.append(li[i-1] + li[i-2])
            i += 1   
            
        return li[-1]