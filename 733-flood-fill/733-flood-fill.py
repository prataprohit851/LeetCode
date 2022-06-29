class Solution(object):
    def floodFill(self, image, sr, sc, color):
        
        def helper(i, j, colorToChange, currColor):
            if(i < 0 or i >= len(image) or j < 0 or j >= len(image[0]) or image[i][j] != currColor or image[i][j] == colorToChange): return
            image[i][j] = colorToChange
            helper(i+1, j, colorToChange, currColor)
            helper(i-1, j, colorToChange, currColor)
            helper(i, j+1, colorToChange, currColor)
            helper(i, j-1, colorToChange, currColor)
        
        helper(sr, sc, color, image[sr][sc])
        return image