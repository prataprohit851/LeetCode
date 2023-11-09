class Solution:
    def countHomogenous(self, s: str) -> int:
        ans = 0
        count = 0
        curr = 0
        for i in s:
            count = count + 1 if curr == i else 1
            curr = i
            ans += count % (10**9 + 7)
        return ans % (10**9 + 7)