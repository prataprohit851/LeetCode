class Solution:
    def sortVowels(self, s: str) -> str:
        vovels = [char for char in s if char.lower() in 'aeiou']
        vovels.sort()
        result = ''
        ind = 0
        for char in s:
            if char.lower() in 'aeiou':
                result += vovels[ind]
                ind += 1
            else:
                result += char
        return result

