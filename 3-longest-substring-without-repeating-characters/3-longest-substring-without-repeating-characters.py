class Solution(object):
    def lengthOfLongestSubstring(self, s):
        i = 0
        j = 0
        n = len(s)
        HT = set()
        maxAns = 0
        
        while (i < n and j < n):
            if s[j] in HT: 
                HT.remove(s[i])
                i += 1
                
            else:
                HT.add(s[j])
                j += 1
                maxAns = max(maxAns, j-i)
                
        return maxAns