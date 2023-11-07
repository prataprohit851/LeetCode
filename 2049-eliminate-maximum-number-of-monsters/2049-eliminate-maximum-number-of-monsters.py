class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        for i in range(0, len(dist)):
            dist[i] /= speed[i]
        dist.sort()
        ans = 0
        while ans < len(dist) and ans < dist[ans]:
            print("hi")
            ans += 1
        return ans 
