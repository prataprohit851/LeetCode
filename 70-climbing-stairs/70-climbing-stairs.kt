class Solution {
    fun climbStairs(n: Int): Int {
        var a = 0
        var b = 1
        for(i in 1..n){
            var temp = a+b
            a = b
            b = temp
        }
        return b
    }
}