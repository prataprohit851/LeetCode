class Solution:
    def executeInstructions(self, n: int, startPos: List[int], s: str) -> List[int]:
        li = []
        count = 0;
        ini = startPos[0]
        inj = startPos[1]
        for i in range(len(s)):
            for j in range(i, len(s)):
                if s[j] == 'R' : startPos[1] += 1
                elif s[j] == 'L' : startPos[1] -= 1
                elif s[j] == 'U' : startPos[0] -= 1
                elif s[j] == 'D' : startPos[0] += 1
                
                if (startPos[1] > -1 and startPos[1] < n and startPos[0] > -1 and startPos[0] < n) : count += 1
                else : startPos = [-1,-1] 
            startPos = [ini, inj]
            li.append(count)
            count = 0
        return li