class Solution(object):
    def minCostClimbingStairs(self, cost):
        one = cost[0]
        two = cost[1]
        for i in range(2, len(cost)):
            currCost = cost[i] + min(one,two)
            one = two
            two = currCost
        return min(one, two)