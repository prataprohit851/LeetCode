class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        minTime = max(abs(sx-fx), abs(sy-fy))

        if sx == fx and sy == fy and t == 1:
            return False


        if minTime > t:
            return False
        else:
            return True
        