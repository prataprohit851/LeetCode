class Solution {
    fun executeInstructions(n: Int, startPos: IntArray, s: String): IntArray {
        var li = IntArray(s.length)
        var count = 0
        var ini = startPos[0]
        var inj = startPos[1]
        
        var currPosition = startPos
        
        for (i in 0..s.length-1){
            for(j in i..s.length-1){
                
                if (s[j] == 'R') {inj += 1}
                else if (s[j] == 'L') {inj -= 1}
                else if (s[j] == 'U') {ini -= 1}
                else if (s[j] == 'D') {ini += 1}
                
                if (inj > -1 && inj < n && ini > -1 && ini < n) count += 1
                else {
                    ini = -1
                    inj = -1
                }
            }
            ini = startPos[0]
            inj = startPos[1]
            li[i] = count
            count = 0
        }
        return li
    }
}