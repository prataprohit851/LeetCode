class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        prevCamCount = 0
        cameraCount = 0
        beams = 0
        for i in range(len(bank)):
            for j in range(len(bank[0])):
                if bank[i][j] == '1' : cameraCount += 1
            if cameraCount : 
                beams += prevCamCount*cameraCount
                prevCamCount = cameraCount
            cameraCount = 0
        return beams