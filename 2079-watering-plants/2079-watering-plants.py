class Solution(object):
    def wateringPlants(self, plants, capacity):
        bucket = 0
        steps = 0
        for i in range(len(plants)):
            if bucket >= plants[i]:
                bucket -= plants[i]
                steps += 1
            else:
                steps += (2*i) + 1
                bucket = capacity
                bucket -= plants[i]
        return steps